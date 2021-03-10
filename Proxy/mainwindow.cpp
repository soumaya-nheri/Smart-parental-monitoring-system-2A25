#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "appareil.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Button_Ajouter_clicked()
{
    Appareil a;
    a.settype(ui->lineEdit_typeappareil->text());
    a.setnom(ui->lineEdit_nomappareil->text());
    a.setnum(ui->lineEdit_numappareil->text());
    a.setproprio(ui->lineEdit_proprio->text());
    Dialog d;
    d.setappareil(a);
    d.exec();

}
