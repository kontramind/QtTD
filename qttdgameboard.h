#ifndef QTTDGAMEBOARD_H
#define QTTDGAMEBOARD_H

#include <QGraphicsScene>
#include "qttd.h"
#include "qttdcontext.h"

class QtTDGameBoard : public QGraphicsScene
{
public:
    QtTDGameBoard();

private:
    QtTD game;
    QtTDContext context;
    qreal offsetX, offsetY;
};

#endif // QTTDGAMEBOARD_H
