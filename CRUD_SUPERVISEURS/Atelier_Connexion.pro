QT       += core gui network
QT       += sql
QT       += serialport
QT += positioning core widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG   += console
TARGET = Atelier_Connexion
TEMPLATE = app
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    localisation.cpp \
    main.cpp \
    mainwindow.cpp \
    maisons.cpp \
    smtp.cpp \
    superviseurs.cpp

HEADERS += \
    arduino.h \
    connection.h \
    localisation.h \
    mainwindow.h \
    maisons.h \
    smtp.h \
    superviseurs.h


FORMS += \
    mainwindow.ui




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    simplelog.txt

RESOURCES +=
    target.path = $$[QT_INSTALL_EXAMPLES]/positioning/localisation
    INSTALLS += target
