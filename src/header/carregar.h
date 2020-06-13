#ifndef Carregar_H
#define Carregar_H


#include <QDialog>
#include <QWidget>
//#include <QFileDialog>
#include <iostream>
#include "diretorio.h"

namespace Ui {
    class Carregar;
}
class  QVideoWidget;
class Carregar: public QDialog
{
    Q_OBJECT

public:
    explicit Carregar(QWidget *parent = nullptr);
    ~Carregar();
    QString fileload="q";

    QString returnfile();

private slots:

    void on_criar_clicked();

    void on_carregar_clicked();


private:
    Ui::Carregar *ui;
};


#endif // Carregar_H
