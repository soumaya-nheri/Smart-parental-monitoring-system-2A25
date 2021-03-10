#ifndef APPAREIL_H
#define APPAREIL_H
#include <QString>

class Appareil
{
public:
    void setnom(QString n);
    void settype(QString n);
    void setnum(QString n);
    void setproprio(QString n);
    QString get_nom();
    QString get_type();
    QString get_num();
    QString get_proprio();
    Appareil();
private:
    QString type,nom,proprio,num;
};
#endif // APPAREIL_H
