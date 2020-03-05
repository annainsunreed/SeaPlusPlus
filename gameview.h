#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QResizeEvent>
#include <QKeyEvent>
//#include "Player.h"
//#include "Enemy.h"
//#include "Score.h"
#include <QMediaPlayer>

class GameView;
extern GameView * game;

class GameView: public QGraphicsView{
    Q_OBJECT
public:
    // member functions
    GameView(QWidget * parent=0);

    void keyPressEvent(QKeyEvent * event);

    void addEnemy(int x, int y); //TODO change to addEnemy(Enemy * Enemy, int x, int y)

    void addEnemyAtrandomTop();

    void addEnemyAtrandomBottom();

    void addEnemyAtrandomRight();

    void addEnemyAtrandomLeft();

    int getRound();

    void nextRound();

    int getNumEnemys();

    void setNumEnemys(int i);

    void placeWalls();

    void placeWall(int x, int y, int width, int length, int rotation);

    // attributes (public because these need to be accessed by pretty much every other class)
    QGraphicsScene * scene;
    //Player * player;
    //Score * score;
    QMediaPlayer * music;
    int round;
    int num_Enemies;
    int fps;

public slots:
    void replayMusic(QMediaPlayer::State s);


};
#endif // GAMEVIEW_H
