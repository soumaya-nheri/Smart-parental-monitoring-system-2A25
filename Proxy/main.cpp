#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include "connexion.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("Fibers.qss");
    /*Connexion c;
    bool test=c.ouvrirConnexion();*/
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet=QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    MainWindow w;
    w.show();
    /*if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("connexion effectuée"),QMessageBox::Cancel);
    } else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("connexion echouee"),QMessageBox::Cancel);
    }*/
    return a.exec();
}
