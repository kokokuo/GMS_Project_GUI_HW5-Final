#include "component.h"
#include "group.h"


//Component
Component::Component(int id, string componentType, string name)
{
    this->id = id;
    this->type = componentType;
    this->name = name;
    //設定預設值
    this->x =  this->y = this->width = this->height = -1 ;
    //如果是線的Type再設定
    if(componentType == Constants::ComponentType::LineTypeString){
        this->x2 = this->y2 = -1;
    }

}
Component::Component( Component& c){
    this->id = c.GetID();
    this->type = c.GetType();
    this->name = c.GetName();
    //設定預設值
    this->x =  this->y = this->width = this->height = -1 ;
    //如果是線的Type再設定
    if(type == Constants::ComponentType::LineTypeString){
        this->x2 = this->y2 = -1;
    }
}
int Component::GetID(){
    return this->id;
}
string Component::GetName(){
    return this->name;
}

string Component::GetType(){
    return this->type;
}

void Component::SetName(string name){
    this->name = name;
}
void Component::SetComponentType(string type){
    this->type = type;
}
void Component::SetPositionX(float x){
    this->x = x;
}
void Component::SetPositionY(float y){
    this->y = y;
}
int Component::GetPositionX(){
    return this->x;
}
int Component::GetPositionY(){
    return this->y;
}
void Component::SetWidth(int width){
    this->width = width;
}
void Component::SetHeight(int height){
    this->height = height;
}
int Component::GetWidth(){
    return this->width;
}
int Component::GetHeight(){
    return this->height;

}
bool Component::CheckBePressed(int x, int y){
    if(this->type != Constants::ComponentType::LineTypeString  &&  x > this->x && x < this->x + this->width && y < this->y + this->height && y > this->y){
        return true;
    }
    else if(this->type == Constants::ComponentType::LineTypeString &&  x > this->x && x < this->x + this->width && y < this->y + this->height +20 && y > this->y){
        return true;
    }
    return false;

}
bool Component::CheckBeSettedDrawableData(){
    //表示有設定繪製時的資料
    if(this->x != -1 &&   this->y != -1 && this->width != -1 && this->height != -1)
        return true;
    return false;
}
//如果是線的Type再設定
bool Component::SetLinePositionX2(int x2){
    if(type == Constants::ComponentType::LineTypeString){
        this->x2 = x2;
        return true;
    }
    return false;
}
//如果是線的Type再設定
bool Component::SetLinePositionY2(int y2){
    if(type == Constants::ComponentType::LineTypeString){
        this->y2 = y2;
        return true;
    }
    return false;
}
int Component::GetLinePositionX2(){
    return this->x2;
}
int Component::GetLinePositionY2(){
    return this->y2;
}
bool Component::SetLinePosition(int x1, int y1, int x2, int y2){
    if(type == Constants::ComponentType::LineTypeString){
        this->x = x1;
        this->y = y1;
        this->x2 = x2;
        this->y2 = y2;

        this->width = abs(x1 - x2);
        this->height = abs(y1-y2);

        return true;
    }
    return false;
}
