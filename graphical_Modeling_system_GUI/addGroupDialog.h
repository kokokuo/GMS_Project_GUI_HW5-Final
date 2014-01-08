#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>
#include <string>
#include <vector>
#include <QMessageBox>
#include "sstream"
#include "components.h"
using namespace std;

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = 0);
    ~AddGroupDialog();
    string GetGroupNameText();
    vector<int> GetAddMembersId();
    void SetComponents (Components components);
private:
    //判斷是否輸入GroupName
    void CheckIsInputGroupName(bool* IsInputGroupName);
    //處理輸入的成員資料ID是否存在該Component
    vector<int> HandleInputMembersIdIsExisted(string inputMemberStr,bool* IsComponentNotExisted);
    //處理輸入的成員字串資料格式是否正確
    string CheckInputMemberStrFormat(bool* IsInputFormatCorrect);
    //用來顯示輸入錯誤的訊息框
    void ShowInputErrorMessage(bool groupName,bool inputComponentFormatError,bool componentsNotExist,vector<int> notExistComponents);
    Ui::AddGroupDialog *ui;
    string groupName;
    vector<int> members;
    Components compareComponents;
private slots:
    void OnButtonAccepted();
};

#endif // ADDGROUPDIALOG_H
