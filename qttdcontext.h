
#ifndef QTTDCONTEXT_H
#define QTTDCONTEXT_H

#include <QObject>
#include <QMutex>
#include <QVector>
#include <QTextStream>
#include <QUrl>
#include <QHash>

#include "qttd.h"
#include "qttdcolorselection.h"

//Forward declarations
class QtTD;
class QtTDTower;
class QtTDWave;
class QtTDHex;

class QtTDContext : public QObject
{
public:
    QtTDContext(QtTD* app);

    void setInfoText(QString s);
    void showAlert(QString alert);

    //maps
    void resetMap();
    bool loadMap(QString maplocation);
    void loadMap(QUrl fetchUrl, QString relativeLoc);
    void loadMap(QTextStream b, QString maplocation);

    //enemies
    void setEnemyCount(int count);
    int getEnemyCount();
    void removeEnemy();
    void removeAllEnemies();

    //interest
    int getInterest();
    void payInterest();
    void setInterest(int start, int increase);

    //credits
    long getCredits();
    void setCredits(long credits);
    void doReceive(int amount);
    bool canPay(int amount);
    bool doPay(int amount);

    //lives
    void resetLives(int n);
    int getLives();
    void removeLife();

    //bonus
    void resetBonus();
    void addBonus();
    void useBonus();
    int getBonus();

    //scores
    long getScore();
    void resetScore();
    void addScore(int s);
    void deductScore(int s);

    //towers
    void addTower(QtTDTower *t);
    void removeTower(QtTDTower *t);
    void sellTower(QtTDTower *t);
    void clearTowers();

    //waves
    void clearWaves();
    void resetWaves();
    int getWave();
    int getWaveCount();
    void nextWave();
    QVector<QtTDWave*> getWaves();
    bool isWaveActive();
    void setWaveActive(bool wActive);

    //images
    QImage loadImage(QString location);
    void clearImages();

    inline qreal getOffsetX() {
        return offsetX;
    }

    inline qreal getOffsetY() {
        return offsetY;
    }

    inline QtTDColorSelection Colors() {
        return colors;\
    }

    inline QString getBackgroundImage() {
        return backgroundImage;
    }

    inline QVector<QVector<QtTDHex* > > getGrid() {
        return grid;
    }

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
    QtTDColorSelection colors;
    QVector<QVector<QtTDHex* > > grid;
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
    //QVector<QtTDPath> paths;
    int wave;
    QVector<QtTDWave *> waves;
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
    QHash<QString, QImage> images;
    //Cache cache;
};

#endif // QTTDCONTEXT_H
