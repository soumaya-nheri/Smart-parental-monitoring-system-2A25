#ifndef VERIF_H
#define VERIF_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "arduino.h"

namespace Ui {
class verif;
}

class verif : public QDialog
{
    Q_OBJECT

public:
    explicit verif(QWidget *parent = nullptr);
    void update();
    ~verif();

private slots:
    void on_pushButton_clicked();
    void update_label();

private:
    Ui::verif *ui;
    QByteArray data;
    Arduino tmp;
    int i=0;
};

#endif // VERIF_H
