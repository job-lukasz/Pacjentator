#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T17:35:56
#
#-------------------------------------------------

QT       += core gui sql

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacjentator
TEMPLATE = app


SOURCES += main.cpp\
    helpers/calendar.cpp \
    model/repositories/pacjentmedicinerepository.cpp \
    view/colorTriangle/colorpickerwidget.cpp \
    view/colorTriangle/colorviewer.cpp \
    view/colorTriangle/qtcolortriangle.cpp \
    view/helpers/spanholder.cpp \
    view/helpers/tabledecorer.cpp \
    model/pacjentmedicine.cpp \
    model/helpers/rowcolorer.cpp \
    controller/pacjentatorcontroller.cpp \
    view/addpatientform.cpp \
    view/pacjentator.cpp \
    model/QPatientModel.cpp \
    model/helpers/QMedicineItem.cpp \
    DatabaseController/databaseconnector.cpp \
    DatabaseController/databaseresult.cpp \
    DatabaseController/databaserow.cpp \
    DatabaseController/databasecell.cpp \
    ORM/databasemodel.cpp \
    ORM/cellparameters.cpp \
    ORM/dbtable.cpp \
    ORM/repositories.cpp

HEADERS  += helpers/calendar.h \
    model/repositories/pacjentmedicinerepository.h \
    view/colorTriangle/colorpickerwidget.h \
    view/colorTriangle/colorviewer.h \
    view/colorTriangle/qtcolortriangle.h \
    view/helpers/spanholder.h \
    view/helpers/tabledecorer.h \
    model/pacjentmedicine.h \
    model/helpers/rowcolorer.h \
    controller/pacjentatorcontroller.h \
    view/addpatientform.h \
    view/pacjentator.h \
    model/QPatientModel.h \
    model/helpers/QMedicineItem.h \
    DatabaseController/databaseconnector.h \
    DatabaseController/databaseresult.h \
    DatabaseController/databaserow.h \
    DatabaseController/databasecell.h \
    ORM/dbcell.hpp \
    ORM/databasemodel.h \
    ORM/cellparameters.h \
    ORM/dbinicjalizator.hpp \
    ORM/dbtable.h \
    ORM/repositories.h

FORMS    += pacjentator.ui \
    addpatientform.ui

DISTFILES +=

RESOURCES += \
    icons.qrc
