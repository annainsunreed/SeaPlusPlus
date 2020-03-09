#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QSet>
#include <QPointF>

class Player: public QObject, public QGraphicsPixmapItem
{
public:
    Player(const QPixmap &pixmap);

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void setAngle(double ang);

    double getAngle() const;

    QPointF getOrigin();

    QSet<int> keysPressed;

public slots:
    void eliminate(double amount);

private:
    double x_previous;
    double y_previous;
    int angle;
    double health;
};


#endif // PLAYER_H
