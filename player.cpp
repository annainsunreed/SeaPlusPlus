#include "player.h"
//#include "rocks.h"
//#include "gameinstance.h"
#include <QDebug>

player::player(QPixmap &pixmap): QObject(), QGraphicsPixmapItem(pixmap)
{
    setTransformOriginPoint(20, 38);

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
            event->key() == Qt::Key_D ||
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
            break;
        }
        {
        case Qt::Key_A:
            setPos(x()-step_size, y());
            break;
        }
        {
        case Qt::Key_S:
            setPos(x(), y()+step_size);
            break;
        }
        {
        case Qt::Key_D:
            setPos(x()+step_size, y());
            break;
        }
    }

    if (keysPressed.size() > 1)
    {
        if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_A))
        {
            setPos(x()-step_size, y()-step_size);
        }
        if (keysPressed.contains(Qt::Key_W) && keysPressed.contains(Qt::Key_D))
        {
            setPos(x()+step_size, y()-step_size);
        }
        if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_A))
        {
            setPos(x()-step_size, y()+step_size);
        }
        if (keysPressed.contains(Qt::Key_S) && keysPressed.contains(Qt::Key_D))
        {
            setPos(x()+step_size, y()+step_size);
        }
    }

    //colliding items function

}
