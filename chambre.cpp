#include "chambre.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

//définition du constructeur par défaut:
chambre::chambre()
{
numero=0; eclairage=""; etat=0;
}

//définition du constructeur paramétré:
chambre::chambre(int numero,QString eclairage,int etat){
this->numero=numero;
this->eclairage=eclairage;
this->etat=etat;
}


//définition des getters:
int chambre::get_numero(){return numero;}
QString chambre:: get_eclairage(){return eclairage;}
int chambre:: get_etat(){return etat;}


//définition des setters:
void chambre:: set_numero(int numero){this->numero=numero;}
void chambre:: set_eclairage(QString eclairage){this->eclairage=eclairage;}
void chambre:: set_etat(int etat){this->etat=etat;}


//définition de la méthode ajouter:
bool chambre::ajouter(){


    QSqlQuery query;  //declaration de requette sql
    QString numero_string= QString::number(numero); //convertire num a QString
    query.prepare("INSERT INTO chambre (numero, eclairage,etat) "
                  "VALUES (:numero, :eclairage, :etat)");   //preparation de requette
    query.bindValue(":numero", numero_string); //injection sql (securité)
    query.bindValue(":eclairage", eclairage);
    query.bindValue(":etat", etat);

    return   query.exec();


}



bool chambre::supprimer(int numero){

 QSqlQuery query;

    query.prepare("Delete from chambre where numero=:numero");
    query.bindValue(0, numero);

    return   query.exec();

}





QSqlQueryModel* chambre::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel(); //representation graphique d un table sql

         model->setQuery("SELECT * FROM chambre");



    return model;
}




QSqlQueryModel * chambre::chercher(int numero)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(numero);
    model->setQuery("select * from chambre where numero like '"+rech+"%'");

        return model;
}

bool chambre::modifier(int numero)
{
    QSqlQuery query;
    query.prepare("update chambre set eclairage=:eclairage,etat=:etat where numero=:numero");
    query.bindValue(":numero", numero);
    query.bindValue(":eclairage", eclairage);
    query.bindValue(":etat", etat);

    return   query.exec();
}
QSqlQueryModel * chambre::trier(QString selon)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from chambre order by "+selon+"");

        return model;
}
QSqlQueryModel * chambre::stat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select etat,count(*) as nombre from chambre group by etat");

        return model;
}
