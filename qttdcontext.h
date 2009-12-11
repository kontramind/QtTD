
#ifndef QTTDCONTEXT_H
#define QTTDCONTEXT_H

#include <QObject>
#include <QMutex>
#include <QUrl>

#include "qttd.h"

// Forward declaration
class QtTD;

class QtTDContext : public QObject
{
public:
    QtTDContext(QtTD* app);

    void payInterest();

private:
    QtTD *qttd;
    QString levelTitle;
    QString levelInfo;
    QString backgroundImage;
    QMutex PaintingLock;
    QMutex gameTimeLock;
    int gameTime;
    QString VERSION;
    //BlackBox blackBoxCurrent;
    QUrl contextUrl;
    QUrl mapContextUrl;
    //colorSelection colors;
    //Hex[][] grid;
    int gridWidth;
    int gridHeight;
    qreal offsetX;
    qreal offsetY;
    qreal minX,  minY,  maxX,  maxY;
    qreal paintScale;
    qreal strokeScale;
    qreal hexPaintWidth;
    qreal hexFloatWidth;
    //HexTD.gameState gameState = HexTD.gameState.selecing;
    QString mapLocation;
    QString mapMD5;
    //EnemySprite[] enemies;
    //QVector<Tower> towers;
    int enemyCount;
    //Vector<Path> paths;
    int wave;
    //Vector<Wave> waves;
    bool waveActive;
    int lives;
    int livesStart;
    long credits;
    long creditsStart;
    int interestStart;
    int interestIncrease;
    int bonus;
    int bonusWait;
    long score;
    //Vector<ContextListener> contextListeners;
    //Vector<TowerListener> towerListeners;
    //Vector<WaveStartListener> waveListeners;
    //SVGUniverse svgUniverse;
    //Hashtable<String, URI> svgImages;
    //Hashtable<String, StyleSheet> styleSheets;
    //Hashtable<String, BufferedImage> images;
    //Cache cache;
};

#endif // QTTDCONTEXT_H
