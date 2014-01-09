#ifndef ADDCOMPONENTCOMMAND_H
#define ADDCOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
#include "gmsModel.h"
#include "constants.h"
using namespace std;


//加入Component指令
class AddComponentCommand :public Command
{
public:
    //建構子 取得執行指令所需的資料
    AddComponentCommand(GMSModel* model, string componentType, string componentName);
    //新增Component,同時包含新增時顯示在圖上的座標寬高等資訊
    AddComponentCommand(GMSModel* model, string componentType, string componentName,DrawableData data);
    ~AddComponentCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Components(Receiver)用來操作(透過Model)
    GMSModel* model;
    //要加入的Type
    string addComponentType;
    //要加入的名稱
    string AddName;
    //要加入時的ID編號
    int addedId;
    //座標寬高資料
    int x1,x2,y1,y2;
    float width,height;
};

#endif // ADDCOMPONENTCOMMAND_H
