#include "header/time.h"
#include "ui_time.h"
#include <QFileDialog>
#include <iostream>
#include <QWidget>

time1::time1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::time1)
{
    ui->setupUi(this);
}
time1::~time1()
{
    delete ui;
}

void time1::on_cancelar_clicked()
{
    this->close();
}

void time1::on_salvar_clicked()
{
   time=ui->timeEdit->text();
   this->close();
}
QString time1::returnTime(){
    return time;
}
