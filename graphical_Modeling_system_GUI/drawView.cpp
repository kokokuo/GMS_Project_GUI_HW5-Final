#include "drawView.h"


DrawView::DrawView(GMS *gmsPtr)
{

    setFixedSize(1980,1080);
    this->gms = gmsPtr;
    installEventFilter(this);
    isComponentPressed = false;
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
            if(drawComponents[i]->GetType() == Constants::DrawComponentData::CubeTypeString){
                painter.setPen(Qt::black);
                painter.drawText(rect,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
                painter.setPen(Qt::blue);
                painter.drawRect(rect);
            }
            else if(drawComponents[i]->GetType()  == Constants::DrawComponentData::PyramidTypeString){
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
            else if(drawComponents[i]->GetType()  == Constants::DrawComponentData::SphereTypeString){
                painter.drawEllipse(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY()
                                    ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight());

                painter.setPen(Qt::black);
                painter.drawText(rect,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
                painter.setPen(Qt::blue);
            }
            else if(drawComponents[i]->GetType() == Constants::DrawComponentData::LineTypeString){
                painter.setPen(Qt::blue);
                painter.drawRect(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY()
                                 ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight());
                painter.setPen(Qt::black);
                painter.drawText(drawComponents[i]->GetPositionX(),drawComponents[i]->GetPositionY()
                                 ,drawComponents[i]->GetWidth(),drawComponents[i]->GetHeight()+25,Qt::AlignCenter,QString::fromStdString(drawComponents[i]->GetName()));
            }
        }
    }
    vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
     if(drawGroups.size() >0 ){
          for(unsigned int i = 0; i < drawGroups.size(); i++){
              painter.drawText(drawGroups[i]->GetPositionX(),drawGroups[i]->GetPositionY(),QString::fromStdString(drawGroups[i]->GetName() + ":" + drawGroups[i]->GetMembersIdByStringFormat()));
          }
     }
}
void DrawView::SetComponentsDrawPostion(){
    //設定座標
    vector<Component*> drawComponents = this->gms->GetComponents().GetAllComponent();
    if(drawComponents.size() >0 ){
        for(unsigned int i = 0; i < drawComponents.size(); i++){
            drawComponents[i]->SetPositionX(Constants::DrawComponentData::COMPONENT_BEGIN_X);
            drawComponents[i]->SetPositionY(Constants::DrawComponentData::COMPONENT_BEGIN_Y + i * Constants::DrawComponentData::COMPONENT_DIFF_Y);
            if(drawComponents[i]->GetType() == Constants::DrawComponentData::CubeTypeString){
                drawComponents[i]->SetWidth(Constants::DrawComponentData::CUBE_WIDTH);
                drawComponents[i]->SetHeight(Constants::DrawComponentData::CUBE_HEIGHT);
            }
            else if(drawComponents[i]->GetType() == Constants::DrawComponentData::PyramidTypeString){
                drawComponents[i]->SetWidth(Constants::DrawComponentData::PYRAMID_WIDTH);
                drawComponents[i]->SetHeight(Constants::DrawComponentData::PYRAMID_HEIGHT);
            }
            else if(drawComponents[i]->GetType() == Constants::DrawComponentData::SphereTypeString){
                drawComponents[i]->SetWidth(Constants::DrawComponentData::SPHERE_WIDTH);
                drawComponents[i]->SetHeight(Constants::DrawComponentData::SPHERE_HEIGHT);
            }
            else if(drawComponents[i]->GetType() == Constants::DrawComponentData::LineTypeString){
                drawComponents[i]->SetWidth(Constants::DrawComponentData::LINE_WIDTH);
                drawComponents[i]->SetHeight(Constants::DrawComponentData::LINE_HEIGHT);
            }
        }
    }
}
void DrawView::SetGroupsDrawPostion(){
    vector<Group*> drawGroups = this->gms->GetGroups().GetGroupByVectorContainer();
    if(drawGroups.size() >0 ){
        for(unsigned int i = 0; i < drawGroups.size(); i++){
            drawGroups[i]->SetPositionX(Constants::DrawComponentData::GROUP_BEGIN_X);
            drawGroups[i]->SetPositionY(Constants::DrawComponentData::GROUP_BEGIN_Y + i * Constants::DrawComponentData::GROUP_BEGIN_Y);
        }
    }
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
        this->update();
    }
    else if (event->type() == QEvent::MouseButtonRelease)
    {
        isComponentPressed = false;
        isGroupPressed = false;
        this->update();
    }

    return false;
}
