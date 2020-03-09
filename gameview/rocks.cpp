#include "rocks.h"
#include <QBrush>
#include <QImage>
//#include "ColliderRight.h"
#include "gameview.h"
#include "QLineF"
#include "QPointF"

extern GameView * game;

Rocks::Rocks(): QGraphicsRectItem(){
    QImage* img = new QImage(":/pictures/rock.png");
    QBrush brush(*img);
    setBrush(brush);
}

