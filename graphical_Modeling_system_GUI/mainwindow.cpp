#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1024,768);
    view = new DrawView(&gms); //取得GMSModel

    //如果Window中只有一個主要原件,可使用,如果有多數元件,如加入ListWidget等 就要移掉此行
    //this->setCentralWidget(ui->drawViewScrollArea);
    ui->drawViewScrollArea->setWidget(view);

    //透過此行讓放在ScrollArea中的Widget可以與scrollArea一起縮放,不過便不會有Scrollbar的出現
    //scrollArea.setWidgetResizable(true);

    //設定ScrollArea的固定高寬 讓他不要跟著Widget一起變動,然後再設定卷軸
    //Widget再設定更大的寬高(要用SetFixedSize才行) 既可以產生卷軸

    ui->drawViewScrollArea->setFixedSize(710,660);
    ui->drawViewScrollArea->horizontalScrollBar()->setValue(100);
    ui->drawViewScrollArea->verticalScrollBar()->setValue(100);

    //設定ListWidget的標頭資料
    ui->componentsListWidget->addItem(QString::fromStdString(Constants::GUIMainWindowParameter::COMPONENTS_LIST_WIDGET_HEADER));
    ui->groupsListWidget->addItem(QString::fromStdString(Constants::GUIMainWindowParameter::GROUPS_LIST_WIDGET_HEADER));

    //Register synchronous event(SINGAL & SLOT) to close MainWindow
    //by menubar
    QObject::connect(ui->actionExitByMenuBar,SIGNAL(triggered()),this,SLOT(close()));
    //by toolbutton
    QObject::connect(ui->actionExitByToolBar,SIGNAL(triggered()),this,SLOT(close()));

    //open FileDialog
    QObject::connect(ui->actionOpenByMenuBar,SIGNAL(triggered()),this,SLOT(OnOpenFileButtonClicked()));
    QObject::connect(ui->actionOpenFolderByToolBar,SIGNAL(triggered()),this,SLOT(OnOpenFileButtonClicked()));

    //save
    QObject::connect(ui->actionSaveByMenuBar,SIGNAL(triggered()),this,SLOT(OnSaveFileButtonClicked()));

    view->update();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//SLOT : When Click OpenFolder Action Control,it will have a slot OnOpenFileButtonClicked() and go here.
void MainWindow::OnOpenFileButtonClicked(){
    QDir fileDir(QDir::currentPath());
    fileDir.cd("../" + QString::fromStdString(Constants::GUIMainWindowParameter::XML_FILES_PATH));
    fileName = QFileDialog::getOpenFileName(this,tr("Open GMS XML File"),
                                            fileDir.path(),tr("XML Files (*.xml)"));
    //載入檔案
    int code = gms.LoadXMLFormatRecord(fileName.toLocal8Bit().constData());
    //有讀取成功
    if(code == XMLErrorCode::OK){
        //Components
        if(this->gms.GetComponents().GetAllComponent().size() > 0){
            stringstream ss;
            ui->componentsListWidget->clear();
            ui->componentsListWidget->addItem(QString::fromStdString(Constants::GUIMainWindowParameter::COMPONENTS_LIST_WIDGET_HEADER));
            vector<Component*> components = this->gms.GetComponents().GetAllComponent();
            for(vector<Component*>::iterator it = components.begin();it != components.end();it++){
                 //取得字串
                ss << (*it)->GetType()[0] << " , " << (*it)->GetID() << " , " << (*it)->GetName();
                ui->componentsListWidget->addItem(QString::fromStdString(ss.str()));
                //清空stringstream的資料
                ss.str(""); ss.flush();
            }
        }
        //Groups
        if(this->gms.GetGroups().GetAllGroups().size() >0){
            stringstream ss;
            ui->groupsListWidget->clear();
            ui->groupsListWidget->addItem(QString::fromStdString(Constants::GUIMainWindowParameter::GROUPS_LIST_WIDGET_HEADER));
            map<string,Group*> groups = this->gms.GetGroups().GetAllGroups();
            for(map<string,Group*>::iterator it = groups.begin();it != groups.end();it++){
                //取得字串
                ss << it->first.c_str() << " , " << (it->second)->GetName() << " , " << (it->second)->GetMembersIdByStringFormat();
                ui->groupsListWidget->addItem(QString::fromStdString(ss.str()));
                //清空stringstream的資料
                ss.str(""); ss.flush();
            }
        }

        //印出載入資料(GUI程式會在應用程式輸出畫面顯示)
        this->gms.OutputComponentsDataByConsole();
        this->gms.OutputGroupsDataByConsole();
    }

    //設定出示繪圖座標
    view->SetComponentsDrawPostion();
    view->SetGroupsDrawPostion();
    //更新畫面
    view->update();
}
//存檔案(尚未測試) 先保留
void MainWindow::OnSaveFileButtonClicked(){
    QDir fileDir(QDir::currentPath());
    fileDir.cd("../" + QString::fromStdString(Constants::GUIMainWindowParameter::XML_FILES_PATH));
    fileName = QFileDialog::getSaveFileName(this,tr("Open GMS XML File"),
                                            fileDir.path(),tr("XML Files (*.xml)"));
    gms.SaveXMLFormatRecord(fileName.toStdString());

}

