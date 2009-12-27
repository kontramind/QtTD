#ifndef QTTDGEOMETRY_H
#define QTTDGEOMETRY_H

#include <QtGui/QPolygonF>
#include <QtGui/QGraphicsEllipseItem>

// Forward declaration
class QGraphicsPathItem;

class QtTDGeometry
{
    /* top-middle
     * top-right
     * bottom-right
     * bottom-middle
     * bottom-left
     * top-left
     */
public:
    static QPolygonF createPolyCoords(qreal scale, qreal x, qreal y);

    inline static QPolygonF createPolyCoords(qreal scale) {
        return createPolyCoords(scale, 0, 0);
    }

    inline static QGraphicsEllipseItem* createCircle(qreal x, qreal y, qreal r) {
        return new QGraphicsEllipseItem(x - r, y - r, r * 2, r * 2, 0, 0);
    }

    static QGraphicsPathItem* coordsToGeneralPath(QPolygonF points, bool closed);

private:
    Q_DISABLE_COPY(QtTDGeometry)

};

#endif // QTTDGEOMETRY_H
