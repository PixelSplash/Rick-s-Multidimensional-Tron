#ifndef PADDLE_H
#define PADDLE_h

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>


class paddle: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    int dir;
    paddle(QGraphicsScene*);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void move();
};

#endif // PADDLE_H

