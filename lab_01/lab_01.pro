QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/undoredo
INCLUDEPATH += $$PWD/model
INCLUDEPATH += $$PWD/view

SOURCES += \
    controller/action_handler.cpp \
    controller/drawer.cpp \
    controller/messager.cpp \
    main.cpp \
    mainwindow.cpp \
    model/bounding_cube.cpp \
    model/figure.cpp \
    model/point.cpp \
    model/point_link.cpp \
    undoredo/stask.cpp \
    undoredo/staskpool.cpp \
    view/figure_item.cpp

HEADERS += \
    controller/action_handler.h \
    controller/drawer.h \
    controller/messager.h \
    mainwindow.h \
    model/bounding_cube.h \
    model/figure.h \
    model/point.h \
    model/point_link.h \
    undoredo/stask.h \
    undoredo/staskpool.h \
    view/figure_item.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    stylesheet.qss

RESOURCES +=
