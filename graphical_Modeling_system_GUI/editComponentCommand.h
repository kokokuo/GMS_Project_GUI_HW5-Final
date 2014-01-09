#ifndef EDITCOMPONENTCOMMAND_H
#define EDITCOMPONENTCOMMAND_H

#include <command.h>
#include <string>
#include "components.h"
#include "component.h"
#include "gmsModel.h"

using namespace std;

/*
 *編輯元件的Command
 *透過建構子多載來判斷此命令是只有編輯狀態、名稱或事都要編輯
*/
class EditComponentCommand : public Command
{
public:
    //都修改
    EditComponentCommand(GMSModel* model,int editId,string editNewName,string editNewComponentType);
    //修改Name
    EditComponentCommand(GMSModel* model,int editId,string editNewName);
    //修改Type
    EditComponentCommand(GMSModel* model,string editNewComponentType,int editId);
    ~EditComponentCommand();
    //執行指令
    void execute();
    //反執行指令
    void unexecute();
private:
    //取得Components(Receiver)用來操作(by Model)
    GMSModel* model;
    //要修改的ID編號
    int editId;

    int editKey; //判斷要修改什麼

    //修改名稱//////////////////
    //要修改的名稱
    string editNewName;
    //原先的名稱
    string originalName;

    //修改Type//////////////////
    void SetLineToOtherType(int width, int height, Component *editComponent); //把線段改成其他類型
    void SetOtherToLineType(); //把其他類型改成線段

    //要修改成的Type
    string editNewComponentType;
    int originalX1,originalY1,originalX2,originalY2; //Line:紀錄原來的x,y座標(因為換到別的形狀時,x1,y1會改變)
    int originalWidth,originalHeight; //原先形狀的寬高
    string originalType; //原來的Type

};

class EditOption{
public:
    static int EditComponentName;
    static int EditComponentType;
    static int EditComponentBothOption;
};



#endif // EDITCOMPONENTCOMMAND_H
