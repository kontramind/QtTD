#include "qttdgameboard.h"

QtTDGameBoard::QtTDGameBoard(QtTD* game, QtTDContext* context)
    : myGame(game), myContext(context)
{
}

void QtTDGameBoard::paint()
{
   //game.paintBoard((Graphics2D) g);
}

QVector<int> QtTDGameBoard::hexCoordsFromScreenCoords(int screenx, int screeny) {
//    int row, column, hexX, hexY;
//    float x, y, dx, dy, h, r, width, height;
    QVector<int> hexC;
//    width = this.context.hexPaintWidth * 2;
//    height = this.context.paintScale * 1.5f;
//    h = this.context.paintScale / 2;
//    r = this.context.hexPaintWidth;
//    x = screenx - this.context.offsetX;
//    y = screeny - this.context.offsetY;
//    column = Math.round( -0.5f + x / width );
//    row = Math.round( -0.5f + y / height );
//    dx = x - column * width;
//    dy = y - row * height;
//
//    hexX = column;
//    hexY = row;
//    if ((row & 1) == 0) {
//        if (dy < (h - (h/r) * dx)) {
//            hexX--;
//            hexY--;
//        }
//        if (dy < (-h + (h/r) * dx)) {
//            hexY--;
//        }
//    } else {
//        if (dx > r) {
//            if (dy < h*2 - h/r*dx ) {
//                hexY--;
//            }
//        } else {
//            if (dy < h/r*dx) {
//                hexY--;
//            } else {
//                hexX--;
//            }
//        }
//    }
//    hexC[0] = hexX;
//    hexC[1] = hexY;
    return hexC;
}
