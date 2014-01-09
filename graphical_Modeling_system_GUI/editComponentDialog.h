#ifndef EDITCOMPONENTDIALOG_H
#define EDITCOMPONENTDIALOG_H

#include <QDialog>
#include "constants.h"
#include <string>
#include <QMessageBox>
namespace Ui {
class EditComponentDialog;
}

class EditComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditComponentDialog(QWidget *parent = 0);
    ~EditComponentDialog();
    string GetInputNameText(); //取得元件名稱
    string GetTypeText(); //取得元件類型
private:
    Ui::EditComponentDialog *ui;
    string componentName; //元件名稱
    string type; //元件類型
private slots:
    void OnButtonAccepted(); //按下確定編輯的按鈕
    void OnSelectEditName(); //選擇CheckBox中的編輯類型
};

#endif // EDITCOMPONENTDIALOG_H
