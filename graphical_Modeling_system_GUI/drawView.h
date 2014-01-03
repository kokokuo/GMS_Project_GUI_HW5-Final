#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QPainter>
#include <QtWidgets>
#include "component.h"
#include <map>
#include <vector>
#include "gms.h"
#include "constants.h"

class DrawView : public QWidget
{
public:
    DrawView(GMS* gmsPtr);
    //設定顯示在畫布上的初始位置
    void SetComponentsDrawPostion(); //設定Component座標
    void SetGroupsDrawPostion(); //設定Group座標

protected:
    bool eventFilter(QObject *, QEvent *);
    void paintEvent(QPaintEvent *);
private:
    bool isComponentPressed; //用來Component記錄有無被按壓到
    bool isGroupPressed; //用來Group記錄有無被按壓到
    Component* dragComponent; //紀錄被拖移的Component
    Group* dragGroup; //紀錄被拖移的Group
    QPoint componentStartPoint; //記錄Component拖移的前一個座標
    QPoint groupStartPoint; //記錄Group拖移的前一個座標
    GMS* gms;

};

#endif // DRAWVIEW_H
