
#include "qttdsprite.h"

QtTDSprite::QtTDSprite() :
        size(QtTDSprite::normal), inactive(true), validTarget(false),
        dead(false), damageColor(Other), damageColorAnti(Other),
        segment(-1), segmentProgression(0), progress(0),
        preferredDelay(0.7), acceleration(1), speed(50),
        speedMax(50), speedMaxBase(50), speedRepairTime(0),
        power(50), powerBase(50), powerRepairTime(0),
        shieldRotationStep(0), shieldColor(QColor(50, 50, 255)),
        shielded(false), selected(false)
{
}

bool QtTDSprite::isValidTarget() {
    return ((!inactive) && validTarget && !dead);
}
