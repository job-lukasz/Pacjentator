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
    ORM/cellparameters.cpp \
    ORM/dbconfig.cpp \
    ORM/dbmodel.cpp \
    ORM/DatabaseController/databaseconnector.cpp \
    ORM/idbcell.cpp \
    ORM/idbtable.cpp \
    ORM/dbdatatypes.cpp

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
    ORM/dbcell.hpp \
    ORM/dbconfig.h \
    ORM/DatabaseController/databaseconnector.h \
    ORM/dbmodel.h \
    ORM/idbrepositories.h \
    ORM/idbtable.h \
    ORM/dbcellparameters.h \
    ORM/idbcell.h \
    ORM/dbdatatypes.h


FORMS    += pacjentator.ui \
    addpatientform.ui

DISTFILES +=

RESOURCES += \
    icons.qrc
