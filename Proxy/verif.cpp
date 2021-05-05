#include "verif.h"
#include "ui_verif.h"
#include "arduino.h"
#include <QTimer>
#include <QDebug>
#include <QString>

using namespace std;
using namespace std::chrono;

verif::verif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verif)
{
    ui->setupUi(this);
    /*int ret=tmp.connect_arduino();
    switch(ret){
    case(0):qDebug() << "arduino is available and connected to : " << tmp.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to : " << tmp.getarduino_port_name();
        break;
    case(-1):qDebug() << "arduino is not available";
        break;
    }
    QObject::connect(tmp.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/

}

verif::~verif()
{
    delete ui;
}


void verif::update_label(){
    data=tmp.read_from_arduino();
    if (data=="1")
        ui->label_verif->setText("Site accédé!!!");
    else if (data=="2")
        ui->label_verif->setText("Site non accédé.");
    else if (data=="0")
        ui->label_verif->setText("Site non accédé.");



}


void verif::on_pushButton_clicked()
{
    QString site = ui->label_verif->text();
    if (site=="facebook" || site=="twitter" )
        tmp.write_to_arduino("1");
    else
        tmp.write_to_arduino("2");

}
