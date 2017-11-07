#include "paddle.h"
#include <QKeyEvent>
#include <QTimer>
#include "globals.h"

paddle::paddle(QGraphicsScene* scene){
    scene->addItem(this);
    setRect(0,SCREEN_HEIGHT-PADDLE_HEIGHT,PADDLE_WIDTH,PADDLE_HEIGHT);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void paddle::keyPressEvent(QKeyEvent *event)
{
     if (event->key() == Qt::Key_Left){
         dir = 2;
     }else if (event->key() == Qt::Key_Right){
         dir = 1;
     }
}

void paddle::keyReleaseEvent(QKeyEvent *event)
{
     if (event->key() == Qt::Key_Left){
         dir = 0;
     }else if (event->key() == Qt::Key_Right){
         dir = 0;
     }
}

void paddle::move()
{
    switch (dir) {
    case 1:
        if(x()+PADDLE_WIDTH < SCREEN_WIDTH)setPos(x()+PADDLE_SPEED,y());
        break;
    case 2:
        if(x() > 0)setPos(x()-PADDLE_SPEED,y());
        break;
    default:
        break;
    }
}
