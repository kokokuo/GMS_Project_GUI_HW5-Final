#-------------------------------------------------
#
# Project created by QtCreator 2013-12-27T18:04:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphical_Modeling_system_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    xmlManager.cpp \
    xmlErrorCode.cpp \
    groups.cpp \
    group.cpp \
    gmsModel.cpp \
    components.cpp \
    component.cpp \
    drawView.cpp \
    commandManager.cpp \
    command.cpp \
    addMembersToGroupCommand.cpp \
    editComponentNameCommand.cpp \
    editComponentTypeCommand.cpp \
    addComponentCommand.cpp \
    deleteComponentCommand.cpp \
    addNewGroupCommand.cpp \
    gms.cpp


HEADERS  += mainwindow.h \
    xmlManager.h \
    xmlErrorCode.h \
    groups.h \
    group.h \
    gmsModel.h \
    components.h \
    component.h \
    drawView.h \
    command.h \
    addComponentCommand.h \
    addMembersToGroupCommand.h \
    addNewGroupCommand.h \
    deleteComponentCommand.h \
    editComponentNameCommand.h \
    editComponentTypeCommand.h \
    gms.h


FORMS    += mainwindow.ui

RESOURCES += \
    asset.qrc
