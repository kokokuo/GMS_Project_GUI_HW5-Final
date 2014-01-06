#ifndef DRAWVIEWSTATE_H
#define DRAWVIEWSTATE_H

#include "gms.h"
#include <QPoint>
#include <QObject>

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
