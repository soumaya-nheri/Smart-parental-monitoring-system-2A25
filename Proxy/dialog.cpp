#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setappareil(Appareil a){
    ui->lineEdit_nom->setText(a.get_nom());
    ui->lineEdit_num->setText(a.get_num());
    ui->lineEdit_proprio->setText(a.get_proprio());
    ui->lineEdit_type->setText(a.get_type());
}
