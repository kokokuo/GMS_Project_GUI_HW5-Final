#include "editComponentDialog.h"
#include "ui_editComponentDialog.h"

EditComponentDialog::EditComponentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditComponentDialog)
{
    ui->setupUi(this);
    componentName = "";
    ui->editNameTextEdit->setEnabled(false); //預設沒有打開
    ui->editTypeComboBox->addItem("Not Edit");
    this->type = "Not Edit";
    ui->editTypeComboBox->addItem(QString::fromStdString(Constants::ComponentType::CubeTypeString));
    ui->editTypeComboBox->addItem(QString::fromStdString(Constants::ComponentType::PyramidTypeString));
    ui->editTypeComboBox->addItem(QString::fromStdString(Constants::ComponentType::SphereTypeString));
    ui->editTypeComboBox->addItem(QString::fromStdString(Constants::ComponentType::LineTypeString));
    ui->editTypeComboBox->setCurrentIndex(0); //預設沒有選

    this->setWindowFlags(Qt::WindowCloseButtonHint); //顯示只要關閉的按鈕在右上角即可,如此可以移除問號
    QObject::connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(OnButtonAccepted()));
    QObject::connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
    QObject::connect(ui->checkEditName,SIGNAL(clicked()),this,SLOT(OnSelectEditName()));
}

EditComponentDialog::~EditComponentDialog()
{
    delete ui;
}


string EditComponentDialog::GetInputNameText(){
    return this->componentName;
}
string EditComponentDialog::GetTypeText(){
    return this->type;
}
void EditComponentDialog::OnButtonAccepted(){

    if(ui->editNameTextEdit->isEnabled() && !ui->editNameTextEdit->text().isEmpty()){
        string temp = ui->editNameTextEdit->text().toStdString();
        temp.erase(remove(temp.begin(),temp.end(),' '),temp.end()); //清除不必要的空白
        if(temp.size() >0){
            componentName = ui->editNameTextEdit->text().toStdString();
        }

    }
    this->type = ui->editTypeComboBox->currentText().toStdString();

}
void EditComponentDialog::OnSelectEditName(){
    if(ui->checkEditName->isChecked()){
        ui->editNameTextEdit->setEnabled(true);
    }
    else{
        ui->editNameTextEdit->setEnabled(false);
    }
}