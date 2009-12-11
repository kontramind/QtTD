


#include "qttdcontext.h"

QtTDContext::QtTDContext()
{
}

void payInterest() {
    long interest = static_cast<long> (credits * (interestStart + bonus * interestIncrease) / 100l);
    bonus += this.bonusWait;
    bonusWait = 0;
    credits += interest;
    score += interest;
    fireMoneyChangedEvent();
}
