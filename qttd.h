#ifndef QTTD_H
#define QTTD_H

#include <QtGui/QMainWindow>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsView>

//Forward declaration
class QtTDContext;
class QtTDGameBoard;

class QtTD : public QMainWindow
{
    Q_OBJECT

public:
    QtTD(QWidget *parent = 0);
    ~QtTD();

    void paintBoard();

private:
    QtTDGameBoard *gameBoard;
    QGraphicsView *view;

    QtTDContext *context;

    QImage layer0; // Cache image for the background
    QImage layer1; // Cache image for the hexes
    //
    QString backgroundDefault;
    bool clearLayer0;
    bool clearLayer1;
    bool drawBackground;
    //
    int boardWidth, boardHeight;
    //
    //QVector<QtTDTower> towers;
    //BlackBox blackBoxRecord;
    //BlackBox blackBoxPlayback;
//    bool autoLaunch = false;
//    bool startWave = false;
//    bool startWaveDelayed = false;
//    bool waveReady = true;
//    bool placingTower = false;
    //
    //TowerFactory.type placingTowerType;
    //
    qreal placingTowerRange;
    int graceTicks;
    int graceTicksMax;
    int paintTime;
    //
    //Object paintTimeLock = new Object();
    //Object paintLock = new Object();
    bool painting;
    //bool noSleep = false;
    //bool noPaint = false;
    //
//    int tickTime = 50;
//    int tickTimeSkip = 0;
//    int tickTimeFast = 15;
//    int tickTimeNormal = 50;
//    bool paused = false;
//    bool gameStopped = false;
//    QVector<int> highlightedHex;
//    int lastPaddedLeft = -1;
    //
    //static DecimalFormat form = new DecimalFormat("#,###.##");
    //
    //URL scorePostUrl;
    //URL scoreFetchUrl;
    int score_id;
    QString mode;
    //QThread gameLogicThread;
    //bool running = true;


};

#endif // QTTD_H
