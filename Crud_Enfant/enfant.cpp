#include "enfant.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

//définition du constructeur par défaut:
Enfant::Enfant()
{
id=0; nom=""; prenom=""; age=0;
}

//définition du constructeur paramétré:
Enfant::Enfant(int id,QString nom,QString prenom,int age){
this->id=id;
this->nom=nom;
this->prenom=prenom;
this->age=age;
}


//définition des getters:
int Enfant::get_id(){return id;}
QString Enfant:: get_nom(){return nom;}
QString Enfant:: get_prenom(){return prenom;}
int Enfant::get_age(){return age;}




//définition des setters:
void Enfant:: set_id(int id){this->id=id;}
void Enfant:: set_nom(QString nom){this->nom=nom;}
void Enfant:: set_prenom(QString prenom){this->prenom=prenom;}
void Enfant:: set_age(int age){this->age=age;}





//définition de la méthode ajouter:
bool Enfant::ajouter(){


    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("INSERT INTO Enfant (id, nom, prenom, age) "
                  "VALUES (:id, :nom, :prenom, :age)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    return   query.exec();


}



bool Enfant::supprimer(int id){

 QSqlQuery query;

    query.prepare("Delete from Enfant where id=:id");
    query.bindValue(0, id);

    return   query.exec();

}





QSqlQueryModel* Enfant::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM Enfant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant:"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom:"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom:"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Âge:"));


    return model;
}




QSqlQueryModel * Enfant::chercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from Enfant where upper(nom) like upper('%"+rech+"%') or upper(prenom) like upper('%"+rech+"%')");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID:"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom:"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom:"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Âge:"));



        return model;
}







