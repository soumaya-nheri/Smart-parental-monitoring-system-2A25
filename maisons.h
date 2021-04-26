#ifndef MAISONS_H
#define MAISONS_H
#include <QString>
#include <QSqlQueryModel>

class MAISONS
{
public:
    MAISONS();
    MAISONS(int, QString , int);
    int getid();
    QString getadresse();
    int getnbr_chambre();
    void setid (int);
    void setadresse (QString);
    void setnbr_chambre (int);
    bool ajouter_maison();
    bool modifier_maison(int);
    QSqlQueryModel * afficher_maison();
    bool supprimer_maison(int);

private:
    int id , nbr_chambre ;
    QString adresse ;
};

#endif // MAISONS_H
