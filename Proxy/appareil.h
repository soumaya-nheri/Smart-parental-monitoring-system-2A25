#ifndef APPAREIL_H
#define APPAREIL_H
#include <QString>

class Appareil
{
public:

    Appareil();
    Appareil(int,QString,QString,int);

    void setid(int id){this->id=id;};
    void settype(QString n){type=n;};
    void setnum(int num){this->num=num;};
    void setowner(QString n){owner=n;};


    int get_id(){return id;};
    QString get_type(){return type;};
    int get_num(){return num;};
    QString get_owner(){return owner;};



    bool ajouterappareil();

private:
    QString type,owner;
    int id,num;




};
#endif // APPAREIL_H
