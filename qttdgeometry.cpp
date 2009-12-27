#include "qttdgeometry.h"

#include <QtCore/qmath.h>
#include <QtGui/QPainterPath>

QPolygonF QtTDGeometry::createPolyCoords(qreal scale, qreal x, qreal y)
{
    qreal width = qSin(qreal(M_PI)/3) * scale;
    QPolygonF points(6);
    points << QPointF(x + 0, y - scale);
    points << QPointF(x + width, y - scale / 2);
    points << QPointF(x + width, y + scale / 2);
    points << QPointF(x + 0, y + scale);
    points << QPointF(x - width, y + scale / 2);
    points << QPointF(x - width, y - scale / 2);
    return points;
}

QGraphicsPathItem* QtTDGeometry::coordsToGeneralPath(QPolygonF points, bool closed) {
    QPainterPath poly;
    poly.moveTo(points.at(0));
    for (int index = 1; index < points.size(); index++) {
        poly.lineTo(points.at(index));
    };
    if (closed) {
        poly.closeSubpath();
    }

    return new QGraphicsPathItem(poly, 0 , 0);
}
