#ifndef ENFANT_H
#define ENFANT_H
#include <QString>
#include <QSqlQueryModel>


class Enfant
{
public:
    //constructeur par défaut:
    Enfant();

    //constructeur paramétré:
    Enfant(int,QString,QString,int);

    //implémentation des getters:
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_age();

    //implémentation des setters:
    void set_id(int);
    void set_nom(QString);
    void set_prenom(QString);
    void set_age(int);

    //implémentation des méthodes (CRUD):
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    QSqlQueryModel * chercher(QString);

private:
    int id;
    QString nom;
    QString prenom;
    int age;


};

#endif // ENFANT_H
