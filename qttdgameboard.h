#ifndef QTTDGAMEBOARD_H
#define QTTDGAMEBOARD_H

#include <QGraphicsScene>

//Forward declarations
class QtTD;
class QtTDContext;

class QtTDGameBoard : public QGraphicsScene
{
public:
    QtTDGameBoard();

private:
    QtTD* game;
    QtTDContext* context;
    qreal offsetX, offsetY;
};

#endif // QTTDGAMEBOARD_H
