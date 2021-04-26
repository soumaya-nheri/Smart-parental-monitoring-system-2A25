#include "maisons.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

MAISONS::MAISONS()
{
  id=0;
  adresse=" ";
  nbr_chambre=0;

}
MAISONS::MAISONS(int id,QString adresse ,int nbr_chambre)
{this->id=id;
 this->adresse=adresse;
 this->nbr_chambre=nbr_chambre;
}
int MAISONS::getid(){return id;}
QString MAISONS::getadresse(){return adresse;}
int MAISONS::getnbr_chambre(){return nbr_chambre;}
void MAISONS::setid (int id){this->id=id;}
void MAISONS::setadresse (QString adresse){this->adresse=adresse;}
void MAISONS::setnbr_chambre (int nbr_chambre){this->nbr_chambre=nbr_chambre;}

bool MAISONS::ajouter_maison()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("INSERT INTO MAISONS (id,adresse,nb_chambre)""VALUES (:id, :adresse, :nbr_chambre)");
    query.bindValue(":id", id_string);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nbr_chambre", nbr_chambre);
    return query.exec();
}

bool MAISONS::modifier_maison(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE MAISONS SET adresse=:adresse ,nbr_chambre=:nbr_chambre , id=:id");
    query.bindValue(":id", id);
    query.bindValue(":adresse", adresse);
    query.bindValue(":nbr_chambre", nbr_chambre);
    return query.exec();

}

QSqlQueryModel* MAISONS::afficher_maison()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("SELECT * FROM MAISONS");
model->setHeaderData(0 ,Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1 ,Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2 ,Qt::Horizontal, QObject::tr("nbr_chambre"));
return model ;
}

bool MAISONS::supprimer_maison(int id)
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare(" DELETE FROM MAISONS WHERE id=:id");
    query.bindValue(0 , id);
    return query.exec();
}
