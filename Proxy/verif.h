#ifndef VERIF_H
#define VERIF_H

#include <QDialog>

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

private:
    Ui::verif *ui;
    QTimer *timer;
    int i=0;
};

#endif // VERIF_H
