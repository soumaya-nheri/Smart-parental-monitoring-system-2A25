QT       += core gui network
QT       += sql
QT       += serialport
CONFIG   += console


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../../SmtpClient-for-Qt-1.1/src/emailaddress.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimeattachment.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimecontentformatter.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimefile.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimehtml.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimeinlinefile.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimemessage.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimemultipart.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimepart.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/mimetext.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/quotedprintable.cpp \
    ../../../SmtpClient-for-Qt-1.1/src/smtpclient.cpp \
    arduino.cpp \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    maisons.cpp \
    mimehtml.cpp \
    mimeinlinefile.cpp \
    mimemessage.cpp \
    mimemultipart.cpp \
    mimepart.cpp \
    mimetext.cpp \
    quotedprintable.cpp \
    superviseurs.cpp

HEADERS += \
    ../../../SmtpClient-for-Qt-1.1/src/SmtpMime \
    ../../../SmtpClient-for-Qt-1.1/src/emailaddress.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimeattachment.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimecontentformatter.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimefile.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimehtml.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimeinlinefile.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimemessage.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimemultipart.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimepart.h \
    ../../../SmtpClient-for-Qt-1.1/src/mimetext.h \
    ../../../SmtpClient-for-Qt-1.1/src/quotedprintable.h \
    ../../../SmtpClient-for-Qt-1.1/src/smtpclient.h \
    ../../../SmtpClient-for-Qt-1.1/src/smtpexports.h \
    SmtpMime \
    arduino.h \
    connection.h \
    mainwindow.h \
    maisons.h \
    mimefile.h \
    mimehtml.h \
    mimeinlinefile.h \
    mimemessage.h \
    mimemultipart.h \
    mimepart.h \
    mimetext.h \
    quotedprintable.h \
    smtpexports.h \
    superviseurs.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
