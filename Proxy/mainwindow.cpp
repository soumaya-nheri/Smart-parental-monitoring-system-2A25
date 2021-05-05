#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appareil.h"
#include "deletebox.h"
#include "verif.h"
#include <QMessageBox>
#include "modification.h"
#include "sites.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setModel(tmpapp.afficher());
    ui->tablesites->setModel(tmpsite.affichersites());
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::updatetable(){
    ui->table->setModel(tmpapp.afficher());
}


void MainWindow::on_Button_Ajouter_clicked()
{
    Appareil a;

    int id=ui->lineEdit_nomappareil->text().toInt();
    QString type=ui->lineEdit_typeappareil->text() ;
    int num=ui->lineEdit_numappareil->text().toInt();
    QString owner=ui->lineEdit_proprio->text() ;

    a= Appareil(id,owner,type,num);
    bool test=a.ajouterappareil();
    if (test) {
        ui->table->setModel(tmpapp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("ajout effectué"),QMessageBox::Cancel);
    } else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("ajout non effectué"),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_clicked()
{
    verif v;

    v.update();
    v.exec();
}

void MainWindow::on_pushButton_9_clicked()
{
   /* Dialog d;
    d.exec();*/
}

void MainWindow::on_suppression_clicked()
{
    DeleteBox d;
    ui->table->setModel(tmpapp.afficher());
    d.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    modification d;
    ui->table->setModel(tmpapp.afficher());
    d.exec();
}



void MainWindow::on_ajoutersitebuton_clicked()
{
    sites a;

    int id=ui->idsite->text().toInt();
    QString type=ui->typesite->text() ;
    QString name=ui->nomsite->text() ;
    QString adress=ui->adresssite->text() ;

    a= sites(id,name,type,adress);
    bool test=a.ajoutersite();
    if (test) {
        ui->table->setModel(tmpapp.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),QObject::tr("ajout effectué"),QMessageBox::Cancel);
    } else
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),QObject::tr("ajout non effectué"),QMessageBox::Cancel);
    }
}



void MainWindow::on_suppsite_clicked()
{
    int i=ui->lineEdit_susite->text().toInt();
    bool testsupp2 = tmpsite.supprimersite(i);
    if (testsupp2){

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                                "Click Cancel to exit." ), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppréssion non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
