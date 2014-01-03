#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <map>
#include <vector>
#include "gmsModel.h"
#include "gms.h"
#include "xmlErrorCode.h"
#include "drawView.h"
#include "string"
#include "constants.h"
#include <string>
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

    Ui::MainWindow *ui;
    //fileName
    QString fileName;
    GMS gms;
    DrawView* view;
private slots:
    //When Click OpenFolder Action Control,it will have a slot OnOpenFileButtonClicked() and go here.
    void OnOpenFileButtonClicked();
    void OnSaveFileButtonClicked();
};

#endif // MAINWINDOW_H
