#-------------------------------------------------
#
# Project created by QtCreator 2014-05-14T07:43:14
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = QMLServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    qmlserver.cpp \
    connection.cpp \
    theaplication.cpp \
    messagehandler.cpp

HEADERS += \
    qmlserver.h \
    connection.h \
    theaplication.h \
    messagehandler.h
