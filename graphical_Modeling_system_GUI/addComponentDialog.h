#ifndef ADDCOMPONENTDIALOG_H
#define ADDCOMPONENTDIALOG_H

#include <QDialog>
#include <string>
#include <QMessageBox>
using namespace std;

namespace Ui {
class AddComponentDialog;
}

class AddComponentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentDialog(QWidget *parent = 0);
    ~AddComponentDialog();
    string GetInputText();
private slots:
    void OnButtonAccepted();

private:
    Ui::AddComponentDialog *ui;
    string componentName;


};

#endif // ADDCOMPONENTDIALOG_H
