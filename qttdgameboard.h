#ifndef QTTDGAMEBOARD_H
#define QTTDGAMEBOARD_H

#include <QGraphicsScene>

//Forward declarations
class QtTD;
class QtTDContext;

class QtTDGameBoard : public QGraphicsScene
{
public:
    QtTDGameBoard(QObject *parent, QtTD* game, QtTDContext* context);

    void paint();
    QVector<int> hexCoordsFromScreenCoords(int screenx, int screeny);

private:
    QtTD* myGame;
    QtTDContext* myContext;
    qreal offsetX, offsetY;
};

#endif // QTTDGAMEBOARD_H
