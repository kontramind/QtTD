


#include "qttdcontext.h"
#include <QTextStream>

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

bool QtTDContext::loadMap(QString maplocation) {
        resetMap();
        bool retval = false;//= MapIO.readLevel( maplocation);
        //mainApp.mapChanged();
        return retval;
}

void QtTDContext::loadMap(QUrl fetchUrl, QString relativeLoc) {
        resetMap();
        //MapIO.readLevel(this, fetchUrl, relativeLoc);
        //mainApp.mapChanged();
}

void QtTDContext::loadMap(QTextStream b, QString maplocation) {
        resetMap();
        //MapIO.readLevel(this, b, maplocation);
        //mainApp.mapChanged();
}

void QtTDContext::resetMap() {
        removeAllEnemies();
        clearTowers();
        setCredits(creditsStart);
        setInterest(interestStart, interestIncrease);
        resetLives(livesStart);
        resetBonus();
        resetScore();
        resetWaves();
        gameTime = 0;
        //mainApp.resetMap();
}

// void highlightHex(int[] hexC) {
//        this.mainApp.highLightHex(hexC);
//}

//QtTDHex getHex(int col, int row) {
//    return this.grid[col][row];
//}

void QtTDContext::setEnemyCount(int c) {
    enemyCount = c;
}

int QtTDContext::getEnemyCount() {
    return enemyCount;
}

void QtTDContext::removeEnemy() {
    enemyCount--;
    //mainApp.enemyDied(enemyCount);
    if (enemyCount == 0) {
//        payInterest();
//        if (wave >= waves.size()) {
//                blackBoxCurrent.endGame();
//        }
    }
}

void QtTDContext::removeAllEnemies() {
        if (enemyCount > 0) {
                enemyCount = 0;
                //enemies = new EnemySprite[0];
                //mainApp.enemyDied(this.enemyCount);
        }
}

// EnemySprite findClosestCreep(float paintX, float paintY, float maxRange) {
//        EnemySprite esFound = null;
//        float maxR2 = maxRange * maxRange;
//        float closestR2 = Float.MAX_VALUE;
//        float r2, dx, dy;
//        if (this.enemies != null) {
//                for (EnemySprite es : this.enemies) {
//                        if (!es.isDead()) {
//                                dx = es.getPaintX() - paintX;
//                                dy = es.getPaintY() - paintY;
//                                r2 = dx * dx + dy * dy;
//                                if (r2 < closestR2) {
//                                        esFound = es;
//                                        closestR2 = r2;
//                                }
//                        }
//                }
//                if (closestR2 < maxR2) {
//                        return esFound;
//                } else {
//                        return null;
//                }
//        } else {
//                return null;
//        }
//}

// Wave handling methods
void QtTDContext::clearWaves() {
    wave = 0;
    //waves.clear();
}

void QtTDContext::resetWaves() {
    wave = 0;
}

QVector<QtTDWave*> QtTDContext::getWaves() {
    return waves;
}

int QtTDContext::getWave() {
    return wave;
}

int QtTDContext::getWaveCount() {
    return waves.size();
}

void QtTDContext::nextWave() {
        //qDebug("Sending next wave: " + this.wave);
//        QtTDWave *w = waves.get(wave);
//        enemies = w->getEnemies();
//        for (int i = 0; i < enemies.length; i++) {
//                enemies[i].resetScale();
//        }
//        wave++;
//        waveActive = true;
//        setEnemyCount(w.enemyCount());
        //fireWaveStartedEvent();
}

// void addWaveStartListener(WaveStartListener l) {
//        this.waveListeners.add(l);
//}
//
// void removeWaveStartListener(WaveStartListener l) {
//        this.waveListeners.remove(l);
//}

//void QtTDContext::fireWaveStartedEvent() {
//    for (int i = 0; i < this.waveListeners.size(); i++) {
//        waveListeners.get(i).waveStarted();
//    }
//}


void QtTDContext::setInfoText(QString s) {
        //mainApp.setInfoText(s);
}

void QtTDContext::addScore(int s) {
    if (s < 0) {
            //qDebug("Context::addScore: Adding negative score? " + s);
    }
    score += s;
}

void QtTDContext::deductScore(int s) {
    if (s < 0) {
            //qDebug("Context::deductScore: Deducting negative score? " + s);
    }
    score -= s;
}

long QtTDContext::getScore() {
    return score;
}

void QtTDContext::resetScore() {
     score = 0;
}

long QtTDContext::getCredits() {
    return credits;
}

void QtTDContext::setCredits(long credits) {
    credits = credits;
    //fireMoneyChangedEvent();
}

void QtTDContext::setInterest(int start, int increase) {
        interestStart = start;
        interestIncrease = increase;
        //fireInterestChangedEvent();
}

bool QtTDContext::canPay(int amount) {
        //System.out.println("Context::canPay: checking "+amount);
        if (amount > 0) {
                return (credits >= amount);
        } else {
                return (bonus + bonusWait > 0);
        }
}

bool QtTDContext::doPay(int amount) {
        //System.out.println("Context::doPay: checking "+amount);
        if (amount > 0) {
                if (canPay(amount)) {
                        credits -= amount;
                        //System.out.println("Context::doPay: credits: "+this.credits);
                        //fireMoneyChangedEvent();
                        return true;
                } else {
                        return false;
                }
        } else {
                if (canPay(amount)) {
                        if (bonusWait > 0) {
                                bonusWait--;
                        } else {
                                bonus--;
                        }
                        //fireMoneyChangedEvent();
                        return true;
                } else {
                        return false;
                }
        }
}

void QtTDContext::doReceive(int amount) {
        if (amount > 0) {
                credits += amount;
                //fireMoneyChangedEvent();
        } else {
                bonusWait++;
                //fireMoneyChangedEvent();
        }

}

void QtTDContext::addTower(QtTDTower *t) {
    //towers.add(t);
    //fireTowerAddedEvent(t);
}

void QtTDContext::removeTower(QtTDTower *t) {
        //towers.remove(t);
        //fireTowerRemovedEvent(t);
}

void QtTDContext::sellTower(QtTDTower *t) {
        //int[] hexC = t.getHex().getLocation();
        //this.blackBoxCurrent.sellTower(hexC[0], hexC[1]);

}

void QtTDContext::clearTowers() {
//        mainApp.unSelectTower();
//        Tower t;
//        for (int i = towers.size() - 1; i >= 0; i--) {
//                t = towers.get(i);
//                Hex hex = t.getHex();
//                hex.unSetTower();
//                t.doCleanup();
//                towers.remove(t);
//                fireTowerRemovedEvent(t);
//        }
}

void nextMode(QtTDTower *t, int m) {
//        int[] hexC = t.getHex().getLocation();
//        blackBoxCurrent.setMode(hexC[0], hexC[1], m, t.getMode(m) + 1);
}

void setMode(QtTDTower *t, int m, int v) {
        //int[] hexC = t.getHex().getLocation();
        //blackBoxCurrent.setMode(hexC[0], hexC[1], m, v);
}

//void addTowerListener(TowerListener l) {
//        towerListeners.add(l);
//}
//
//void removeTowerListener(TowerListener l) {
//        towerListeners.remove(l);
//}

//private void fireTowerAddedEvent(Tower t) {
//        for (int i = 0; i < towerListeners.size(); i++) {
//                towerListeners.get(i).towerBuild(t);
//        }
//}
//
//private void fireTowerRemovedEvent(Tower t) {
//        for (int i = 0; i < towerListeners.size(); i++) {
//                towerListeners.get(i).towerRemoved(t);
//        }
//}

// void addContextListener(ContextListener l) {
//        contextListeners.add(l);
//}
//
// void removeContextListener(ContextListener l) {
//        contextListeners.remove(l);
//}

// signal
//void fireMoneyChangedEvent() {
//    for (int i = 0; i < contextListeners.size(); i++) {
//        contextListeners.get(i).moneyChanged();
//    }
//}

//void fireLivesChangedEvent() {
//    for (int i = 0; i < contextListeners.size(); i++) {
//        contextListeners.get(i).livesChanged();
//    }
//}

//void fireInterestChangedEvent() {
//    for (int i = 0; i < contextListeners.size(); i++) {
//        contextListeners.get(i).interestChanged();
//    }
//}

//QVector<Path> QtTDContext::getPaths() {
//    return paths;
//}
//
// Path getPath(int p) {
//        if (p < 0) {
//                p = 0;
//        }
//        if (p > paths.size() - 1) {
//                p = paths.size() - 1;
//        }
//        return paths.get(p);
//}

int QtTDContext::getLives() {
    return lives;
}

void QtTDContext::removeLife() {
    lives--;
//    if (lives <= 0 && blackBoxCurrent != null) {
//        blackBoxCurrent.endGame();
//    }
    //fireLivesChangedEvent();
}

void QtTDContext::resetLives(int n) {
    lives = n;
    //fireLivesChangedEvent();
}

void QtTDContext::addBonus() {
    bonus++;
    //fireInterestChangedEvent();
}

void QtTDContext::useBonus() {
    bonus--;
    //fireInterestChangedEvent();
}

int QtTDContext::getInterest() {
    return interestStart + bonus * interestIncrease;
}

int QtTDContext::getBonus() {
    return bonus + bonusWait;
}

void QtTDContext::resetBonus() {
     bonus = 0;
     bonusWait = 0;
     //fireInterestChangedEvent();
}

void QtTDContext::showAlert(QString alert) {
        //mainApp.showAlert(alert);
}

//QtTDCache QtTDContext::getCache() {
//    return cache;
//}

// StyleSheet loadStyleSheet(String name) {
//        if (styleSheets.containsKey(name)) {
//                return styleSheets.get(name);
//        } else {
//                StyleSheet s = new StyleSheet();
//                URL u;
//                try {
//                        u = new URL(contextUrl, name);
//                        s.importStyleSheet(u);
//                } catch (MalformedURLException ex) {
//                        ex.printStackTrace();
//                }
//                styleSheets.put(name, s);
//                return s;
//        }
//}

void QtTDContext::clearImages() {
    images.clear();
}

 QImage QtTDContext::loadImage(QString location) {
    if (images.contains(location)) {
       return images.value(location);
    } else {
        QImage image(location);
        if (image.isNull()) {
            image = QImage(1, 1,QImage::Format_RGB32);
        }
        images.insert(location, image);
        return image;
    }
}
//
// URI loadSvg(String name, String location) {
//        if (svgUniverse == null) {
//                svgUniverse = SVGCache.getSVGUniverse();
//        }
//        if (!svgImages.containsKey(name)) {
//                URL url;
//                try {
//                        url = new URL(contextUrl, location);
//                } catch (MalformedURLException ex) {
//                        ex.printStackTrace();
//                        return null;
//                }
//                URI uri = svgUniverse.loadSVG(url);
//                svgImages.put(name, uri);
//        }
//        return svgImages.get(name);
//}

// void renderSvgImage(String name, Graphics2D g, int w, int h) {
//        AffineTransform oldXform = g.getTransform();
//        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
//        URI image = svgImages.get(name);
//        SVGDiagram diagram = svgUniverse.getDiagram(image);
//        Rectangle2D.Double rect = new Rectangle2D.Double();
//        diagram.getViewRect(rect);
//
//        AffineTransform scaleXform = new AffineTransform();
//        //scaleXform.setToTranslation(50,50);
//        scaleXform.setToScale(w / rect.width, h / rect.height);
//        g.transform(scaleXform);
//
//        //diagram.setDeviceViewport(new Rectangle(0, 0, w, h));
//        diagram.setIgnoringClipHeuristic(true);
//        try {
//                diagram.render(g);
//        } catch (SVGException ex) {
//                ex.printStackTrace();
//        }
//        g.setTransform(oldXform);
//}

bool QtTDContext::isWaveActive() {
        return waveActive;
}

void QtTDContext::setWaveActive(bool wActive) {
        waveActive = wActive;
}
