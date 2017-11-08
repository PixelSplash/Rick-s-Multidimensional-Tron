#include "blockzone.h"
#include "globals.h"

#include <sstream>

std::string NumberToString ( int Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

blockzone::blockzone(QGraphicsScene* scene)
{
    this->scene = scene;
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

    if(y > BLOCK_ZONE_Y + ROWS * BLOCK_HEIGHT || y + BALL_HEIGHT < BLOCK_ZONE_Y || x > BLOCK_ZONE_X + COLUMNS * BLOCK_WIDTH || x + BALL_WIDTH < BLOCK_ZONE_X)return false;
    int i = (y + BALL_HEIGHT/2 - BLOCK_ZONE_Y)/(BLOCK_HEIGHT);
    int j = (x + BALL_WIDTH/2 - BLOCK_ZONE_X)/(BLOCK_WIDTH);
    //qDebug() << NumberToString(x + BALL_WIDTH/2 - BLOCK_ZONE_X).c_str() << " " << NumberToString(y + BALL_HEIGHT/2 - BLOCK_ZONE_Y).c_str();
    if(i>=ROWS || j>=COLUMNS || i<0 || j<0)return false;


    if(block_mat[i][j]!=NULL){
        delete block_mat[i][j];
        block_mat[i][j] = NULL;
        return true;
    }
    return false;
}

