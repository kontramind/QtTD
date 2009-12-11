
#ifndef QTTDCONTEXT_H
#define QTTDCONTEXT_H

#include <QObject>

class QtTDContext : public QObject
{
public:
    QtTDContext();

    void payInterest();

private:
    QString levelTitle;
    QString levelInfo = "";
    QString backgroundImage = "images/sunset.jpg";
    QMutex PaintingLock;
    QMutex gameTimeLock;
    int gameTime;
    //HexTD mainApp;
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
    int enemyCount = 0;
    //Vector<Path> paths;
    int wave = 0;
    //Vector<Wave> waves;
    bool waveActive = false;
    int lives = 20;
    int livesStart = 20;
    long credits = 0;
    long creditsStart = 0;
    int interestStart = 3;
    int interestIncrease = 3;
    int bonus = 0;
    int bonusWait = 0;
    long score = 0;
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
