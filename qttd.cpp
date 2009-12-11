#include "qttd.h"
#include <QtGui/QHBoxLayout>

QtTD::QtTD(QWidget *parent)
    : QMainWindow(parent)
{
//    createActions();
//    createToolBox();
//    createMenus();

    scene = new QGraphicsScene(parent);
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
