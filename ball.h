#ifndef BOLA_H
#define BOLA_H

#include <QGraphicsRectItem>
#include <QObject>
#include "blockzone.h"
#include <QGraphicsScene>


class ball: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    QGraphicsRectItem* pad;
    blockzone* zone;
    int xspd,yspd;
    ball(QGraphicsScene*,QGraphicsRectItem*,blockzone*);
    void checkCollision();
public slots:
    void move();
};

#endif // BOLA_H
