QT       += core gui printsupport
QT       +=sql
CONFIG   +=console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chambre.cpp \
    connexion.cpp \
    lampe.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chambre.h \
    connexion.h \
    lampe.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMG.qrc

DISTFILES += \
    image/acceuil.png \
    image/acceuilpr.png \
    image/ajbtn.png \
    image/ajbtnp.png \
    image/ajout.png \
    image/ajoutabs.png \
    image/ajoutlvr.png \
    image/ajoutlvs.png \
    image/annbtn.png \
    image/annbtnp.png \
    image/back.png \
    image/backing.png \
    image/bouton_ajouter-un-profil.png \
    image/bouton_modifier-un-profil.png \
    image/bouton_supprimer-un-profil.png \
    image/btnliv.png \
    image/btnlivpr.png \
    image/btnlivrpr.png \
    image/btnlvr.png \
    image/cherchbtn.png \
    image/cherchbtnpr.png \
    image/exit.png \
    image/exit1.png \
    image/gg.png \
    image/ggabs.png \
    image/modabs.png \
    image/modifbtn.png \
    image/modifbtndia.png \
    image/modifbtnpr.png \
    image/modiflvbtnpr.png \
    image/motabs.png \
    image/motpr.png \
    image/print.png \
    image/reload.png \
    image/rpl.png \
    image/suppabs.png \
    image/suppbtn.png \
    image/suppbtnlvpr.png \
    image/suppbtnpr.png \
    image/title.png \
    image/titlepr.png \
    image/triup.png \
    image/unnamed.png
