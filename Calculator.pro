#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T18:50:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calculator
TEMPLATE = app


SOURCES += \
    src/calculater/comstat.cpp \
    src/calculater/digitstat.cpp \
    src/calculater/estatue.cpp \
    src/calculater/evaluation.cpp \
    src/operation/addopreator.cpp \
    src/operation/divoperator.cpp \
    src/operation/muloperator.cpp \
    src/operation/operation.cpp \
    src/operation/operatorfactory.cpp \
    src/operation/suboperator.cpp \
    src/widget/calculator.cpp \
    src/main.cpp

HEADERS  += \
    src/calculater/comstat.h \
    src/calculater/digitstat.h \
    src/calculater/estatue.h \
    src/calculater/evaluation.h \
    src/operation/addopreator.h \
    src/operation/divoperator.h \
    src/operation/muloperator.h \
    src/operation/operation.h \
    src/operation/operatorfactory.h \
    src/operation/suboperator.h \
    src/widget/calculator.h
