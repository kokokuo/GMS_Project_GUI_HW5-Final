#include "moveGroupCommand.h"

MoveGroupCommand::MoveGroupCommand(GMSModel* model,int moveId,int x,int y,int oriX,int oriY)
{
    this->model = model;
    this->moveId = moveId;
    this->moveX = x;
    this->moveY = y;
    this->originalX1 = oriX;
    this->originalY1 = oriY;
}
MoveGroupCommand::~MoveGroupCommand(){

}
void MoveGroupCommand::execute(){
    //取得原先座標
    model->MoveGroup(moveId,moveX,moveY);
}
void MoveGroupCommand::unexecute(){
    model->MoveGroup(moveId,originalX1,originalY1);
}
