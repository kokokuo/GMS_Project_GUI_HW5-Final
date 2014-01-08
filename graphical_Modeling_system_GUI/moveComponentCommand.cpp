#include "moveComponentCommand.h"

MoveComponentCommand::MoveComponentCommand(GMSModel* model,int moveId,int x,int y,int oriX,int oriY)
{
    this->model = model;
    this->moveId = moveId;
    this->moveX = x;
    this->moveY = y;
    this->originalX1 = oriX;
    this->originalY1 = oriY;
}
MoveComponentCommand::~MoveComponentCommand(){

}
void MoveComponentCommand::execute(){
    //取得原先座標

    model->MoveComponent(moveId,moveX,moveY);
}
void MoveComponentCommand::unexecute(){
    model->UnDoMoveComponent(moveId,originalX1,originalY1);
}
