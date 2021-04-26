#ifndef SUPERVISEURS_H
#define SUPERVISEURS_H
#include <QString>
#include <QSqlQueryModel>

class SUPERVISEURS
{
public:
    SUPERVISEURS();
    SUPERVISEURS(int,QString,QString,QString,QString,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getsexe();
    int getage();
    void setid (int);
    void setnom (QString);
    void setprenom (QString);
    void setemail (QString);
    void setsexe (QString);
    void setage (int);

    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);



private:
    int id , age;
    QString nom , prenom , email , sexe ;

};


#endif // SUPERVISEURS_H
