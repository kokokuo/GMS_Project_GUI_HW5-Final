#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <map>
#include <vector>
#include <string>
#include "gmsModel.h"
#include "gms.h"
#include "xmlErrorCode.h"
#include "drawView.h"
#include "addComponentDialog.h"
#include "constants.h"
#include "component.h"
#include "group.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
     //更新Component顯示在ListWidget上的資料
    void UpdateComponentListWidget(vector<Component*> componentList);
     //更新Group顯示在ListWidget上的資料
    void UpdateGroupListWidget(map<string, Group *> groupList);
    Ui::MainWindow *ui;
    //fileName
    QString fileName;
    GMS gms;
    DrawView* view;
private slots:
    //When Click OpenFolder Action Control,it will have a slot OnOpenFileButtonClicked() and go here.
    void OnOpenFileButtonClicked();
    void OnSaveFileButtonClicked();
    //Add Component
    void OnAddCubeComponentClicked();
    void OnAddPyramidComponentClicked();
    void OnAddSphereComponentClicked();
    void OnAddLineComponentClicked();
    //Redo Undo
    void OnRedoClicked();
    void OnUndoClicked();
};

#endif // MAINWINDOW_H
