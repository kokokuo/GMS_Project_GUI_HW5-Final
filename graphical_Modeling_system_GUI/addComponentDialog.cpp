#include "addComponentDialog.h"
#include "ui_addComponentDialog.h"

AddComponentDialog::AddComponentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComponentDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowCloseButtonHint); //顯示只要關閉的按鈕在右上角即可,如此可以移除問號
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
    if(!ui->componentNameTextEdit->text().isEmpty()){
        string temp = ui->componentNameTextEdit->text().toStdString();
        temp.erase(remove(temp.begin(),temp.end(),' '),temp.end()); //清除不必要的空白
        if(temp.size() >0){
            componentName = ui->componentNameTextEdit->text().toStdString();
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
