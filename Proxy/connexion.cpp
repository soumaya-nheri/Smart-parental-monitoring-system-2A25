#include "connexion.h"
#include <QSqlError>
#include <QDebug>

Connexion::Connexion(){
                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("control");
                           db.setUserName("ramy");//inserer nom de l'utilisateur
                           db.setPassword("ramy");//inserer mot de passe de cet utilisateur

if (db.open()){
    test=true;
    qDebug() << "base t7allet";
}
else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
