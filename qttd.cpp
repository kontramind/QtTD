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
    gameBoard = new QtTDGameBoard(parent, this, context);
    gameBoard->setSceneRect(QRectF(0, 0, 1000, 1000));
//    connect(scene, SIGNAL(itemInserted(DiagramItem *)),
//            this, SLOT(itemInserted(DiagramItem *)));
//    connect(scene, SIGNAL(textInserted(QGraphicsTextItem *)),
//        this, SLOT(textInserted(QGraphicsTextItem *)));
//    connect(scene, SIGNAL(itemSelected(QGraphicsItem *)),
//        this, SLOT(itemSelected(QGraphicsItem *)));
//    createToolbars();

    QHBoxLayout *layout = new QHBoxLayout;
    //layout->addWidget(toolBox);
    view = new QGraphicsView(gameBoard);
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
                painting = true;
//        }
        int time;
        // Two layers for the background (hexes) that are cached.
        QGraphicsPixmapItem g2_0;
        QGraphicsPixmapItem g2_1;
        bool clearedLayer0 = false;
        bool clearedLayer1 = false;

//        synchronized (this.paintTimeLock) {
                time = paintTime;
//        }

//        synchronized (this.context.PaintingLock) {
                //panelWaveInfo.doTick(time);

                //long time1 = new Date().getTime();

                if (clearLayer0) {
                        //System.out.println("Redrawing layer 0...");
                        clearLayer0 = false;
                        clearedLayer0 = true;
//                        g2_0 = layer0.createGraphics();
//                        g2_0.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
//                        g2_0.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
//                        g2_0.setColor(colors.getColorBaseBackGround());
//                        g2_0.fillRect(0, 0, boardWidth, boardHeight);

                        if (drawBackground) {
                                QImage bg;
                                if (context->getBackgroundImage().length() > 0) {
                                        bg = context->loadImage(context->getBackgroundImage());
                                } else {
                                        bg = context->loadImage(backgroundDefault);
                                }
                                int ox = qRound(context->getOffsetX());
                                int oy = qRound(context->getOffsetY());
                                int width = qRound(boardWidth - context->getOffsetX() * 2);
                                int height = qRound(boardHeight - context->getOffsetY() * 2);
                                //g2_0.drawImage(bg, ox, oy, width, height, colors->getColorBaseBackGround(), null);
                        }
                }

                if (clearLayer1) {
                        //System.out.println("Redrawing layer 1...");
                        clearLayer1 = false;
                        clearedLayer1 = true;
//                        g2_1 = layer1.createGraphics();
//                        g2_1.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
//                        g2_1.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
//                        g2_1.setComposite(AlphaComposite.getInstance(AlphaComposite.CLEAR, 0.0f));
//                        g2_1.fillRect(0, 0, boardWidth, boardHeight);
//                        g2_1.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER));
                }

                if (clearedLayer0 || clearedLayer1) {
                        if (!context->getGrid().isEmpty()) {
                                for (int y = 0; y < context->getGrid().at(0).size(); y++) {
                                        int xLength = context->getGrid().size() - (y & 1);
                                        for (int x = 0; x < xLength; x++) {
                                                //context->getGrid().at(x).at(y).paintBase(g2_0, g2_1);
                                        }
                                }
                        }
                        //g2_0.drawImage(this.layer1, 0, 0, null);
                }
//                if (g2_0 != null) {
//                        g2_0.dispose();
//                }
//                if (g2_1 != null) {
//                        g2_1.dispose();
//                }

//                g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
//                g2.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
//                g2.setComposite(AlphaComposite.getInstance(AlphaComposite.CLEAR, 0.0f));
//                g2.setComposite(AlphaComposite.getInstance(AlphaComposite.SRC_OVER));

                // Draw the cached background.
//                g2.drawImage(this.layer0, 0, 0, null);

                if (!context->getGrid().isEmpty()) {
                        for (int y = 0; y < context->getGrid().at(0).size(); y++) {
                                int xLength = context->getGrid().size() - (y & 1);
                                for (int x = 0; x < xLength; x++) {
                                        //context->getGrid().at(x).at(y).paintEffects(g2);
                                }
                        }
                }
//                QVector<QtTDPath> paths = context->getPaths();
//                for (int i = paths.size() - 1; i >= 0; i--) {
//                        //paths.at(i).paint(g2, time);
//                }

//                if (!context->getEenemies().isEmpty()) {
//                        for (int i = 0; i < context->getEenemies().size(); i++) {
//                                //context.enemies[i].paint(g2, time);
//                        }
//                }

//                for (int i = 0; i < towers.size(); i++) {
//                        towers.at(i).paint(g2, time);
//                }
//
//                for (int i = 0; i < towers.size(); i++) {
//                        towers.at(i).paintEffects(g2, time);
//                }
//        }

//        synchronized (this.paintLock) {
                painting = false;
//        }
}
