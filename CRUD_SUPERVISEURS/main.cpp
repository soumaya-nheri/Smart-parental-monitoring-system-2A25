#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createConnection();
    MainWindow w;

    //bonjour tortoise

    if(test){

        w.show();
        QMessageBox::information(nullptr, QObject::tr("database to open"),
                                 QObject::tr("Connected Successfully!\n"
                                              "Click Ok to exit"), QMessageBox::Ok);
        //qDebug()<<"Connection réussite"; // la première méthode pour tester si la connection est réussite via qDebug
        //w.show();
    }

    else

        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                 QObject::tr("Failed To Connect!\n"
                                              "Click Cancel to exit"), QMessageBox::Cancel);

        //qDebug()<<"Erreur de connection";


    return a.exec();
}
