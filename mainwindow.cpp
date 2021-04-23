#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "superviseurs.h"
#include "maisons.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QTextDocument>
#include <QDebug>
#include <QPainter>
#include <QIntValidator>
#include <QFileDialog>
#include <QSpinBox>
#include <QMetaObject>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->le_id->setValidator( new QIntValidator(0,9999999,this));
    ui->tableView->setModel(S.afficher());
    ui->tableView_2->setModel(M.afficher_maison());
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_ajouter_superviseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_Nom->text();
    QString prenom=ui->le_Prenom->text();
    QString email=ui->le_Email->text();
    QString sexe=ui->Sexe_H->text();
    int age=ui->age->text().toInt();
  SUPERVISEURS S(id,nom,prenom,email,sexe,age);


if(S.ajouter())
    {
    ui->le_id->setText("");
    ui->le_Nom->setText("");
    ui->le_Prenom->setText("");
    ui->le_Email->setText("");
    ui->Sexe_H->setText("");
    ui->age->setText("");
    QMessageBox::information(nullptr, QObject::tr("Ajouter un superviseur"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un superviseur"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
}

void MainWindow::on_pb_modifier_superviseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_Nom->text();
    QString prenom=ui->le_Prenom->text();
    QString email=ui->le_Email->text();
    QString sexe=ui->Sexe_H->text();
    int age=ui->age->text().toInt();
  SUPERVISEURS S(id,nom,prenom,email,sexe,age);


if(S.modifier(id))
    {
    ui->le_id->setText("");
    ui->le_Nom->setText("");
    ui->le_Prenom->setText("");
    ui->le_Email->setText("");
    ui->Sexe_H->setText("");
    ui->age->setText("");
    QMessageBox::information(nullptr, QObject::tr("Modifier un superviseur"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un superviseur"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
}


void MainWindow::on_pb_supprimer_superviseur_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     SUPERVISEURS S1;
     S1.setid(ui->id_supp_superviseur->text().toInt());
     bool test=S1.supprimer(S1.getid());

     QMessageBox msgBox;
     if(test)
     {
         msgBox.setText("Suppression avec succes");
         ui->tableView->setModel(S.afficher());
     }
     else
     {
         msgBox.setText("Echec de suppression");
     }
     msgBox.exec();
}

void MainWindow::on_pb_ajouter_maison_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    int id=ui->id_maison->text().toInt();
    QString adresse=ui->adresse_maison->text();
    int nbr_chambre=ui->nbr_chambre->text().toInt();
  MAISONS M(id,adresse,nbr_chambre);


if(M.ajouter_maison())
    {
    ui->id_maison->setText("");
    ui->adresse_maison->setText("");
    ui->nbr_chambre->setText("");
    QMessageBox::information(nullptr, QObject::tr("Ajouter un superviseur"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
}

void MainWindow::on_pb_modifier_maison_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    int id=ui->id_maison->text().toInt();
    QString adresse=ui->adresse_maison->text();
    int nbr_chambre=ui->nbr_chambre->text().toInt();
  MAISONS M(id,adresse,nbr_chambre);


if(M.modifier_maison(id))
    {
    ui->id_maison->text().toInt();
    ui->adresse_maison->text();
    ui->nbr_chambre->text().toInt();
    QMessageBox::information(nullptr, QObject::tr("Modifier un maison"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un maison"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
}
void MainWindow::on_pb_supprimer_maison_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
     MAISONS M1;
     M1.setid(ui->id_supp_maison->text().toInt());
     bool test=M1.supprimer_maison(M1.getid());

     QMessageBox msgBox;
     if(test)
     {
         msgBox.setText("Suppression avec succes");
         ui->tableView_2->setModel(M1.afficher_maison());
     }
     else
     {
         msgBox.setText("Echec de suppression");
     }
     msgBox.exec();
}
