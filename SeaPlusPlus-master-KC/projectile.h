#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include <QGraphicsItem>

class Projectile: public QObject, public QGraphicsPixmapItem{
    Q_Object
public:
    Projectile(QGraphicsItem * parent);
public slots:
    //instead of move
    void fly();
    void setOwner(QGraphicsItem * item);
    QGraphicsItem* getOwner();

//    int getDamage();
//    void setDamage(int val);
//    void setRange(int n);
private:
    QGraphicsItem* owner;
    int damage;
    int distanceTraveled;
    int range;

    // after two bounces off the rocks, the projectile should disapear
    int bounceCount;
};

#endif // PROJECTILE_H
