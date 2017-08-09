QT += core
QT -= gui

CONFIG += c++11

TARGET = Exceptions
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    exceptionsum.h \
    exceptionintlegal.h \
    range.h
