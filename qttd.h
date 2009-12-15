#ifndef QTTD_H
#define QTTD_H

#include <QtGui/QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>

//Forward declaration
class QtTDContext;

class QtTD : public QMainWindow
{
    Q_OBJECT

public:
    QtTD(QWidget *parent = 0);
    ~QtTD();

    void paintBoard();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    QtTDContext *context;

    QImage layer0; // Cache image for the background
    QImage layer1; // Cache image for the hexes
};

#endif // QTTD_H
