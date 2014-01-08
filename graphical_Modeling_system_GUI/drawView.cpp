#include "drawView.h"
#include "mainwindow.h"

DrawView::DrawView(GMS *gmsPtr, MainWindow* window)
{
    setFixedSize(1280,1080);
    this->gms = gmsPtr;
    installEventFilter(this);
    this->gmsWindow = window;
    //放置State pattern
    states.insert(pair<Constants::DrawViewStateEnum,DrawViewState*>(Constants::DRAW_NORMAL_STATE,new DrawViewNormalState(gms) ));
    states.insert(pair<Constants::DrawViewStateEnum,DrawViewState*>(Constants::DRAW_LINE_STATE,new DrawLineState(gms) ));
    //設定目前的State唯一般的可拖移State
    currentState = states[Constants::DRAW_NORMAL_STATE];
    //建立同步事件
    QObject::connect(this,SIGNAL(WantedComponentBeSelected(int)),gmsWindow,SLOT(OnWantedEditComponentbeSelected(int)));
    //從DrawLineSate取得座標 並在發送signal協助傳到Mainwindow
    QObject::connect(states[Constants::DRAW_LINE_STATE],SIGNAL(SendGetDrawLinePoints(QPoint,QPoint)), gmsWindow,SLOT(OnGetDrawLinePoints(QPoint,QPoint)));

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
                                 ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight(),Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
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
    int width,height;
    //設定座標
    vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
    if(drawComponents.size() >0 ){
        for(unsigned int i = 0; i < drawComponents.size(); i++){
            //如果沒有被設定資料,再設定
            if(!drawComponents[i]->CheckBeSettedDrawableData()){
                //設定繪製的相關座標與元件的寬高
                drawComponents[i]->SetPositionX(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X);
                drawComponents[i]->SetPositionY(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_Y + i * Constants::DrawComponenPositiontData::COMPONENT_DIFF_Y);
                //如果是Line,再設定第二個點的X,Y座標
                if(drawComponents[i]->GetType() == Constants::ComponentType::LineTypeString){
                    drawComponents[i]->SetLinePositionX2(Constants::DrawComponenPositiontData::COMPONENT_BEGIN_X + Constants::DrawComponenPositiontData::LINE_WIDTH);
                    drawComponents[i]->SetLinePositionY2(drawComponents[i]->GetPositionY());
                }
                //取得寬高
                Constants::SetComponentWidthHeight(&height,&width,drawComponents[i]->GetType());
                drawComponents[i]->SetWidth(width);
                drawComponents[i]->SetHeight(height);

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

    //取得寬高
    Constants::SetComponentWidthHeight(&height,&width,type);

    DrawableData data;
    data.x = x; data.y = y; data.width = width; data.height = height; data.x2 = -1; data.y2 = -1;
    gms->AddDrawableComponentsByCommand(type,name,data);
}

//加入繪製group時的座標資訊
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
        currentState->MouseMoveEvent(e->pos()); //State pattern對應目前指令
        this->update();

    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *e = (QMouseEvent*)event;
        currentState->MousePresseEvent(e->pos());
        this->update();
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        currentState->MouseReleaseEvent();
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

    }
    return false;
}
//設定是否為加入線段的指令
void DrawView::SetBeAddedLineComannd(bool decision){
    if(decision)
        currentState = states[Constants::DRAW_LINE_STATE];
    else
        currentState = states[Constants::DRAW_NORMAL_STATE];
}
