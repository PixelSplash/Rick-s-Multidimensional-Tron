#include "ball.h"
#include "globals.h"
#include <QTimer>

ball::ball(QGraphicsScene* scene,QGraphicsRectItem* ppad, blockzone* pzone)
{
    scene->addItem(this);
    zone = pzone;
    pad = ppad;
    xspd = yspd = 1;
    setRect(0,0,BALL_WIDTH,BALL_HEIGHT);
    setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void ball::checkCollision()
{
    if(x() < 0 || x()+BALL_WIDTH > SCREEN_WIDTH)xspd = -xspd;
    if(y() < 0)yspd = -yspd;
    if(y()+BALL_HEIGHT >= SCREEN_HEIGHT-PADDLE_HEIGHT){
        if(y()+BALL_HEIGHT > SCREEN_HEIGHT)setPos(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        else if(x() > pad->x() && x() < pad->x() + PADDLE_WIDTH)yspd = -1;
    }
}

void ball::move()
{
    setPos(x()+(BALL_SPEED*xspd),y()+(BALL_SPEED*yspd));
    checkCollision();
}

