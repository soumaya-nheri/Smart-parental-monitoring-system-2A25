#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "superviseurs.h"
#include "maisons.h"
#include "smtp.h"
#include "arduino.h"



#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QGeoPositionInfo;
class QTextEdit;
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
    void sendMail();
    void mailSent(QString);
    void browse();
    void update_label();// slot de mise à jour du label etat
    // de la lampe 1 , ce slot est lancé à chaque récéption d'un message de Arduino
    void on_pushButton_clicked();// bouton activer le capteur
    void on_pushButton_2_clicked();// bouton désactiver le capteur
    //void positionUpdated(const QGeoPositionInfo &info);



private:
    Ui::MainWindow *ui;
    SUPERVISEURS S;
    MAISONS M;
    Arduino A ;
    QByteArray data ;
    QStringList files;
   // QTextEdit *textEdit;

};
#endif // MAINWINDOW_H
