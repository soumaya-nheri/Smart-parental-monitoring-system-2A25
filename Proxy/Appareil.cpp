#include "appareil.h"

Appareil::Appareil()
{
    num="";
    nom="";
    type="";
    proprio="";

}

void Appareil::setnum(QString n) {num=n;}
void Appareil::settype(QString n) {type=n;}
void Appareil::setnom(QString n) {nom=n;}
void Appareil::setproprio(QString n) {proprio=n;}

QString Appareil::get_nom(){return nom;}
QString Appareil::get_type(){return type;}
QString Appareil::get_num(){return num;}
QString Appareil::get_proprio(){return proprio;}
