#include "editComponentTypeCommand.h"

EditComponentTypeCommand::EditComponentTypeCommand(GMSModel* model, int editId, string editNewComponentType)
{
    this->model = model;
    this->editId = editId;
    this->editNewComponentType = editNewComponentType;
}
EditComponentTypeCommand::~EditComponentTypeCommand(){

}
void EditComponentTypeCommand::execute(){
    int x1,x2,y1,y2;
    Component* editComponent = model->GetComponents().GetComponentById(editId);
    this->originalWidth = editComponent->GetWidth();
    this->originalHeight =editComponent->GetHeight();
    //設定新的Type的繪製座標
    this->originalType = model->EditComponentType(editId,editNewComponentType);
    if(editComponent->GetType() == Constants::ComponentType::CubeTypeString){
        editComponent->SetWidth(Constants::DrawComponenPositiontData::CUBE_WIDTH);
        editComponent->SetHeight(Constants::DrawComponenPositiontData::CUBE_HEIGHT);
    }
    else if(editComponent->GetType() == Constants::ComponentType::PyramidTypeString){
        editComponent->SetWidth(Constants::DrawComponenPositiontData::PYRAMID_WIDTH);
        editComponent->SetHeight(Constants::DrawComponenPositiontData::PYRAMID_HEIGHT);
    }
    else if(editComponent->GetType() == Constants::ComponentType::SphereTypeString){
        editComponent->SetWidth(Constants::DrawComponenPositiontData::SPHERE_WIDTH);
        editComponent->SetHeight(Constants::DrawComponenPositiontData::SPHERE_HEIGHT);
    }
    else if(editComponent->GetType() == Constants::ComponentType::LineTypeString){
        editComponent->SetWidth(Constants::DrawComponenPositiontData::LINE_WIDTH);
       editComponent->SetHeight(Constants::DrawComponenPositiontData::LINE_HEIGHT);
    }

    //如果原本的是線段,就記錄原先的x,y,因為之後要畫修改的形狀,會以原先線段左上角的rect座標為起始點
    /*如下*是線段
     case1:
        * <-2
          *        => x1 =x2, y1= y2
            * <-1
     case2:
            * <-2
          *        => x1 =x2
        * <-1
    */

    if(this->originalType == Constants::ComponentType::LineTypeString){
        this->originalX1 = model->GetComponents().GetComponentById(editId)->GetPositionX();
        this->originalY1 = model->GetComponents().GetComponentById(editId)->GetPositionY();
        //設定新的座標
        //並且新的形狀不是Line
        if(model->GetComponents().GetComponentById(editId)->GetType() != Constants::ComponentType::LineTypeString){
            x1 = model->GetComponents().GetComponentById(editId)->GetPositionX();
            x2 = model->GetComponents().GetComponentById(editId)->GetLinePositionX2();
            y1 = model->GetComponents().GetComponentById(editId)->GetPositionY();
            y2 = model->GetComponents().GetComponentById(editId)->GetLinePositionY2();
            if(x2 != -1 && x2 < x1){
               //如果x2比較小,則把x2的座標設為原先x1
               model->GetComponents().GetComponentById(editId)->SetPositionX(x2);
            }
            if(y2 != -1 && y2 < y1){
                model->GetComponents().GetComponentById(editId)->SetPositionY(y2);
            }
        }
    }
    //原先不是線段,要改成線段
    else if (this->originalType != Constants::ComponentType::LineTypeString
             && model->GetComponents().GetComponentById(editId)->GetType() != Constants::ComponentType::LineTypeString){
       x1 = model->GetComponents().GetComponentById(editId)->GetPositionX();
       y1 = model->GetComponents().GetComponentById(editId)->GetPositionY();
        //畫成水平線
        //x2 = x1 + width
        model->GetComponents().GetComponentById(editId)->SetLinePositionX2(x1 + model->GetComponents().GetComponentById(editId)->GetWidth());
        //y2 = y1;
        model->GetComponents().GetComponentById(editId)->SetLinePositionY2(y1);

    }
}
void EditComponentTypeCommand::unexecute(){
    model->UnDoEditComponentType(editId,originalType);
    model->GetComponents().GetComponentById(editId)->SetWidth(this->originalWidth);
    model->GetComponents().GetComponentById(editId)->SetHeight(this->originalHeight);
    //設定回原來的線段座標
    if(this->originalType == Constants::ComponentType::LineTypeString){
        model->GetComponents().GetComponentById(editId)->SetPositionY(this->originalX1);
        model->GetComponents().GetComponentById(editId)->SetPositionY(this->originalY1);
    }

}
