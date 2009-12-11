
#ifndef QTTDSPRITE_H
#define QTTDSPRITE_H

#include <QGraphicsItem>
#include "qttdpath.h"
#include "qttdcontext.h"

class QtTDSprite : public QGraphicsItem
{
public:

    enum Color {
            Red,
            Green,
            Blue,
            Yellow,
            Other
    };

    enum DamageType {
            Normal,
            Speed,
            Power,
            Time
    };

    struct Size {
            QChar letter;
            qreal scaleMod;

            Size(QChar l, qreal scaleMod) {
                    letter = l;
                    scaleMod = scaleMod;
            }
    };

    static const Size small;
    static const Size normal;
    static const Size large;

    QtTDSprite();

    qreal getPreferredDelay();

    void doTick(int gameTime);

    void resetScale();

    //public void paint(Graphics2D g2, int gameTime);

    qreal getX();

    qreal getY();

    qreal getPaintX();

    qreal getPaintY();

    bool isValidTarget();

    bool isDead();

    long getHealth();

    qreal getProgress();

    void remove();

    void doDamage(int damage, Color c);

    void doDamage(qreal damage, DamageType t, Color c);

    qreal getSpeed();

    bool isShielded();

    //void setSize(Size s);

    void setSelected(bool selected);

    QString getInfoString();

    QString getStatusString();

    //void addStatusListener(EnemySpriteChangedListener l);

    //void removeStatusListener(EnemySpriteChangedListener l);

    //public EnemySprite create(Context context, int path, float delay, long health, int price, Size s);

protected:

    Size size;
    QString name;
    //
    bool inactive;
    bool validTarget;
    bool dead;
    int price;
    QColor damageColor;
    QColor damageColorAnti;
    qreal delay;
    qreal xFloat,  yFloat;
    qreal xPaint,  yPaint;
    qreal paintScale;
    QTransform atTranslate;
    QtTDPath path;
    int segment;
    int segmentProgression;
    QVector<qreal> segmentStartPoint;
    QVector<qreal> segmentEndPoint;
    qreal progress;
    qreal preferredDelay;
    qreal acceleration;
    qreal speed;          // * 1/1000 segments per tick
    qreal speedMax;      // * 1/1000 segments per tick
    qreal speedMaxBase;  // * 1/1000 segments per tick
    qreal speedRepairTime;
    qreal power;      // power > speedMax => speed = speedMax
    qreal powerBase;  // power > speedMax => speed = speedMax
    qreal powerRepairTime;
    long health;
    long healthMax;
    QAbstractGraphicsShapeItem* healthLineShape;
    QPainterPathStroker healthLineStroke;
    QColor healthLineColor;
    qreal shieldRotationStep;
    qreal shieldW;
    qreal shieldH;
    int shieldO;
    QColor shieldColor;
    QPainterPathStroker shieldStroke;
    bool shielded;
    bool selected;
    //
    QtTDContext *context;
    //Vector<EnemySpriteChangedListener> listeners; // signal slot
     //
    //static DecimalFormat form = new DecimalFormat("#,###.#");
};

const QtTDSprite::Size QtTDSprite::small(QChar('S'), qreal(0.5));
const QtTDSprite::Size QtTDSprite::normal(QChar('N'), qreal(1.0));
const QtTDSprite::Size QtTDSprite::large(QChar('L'), qreal(1.5));

#endif // QTTDSPRITE_H
