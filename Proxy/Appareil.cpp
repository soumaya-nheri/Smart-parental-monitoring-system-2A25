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
