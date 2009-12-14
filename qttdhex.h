#ifndef QTTDHEX_H
#define QTTDHEX_H

#include <QChar>
#include <QVector>
#include <QColor>
#include <QGraphicsEllipseItem>

// Forward declaration
class QtTDContext;
class QtTDTower;

class QtTDHex
{
public:
    static int BASE;
    static int EMPTY;
    static int PATH;

    QtTDHex(int x, int y, QtTDContext *_context, bool buildable);

    enum highlightType {
        none,
        selectTower,
        placeTower,
        editHex
    };

    int getType();
    QChar getShortName();
    void resetScale();
    //void paintBase(Graphics2D g2_0, Graphics2D g2_1);
    //public void paintEffects(Graphics2D g2);

    void setLocation(int x, int y);
    QVector<int> getLocation();
    QVector<qreal> getQRealLocation();
    QVector<qreal> getPaintLocation();
    void setHighlight(highlightType hightlight);
    void setHighlightRange(qreal range);
    bool isFree();

    bool hasTower();
    void setTower(QtTDTower *tower);
    void unSetTower();
    QtTDTower* getTower();

protected:

    char shortName;
    int type;
    int x;
    int y;

    qreal paintScale;
    qreal xQReal,yQReal;
    qreal xPaint,yPaint;
    qreal wqreal,hqreal;
    qreal wPaint,hPaint;

    //private qreal[][] points;

    //GeneralPath polyHex;
    //Stroke stroke1;
    //Stroke stroke2;
    //Shape[] bordersE;
    QColor borderColor;
    QColor borderEmptyColor;
    QColor fillColor;
    QColor highlightOK;
    QColor highlightNOK;
    QColor rangeColor;

    QtTDContext *context;
    highlightType highlight;// = highlightType.none;
    qreal highlightRange; //=0;
    QGraphicsEllipseItem rangeCircle;

    bool free; // = true;
    QtTDTower *tower; //= 0;
};

class QtTDHexEmpty : public QtTDHex
{
public:
    QtTDHexEmpty(int _x, int _y, QtTDContext* _context);

    //inline void paintBase(Graphics2D g2_0, Graphics2D g2_1) { }
};

class QtTDHexPath : public QtTDHex
{
public:
    QtTDHexPath(int _x, int _y, QtTDContext* _context);

//    void paintBase(Graphics2D g2_0, Graphics2D g2_1) {
//        if (g2_0 != null) {
//            g2_0.setColor(this.fillColor);
//            g2_0.draw(this.polyHex);
//            g2_0.fill(this.polyHex);
//        }
//    }
//
//    public void paintEffects(Graphics2D g2) {
//        switch (this.highlight) {
//            case placeTower:
//                g2.setColor(this.highlightNOK);
//                g2.fill(this.polyHex);
//                this.paintRangeCircle(g2);
//                break;
//            case editHex:
//                g2.setColor(this.highlightOK);
//                g2.fill(this.polyHex);
//                break;
//            default:
//        }
//    }

protected:
    QColor fillColor;
};


#endif // QTTDHEX_H
