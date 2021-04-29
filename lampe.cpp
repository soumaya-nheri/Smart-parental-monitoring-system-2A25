#include "lampe.h"

lampe::lampe()
{

}
lampe::lampe(int id,QString etat)
{
    this->id=id;
    this->etat=etat;
}
bool lampe::ajouter(){


    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("INSERT INTO lampe (id,etat) "
                  "VALUES (:id,:etat)");
    query.bindValue(":id", id_string);
    query.bindValue(":etat", etat);

    return   query.exec();


}
bool lampe::supprimer(int id){

 QSqlQuery query;

    query.prepare("Delete from lampe where id=:id");
    query.bindValue(0, id);

    return   query.exec();

}
QSqlQueryModel* lampe::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM lampe");

    return model;
}
QSqlQueryModel * lampe::chercher(int id)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(id);
    model->setQuery("select * from lampe where id like '"+rech+"%'");

        return model;
}
bool lampe::modifier(int id)
{
    QSqlQuery query;
    query.prepare("update lampe set etat=:etat where id=:id");
    query.bindValue(":id", id);
    query.bindValue(":etat", etat);

    return   query.exec();
}
