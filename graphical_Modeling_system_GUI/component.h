#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <vector>
#include <math.h>
#include "constants.h"

using namespace std;

class Group;



//=================================================


class Component
{
public:
    //加入編號，類型，與元件名稱
    Component(int id, string componentType, string name);
    //加入MemberToGroup時,要建立連結
    void AddGroup(Group* );
    //復原時,要移除連結
    void RemoveGroup(Group* );
    //copy constructor
    Component(Component &c);
    ~Component(){}
    int GetID(); //取得ID
    string GetType(); //取得Type

    string GetName(); //取得名稱
    void SetName(string name); //設定名稱
    void SetComponentType(string type); //設定類型

    //GUI用 設定座標

    void SetPositionX(float x);
    void SetPositionY(float Y);
    int GetPositionX(); //取得X座標
    int GetPositionY(); //取得Y座標

    //設定線段的兩點x,y座標
    bool SetLinePosition(int x1, int y1, int x2, int y2);
    bool SetLinePositionX2(int x2); //設定線段的X2座標
    bool SetLinePositionY2(int Y2); //設定線段的Y2座標
    int GetLinePositionX2(); //取得X2座標
    int GetLinePositionY2(); //取得Y2座標

    void SetWidth(int width); //設定寬
    void SetHeight(int height); //設定高
    int GetWidth(); //取得寬
    int GetHeight(); //取得高
    //確認GUI滑鼠的點擊座標是否有按掉
    bool CheckBePressed(int x, int y);
    //確認有無被設定話圖的座標位置與寬高
    bool CheckBeSettedDrawableData();

private:
    //用來調整線段的寬高
    void AdjustWidthAndHeightForLine();
    int id;
    string type;
    string name;
    vector<Group*> GroupsAddedComponent; //紀錄有加入此Component的Group記憶體位址
    int x,y;
    int width,height;
    int x2,y2; //畫線
};

#endif // COMPONENT_H
