/********************************************************************************
** Form generated from reading UI file 'addComponentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPONENTDIALOG_H
#define UI_ADDCOMPONENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddComponentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *componentNameTextEdit;

    void setupUi(QDialog *AddComponentDialog)
    {
        if (AddComponentDialog->objectName().isEmpty())
            AddComponentDialog->setObjectName(QStringLiteral("AddComponentDialog"));
        AddComponentDialog->resize(400, 193);
        buttonBox = new QDialogButtonBox(AddComponentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddComponentDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 111, 16));
        componentNameTextEdit = new QLineEdit(AddComponentDialog);
        componentNameTextEdit->setObjectName(QStringLiteral("componentNameTextEdit"));
        componentNameTextEdit->setGeometry(QRect(20, 60, 341, 31));

        retranslateUi(AddComponentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddComponentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddComponentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddComponentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddComponentDialog)
    {
        AddComponentDialog->setWindowTitle(QApplication::translate("AddComponentDialog", "Input Component Name", 0));
        label->setText(QApplication::translate("AddComponentDialog", "Enter Name:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddComponentDialog: public Ui_AddComponentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPONENTDIALOG_H
