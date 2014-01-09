#include "editComponentCommand.h"

int EditOption::EditComponentBothOption = 0;
int EditOption::EditComponentName = 1;
int EditOption::EditComponentType = 2;

//都修改
EditComponentCommand::EditComponentCommand(GMSModel* model, int editId, string editNewName, string editNewComponentType){
    this->editNewName = editNewName;
    this->editId = editId;
    this->model = model;
    this->editNewComponentType = editNewComponentType;
    editKey = EditOption::EditComponentBothOption;
}
//修改Name
EditComponentCommand::EditComponentCommand(GMSModel* model,int editId,string editNewName){
    this->editNewName = editNewName;
    this->editId = editId;
    this->model = model;
    editKey = EditOption::EditComponentName;
}
//修改Type
EditComponentCommand::EditComponentCommand(GMSModel* model, string editNewComponentType, int editId){
    this->editNewComponentType = editNewComponentType;
    this->model = model;
    this->editId = editId;
    editKey = EditOption::EditComponentType;
}
EditComponentCommand::~EditComponentCommand(){

}
void EditComponentCommand::execute(){
    //如果都要修改或是修改Name
    if(editKey == EditOption::EditComponentBothOption || editKey == EditOption::EditComponentName){
        this->originalName = model->EditComponentName(editId,editNewName);
    }
    if(editKey == EditOption::EditComponentBothOption || editKey == EditOption::EditComponentType){
        Component* editComponent = model->GetComponents().GetComponentById(editId);
        //取得原先的類型的寬高
        this->originalWidth = editComponent->GetWidth();
        this->originalHeight =editComponent->GetHeight();
        //設定新的Type的繪製座標
        this->originalType = model->EditComponentType(editId,editNewComponentType);
        //設定寬高
        int width,height;
        Constants::SetComponentWidthHeight(&height,&width,editComponent->GetType());

        //如果原本的是線段,就記錄原先的x,y,因為之後要畫修改的形狀,會以原先線段左上角的rect座標為起始點
        if(this->originalType == Constants::ComponentType::LineTypeString){
            SetLineToOtherType(width,height,editComponent);
        }
        //原先不是線段,要改成線段
        else if (this->originalType != Constants::ComponentType::LineTypeString
                 && model->GetComponents().GetComponentById(editId)->GetType() == Constants::ComponentType::LineTypeString){
            SetOtherToLineType();
        }
        //原先與編輯的類型都不是線段
        else if(this->originalType != Constants::ComponentType::LineTypeString
                && editComponent->GetType() != Constants::ComponentType::LineTypeString){
            //只需改變新的類型元件的寬高
            editComponent->SetWidth(width);
            editComponent->SetHeight(height);
        }
    }
}

void EditComponentCommand::unexecute(){
    //如果都要修改或是修改Name(還原)
    if(editKey == EditOption::EditComponentBothOption || editKey == EditOption::EditComponentName){
        model->UnDoEditComponentName(editId,originalName);
    }
    //都吸改或是修改Type
    if(editKey == EditOption::EditComponentBothOption || editKey == EditOption::EditComponentType){
        model->UnDoEditComponentType(editId,originalType);
        model->GetComponents().GetComponentById(editId)->SetWidth(this->originalWidth);
        model->GetComponents().GetComponentById(editId)->SetHeight(this->originalHeight);
        //設定回原來的線段座標
        if(this->originalType == Constants::ComponentType::LineTypeString){
            model->GetComponents().GetComponentById(editId)->SetPositionX(this->originalX1);
            model->GetComponents().GetComponentById(editId)->SetPositionY(this->originalY1);
            model->GetComponents().GetComponentById(editId)->SetLinePositionX2(this->originalX2);
            model->GetComponents().GetComponentById(editId)->SetLinePositionY2(this->originalY2);
        }
    }
}

void EditComponentCommand::SetLineToOtherType(int width,int height,Component* editComponent){

    //如果原先的型態是線段
    int x1,x2,y1,y2;
    x1 = x2 = y1 = y2 =-1;
    this->originalX1 = model->GetComponents().GetComponentById(editId)->GetPositionX();
    this->originalY1 = model->GetComponents().GetComponentById(editId)->GetPositionY();
    this->originalX2 = model->GetComponents().GetComponentById(editId)->GetLinePositionX2();
    this->originalY2 = model->GetComponents().GetComponentById(editId)->GetLinePositionY2();
    //設定新的座標
    /*如下 *是線段
     case1:
        * <-2
          *        => x1 =x2, y1= y2
            * <-1
     case2:
            * <-2
          *        => x1 =x2
        * <-1
    */
    //如果原先的型態是線段並且新的形狀不是Line
    if(model->GetComponents().GetComponentById(editId)->GetType() != Constants::ComponentType::LineTypeString){
        x1 = this->originalX1; x2 = this->originalX2; y1 = this->originalY1 ; y2 = this->originalY2;
        if(x2 != -1 && x2 < x1){
           //如果不為-1 且比較小,則把x2的座標設為原先x1
           model->GetComponents().GetComponentById(editId)->SetPositionX(x2);
        }
        if(y2 != -1 && y2 < y1){
            model->GetComponents().GetComponentById(editId)->SetPositionY(y2);
        }
        //設定寬高
        editComponent->SetWidth(width);
        editComponent->SetHeight(height);
    }

}
void EditComponentCommand::SetOtherToLineType(){
    int x1,x2,y1,y2;
    x1 = x2 = y1 = y2 =-1;
    x1 = model->GetComponents().GetComponentById(editId)->GetPositionX();
    y1 = model->GetComponents().GetComponentById(editId)->GetPositionY();
     //畫成水平線
     //x2 = x1 + width
     model->GetComponents().GetComponentById(editId)->SetLinePositionX2(x1 + model->GetComponents().GetComponentById(editId)->GetWidth());
     //y2 = y1;
     model->GetComponents().GetComponentById(editId)->SetLinePositionY2(y1);
     //寬高會自己調整

}
