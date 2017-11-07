#ifndef BLOCKZONE_H
#define BLOCKZONE_H

#include "block.h"
#include <QGraphicsScene>

class blockzone
{
public:
    int rows,columns;
    block*** block_mat;
    blockzone(QGraphicsScene*);
};

#endif // BLOCKZONE_H
