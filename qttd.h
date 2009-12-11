#ifndef QTTD_H
#define QTTD_H

#include <QtGui/QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>

class QtTD : public QMainWindow
{
    Q_OBJECT

public:
    QtTD(QWidget *parent = 0);
    ~QtTD();
private:
    QGraphicsScene *scene;
    QGraphicsView *view;

    QPixmap layer0; // Cache image for the background
    QPixmap layer1; // Cache image for the hexes
};

#endif // QTTD_H
