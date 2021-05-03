#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "superviseurs.h"
#include "maisons.h"
#include "arduino.h"
#include "smtp.h"
#include "localisation.h"
#include <QtCore>
#include <QTextEdit>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QPainter>
#include <QIntValidator>
#include <QFileDialog>
#include <QSpinBox>
#include <QObject>
#include <QMetaObject>
#include <QGeoCoordinate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        ui->le_id->setValidator( new QIntValidator(0,9999999,this));
        ui->age->setValidator(new QIntValidator(0,9999999,this));
        ui->id_maison->setValidator( new QIntValidator(0,9999999,this));
        ui->nbr_chambre->setValidator(new QIntValidator(0,9999999,this));
        ui->tableView->setModel(S.afficher());
        ui->tableView_2->setModel(M.afficher_maison());
        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
            int ret=A.connect_arduino();
            switch(ret){
            case(0):qDebug() <<"arduino is available and connected to : "<< A.getarduino_port_name();
                break;
               case(1):qDebug() <<"arduino is available but not connected to :" <<A.getarduino_port_name();
                break;
            case(-1):qDebug() <<"arduino is not available";
            }
            QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
            /*textEdit = new QTextEdit;
                setCentralWidget(textEdit);

                localisation *source = new localisation(this);
                connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                        this, SLOT(positionUpdated(QGeoPositionInfo)));
                 source->startUpdates();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_superviseur_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_Nom->text();
    QString prenom=ui->le_Prenom->text();
    QString email=ui->le_Email->text();
    QString sexe=ui->Sexe_H->text();
    int age=ui->age->text().toInt();
  SUPERVISEURS S(id,nom,prenom,email,sexe,age);
  ui->tableView->setModel(S.afficher());


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
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_Nom->text();
    QString prenom=ui->le_Prenom->text();
    QString email=ui->le_Email->text();
    QString sexe=ui->Sexe_H->text();
    int age=ui->age->text().toInt();
  SUPERVISEURS S(id,nom,prenom,email,sexe,age);
  ui->tableView->setModel(S.afficher());


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
    int id=ui->id_maison->text().toInt();
    QString adresse=ui->adresse_maison->text();
    int nbr_chambre=ui->nbr_chambre->text().toInt();
  MAISONS M(id,adresse,nbr_chambre);
  ui->tableView_2->setModel(M.afficher_maison());


if(M.ajouter_maison())
    {
    ui->id_maison->setText("");
    ui->adresse_maison->setText("");
    ui->nbr_chambre->setText("");
    QMessageBox::information(nullptr, QObject::tr("Ajouter une maison"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
else
{
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une maison"),
                       QObject::tr("Erreur l'id existe deja!.\n"
                                   "Click Close to exit."), QMessageBox::Close);
}
}

void MainWindow::on_pb_modifier_maison_clicked()
{
    int id=ui->id_maison->text().toInt();
    QString adresse=ui->adresse_maison->text();
    int nbr_chambre=ui->nbr_chambre->text().toInt();
  MAISONS M(id,adresse,nbr_chambre);
  ui->tableView_2->setModel(M.afficher_maison());


if(M.modifier_maison(id))
    {
    ui->id_maison->text().toInt();
    ui->adresse_maison->text();
    ui->nbr_chambre->text().toInt();
    QMessageBox::information(nullptr, QObject::tr("Modifier une maison"),
                       QObject::tr("Ajout avec succès !.\n"
                                   "Click Close to exit."), QMessageBox::Close);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier une maison"),
                           QObject::tr("Erreur l'id existe deja!.\n"
                                       "Click Close to exit."), QMessageBox::Close);
    }
}
void MainWindow::on_pb_supprimer_maison_clicked()
{

     MAISONS M;
     M.setid(ui->id_supp_maison->text().toInt());
     bool test=M.supprimer_maison(M.getid());

     QMessageBox msgBox;
     if(test)
     {
         msgBox.setText("Suppression avec succes");
         ui->tableView_2->setModel(M.afficher_maison());
     }
     else
     {
         msgBox.setText("Echec de suppression");
     }
     msgBox.exec();
}

void MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void MainWindow::on_pb_activer_capteur_clicked()
{
    A.write_to_arduino("1"); // send 1 to arduino
    qDebug() << "Vous avez activé le capteur" ;
}

void MainWindow::on_pb_desactiver_capteur_clicked()
{
    A.write_to_arduino("0"); // send 0 to arduino
    qDebug() << "vous n'avait pas activé le capteur" ;
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();// lire les données de arduino
    if (data=="0")
    {
        ui->label_21->setText("Votre capteur est encore désactivé ");
    }
    else if (data=="1")
    {
        ui->label_21->setText("Votre capteur est correctement activé");
    }
    else if (data=="2")
    {
        qDebug() << " quelqu'un est proche , votre buzzer est en marche";
    }
    else if (data=="3")
    {
        qDebug() << " Il n'y a aucun , le buzzer est désactiver";
    }

}

/*void MainWindow::positionUpdated(const QGeoPositionInfo &info)
{
    textEdit->append(QString("Position updated: Date/time = %1, Coordinate = %2").arg(info.timestamp().toString()).arg(info.coordinate().toString()));
}*/
