#ifndef EDITCOMPONENTTYPECOMMAND_H
#define EDITCOMPONENTTYPECOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
#include "gmsModel.h"
#include "constants.h"
using namespace std;

class EditComponentTypeCommand : public Command
{
public:
    EditComponentTypeCommand(GMSModel* model,int editId,string editNewComponentType);
    ~EditComponentTypeCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    void SetLineToOtherType(int width, int height, Component *editComponent); //把線段改成其他類型
    void SetOtherToLineType(); //把其他類型改成線段

    //取得Components(Receiver)用來操作(By Model)
    GMSModel* model;
    //要修改成的Type
    string editNewComponentType;
    int originalX1,originalY1,originalX2,originalY2; //Line:紀錄原來的x,y座標(因為換到別的形狀時,x1,y1會改變)
    int originalWidth,originalHeight; //原先形狀的寬高

    string originalType; //原來的Type
    //要修改的ID編號
    int editId;
};

#endif // EDITCOMPONENTYYPECOMMAND_H
