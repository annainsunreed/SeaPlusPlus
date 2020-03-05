#include "gameview.h"
#include <QLineF>
#include <QPointF>
#include <QCursor>
#include <QMediaPlayer>
//#include "Wall.h"

#include <QImage>
#include <stdlib.h>
#include "ShootEnemy.h"
#include "Score.h"
#include "ColliderRight.h"
#include "ColliderLeft.h"
#include "ColliderTop.h"
#include "ColliderBottom.h"

GameView::GameView(QWidget *parent): QGraphicsView(parent){
    // set the frames pers second
    //fps = 30;

    // play music
    // music = new QMediaPlayer(this);
    //music->setMedia(QUrl("qrc:/sounds/bg_music.mp3"));
    //music->play();
    //connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));

    // add scene
    scene = new QGraphicsScene(this);

    // add player
    player = new Player(QPixmap(":/images/player.png"));
    player->setFlag(QGraphicsItem::ItemIsFocusable,true);
    player->setFocus();
    player->setPos(300,200);

    // set scene background
    scene->setSceneRect(0,0,width(),height());
    QImage * img = new QImage(":/images/grass.png");
    QBrush bg_brush(*img);
    scene->setBackgroundBrush(bg_brush);

    // add player to scene
    scene->addItem(player);

    // set the scene and the part of the scene to view (the whole thing in this case)
    setScene(scene);
    setSceneRect(scene->sceneRect());

    // set the round to 0 initially
    round = 0;

    // set the cursor
    setCursor(QCursor(Qt::CrossCursor));
    num_Enemies=0;
}
