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
        ui->idsite->clear();
        ui->typesite->clear() ;
        ui->nomsite->clear() ;
        ui->adresssite->clear() ;
        ui->tablesites->setModel(tmpsite.affichersites());
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
        ui->tablesites->setModel(tmpsite.affichersites());
        ui->lineEdit_susite->clear();
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                                "Click Cancel to exit." ), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppréssion non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &arg1)
{
    int filtre=1;
    if (ui->radioButton->isChecked())
        filtre=1;
    else if (ui->radioButton_2->isChecked())
        filtre=2;
    else if (ui->radioButton_3->isChecked())
        filtre=3;
    ui->tablesites->setModel(tmpsite.recherchesite(arg1,filtre));
}

void MainWindow::on_radioButton_2_pressed()
{
    QString s=ui->lineEdit_recherche->text();
    ui->tablesites->setModel(tmpsite.recherchesite(s,2));
}

void MainWindow::on_radioButton_pressed()
{
    QString s=ui->lineEdit_recherche->text();
    ui->tablesites->setModel(tmpsite.recherchesite(s,1));
}

void MainWindow::on_radioButton_3_pressed()
{
    QString s=ui->lineEdit_recherche->text();
    ui->tablesites->setModel(tmpsite.recherchesite(s,3));
}

void MainWindow::on_modifiersite_clicked()
{


            int id=ui->lineEdit_modifiersite->text().toInt();
            QString nom=ui->lineEditnewname->text();
            QString type=ui->lineEditnewtype->text();
            QString adresse=ui->lineEditnewadr->text();


            sites S(id,nom,type,adresse);
            bool test = S.modifiersite(id);

            if (test){
                ui->tablesites->setModel(tmpsite.affichersites());


                QMessageBox::information(nullptr,QObject::tr("OK"),
                                         QObject::tr("Modification effectué\n"
        "Click Cancel to exit"),QMessageBox::Cancel);

                ui->lineEdit_modifiersite->clear();
                ui->lineEditnewname->clear();
                ui->lineEditnewadr->clear();
                ui->lineEditnewtype->clear();


            }
            else
                QMessageBox::critical(nullptr,QObject::tr("Not OK"), QObject::tr("Modification non effectué.\n" "Clic Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->table->setModel(tmpapp.afficher());
}
