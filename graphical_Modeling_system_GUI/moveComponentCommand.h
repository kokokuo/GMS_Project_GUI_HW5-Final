#ifndef MOVECOMPONENTCOMMAND_H
#define MOVECOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
#include "gmsModel.h"
#include "constants.h"
using namespace std;

class MoveComponentCommand : public Command
{
public:
    //建構子 取得執行指令所需的資料
    MoveComponentCommand(GMSModel* model, int moveId, int x, int y,int oriX,int oriY);
    ~MoveComponentCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Components(Receiver)用來操作(透過Model)
    GMSModel* model;
    //要加入的Type
    int moveId;
    int originalX1,originalY1; //Line:紀錄原來的x,y座標(因為換到別的形狀時,x1,y1會改變)
    int moveX,moveY; //原先形狀的寬高
};

#endif // MOVECOMPONENTCOMMAND_H
