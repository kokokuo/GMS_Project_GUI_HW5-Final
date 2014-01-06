#ifndef DRAWLINESTATE_H
#define DRAWLINESTATE_H

#include <Qt>
#include <QPoint>
#include "gms.h"
#include "drawViewState.h"

class DrawLineState :public DrawViewState
{
    Q_OBJECT

public:
    DrawLineState(GMS* gmsPtr);
    void MousePresseEvent(QPoint p);
    void MouseMoveEvent(QPoint p);
    void MouseReleaseEvent();
signals:
    void SendGetDrawLinePoints(QPoint,QPoint);
private:
    bool isClickStartPoint,isClickEndPoint;
    QPoint drawLineStartPoints; //畫線段的初始座標
    QPoint drawLineEndPoints; //畫線段的結束座標
};

#endif // DRAWLINESTATE_H
