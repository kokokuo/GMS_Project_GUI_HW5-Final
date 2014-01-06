#ifndef DRAWVIEWNORMALSTATE_H
#define DRAWVIEWNORMALSTATE_H

#include <QPoint>
#include "gms.h"
#include "drawViewState.h"
class DrawViewNormalState : public DrawViewState
{
public:
    DrawViewNormalState(GMS* gmsPtr);
    void MousePresseEvent(QPoint p);
    void MouseMoveEvent(QPoint p);
    void MouseReleaseEvent();

private:
    bool isComponentPressed; //用來Component記錄有無被按壓到
    bool isGroupPressed; //用來Group記錄有無被按壓到
    Component* dragComponent; //紀錄被拖移的Component
    Group* dragGroup; //紀錄被拖移的Group
    QPoint componentStartPoint; //記錄Component拖移的前一個座標
    QPoint groupStartPoint; //記錄Group拖移的前一個座標

};

#endif // DRAWVIEWNORMALSTATE_H
