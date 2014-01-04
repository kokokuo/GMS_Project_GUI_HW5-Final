/********************************************************************************
** Form generated from reading UI file 'editComponentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCOMPONENTDIALOG_H
#define UI_EDITCOMPONENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_EditComponentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *editNameTextEdit;
    QLabel *label_2;
    QComboBox *editTypeComboBox;
    QCheckBox *checkEditName;

    void setupUi(QDialog *EditComponentDialog)
    {
        if (EditComponentDialog->objectName().isEmpty())
            EditComponentDialog->setObjectName(QStringLiteral("EditComponentDialog"));
        EditComponentDialog->resize(400, 254);
        buttonBox = new QDialogButtonBox(EditComponentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 200, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(EditComponentDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 111, 16));
        editNameTextEdit = new QLineEdit(EditComponentDialog);
        editNameTextEdit->setObjectName(QStringLiteral("editNameTextEdit"));
        editNameTextEdit->setGeometry(QRect(20, 90, 341, 31));
        label_2 = new QLabel(EditComponentDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 111, 16));
        editTypeComboBox = new QComboBox(EditComponentDialog);
        editTypeComboBox->setObjectName(QStringLiteral("editTypeComboBox"));
        editTypeComboBox->setGeometry(QRect(20, 160, 80, 22));
        checkEditName = new QCheckBox(EditComponentDialog);
        checkEditName->setObjectName(QStringLiteral("checkEditName"));
        checkEditName->setGeometry(QRect(20, 30, 181, 21));
        checkEditName->setMaximumSize(QSize(16777215, 16777210));

        retranslateUi(EditComponentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditComponentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditComponentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditComponentDialog);
    } // setupUi

    void retranslateUi(QDialog *EditComponentDialog)
    {
        EditComponentDialog->setWindowTitle(QApplication::translate("EditComponentDialog", "Dialog", 0));
        label->setText(QApplication::translate("EditComponentDialog", "Enter Name:", 0));
        label_2->setText(QApplication::translate("EditComponentDialog", "EditType:", 0));
        checkEditName->setText(QApplication::translate("EditComponentDialog", "Want To Edit Name?", 0));
    } // retranslateUi

};

namespace Ui {
    class EditComponentDialog: public Ui_EditComponentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCOMPONENTDIALOG_H
