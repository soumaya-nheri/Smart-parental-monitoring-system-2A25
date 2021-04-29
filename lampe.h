#ifndef LAMPE_H
#define LAMPE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class lampe
{
public:
lampe();
lampe(int,QString);
bool ajouter();
QSqlQueryModel *afficher();
bool supprimer (int);
QSqlQueryModel *chercher(int);
bool modifier(int);
private:
int id;
QString etat;
};

#endif // LAMPE_H
