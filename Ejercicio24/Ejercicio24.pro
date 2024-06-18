QT += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = YourApplicationName
TEMPLATE = app

HEADERS += \
    mainwindow.h \
    parser.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    parser.cpp
