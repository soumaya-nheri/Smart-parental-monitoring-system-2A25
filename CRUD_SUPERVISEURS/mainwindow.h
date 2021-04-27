#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "superviseurs.h"
#include "maisons.h"
#include "arduino.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_superviseur_clicked();
    void on_pb_modifier_superviseur_clicked();
    void on_pb_supprimer_superviseur_clicked();
    void on_pb_ajouter_maison_clicked();
    void on_pb_modifier_maison_clicked();
    void on_pb_supprimer_maison_clicked();
    void update_label();
    void on_pushButtom_clicked();
    void on_pushButtom_2_clicked();
    void on_pushButtom_3_clicked();
    void on_pushButtom_4_clicked();


private:
    Ui::MainWindow *ui;
    SUPERVISEURS S;
    MAISONS M;
    QByteArray data ;
    Arduino A;
};
#endif // MAINWINDOW_H
