#include "player.h"
#include "rocks.h"
#include "gameview.h"
#include <QDebug>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

Player::Player(const QPixmap &pixmap): QObject(), QGraphicsPixmapItem(pixmap)
{
    setTransformOriginPoint(130,97);
    x_previous = pos().x();
    y_previous = pos().y();
    health = 1;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (
            event->key() == Qt::Key_W ||
            event->key() == Qt::Key_A ||
            event->key() == Qt::Key_S ||
            event->key() == Qt::Key_D
       )
    {
        keysPressed.insert(event->key());
    }

    int step_size = 10;

    if (keysPressed.size() == 1){
        switch (event->key())
        {
        case Qt::Key_W:
            setPos(x(), y()-step_size);
            setRotation(0);
            break;

        case Qt::Key_A:
            setPos(x()-step_size, y());
            setRotation(270);

            break;

        case Qt::Key_S:
            setPos(x(), y()+step_size);
            setRotation(180);

            break;

        case Qt::Key_D:
            setPos(x()+step_size, y());
            setRotation(90);
            break;
        }
    }

    if (keysPressed.size() > 1)
    {
        if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_A))
        {
            setPos(x()-step_size, y()-step_size);
            setRotation(315);


        }
        if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_D))
        {
            setPos(x()+step_size, y()-step_size);
            setRotation(45);

        }
        if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_A))
        {
            setPos(x()-step_size, y()+step_size);
            setRotation(225);

        }
        if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_D))
        {
            setPos(x()+step_size, y()+step_size);
            setRotation(135);

        }
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
       for (int i = 0, n = colliding_items.size();i<n;i++){
           // player collides w Wall - move him back to his previous position
           if (typeid(Rocks) == typeid(*colliding_items[i])){
               setPos(x_previous,y_previous);
               return;
           }
       }
    x_previous = pos().x();
    y_previous = pos().y();
}

void Player::keyReleaseEvent(QKeyEvent *event){
    keysPressed.remove(event->key());
}

void Player::setAngle(double a){
    angle = a;
}

double Player::getAngle() const{
    return angle;
}

QPointF Player::getOrigin(){
    return mapToScene(transformOriginPoint());
}

