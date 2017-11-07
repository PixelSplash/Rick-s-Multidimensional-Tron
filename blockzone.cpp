#include "blockzone.h"
#include "globals.h"

blockzone::blockzone(QGraphicsScene* scene)
{
    columns = BLOCK_ZONE_WIDTH / BLOCK_WIDTH;
    rows = BLOCK_NUM / columns;
    block_mat = (block***)malloc(sizeof(block**)*rows);
    for(int i = 0; i< rows; i++){
        block_mat[i] = (block**)malloc(sizeof(block*)*rows);
        for(int j = 0; j< rows; j++){

            block_mat[i][j] = new block();
            block_mat[i][j]->setPos(BLOCK_ZONE_X+(j*BLOCK_WIDTH),BLOCK_ZONE_Y+(i*BLOCK_HEIGHT));
            scene->addItem(block_mat[i][j]);
        }
    }


}

