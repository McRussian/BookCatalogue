QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tst_testbasemodels.cpp \
    tst_testtools.cpp \
    tst_testbasefields.cpp
