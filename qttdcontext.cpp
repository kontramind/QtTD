


#include "qttdcontext.h"

QtTDContext::QtTDContext(QtTD* app)
    : qttd(app),
      backgroundImage("images/sunset.jpg"),
      enemyCount(0), wave(0), waveActive(false),
      lives(20), livesStart(20), credits(0),
      creditsStart(0), interestStart(3), interestIncrease(3),
      bonus(0), bonusWait(0), score(0)
{
}

void QtTDContext::payInterest() {
    long interest = static_cast<long> (credits * (interestStart + bonus * interestIncrease) / 100l);
    bonus += bonusWait;
    bonusWait = 0;
    credits += interest;
    score += interest;
    // emit fireMoneyChangedEvent();
}
