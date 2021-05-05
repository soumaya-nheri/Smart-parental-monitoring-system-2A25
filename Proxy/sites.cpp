#include "sites.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"connexion.h"

sites::sites()
{
    adress="";
    id=0;
    type="";
    name="";
}


sites::sites(int id, QString name, QString type, QString adress)
{
    this->id=id;
    this->adress=adress;
    this->type=type;
    this->name=name;


}
bool sites::ajoutersite()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO sites (ID, NAME, TYPE,ADRESS) "
                    "VALUES (:id, :name, :type, :adress)");
query.bindValue(":id", res);
query.bindValue(":name", name);
query.bindValue(":type", type);
query.bindValue(":adress", adress);

return    query.exec();

}

bool sites::supprimersite(int ID)
{

    QSqlQuery qry;
    //QString res=QString::number(ID);

    qry.prepare("DELETE from sites where ID = :ID");
    qry.bindValue(":ID",ID);
    return qry.exec();
}

QSqlQueryModel * sites::affichersites()
{
QSqlQueryModel * model = new QSqlQueryModel();

model->setQuery("select * from sites");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}

QSqlQueryModel * sites::recherchesite(const QString &id, int filtre)
{
    QString site = "site";
    QString app = "app";
    QSqlQueryModel * model = new QSqlQueryModel();
    if (filtre==1)
        model->setQuery("select * from SITES where(NAME LIKE '"+id+"%') or (ID LIKE'"+id+"%') or (ADRESS LIKE '"+id+"%')");
    else if (filtre==2)
        model->setQuery("select * from SITES where((NAME LIKE '"+id+"%') or (ID LIKE'"+id+"%') or (ADRESS LIKE '"+id+"%')) and (TYPE LIKE '"+site+"%')");
    else if (filtre==3)
        model->setQuery("select * from SITES where((NAME LIKE '"+id+"%') or (ID LIKE'"+id+"%') or (ADRESS LIKE '"+id+"%')) and (TYPE LIKE '"+app+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));


    return model;
}
