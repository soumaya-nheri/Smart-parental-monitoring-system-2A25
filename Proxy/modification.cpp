#include "modification.h"
#include "ui_modification.h"
#include "appareil.h"
#include <QString>
#include <QMessageBox>
modification::modification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modification)
{
    ui->setupUi(this);
}

modification::~modification()
{
    delete ui;
}

void modification::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString owner= ui->lineEdit_proprio->text();
    QString type= ui->lineEdit_type->text();
    int num=ui->lineEdit_num->text().toInt();
    bool testmodif = tmpapp.modifierApp(id,owner,type,num);
    if (testmodif){

        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Modification non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
