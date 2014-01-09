#include "addNewGroupCommand.h"

AddNewGroupCommand::AddNewGroupCommand(GMSModel* model,string name, vector<int> members)
{
    this->addedId = 0;
    this->addName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->model = model;
}
AddNewGroupCommand::AddNewGroupCommand(GMSModel* model,string name, vector<int> members,DrawableData data){
    this->addedId = 0;
    this->addName = name;
    for(vector<int>::iterator it = members.begin();it != members.end();it++){
       this->addMembers.push_back((*it));
    }
    this->model = model;
    this->x = data.x;
    this->y = data.y;

}
AddNewGroupCommand::~AddNewGroupCommand(){

}
void AddNewGroupCommand::execute(){
    model->AddNewGroup(&addedId,addName,addMembers);
    Group* addGroup = model->GetGroups().GetGroupById(addedId);
    //設定座標
    addGroup->SetPositionX(x);
    addGroup->SetPositionY(y);
}
void AddNewGroupCommand::unexecute(){
    model->UnDoAddNewGroup(addedId);
}
