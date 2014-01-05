/********************************************************************************
** Form generated from reading UI file 'addGroupDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPDIALOG_H
#define UI_ADDGROUPDIALOG_H

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

class Ui_AddGroupDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *addGroupNameTextEdit;
    QLabel *label_2;
    QLineEdit *addMemberTextEdit;

    void setupUi(QDialog *AddGroupDialog)
    {
        if (AddGroupDialog->objectName().isEmpty())
            AddGroupDialog->setObjectName(QStringLiteral("AddGroupDialog"));
        AddGroupDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddGroupDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(AddGroupDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 111, 16));
        addGroupNameTextEdit = new QLineEdit(AddGroupDialog);
        addGroupNameTextEdit->setObjectName(QStringLiteral("addGroupNameTextEdit"));
        addGroupNameTextEdit->setGeometry(QRect(20, 70, 341, 31));
        label_2 = new QLabel(AddGroupDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 111, 16));
        addMemberTextEdit = new QLineEdit(AddGroupDialog);
        addMemberTextEdit->setObjectName(QStringLiteral("addMemberTextEdit"));
        addMemberTextEdit->setGeometry(QRect(20, 160, 341, 31));

        retranslateUi(AddGroupDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddGroupDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddGroupDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupDialog)
    {
        AddGroupDialog->setWindowTitle(QApplication::translate("AddGroupDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddGroupDialog", "Enter Name:", 0));
        label_2->setText(QApplication::translate("AddGroupDialog", "Enter Member:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddGroupDialog: public Ui_AddGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPDIALOG_H
