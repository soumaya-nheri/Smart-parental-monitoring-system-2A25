#include "appareil.h"
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include"connexion.h"

Appareil::Appareil()
{
    num=0;
    id=0;
    type="";
    owner="";

}

Appareil::Appareil(int id, QString owner, QString type, int num)
{
    this->id=id;
    this->num=num;
    this->type=type;
    this->owner=owner;


}



/*void Appareil::setnum(int n) {num=n;}
void Appareil::settype(QString n) {type=n;}
void Appareil::setid(int n) {id=n;}
void Appareil::setowner(QString n) {owner=n;}

QString Appareil::get_id(){return id;}
QString Appareil::get_type(){return type;}
QString Appareil::get_num(){return num;}
QString Appareil::get_owner(){return owner;}*/

bool Appareil::ajouterappareil()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO appareils (ID, OWNER, TYPE,NUMERO) "
                    "VALUES (:id, :owner, :type, :num)");
query.bindValue(":id", res);
query.bindValue(":owner", owner);
query.bindValue(":type", type);
query.bindValue(":num", num);

return    query.exec();

}

bool Appareil::supprimerappareil(int id)
{

    QSqlQuery qry;

    qry.prepare("Delete from appareils where id = :id");
    qry.bindValue(":id",id);
    return qry.exec();
}

QSqlQueryModel * Appareil::afficher()
{
QSqlQueryModel * model = new QSqlQueryModel();

model->setQuery("select * from appareils");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Propriétaire"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));

    return model;
}


bool Appareil::modifierApp(int id,QString owner,QString type,int num)
{
   QSqlQuery query;
   query.prepare("UPDATE collaborateur SET id= :id,owner= :owner,type=:type,num= :num");
   query.bindValue(":id", id);
   query.bindValue(":owner",owner );
   query.bindValue(":type",type);
   query.bindValue(":num", num);
   return    query.exec();
}
