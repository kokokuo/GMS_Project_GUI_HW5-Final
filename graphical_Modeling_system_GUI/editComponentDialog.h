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
    string GetInputNameText();
    string GetTypeText();
private:
    Ui::EditComponentDialog *ui;
    string componentName;
    string type;
private slots:
    void OnButtonAccepted();
    void OnSelectEditName();
};

#endif // EDITCOMPONENTDIALOG_H
