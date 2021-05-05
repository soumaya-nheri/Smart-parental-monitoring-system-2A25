#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "appareil.h"
#include "sites.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updatetable();

private slots:

    void on_Button_Ajouter_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_suppression_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_ajoutersitebuton_clicked();

    void on_idsite_editingFinished();

    void on_suppsite_clicked();

private:
    Ui::MainWindow *ui;
    Appareil tmpapp;
    sites tmpsite;


};
#endif // MAINWINDOW_H
