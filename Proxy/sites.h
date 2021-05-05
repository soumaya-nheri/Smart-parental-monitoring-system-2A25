#ifndef SITES_H
#define SITES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class sites
{

public:

    sites();
    sites(int,QString,QString,QString);

    void setid(int id){this->id=id;};
    void settype(QString n){type=n;};
    void setname(QString n){name=n;};
    void setadress(QString n){adress=n;};


    int get_id(){return id;};
    QString get_name(){return name;};
    QString get_adress(){return adress;};
    QString get_type(){return type;};



    bool ajoutersite();
    bool supprimersite(int id);
    QSqlQueryModel * affichersites();

private:
    QString type,name,adress;
    int id;
};

#endif // SITES_H
