#include "drawLineState.h"

DrawLineState::DrawLineState(GMS *gmsPtr)
    :DrawViewState(gmsPtr)
{
    isClickStartPoint = isClickEndPoint = false;
}
void DrawLineState::MousePresseEvent(QPoint p){
    //是否沒有點擊,給予座標
    if(!isClickStartPoint){
        isClickStartPoint = true;
        drawLineStartPoints = p;
    }
    else if(!isClickEndPoint){
        isClickEndPoint = true;
        drawLineEndPoints = p;
    }
}
void DrawLineState::MouseMoveEvent(QPoint p){

}
void DrawLineState::MouseReleaseEvent(){
    //如果都有點擊為false
    if(isClickStartPoint && isClickEndPoint){
        //發動Signal(送出點選完的座標資料)
        emit SendGetDrawLinePoints(drawLineStartPoints,drawLineEndPoints);
        isClickEndPoint = isClickStartPoint = false;
    }


}
