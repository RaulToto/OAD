QT += core
QT -= gui

CONFIG += c++11

TARGET = HashTables
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    linkedlist.cpp

HEADERS += \
    linkedlist.h
