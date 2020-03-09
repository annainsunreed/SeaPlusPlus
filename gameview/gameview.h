#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
//#include <QMouseEvent>
//#include <QResizeEvent>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "player.h"
#include "rocks.h"

class GameView;
extern GameView * game;

class GameView: public QGraphicsView{
    Q_OBJECT
public:
    GameView(QWidget * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QGraphicsScene * scene;
    Player * player;
    QMediaPlayer * music;
    void placeRocks();
    void placeRock(int x, int y, int width, int length, int rotation);

};

#endif // GAMEVIEW_H
