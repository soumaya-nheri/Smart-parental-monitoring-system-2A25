#ifndef MODIFICATION_H
#define MODIFICATION_H
#include "appareil.h"
#include <QDialog>

namespace Ui {
class modification;
}

class modification : public QDialog
{
    Q_OBJECT

public:
    explicit modification(QWidget *parent = nullptr);
    ~modification();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modification *ui;
        Appareil tmpapp;
};

#endif // MODIFICATION_H
