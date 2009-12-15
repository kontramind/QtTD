#include "qttd.h"
#include "qttdcontext.h"
#include "qttdgameboard.h"

#include <QtGui/QHBoxLayout>
#include <QtGui/QGraphicsPixmapItem>

QtTD::QtTD(QWidget *parent)
    : QMainWindow(parent)
{
//    createActions();
//    createToolBox();
//    createMenus();
    context = new QtTDContext(this);
    scene = new QtTDGameBoard(parent, this, context);
    scene->setSceneRect(QRectF(0, 0, 1000, 1000));
//    connect(scene, SIGNAL(itemInserted(DiagramItem *)),
//            this, SLOT(itemInserted(DiagramItem *)));
//    connect(scene, SIGNAL(textInserted(QGraphicsTextItem *)),
//        this, SLOT(textInserted(QGraphicsTextItem *)));
//    connect(scene, SIGNAL(itemSelected(QGraphicsItem *)),
//        this, SLOT(itemSelected(QGraphicsItem *)));
//    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    //layout->addWidget(toolBox);
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    layout->addWidget(view);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("QtTD"));
//    setUnifiedTitleAndToolBarOnMac(true);
}

QtTD::~QtTD()
{

}

void QtTD::paintBoard() {
//        synchronized (this.paintLock) {
//                this.painting = true;
//        }
        int time;
        // Two layers for the background (hexes) that are cached.
        QGraphicsPixmapItem g2_0 = null;
        QGraphicsPixmapItem g2_1 = null;
        bool clearedLayer0 = false;
        bool clearedLayer1 = false;

//        synchronized (this.paintTimeLock) {
//                time = this.paintTime;
//        }

        synchronized (this.context.PaintingLock) {
                this.panelWaveInfo.doTick(time);

                //long time1 = new Date().getTime();

                if (this.clearLayer0) {
                        //System.out.println("Redrawing layer 0...");
                        this.clearLayer0 = false;
                        clearedLayer0 = true;
                        g2_0 = this.layer0.createGraphics();
                        g2_0.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                        g2_0.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
                        g2_0.setColor(this.colors.getColorBaseBackGround());
                        g2_0.fillRect(0, 0, this.boardWidth, this.boardHeight);

                        if (this.drawBackground) {
                                BufferedImage bg;
                                if (this.context.backgroundImage.length() > 0) {
                                        bg = this.context.loadImage(this.context.backgroundImage);
                                } else {
                                        bg = this.context.loadImage(this.backgroundDefault);
                                }
                                int ox = Math.round(this.context.offsetX);
                                int oy = Math.round(this.context.offsetY);
                                int width = Math.round(this.boardWidth - this.context.offsetX * 2);
                                int height = Math.round(this.boardHeight - this.context.offsetY * 2);
                                g2_0.drawImage(bg, ox, oy, width, height, this.colors.getColorBaseBackGround(), null);
                        }
                }

                if (clearLayer1) {
                        //System.out.println("Redrawing layer 1...");
                        this.clearLayer1 = false;
                        clearedLayer1 = true;
                        g2_1 = this.layer1.createGraphics();
                        g2_1.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                        g2_1.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
                        g2_1.setComposite(AlphaComposite.getInstance(AlphaComposite.CLEAR, 0.0f));
                        g2_1.fillRect(0, 0, this.boardWidth, this.boardHeight);
                        g2_1.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER));
                }

                if (clearedLayer0 || clearedLayer1) {
                        if (this.context.grid != null) {
                                for (int y = 0; y < this.context.grid[0].length; y++) {
                                        int xLength = this.context.grid.length - (y & 1);
                                        for (int x = 0; x < xLength; x++) {
                                                this.context.grid[x][y].paintBase(g2_0, g2_1);
                                        }
                                }
                        }
                        g2_0.drawImage(this.layer1, 0, 0, null);
                }
                if (g2_0 != null) {
                        g2_0.dispose();
                }
                if (g2_1 != null) {
                        g2_1.dispose();
                }

                g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
                g2.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
                g2.setComposite(AlphaComposite.getInstance(AlphaComposite.CLEAR, 0.0f));
                g2.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER));

                // Draw the cached background.
                g2.drawImage(this.layer0, 0, 0, null);

                if (this.context.grid != null) {
                        for (int y = 0; y < this.context.grid[0].length; y++) {
                                int xLength = this.context.grid.length - (y & 1);
                                for (int x = 0; x < xLength; x++) {
                                        this.context.grid[x][y].paintEffects(g2);
                                }
                        }
                }
                Vector<Path> paths = this.context.getPaths();
                for (int i = paths.size() - 1; i >= 0; i--) {
                        paths.get(i).paint(g2, time);
                }

                if (this.context.enemies != null) {
                        for (int i = 0; i < this.context.enemies.length; i++) {
                                this.context.enemies[i].paint(g2, time);
                        }
                }

                for (int i = 0; i < this.towers.size(); i++) {
                        this.towers.get(i).paint(g2, time);
                }

                for (int i = 0; i < this.towers.size(); i++) {
                        this.towers.get(i).paintEffects(g2, time);
                }
        }
        //long time2 = new Date().getTime();
        //this.jLabel_time.setText(""+(time2-time1));
        synchronized (this.paintLock) {
                this.painting = false;
        }
}
