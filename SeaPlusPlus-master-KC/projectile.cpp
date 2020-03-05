#include "projectile.h"
#include <QTimer>
#include <QList>
//#include "Bandit.h"
//#include "GameView.h"
#include <qmath.h>
//#include "ShootBandit.h"
#include "rocks.h"

Projectile::Projectile(QGraphicsItem* parent){

    setPixmap(QPixmap(":/projectile/projectile.png"));

    damage = 1;
    bounceCount = 0;

    owner = parent;

    setRotation(parent->rotation());

    // connect a timer to move()
    int MOVE_EVERY = 10; //1000/game->fps;
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(MOVE_EVERY);
}

void Projectile::fly(){
    int STEP_SIZE = 45;

    int dx = STEP_SIZE * qCos(qDegreesToRadians(rotation()));
    int dy = STEP_SIZE * qSin(qDegreesToRadians(rotation()));

    setX(x()+dx);
    setY(y()+dy);

    distanceTraveled += STEP_SIZE;

    // delete the arrow if its past its range
    if (bounceCount == 2){
          game->scene->removeItem(this);
          delete this;
          return;}

    // delete the arrow if its out of bounds
       double pos_x = scenePos().x();
       double pos_y = scenePos().y();
       double scene_width = game->scene->sceneRect().width();
       double scene_height = game->scene->sceneRect().height();
       if (pos_x > scene_width || pos_x < 0 || pos_y > scene_height || pos_y < 0){
           game->scene->removeItem(this);
           delete this;
           return;
       }
}


QList<QGraphicsItem *> colliding_items = collidingItems();
// if projectile collides with rock, bounce and increment counter
for(size_t i = 0,n = colliding_items.size(); i < n; ++i){
     // if the projectile collides with a wall, increment bounceCount
     if (dynamic_cast<rocks *>(colliding_items[i])){
        bounceCount++;
        return;
     }
      // if projectile collides with enemy ship, kill enemy ship
     StaticGameObject * attacked_object = dynamic_cast<StaticGameObject *>(colliding_items[i]);
             if (attacked_object != nullptr && attacked_object->isdamageable() && attacked_object != owner) {
                 // kill
                 attacked_object->kill(); // need to make kill function
                 // remove/delete projectile
                 game->scene->removeItem(this);
                 delete this;
                 break;
             }
     }
void Projectile::setOwner(QGraphicsItem *item){
    owner = item;
}

QGraphicsItem *Projectile::getOwner(){
    return owner;
}




