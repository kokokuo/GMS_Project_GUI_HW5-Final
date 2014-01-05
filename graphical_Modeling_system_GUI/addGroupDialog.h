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
    void ShowInputErrorMessage(bool groupName,bool inputComponentFormatError,bool componentsNotExist,vector<int> notExistComponents);
    Ui::AddGroupDialog *ui;
    string groupName;
    vector<int> members;
    Components compareComponents;
private slots:
    void OnButtonAccepted();
};

#endif // ADDGROUPDIALOG_H
