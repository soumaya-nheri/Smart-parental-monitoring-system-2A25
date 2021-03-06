#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chambre.h"
#include <QString>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->line_num->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_chambre->setModel(C.afficher());
    ui->tableView->setModel(C.stat());
    ui->tab_lampe->setModel(l.afficher());
    /*
    QPieSeries *series = new QPieSeries();
    QSqlQuery q("select etat,count(*) from chambre group by etat");


     while(q.next())
     {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques");
    chart->setBackgroundBrush(Qt::transparent);
    QChartView *chartview = new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame);
    chartview->resize(400,300);

    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    series->setLabelsVisible(true);
      */

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_ajout_clicked()
{

    int numero=ui->line_num->text().toInt();
        QString eclairage=ui->line_eclair->text();
        int etat=ui->line_etat->text().toInt();
        chambre C(numero,eclairage,etat);


        if(C.ajouter())
            {
            ui->line_num->setText("");
            ui->line_eclair->setText("");
            ui->line_etat->setText("");


            QMessageBox::information(nullptr, QObject::tr("Ajouter une chambre"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_chambre->setModel(C.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une chambre"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
    }


void MainWindow::on_btn_supp_clicked()
{
    chambre C1;
    int row=ui->tab_chambre->selectionModel()->currentIndex().row();
      C1.set_numero(ui->tab_chambre->model()->index(row,0).data().toInt());
      bool test=C1.supprimer(C1.get_numero());

      QMessageBox msgBox;

      if(test)
      {
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_chambre->setModel(C.afficher());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ui->tab_chambre->setModel(C.chercher(id)); //rechercher
}

void MainWindow::on_pushButton_clicked()
{
    int numero=ui->line_num->text().toInt();
        QString eclairage=ui->line_eclair->text();
        int etat=ui->line_etat->text().toInt();
        chambre C(numero,eclairage,etat);


        if(C.modifier(numero))
            {
            ui->line_num->setText("");
            ui->line_eclair->setText("");
            ui->line_etat->setText("");


            QMessageBox::information(nullptr, QObject::tr("modifier une chambre"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_chambre->setModel(C.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("modifier une chambre"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_pushButton_3_clicked()
{
    QString selon=ui->comboBox->currentText();
     ui->tab_chambre->setModel(C.trier(selon));
}

void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_chambre->model()->rowCount();
                        const int columnCount = ui->tab_chambre->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des chambres</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_chambre->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_chambre->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_chambre->isColumnHidden(column)) {
                                                QString data = ui->tab_chambre->model()->data(ui->tab_chambre->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);

                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);

                                doc.print(&printer);
}

void MainWindow::on_btn_ajout_2_clicked()
{
    int id=ui->line_num_2->text().toInt();
        QString etat=ui->line_etat_2->text();

        lampe l(id,etat);


        if(l.ajouter())
            {
            ui->line_num_2->setText("");
            ui->line_etat_2->setText("");


            QMessageBox::information(nullptr, QObject::tr("Ajouter une lampe"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_lampe->setModel(l.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une lampe"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_btn_supp_2_clicked()
{
    lampe l1;
    int row=ui->tab_lampe->selectionModel()->currentIndex().row();
      int id=ui->tab_lampe->model()->index(row,0).data().toInt();
      bool test=l1.supprimer(id);

      QMessageBox msgBox;

      if(test)
      {
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_lampe->setModel(l1.afficher());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->lineEdit_2->text().toInt();
    ui->tab_lampe->setModel(l.chercher(id));
}

void MainWindow::on_pushButton_8_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_lampe->model()->rowCount();
                        const int columnCount = ui->tab_lampe->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des lampes</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_lampe->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_lampe->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_lampe->isColumnHidden(column)) {
                                                QString data = ui->tab_lampe->model()->data(ui->tab_lampe->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);

                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);

                                doc.print(&printer);
}

void MainWindow::on_pushButton_7_clicked()
{
    int row=ui->tab_lampe->selectionModel()->currentIndex().row();
      int id=ui->tab_lampe->model()->index(row,0).data().toInt();
      QString res=QString::number(id);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->line_num_2->setText(res);
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->line_num_2->text().toInt();
        QString etat=ui->line_etat_2->text();

        lampe l(id,etat);


        if(l.modifier(id))
            {
            ui->line_num_2->setText("");
            ui->line_etat_2->setText("");


            QMessageBox::information(nullptr, QObject::tr("Modifier une lampe"),
                               QObject::tr("modification avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_lampe->setModel(l.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier une lampe"),
                                   QObject::tr("Erreur!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
}

void MainWindow::on_pushButton_9_clicked()
{
    QTableView *table;
       table = ui->tab_chambre;

       QString filters("CSV files (*.csv);;All files (*.*)");
       QString defaultFilter("CSV files (*.csv)");
       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                          filters, &defaultFilter);
       QFile file(fileName);

       QAbstractItemModel *model =  table->model();
       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
           QTextStream data(&file);
           QStringList strList;
           for (int i = 0; i < model->columnCount(); i++) {
               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
               else
                   strList.append("");
           }
           data << strList.join(";") << "\n";
           for (int i = 0; i < model->rowCount(); i++) {
               strList.clear();
               for (int j = 0; j < model->columnCount(); j++) {

                   if (model->data(model->index(i, j)).toString().length() > 0)
                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                   else
                       strList.append("");
               }
               data << strList.join(";") + "\n";
           }
           file.close();
           QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
       }
}
