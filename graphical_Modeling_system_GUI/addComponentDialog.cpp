#include "addComponentDialog.h"
#include "ui_addComponentDialog.h"

AddComponentDialog::AddComponentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComponentDialog)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(OnButtonAccepted()));
    QObject::connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
}

AddComponentDialog::~AddComponentDialog()
{
    delete ui;
}
string AddComponentDialog::GetInputText(){
    return componentName;
}
void AddComponentDialog::OnButtonAccepted(){
    if(!ui->componentNameTextEdit->toPlainText().isEmpty()){
        string temp = ui->componentNameTextEdit->toPlainText().toStdString();
        temp.erase(remove(temp.begin(),temp.end(),' '),temp.end()); //清除不必要的空白
        if(temp.size() >0){
            componentName = ui->componentNameTextEdit->toPlainText().toStdString();
        }
        else{
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warning");
            msgBox.setText("You don't input component Name");
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();

        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setWindowTitle("Warning");
        msgBox.setText("You don't input component Name");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

}
