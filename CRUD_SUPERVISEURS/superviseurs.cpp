#include "superviseurs.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>

SUPERVISEURS::SUPERVISEURS()
{
    id=0;
    nom=" ";
    prenom=" ";
    email=" ";
    sexe=" ";
    age=0;
}
SUPERVISEURS::SUPERVISEURS(int id,QString nom ,QString prenom ,QString email ,QString sexe ,int age)
{this->id=id;
 this->nom=nom;
 this->prenom=prenom;
 this->email=email;
 this->sexe=sexe;
 this->age=age;
}
int SUPERVISEURS::getid(){return id;}
QString SUPERVISEURS::getnom(){return nom;}
QString SUPERVISEURS::getprenom(){return prenom;}
QString SUPERVISEURS::getemail(){return email;}
QString SUPERVISEURS::getsexe(){return sexe;}
int SUPERVISEURS::getage(){return age;}
void SUPERVISEURS::setid (int id){this->id=id;}
void SUPERVISEURS::setnom (QString nom){this->nom=nom;}
void SUPERVISEURS::setprenom (QString prenom){this->prenom=prenom;}
void SUPERVISEURS::setemail (QString email){this->email=email;}
void SUPERVISEURS::setsexe (QString sexe){this->sexe=sexe;}
void SUPERVISEURS::setage (int age){this->age=age;}
bool SUPERVISEURS::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    query.prepare("INSERT INTO SUPERVISEURS (id,nom,prenom,email,sexe,age)""VALUES (:id, :nom, :prenom, :email ,:sexe, :age)");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":sexe", sexe);
    query.bindValue(":age", age);
    return query.exec();
}

bool SUPERVISEURS::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE SUPERVISEURS SET nom=:nom ,prenom=:prenom , email=:email , sexe=:sexe , age=:age , id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":sexe", sexe);
    query.bindValue(":age", age);
    return query.exec();

}

    QSqlQueryModel* SUPERVISEURS::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SUPERVISEURS");
    model->setHeaderData(0 ,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1 ,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2 ,Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2 ,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(3 ,Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(4 ,Qt::Horizontal, QObject::tr("Age"));
    return model ;
}
    bool SUPERVISEURS::supprimer(int id)
    {
        QSqlQuery query;
        QString id_string= QString::number(id);
        query.prepare(" DELETE FROM SUPERVISEURS WHERE id=:id");
        query.bindValue(0 , id);
        return query.exec();
    }
