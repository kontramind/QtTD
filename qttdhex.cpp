#include "qttdhex.h"
#include "qttdcontext.h"
#include "qttdcolorselection.h"

int QtTDHex::BASE  = 1;
int QtTDHex::EMPTY = 2;
int QtTDHex::PATH  = 3;

QtTDHex::QtTDHex(int _x, int _y, QtTDContext *_context, bool _buildable) {
    QColor tempColor;
    // even or odd
    x = _x;
    y = _y;
    context = context;
    borderColor = context->Colors().getColorBaseHexBorder();

    tempColor  = context->Colors().getColorBaseHexBackGround();
    fillColor = QColor(tempColor.red(), tempColor.green(), tempColor.blue(), 125);
    borderEmptyColor = context->Colors().getColorBaseEmptyHexBorder();
    tempColor = context->Colors().getColorHighlightOK();
    highlightOK = QColor(tempColor.red(), tempColor.green(), tempColor.blue(), 125);
    tempColor = context->Colors().getColorHighlightNOK();
    highlightNOK = QColor(tempColor.red(), tempColor.green(), tempColor.blue(), 125);
    rangeColor = context->Colors().getColorRangeCircle();
    type = QtTDHex::BASE;
    shortName = 'b';
    free = _buildable;
}

void QtTDHex::setLocation(int _x, int _y) {
    x = _x;
    y = _y;
}

QVector<int> QtTDHex::getLocation() {
    QVector<int> retVal(x, y);
    return retVal;
}

QVector<qreal> QtTDHex::getQRealLocation() {
    QVector<qreal> returnVal(xQReal, yQReal);
    return returnVal;
}

QVector<qreal> QtTDHex::getPaintLocation() {
    QVector<qreal> returnVal(xPaint, yPaint);
    return returnVal;
}

bool QtTDHex::hasTower() {
    return (tower != 0);
}

void QtTDHex::unSetTower() {
    if (tower != 0) {
        tower = 0;
        free = true;
    }
}

void QtTDHex::setTower(QtTDTower *tower) {
    if (free) {
        tower = tower;
        free = false;
    }
}

QtTDTower* QtTDHex::getTower() {
    return tower;
}


void QtTDHex::setHighlight(highlightType hglg) {
    highlight = hglg;
}

void QtTDHex::setHighlightRange(qreal range) {
    highlightRange = range;
    qreal paintRange = highlightRange * paintScale;
    qreal xPaint = context->getOffsetX() + xQReal * paintScale;
    qreal yPaint = context->getOffsetY() + yQReal * paintScale;
//    rangeCircle(xPaint-paintRange, yPaint-paintRange,
//                paintRange*2, paintRange*2,
//                static_cast<QGraphicsItem * >(0), static_cast<QGraphicsScene * >(0));

    QGraphicsEllipseItem *ptr = new QGraphicsEllipseItem(xPaint-paintRange, yPaint-paintRange,
                     paintRange*2, paintRange*2,
                     static_cast<QGraphicsItem * >(0), static_cast<QGraphicsScene * >(0));
}

//public void resetScale() {
//    this.paintScale = this.context.paintScale;
//    float paintX, paintY;
//
//    int shift = this.y&1;
//    this.wFloat = (float)Math.sin(Math.PI/3);
//    this.xFloat = this.wFloat + this.x*this.wFloat*2 + shift*this.wFloat;
//    this.yFloat = 1.5f*this.y + 1;
//
//    this.wPaint = this.wFloat * this.paintScale;
//    this.xPaint = this.context.offsetX + this.xFloat * this.paintScale;
//    this.yPaint = this.context.offsetY + this.yFloat * this.paintScale;
//
//    this.points = Geometry.createPolyCoords(this.paintScale, xPaint, yPaint);
//    this.polyHex = Geometry.coordsToGeneralPath(this.points, true);
//
//    Vector<Shape> borders = new Vector<Shape>();
//    Hex[][] grid = this.context.grid;
//    if ( this.x < (this.context.gridWidth-(this.y&1)-1) && grid[this.x+1][this.y].getType() == Hex.PATH) {
//        // Right is empty
//        Line2D tempLine = new Line2D.Float(xPaint+this.wPaint, yPaint-paintScale/2, xPaint+this.wPaint, yPaint+paintScale/2);
//        borders.add(tempLine);
//    }
//    if ( this.y > 0 && this.x+(this.y&1) <= (this.context.gridWidth-((this.y-1)&1)-1) && (grid[this.x+(this.y&1)][this.y-1].getType() == Hex.PATH) ) {
//        // Right-Up is empty
//        Line2D tempLine = new Line2D.Float(xPaint+0, yPaint-paintScale, xPaint+this.wPaint, yPaint-paintScale/2);
//        borders.add(tempLine);
//    }
//
//    if ( this.y < this.context.gridHeight-1 && this.x+(this.y&1) <= (this.context.gridWidth-((this.y+1)&1)-1) && (grid[this.x+(this.y&1)][this.y+1].getType() == Hex.PATH) ) {
//        // Right-Down is empty
//        Line2D tempLine = new Line2D.Float(xPaint+0, yPaint+paintScale, xPaint+this.wPaint, yPaint+paintScale/2);
//        borders.add(tempLine);
//    }
//
//
//    if ( (this.x > 0) && (grid[this.x-1][this.y].getType() == Hex.PATH) ) {
//        // Left is empty
//        Line2D tempLine = new Line2D.Float(xPaint-this.wPaint, yPaint-paintScale/2, xPaint-this.wPaint, yPaint+paintScale/2);
//        borders.add(tempLine);
//    }
//
//    if ( this.y > 0 && this.x-((this.y+1)&1) >= 0 && (grid[this.x-((this.y+1)&1)][this.y-1].getType() == Hex.PATH) ) {
//        // Left-Up is empty
//        Line2D tempLine = new Line2D.Float(xPaint+0, yPaint-paintScale, xPaint-this.wPaint, yPaint-paintScale/2);
//        borders.add(tempLine);
//    }
//    if ( this.y < this.context.gridHeight-1 && this.x-((this.y+1)&1) >= 0 && (grid[this.x-((this.y+1)&1)][this.y+1].getType() == Hex.PATH) ) {
//        // Left-Down is empty
//        Line2D tempLine = new Line2D.Float(xPaint+0, yPaint+paintScale, xPaint-this.wPaint, yPaint+paintScale/2);
//        borders.add(tempLine);
//    }
//
//    this.bordersE = new Shape[borders.size()];
//    this.bordersE = borders.toArray(this.bordersE);
//
//    this.stroke1 = new BasicStroke(1.0f*this.context.strokeScale, BasicStroke.CAP_ROUND, BasicStroke.JOIN_BEVEL);
//    this.stroke2 = new BasicStroke(3.0f*this.context.strokeScale, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
//
//    float paintRange = this.highlightRange * this.paintScale;
//    this.rangeCircle = new Ellipse2D.Float(xPaint-paintRange, yPaint-paintRange, paintRange*2, paintRange*2);
//}

//public void paintRangeCircle(Graphics2D g2) {
//    g2.setColor(this.rangeColor);
//    g2.draw(this.rangeCircle);
//}

//public void paintBase(Graphics2D g2_0, Graphics2D g2_1) {
//    if (g2_1 != null) {
//        Stroke defaultStroke = g2_1.getStroke();
//
//        g2_1.setStroke(this.stroke1);
//        g2_1.setColor(this.fillColor);
//        g2_1.fill(this.polyHex);
//        g2_1.setColor(this.borderColor);
//        g2_1.draw(this.polyHex);
//
//        g2_1.setStroke(this.stroke2);
//        g2_1.setColor(this.borderEmptyColor);
//        for (int i=0; i<this.bordersE.length; i++) {
//            g2_1.draw(this.bordersE[i]);
//        }
//
//        g2_1.setStroke(defaultStroke);
//    }
//}

//public void paintEffects(Graphics2D g2) {
//    switch (this.highlight) {
//        case placeTower:
//            if (this.free) {
//                g2.setColor(this.highlightOK);
//                this.paintRangeCircle(g2);
//            } else {
//                g2.setColor(this.highlightNOK);
//                this.paintRangeCircle(g2);
//            }
//            g2.fill(this.polyHex);
//            break;
//        case editHex:
//            g2.setColor(this.highlightOK);
//            g2.fill(this.polyHex);
//            break;
//        case selectTower:
//            g2.setColor(this.highlightOK);
//            g2.fill(this.polyHex);
//            break;
//    }
//}

QChar QtTDHex::getShortName() {
    return shortName;
}

int QtTDHex::getType() {
    return type;
}

bool QtTDHex::isFree() {
    return free;
}

// ************************************************************************************ //
QtTDHexEmpty::QtTDHexEmpty(int _x, int _y, QtTDContext* _context)
    : QtTDHex(_x, _y, _context, false)
{
    borderColor;// = context.colors.getColorBaseEmptyHexBorder();
    fillColor;// = context.colors.getColorOpenBackGround();
    type = QtTDHex::EMPTY;
    shortName = 'n';
}

//void QtTDHexEmpty::paintEffects(Graphics2D g2) {
//    switch (this.highlight) {
//        case placeTower:
//            g2.setColor(this.highlightNOK);
//            g2.fill(this.polyHex);
//            this.paintRangeCircle(g2);
//            break;
//        case editHex:
//            g2.setColor(this.highlightOK);
//            g2.fill(this.polyHex);
//            break;
//        default:
//    }
//}

// ************************************************************************************ //
QtTDHexPath::QtTDHexPath(int _x, int _y, QtTDContext* _context)
    : QtTDHex(_x, _y, _context, false)
{

    borderColor;// = context.colors.getColorBaseEmptyHexBorder();
    fillColor; //= this.context.colors.getColorOpenBackGround();
    type = QtTDHex::PATH;
    shortName = 'p';
}
