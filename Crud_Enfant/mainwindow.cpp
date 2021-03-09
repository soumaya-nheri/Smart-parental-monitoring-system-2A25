#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enfant.h"
#include <QString>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QIntValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_id->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_enfant->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_bt_ajouter_clicked()
{
    int id=ui->line_id->text().toInt();
    QString nom=ui->line_nom->text();
    QString prenom=ui->line_prenom->text();
    int age=ui->line_age->text().toInt();
    Enfant E(id,nom,prenom,age);


    if(E.ajouter())
        {
        ui->line_id->setText("");
        ui->line_nom->setText("");
        ui->line_prenom->setText("");
        ui->line_age->setText("");

        QMessageBox::information(nullptr, QObject::tr("Ajouter un enfant"),
                           QObject::tr("Ajout avec succès !.\n"
                                       "Click Close to exit."), QMessageBox::Close);

        //mettre à jour mon affichage après ajout:
        ui->tab_enfant->setModel(E.afficher());


        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Ajouter un enfant"),
                               QObject::tr("Erreur l'id existe deja!.\n"
                                           "Click Close to exit."), QMessageBox::Close);
        }
}



void MainWindow::on_bt_supprimer_clicked()
{

  Enfant E1;
  E1.set_id(ui->id_supp->text().toInt());
  bool test=E1.supprimer(E1.get_id());

  QMessageBox msgBox;

  if(test)
  {
      msgBox.setText("Suppression avec succès.");


      //Mettre à jour mon affichage après suppression:
      ui->tab_enfant->setModel(E.afficher());

      }
else
  {
     msgBox.setText("Echec de la suppression!");
  }

    msgBox.exec();

}
