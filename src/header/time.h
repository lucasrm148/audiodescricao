#ifndef time_H
#define time_H

#include <QDialog>
#include <QWidget>
#include <iostream>
#include "ui_time.h"

namespace Ui {
    class time1;
    class QDialog;
}
class time1: public QDialog
{
    Q_OBJECT
public:
    explicit time1(QWidget *parent = nullptr);
    ~time1();
    QString time;
    QString returnTime();
private slots:

    void on_cancelar_clicked();

    void on_salvar_clicked();

private:
    Ui::time1 *ui;

};

#endif
