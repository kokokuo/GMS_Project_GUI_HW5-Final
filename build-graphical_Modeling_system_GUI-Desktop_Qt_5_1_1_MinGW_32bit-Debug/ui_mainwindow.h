/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenByMenuBar;
    QAction *actionExitByMenuBar;
    QAction *actionOpenFolderByToolBar;
    QAction *actionExitByToolBar;
    QAction *actionAdd_Group;
    QAction *actionRedo;
    QAction *actionUndo;
    QAction *actionCube;
    QAction *actionPyramid;
    QAction *actionSphere;
    QAction *actionLine;
    QAction *actionSaveByMenuBar;
    QWidget *centralWidget;
    QScrollArea *drawViewScrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *groupsListWidget;
    QListWidget *componentsListWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAdd_Component;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionOpenByMenuBar = new QAction(MainWindow);
        actionOpenByMenuBar->setObjectName(QStringLiteral("actionOpenByMenuBar"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/toolButton_images/asset images/folder_open_48px.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpenByMenuBar->setIcon(icon);
        actionExitByMenuBar = new QAction(MainWindow);
        actionExitByMenuBar->setObjectName(QStringLiteral("actionExitByMenuBar"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/toolButton_images/asset images/exit_48px.png"), QSize(), QIcon::Normal, QIcon::On);
        actionExitByMenuBar->setIcon(icon1);
        actionOpenFolderByToolBar = new QAction(MainWindow);
        actionOpenFolderByToolBar->setObjectName(QStringLiteral("actionOpenFolderByToolBar"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/toolButton_images/asset images/folder_open_48px.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFolderByToolBar->setIcon(icon2);
        actionExitByToolBar = new QAction(MainWindow);
        actionExitByToolBar->setObjectName(QStringLiteral("actionExitByToolBar"));
        actionExitByToolBar->setIcon(icon1);
        actionAdd_Group = new QAction(MainWindow);
        actionAdd_Group->setObjectName(QStringLiteral("actionAdd_Group"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionCube = new QAction(MainWindow);
        actionCube->setObjectName(QStringLiteral("actionCube"));
        actionPyramid = new QAction(MainWindow);
        actionPyramid->setObjectName(QStringLiteral("actionPyramid"));
        actionSphere = new QAction(MainWindow);
        actionSphere->setObjectName(QStringLiteral("actionSphere"));
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QStringLiteral("actionLine"));
        actionSaveByMenuBar = new QAction(MainWindow);
        actionSaveByMenuBar->setObjectName(QStringLiteral("actionSaveByMenuBar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        drawViewScrollArea = new QScrollArea(centralWidget);
        drawViewScrollArea->setObjectName(QStringLiteral("drawViewScrollArea"));
        drawViewScrollArea->setGeometry(QRect(10, 10, 711, 661));
        drawViewScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 659));
        drawViewScrollArea->setWidget(scrollAreaWidgetContents);
        groupsListWidget = new QListWidget(centralWidget);
        groupsListWidget->setObjectName(QStringLiteral("groupsListWidget"));
        groupsListWidget->setGeometry(QRect(740, 10, 251, 281));
        componentsListWidget = new QListWidget(centralWidget);
        componentsListWidget->setObjectName(QStringLiteral("componentsListWidget"));
        componentsListWidget->setGeometry(QRect(740, 330, 256, 281));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAdd_Component = new QMenu(menuEdit);
        menuAdd_Component->setObjectName(QStringLiteral("menuAdd_Component"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionOpenByMenuBar);
        menuFile->addAction(actionSaveByMenuBar);
        menuFile->addAction(actionExitByMenuBar);
        menuEdit->addAction(menuAdd_Component->menuAction());
        menuEdit->addAction(actionAdd_Group);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionUndo);
        menuAdd_Component->addAction(actionCube);
        menuAdd_Component->addAction(actionPyramid);
        menuAdd_Component->addAction(actionSphere);
        menuAdd_Component->addAction(actionLine);
        mainToolBar->addAction(actionOpenFolderByToolBar);
        mainToolBar->addAction(actionExitByToolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpenByMenuBar->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExitByMenuBar->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionOpenFolderByToolBar->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExitByToolBar->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionAdd_Group->setText(QApplication::translate("MainWindow", "Add Group", 0));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        actionCube->setText(QApplication::translate("MainWindow", "Cube", 0));
        actionPyramid->setText(QApplication::translate("MainWindow", "Pyramid", 0));
        actionSphere->setText(QApplication::translate("MainWindow", "Sphere", 0));
        actionLine->setText(QApplication::translate("MainWindow", "Line", 0));
        actionSaveByMenuBar->setText(QApplication::translate("MainWindow", "Save", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuAdd_Component->setTitle(QApplication::translate("MainWindow", "Add Component", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
