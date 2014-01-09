#ifndef DRAWVIEWSTATE_H
#define DRAWVIEWSTATE_H

#include "gms.h"
#include <QPoint>
#include <QObject>

/*
 *State Pattern
 *用來判斷現在的狀態是畫線 還是一般的元件拖移
 *子類別的實作狀態是
 *1.drawViewNormalState :一般的拖移狀態
 *2.drawLineState: 畫線時的狀態
*/
class DrawViewState : public QObject
{
    Q_OBJECT

public:
    DrawViewState(GMS* gmsPtr);
    virtual void MousePresseEvent(QPoint p) = 0;
    virtual void MouseMoveEvent(QPoint p) = 0;
    virtual void MouseReleaseEvent() = 0;


protected:
    GMS* gms;
};

#endif // DRAWVIEWSTATE_H
