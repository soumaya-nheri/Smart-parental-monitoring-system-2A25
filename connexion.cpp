#include "connexion.h"
#include "QSqlDatabase"

Connection::Connection()
{

}

bool Connection::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_2A25");
    db.setUserName("siwar");
    db.setPassword("esprit21");

    if(db.open())
        test=true;
    return test;
}
void Connection::fermerconnexion()
{
    db.close();
}
