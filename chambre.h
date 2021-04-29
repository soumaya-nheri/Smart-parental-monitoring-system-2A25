#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <QString>
#include <QSqlQueryModel>


class chambre
{
public:
    //constructeur par défaut:
    chambre();
    //constructeur paramétré:
    chambre(int,QString,int);

    //implementation des getters:
    int get_numero();
    QString get_eclairage();
    int get_etat();

    //implementation des setters:
    void set_numero(int);
    void set_eclairage(QString);
    void set_etat(int);
    //implementation des methodes (CRUD):
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *stat();
    QSqlQueryModel *trier(QString);
    bool supprimer (int);
    QSqlQueryModel *chercher(int);
    bool modifier(int);

private:
    int numero;
    QString eclairage;
    int etat;
};

#endif // CHAMBRE_H
