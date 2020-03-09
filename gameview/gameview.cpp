#include <QLineF>
#include <QPointF>
#include <QCursor>
#include <QMediaPlayer>
#include <QImage>
#include <stdlib.h>
#include "player.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "rocks.h"
#include "gameview.h"
#include "colliderright.h"
#include "colliderleft.h"
#include "collidertop.h"
#include "colliderbottom.h"

GameView::GameView(QWidget *parent): QGraphicsView(parent){
    //music = new QMediaPlayer(this);
    //music->setMedia(QUrl("qrc:/sound/backgroundsound.mp3"));
    //music->play();

    player = new Player(QPixmap(":/pictures/ship.png"));

    player->setFlag(QGraphicsItem::ItemIsFocusable,true);
    player->setFocus();
    player->setPos(50,50);

    scene = new QGraphicsScene(this);
    scene->addItem(player);
    placeRocks();
    scene->setSceneRect(0,0,width(),height());

    QImage * img = new QImage(":/pictures/sea.png");
    QBrush bg_brush(*img);
    scene->setBackgroundBrush(bg_brush);
    setScene(scene);
    setSceneRect(scene->sceneRect());

    setWindowTitle("SeaPlusPlus Wars");

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GameView::keyPressEvent(QKeyEvent *event){
    // if esc is pressed, close the game
    if (event->key() == Qt::Key_Escape)
    close();

    // other wise, pass keyboard event to scene which passes it to focused item (which is the player)
    QGraphicsView::keyPressEvent(event);
}

void GameView::placeRocks(){
    // randomly places a bunch of Rocks on the scene
    int MIN_NUM_RockS = 8;
    int MAX_NUM_RockS = 12;

    int num_Rocks = MIN_NUM_RockS + ( rand() % ( MAX_NUM_RockS - MIN_NUM_RockS + 1 ) );;
    for (int i = 0; i < num_Rocks; ++i){
        int rand_x = rand() % width();
        int rand_y = rand() % height();
        int rand_mult = rand() % 5 + 1; //1-5 times a default size

        int w_or_h = rand() % 2; // 0 or 1
        if (w_or_h == 0){
            placeRock(rand_x,rand_y,64 * rand_mult,64,0);
        }
        else {
            placeRock(rand_x,rand_y,64,64 * rand_mult,0);
        }

    }
}
void GameView::placeRock(int x, int y, int width, int length, int rotation){
    Rocks * rock = new Rocks();
    rock->setPos(x,y);

    rock->setRect(0,0,width,length);
    rock->setRotation(rotation);

    // add right collider
    ColliderLeft * left = new ColliderLeft(rock);
    left->setRect(0,0,1,rock->rect().height());

    // add right collider
    ColliderRight * right = new ColliderRight(rock);
    right->setRect(0+rock->rect().width()-1,0,1,rock->rect().height());

    // add top collider
    ColliderTop * top = new ColliderTop(rock);
    top->setRect(0,0,rock->rect().width(),1);

    // add bottom collider
    ColliderBottom * bottom = new ColliderBottom(rock);
    bottom->setRect(0,0+rock->rect().height()-1,rock->rect().width(),1);

    scene->addItem(rock);
}
