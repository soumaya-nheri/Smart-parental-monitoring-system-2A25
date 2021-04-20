#include "deletebox.h"
#include "ui_deletebox.h"
#include "appareil.h"
#include <QMessageBox>

DeleteBox::DeleteBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteBox)
{
    ui->setupUi(this);
}

DeleteBox::~DeleteBox()
{
    delete ui;
}

void DeleteBox::on_cancelbutton_clicked()
{
    delete ui;
}

void DeleteBox::on_suppbutton_clicked()
{
    int i=ui->lineEdit->text().toInt();
    bool testsupp = tmpapp.supprimerappareil(i);
    if (testsupp){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                    QObject::tr("Suppréssion non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
