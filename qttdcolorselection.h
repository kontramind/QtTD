#ifndef QTTDCOLORSELECTION_H
#define QTTDCOLORSELECTION_H

#include <QColor>

class QtTDColorSelection
{
public:
    QtTDColorSelection();

    inline QColor getColorBaseBackGround() {
        return myColorBaseBackGround;
    }

    inline void setColorBaseBackGround(QColor  colorBaseBackGround) {
        myColorBaseBackGround = colorBaseBackGround;
    }

    inline QColor getColorOpenBackGround() {
        return myColorOpenBackGround;
    }

    inline void setColorOpenBackGround(QColor colorOpenBackGround) {
        myColorOpenBackGround = colorOpenBackGround;
    }

    inline QColor getColorBaseHexBorder() {
        return myColorBaseHexBorder;
    }

    inline void setColorBaseHexBorder(QColor colorBaseHexBorder) {
        myColorBaseHexBorder = colorBaseHexBorder;
    }

    inline QColor getColorBaseEmptyHexBorder() {
        return myColorBaseEmptyHexBorder;
    }

    inline void setColorBaseEmptyHexBorder(QColor colorBaseEmptyHexBorder) {
        myColorBaseEmptyHexBorder = colorBaseEmptyHexBorder;
    }

    inline QColor getColorBaseHexBackGround() {
        return myColorBaseHexBackGround;
    }

    inline void setColorBaseHexBackGround(QColor colorBaseHexBackGround) {
        myColorBaseHexBackGround = colorBaseHexBackGround;
    }

    inline QColor getColorHighlightOK() {
        return myColorHighlightOK;
    }

    inline void setColorHighlightOK(QColor colorHighlightOK) {
        myColorHighlightOK = colorHighlightOK;
    }

    inline QColor getColorHighlightNOK() {
        return myColorHighlightNOK;
    }

    inline void setColorHighlightNOK(QColor colorHighlightNOK) {
        myColorHighlightNOK = colorHighlightNOK;
    }

    inline QColor getColorRangeCircle() {
        return myColorRangeCircle;
    }

    inline void setColorRangeCircle(QColor colorRangeCircle) {
        myColorRangeCircle = colorRangeCircle;
    }

    inline QColor getColorHealthLine() {
        return myColorHealthLine;
    }

    inline void setColorHealthLine(QColor colorHealthLine) {
        myColorHealthLine = colorHealthLine;
    }

    inline QColor getColorForeGround() {
        return myColorForeGround;
    }

    inline void setColorForeGround(QColor colorForeGround) {
        myColorForeGround = colorForeGround;
    }

    inline QColor getColorBackGround() {
        return myColorBackGround;
    }

    inline void setColorBackGround(QColor colorBackGround) {
        myColorBackGround = colorBackGround;
    }

private:
    QColor myColorBaseBackGround;
    QColor myColorOpenBackGround;
    QColor myColorBaseHexBorder;
    QColor myColorBaseHexBackGround;
    QColor myColorBaseEmptyHexBorder;
    QColor myColorHighlightOK;
    QColor myColorHighlightNOK;
    QColor myColorRangeCircle;
    QColor myColorHealthLine;
    QColor myColorForeGround;
    QColor myColorBackGround; //= QColor::BLACK;
};

#endif // QTTDCOLORSELECTION_H
