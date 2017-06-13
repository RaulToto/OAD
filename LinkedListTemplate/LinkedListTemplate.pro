QT += core
QT -= gui

CONFIG += c++11

TARGET = LinkedListTemplate
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    node.h \
    linkedlist.h
