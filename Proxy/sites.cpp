#include "sites.h"

sites::sites()
{
    adress="";
    id=0;
    type="";
    name="";
}


sites::sites(int id, QString name, QString type, QString adress)
{
    this->id=id;
    this->adress=adress;
    this->type=type;
    this->name=name;


}
