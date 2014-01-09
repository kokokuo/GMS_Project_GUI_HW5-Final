#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <QPainter>
#include <QtWidgets>
#include "component.h"
#include <map>
#include <vector>
#include "gms.h"
#include "constants.h"
#include <QPoint>
#include "drawViewState.h"
#include "drawViewNormalState.h"
#include "drawLineState.h"

class MainWindow;

/*此類別用來
 *1.繪圖
 *2.設定繪製時的座標
 *3.取得滑鼠點擊事件的類別*/
class DrawView : public QWidget
{
    Q_OBJECT

public:
    DrawView(GMS* gmsPtr, MainWindow* window);
    //設定載入的檔案顯示在畫布上的初始位置
    void SetLoadedGMSFileDrawPostion();
    //拿取要加入的Component資料,並給予座標,再加入命令
    void AddComponentDrawablePositionInfo(string type,string name);
    //拿取要加入的Group資料,並給予座標,再加入命令
    void AddGroupDrawablePositionInfo(string groupName,vector<int> membersId);
    void SetBeAddedLineComannd(bool decision); //設定是否要加入Line Command

signals:
    void WantedComponentBeSelected(int editId); //發送想要選擇的Component,用在編輯時所使用

protected:
    bool eventFilter(QObject *, QEvent *); //事件過濾器
    void paintEvent(QPaintEvent *);
private:
    GMS* gms; //gms
    MainWindow* gmsWindow; //mainwindow
    map<Constants::DrawViewStateEnum,DrawViewState*> states; //紀錄兩種state
    DrawViewState* currentState; //紀錄目前的state;


};

#endif // DRAWVIEW_H
