#include "verif.h"
#include "ui_verif.h"
#include <QTimer>
#include <QDebug>



using namespace std;
using namespace std::chrono;

verif::verif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verif)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);



}

verif::~verif()
{
    delete ui;
}

void verif::update(){
    i=0;
i=i+10;
ui->progressBar->setValue(i);


    }

