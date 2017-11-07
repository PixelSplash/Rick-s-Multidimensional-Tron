#include "blockzone.h"
#include "globals.h"
#include <stdio.h>

blockzone::blockzone(QGraphicsScene* scene)
{

    block_mat = (block***)malloc(sizeof(block**)*ROWS);
    for(int i = 0; i< ROWS; i++){
        block_mat[i] = (block**)malloc(sizeof(block*)*ROWS);
        for(int j = 0; j< COLUMNS; j++){

            block_mat[i][j] = new block();
            block_mat[i][j]->setPos(BLOCK_ZONE_X+(j*BLOCK_WIDTH),BLOCK_ZONE_Y+(i*BLOCK_HEIGHT));
            scene->addItem(block_mat[i][j]);
        }
    }


}

bool blockzone::checkCollision(int x, int y)
{
    if(x > BLOCK_ZONE_X + COLUMNS * BLOCK_WIDTH || x < BLOCK_ZONE_X || y < BLOCK_ZONE_Y)return false;
    int i = (ROWS - 1) - (((BLOCK_ZONE_Y + ROWS * BLOCK_HEIGHT) - x)%(BLOCK_HEIGHT));
    int j = (COLUMNS - 1) - (((BLOCK_ZONE_X + COLUMNS * BLOCK_WIDTH) - x)%(BLOCK_WIDTH));
    printf ("I: %d J: %d \n", i, j);
    if(block_mat[i][j]!=NULL)return true;
    return false;
}

