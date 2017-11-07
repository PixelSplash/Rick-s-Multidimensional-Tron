#include <QApplication>
#include <QGraphicsScene>
#include "paddle.h"
#include <QGraphicsView>
#include "globals.h"
#include "ball.h"
#include "blockzone.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

    // create an item to put into the scene
    blockzone * zone = new blockzone(scene);
    paddle * rect = new paddle(scene);
    ball * bal = new ball(scene,rect,zone);

    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(SCREEN_WIDTH,SCREEN_HEIGHT);

    view->show();

    return a.exec();
}
