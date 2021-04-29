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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
        ui->le_id->setValidator( new QIntValidator(0,9999999,this));
        ui->tableView->setModel(S.afficher());
        ui->tableView_2->setModel(M.afficher_maison());
        ui->setupUi(this);
        connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
        connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
        ui->setupUi(this);
            int ret=A.connect_arduino();
            switch(ret){
            case(0):qDebug() <<"arduino is available and connected to : "<< A.getarduino_port_name();
                break;
               case(1):qDebug() <<"arduino is available but not connected to :" <<A.getarduino_port_name();
                break;
            case(-1):qDebug() <<"arduino is not available";
            }
            QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
            textEdit = new QTextEdit;
                setCentralWidget(textEdit);

                localisation *source = new localisation(this);
                connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                        this, SLOT(positionUpdated(QGeoPositionInfo)));
                 source->startUpdates();
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

void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if(data=="1")
        ui->label_3->setText("ON");// si les donnees de arduino via la liaison serie sont egales à 1
    // alors afficher ON
    else if (data=="0")
        ui->label_3->setText("OFF");
}

void MainWindow::on_pushButton_clicked()
{
    A.write_to_arduino("1"); // send 1 to arduino
}

void MainWindow::on_pushButton_2_clicked()
{
    A.write_to_arduino("0"); // send 0 to arduino
}
void MainWindow::on_pushButton_3_clicked()
{
    A.write_to_arduino("2"); // send 2 to arduino
}
void MainWindow::on_pushButton_4_clicked()
{
    A.write_to_arduino("3"); // send 3 to arduino
}
void MainWindow::positionUpdated(const QGeoPositionInfo &info)
{
    textEdit->append(QString("Position updated: Date/time = %1, Coordinate = %2").arg(info.timestamp().toString()).arg(info.coordinate().toString()));
}

