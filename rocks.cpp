
#include "rocks.h"
#include <QBrush>
#include <QImage>
//#include "ColliderRight.h"
//#include "GameView.h"
#include "QLineF"
#include "QPointF"

extern GameView * game;

rocks::rocks(): QGraphicsRectItem(){
    QImage* img = new QImage(":/picture/rock.png");
    QBrushbrush(*img);
    setBrush(brush);
}
