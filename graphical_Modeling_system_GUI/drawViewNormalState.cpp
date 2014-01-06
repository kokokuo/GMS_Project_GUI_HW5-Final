#include "drawViewNormalState.h"

DrawViewNormalState::DrawViewNormalState(GMS *gmsPtr)
    :DrawViewState(gmsPtr)
{
    isGroupPressed = false;
    isComponentPressed = false;
}
void DrawViewNormalState::MousePresseEvent(QPoint p){
    //判斷有無拖拉Component
    vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
    if(drawComponents.size() >0 ){
       for(unsigned int i = 0; i < drawComponents.size(); i++){
           if(drawComponents[i]->CheckBePressed(p.x(), p.y() ) && !isComponentPressed){
               isComponentPressed = true;
               componentStartPoint = p;
               dragComponent = drawComponents[i];
               break;
           }
       }
    }
    //判斷有無拖拉Group
    vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
    if(drawGroups.size() >0 ){
        for(unsigned int i = 0; i < drawGroups.size(); i++){
            if(drawGroups[i]->CheckBePressed(p.x(), p.y() ) && !isGroupPressed){
                isGroupPressed = true;
                groupStartPoint = p;
                dragGroup = drawGroups[i];
                break;
            }
        }
    }
}
void DrawViewNormalState::MouseMoveEvent(QPoint p){
    //如果有按壓到Component物件
    if(isComponentPressed){
        //拖移 = 原先的物件座標 + 移動的座標位移差(現在的位移座標 - 原先的座標)
        dragComponent->SetPositionX(dragComponent->GetPositionX() + (p.x() -componentStartPoint.x()) );
        dragComponent->SetPositionY(dragComponent->GetPositionY() + (p.y() -componentStartPoint.y()) );
        //如果是線段要再設定
        if(dragComponent->GetType() == Constants::ComponentType::LineTypeString){
            dragComponent->SetLinePositionX2(dragComponent->GetLinePositionX2() + (p.x() -componentStartPoint.x()) );
            dragComponent->SetLinePositionY2(dragComponent->GetLinePositionY2() + (p.y() -componentStartPoint.y()) );

        }
        componentStartPoint = p;

    }
    //如果有按壓到Group物件
    else if(isGroupPressed){
        //拖移 = 原先的物件座標 + 移動的座標位移差(現在的位移座標 - 原先的座標)
        dragGroup->SetPositionX(dragGroup->GetPositionX() + (p.x() -groupStartPoint.x()) );
        dragGroup->SetPositionY(dragGroup->GetPositionY() + (p.y() -groupStartPoint.y()) );
        groupStartPoint = p;
    }
}
void DrawViewNormalState::MouseReleaseEvent(){
    isComponentPressed = false;
    isGroupPressed = false;
}
