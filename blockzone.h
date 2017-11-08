#ifndef BLOCKZONE_H
#define BLOCKZONE_H

#include "block.h"
#include <QGraphicsScene>

#include <QDebug>
#include <stdlib.h>
#include <string>

using namespace std;

class blockzone
{
public:
    QGraphicsScene * scene;
    int rows,columns;
    block*** block_mat;
    blockzone(QGraphicsScene*);
    bool checkCollision(int,int);
};

#endif // BLOCKZONE_H
