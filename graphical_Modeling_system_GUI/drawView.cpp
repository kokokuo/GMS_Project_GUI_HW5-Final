#include "drawView.h"
#include "mainwindow.h"

DrawView::DrawView(GMS *gmsPtr, MainWindow* window)
{
    setFixedSize(1980,1080);
    this->gms = gmsPtr;
    installEventFilter(this);
    isComponentPressed = false;
    isClickStartPoint = isClickEndPoint = false;
    isAddLineCommand = false;
    this->gmsWindow = window;
    //建立同步事件
    QObject::connect(this,SIGNAL(GetDrawLinePoints(QPoint,QPoint)),gmsWindow,SLOT(OnGetDrawLinePoints(QPoint,QPoint)));
    QObject::connect(this,SIGNAL(WantedComponentBeSelected(int)),gmsWindow,SLOT(OnWantedEditComponentbeSelected(int)));
}
void DrawView::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.fillRect(0,0,this->width(),this->height(),Qt::white); //作為背景,寬與高會隨著拖拉而改變
    //繪圖
    vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
    if(drawComponents.size() >0 ){
        for(unsigned int i = 0; i < drawComponents.size(); i++){
            //文字的矩形
            QRect rect(drawComponents[i]->GetPositionX(),
                   drawComponents[i]->GetPositionY(),
                   drawComponents[i]->GetWidth(),
                   drawComponents[i]->GetHeight());
            //判斷類型
            if(drawComponents[i]->GetType() == Constants::ComponentType::CubeTypeString){
                painter.setPen(Qt::black);
                painter.drawText(rect,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
                painter.setPen(Qt::blue);
                painter.drawRect(rect);
            }
            else if(drawComponents[i]->GetType()  == Constants::ComponentType::PyramidTypeString){
               //三角形的座標
                QPolygon polygon;
                polygon << QPoint( drawComponents[i]->GetPositionX() + (drawComponents[i]->GetWidth()/2 ) , drawComponents[i]->GetPositionY())
                        << QPoint(drawComponents[i]->GetPositionX(), drawComponents[i]->GetPositionY() + drawComponents[i]->GetHeight() )
                       << QPoint(drawComponents[i]->GetPositionX() + drawComponents[i]->GetWidth(), drawComponents[i]->GetPositionY() + drawComponents[i]->GetHeight());
                painter.setPen(Qt::black);
                painter.drawText(rect,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()) );
                painter.setPen(Qt::blue);
                painter.drawPolygon(polygon);
            }
            //橢圓形
            else if(drawComponents[i]->GetType()  == Constants::ComponentType::SphereTypeString){
                painter.drawEllipse(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY()
                                    ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight());

                painter.setPen(Qt::black);
                painter.drawText(rect,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
                painter.setPen(Qt::blue);
            }
            //線段
            else if(drawComponents[i]->GetType() == Constants::ComponentType::LineTypeString){
                painter.setPen(Qt::blue);
                painter.drawLine(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY(),drawComponents[i]->GetLinePositionX2(),drawComponents[i]->GetLinePositionY2());

                painter.setPen(Qt::black);
                painter.drawText(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY()
                                 ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight()+25,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
            }
        }
    }
    //Group
    vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
     if(drawGroups.size() >0 ){
          for(unsigned int i = 0; i < drawGroups.size(); i++){
              painter.drawText(drawGroups[i]->GetPositionX(),drawGroups[i]->GetPositionY(),QString::fromStdString(drawGroups[i]->GetName() + ":" + drawGroups[i]->GetMembersIdByStringFormat()));
          }
     }
}


void DrawView::SetLoadedGMSFileDrawPostion(){
    //設定座標
    vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
    if(drawComponents.size() >0 ){
        for(unsigned int i = 0; i < drawComponents.size(); i++){
            //如果沒有被設定資料,再設定
            if(!drawComponents[i]->CheckBeSettedDrawableData()){
                //設定繪製的相關座標與元件的寬高
                drawComponents[i]->SetPositionX(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X);
                drawComponents[i]->SetPositionY(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_Y + i * Constants::DrawComponenPositiontData::COMPONENT_DIFF_Y);
                if(drawComponents[i]->GetType() == Constants::ComponentType::CubeTypeString){
                    drawComponents[i]->SetWidth(Constants::DrawComponenPositiontData::CUBE_WIDTH);
                    drawComponents[i]->SetHeight(Constants::DrawComponenPositiontData::CUBE_HEIGHT);
                }
                else if(drawComponents[i]->GetType() == Constants::ComponentType::PyramidTypeString){
                    drawComponents[i]->SetWidth(Constants::DrawComponenPositiontData::PYRAMID_WIDTH);
                    drawComponents[i]->SetHeight(Constants::DrawComponenPositiontData::PYRAMID_HEIGHT);
                }
                else if(drawComponents[i]->GetType() == Constants::ComponentType::SphereTypeString){
                    drawComponents[i]->SetWidth(Constants::DrawComponenPositiontData::SPHERE_WIDTH);
                    drawComponents[i]->SetHeight(Constants::DrawComponenPositiontData::SPHERE_HEIGHT);
                }
                else if(drawComponents[i]->GetType() == Constants::ComponentType::LineTypeString){
                    drawComponents[i]->SetLinePositionX2(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X + Constants::DrawComponenPositiontData::LINE_WIDTH);
                    drawComponents[i]->SetLinePositionY2(drawComponents[i]->GetPositionY());
                    drawComponents[i]->SetWidth(Constants::DrawComponenPositiontData::LINE_WIDTH);
                    drawComponents[i]->SetHeight(Constants::DrawComponenPositiontData::LINE_HEIGHT);
                }
            }
        }
    }
    vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
    if(drawGroups.size() >0 ){
        for(unsigned int i = 0; i < drawGroups.size(); i++){
            //如果沒有被設定資料,再設定
            if(!drawGroups[i]->CheckBeSettedDrawableData()){
                drawGroups[i]->SetPositionX(Constants::DrawGroupsPositionData::GROUP_BEGIN_X);
                drawGroups[i]->SetPositionY(Constants::DrawGroupsPositionData::GROUP_BEGIN_Y + i * Constants::DrawGroupsPositionData::GROUP_BEGIN_Y);
            }
        }
    }
}
void DrawView::AddComponentDrawablePositionInfo(string type,string name){

    int i = gms->GetComponents().GetAllComponent().size() ;
    int x = Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X;
    int y = Constants::DrawComponenPositiontData::COMPONENT_BEGIN_Y + i * Constants::DrawComponenPositiontData::COMPONENT_DIFF_Y;
    int width = -1,height = -1;
    //設定繪製的相關座標與元件的寬高

    if(type == Constants::ComponentType::CubeTypeString){
        width = Constants::DrawComponenPositiontData::CUBE_WIDTH;
        height = Constants::DrawComponenPositiontData::CUBE_HEIGHT;
    }
    else if(type == Constants::ComponentType::PyramidTypeString){
        width = Constants::DrawComponenPositiontData::PYRAMID_WIDTH;
        height = Constants::DrawComponenPositiontData::PYRAMID_HEIGHT;
    }
    else if(type == Constants::ComponentType::SphereTypeString){
        width = Constants::DrawComponenPositiontData::SPHERE_WIDTH;
        height = Constants::DrawComponenPositiontData::SPHERE_HEIGHT;
    }
    DrawableData data;
    data.x = x; data.y = y; data.width = width; data.height = height; data.x2 = -1; data.y2 = -1;
    gms->AddDrawableComponentsByCommand(type,name,data);
}
void DrawView::AddGroupDrawablePositionInfo(string groupName, vector<int> membersId){
    int i = gms->GetGroups().GetGroupByVectorContainer().size() ;
    int x = Constants::DrawGroupsPositionData::GROUP_BEGIN_X;
    int y = Constants::DrawGroupsPositionData::GROUP_BEGIN_Y + i * Constants::DrawGroupsPositionData::GROUP_BEGIN_Y;

    DrawableData data;
    data.x = x; data.y = y; data.width = -1; data.height = -1; data.x2 = -1; data.y2 = -1;
    gms->AddDrawableNewGroupByCommand(groupName,membersId,data);
}

bool DrawView::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent *e = (QMouseEvent*)event;
        //如果有按壓到Component物件
        if(isComponentPressed){
            //拖移 = 原先的物件座標 + 移動的座標位移差(現在的位移座標 - 原先的座標)
            dragComponent->SetPositionX(dragComponent->GetPositionX() + (e->pos().x() -componentStartPoint.x()) );
            dragComponent->SetPositionY(dragComponent->GetPositionY() + (e->pos().y() -componentStartPoint.y()) );
            //如果是線段要再設定
            if(dragComponent->GetType() == Constants::ComponentType::LineTypeString){
                dragComponent->SetLinePositionX2(dragComponent->GetLinePositionX2() + (e->pos().x() -componentStartPoint.x()) );
                dragComponent->SetLinePositionY2(dragComponent->GetLinePositionY2() + (e->pos().y() -componentStartPoint.y()) );

            }
            componentStartPoint = e->pos();

        }
        //如果有按壓到Group物件
        else if(isGroupPressed){
            //拖移 = 原先的物件座標 + 移動的座標位移差(現在的位移座標 - 原先的座標)
            dragGroup->SetPositionX(dragGroup->GetPositionX() + (e->pos().x() -groupStartPoint.x()) );
            dragGroup->SetPositionY(dragGroup->GetPositionY() + (e->pos().y() -groupStartPoint.y()) );
            groupStartPoint = e->pos();
        }
        this->update();

    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *e = (QMouseEvent*)event;
        //判斷有無拖拉Component
        vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
        if(drawComponents.size() >0 ){
           for(unsigned int i = 0; i < drawComponents.size(); i++){
               if(drawComponents[i]->CheckBePressed(e->pos().x(), e->pos().y() ) && !isComponentPressed){
                   isComponentPressed = true;
                   componentStartPoint = e->pos();
                   dragComponent = drawComponents[i];
                   break;
               }
           }
        }
        //判斷有無拖拉Group
        vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
        if(drawGroups.size() >0 ){
            for(unsigned int i = 0; i < drawGroups.size(); i++){
                if(drawGroups[i]->CheckBePressed(e->pos().x(), e->pos().y() ) && !isGroupPressed){
                    isGroupPressed = true;
                    groupStartPoint = e->pos();
                    dragGroup = drawGroups[i];
                    break;
                }
            }
        }
        //如果有加入線段
        if(isAddLineCommand){
            if(!isClickStartPoint){
                isClickStartPoint = true;
                drawLineStartPoints = e->pos();
            }
            else if(!isClickEndPoint){
                isClickEndPoint = true;
                drawLineEndPoints = e->pos();
            }
        }

        this->update();
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        isComponentPressed = false;
        isGroupPressed = false;
        //如果現在是要加入線段
        if(isAddLineCommand){
            //如果都有點擊為false
            if(isClickStartPoint && isClickEndPoint){
                //發動Signal
                emit GetDrawLinePoints(drawLineStartPoints,drawLineEndPoints);
                isClickEndPoint = isClickStartPoint = false;
            }
        }
        else{
            isClickEndPoint = isClickStartPoint = false;
        }

        this->update();
    }
    else if( event->type() == QEvent::MouseButtonDblClick){
        QMouseEvent *e = (QMouseEvent*)event;
        vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
        if(drawComponents.size() >0 ){
           for(unsigned int i = 0; i < drawComponents.size(); i++){
               if(drawComponents[i]->CheckBePressed(e->pos().x(), e->pos().y() )){
                   emit WantedComponentBeSelected(drawComponents[i]->GetID());
                   break;
               }
           }
        }
        //避免修改完後要切換到drag會座標跑調(因為double click,可能會觸發press的部分)
        isComponentPressed = false;
        isGroupPressed = false;
    }
    return false;
}
//設定是否為加入線段的指令
void DrawView::SetBeAddedLineComannd(bool decision){
    isAddLineCommand = decision;
}
