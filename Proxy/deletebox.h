#ifndef DELETEBOX_H
#define DELETEBOX_H
#include "mainwindow.h"
#include <QDialog>
#include "appareil.h"
namespace Ui {
class DeleteBox;
}

class DeleteBox : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteBox(QWidget *parent = nullptr);
    ~DeleteBox();
    void Update(Ui::MainWindow *ui);


private slots:
    void on_cancelbutton_clicked();

    void on_suppbutton_clicked();

private:
    Ui::DeleteBox *ui;
    Appareil tmpapp;
};

#endif // DELETEBOX_H
