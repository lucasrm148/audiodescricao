#include "header/carregar.h"
#include "ui_carregar.h"
#include <QVideoWidget>
#include <QFileDialog>
#include <iostream>
#include <string>
using namespace std;
Carregar::Carregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Carregar)
{
    ui->setupUi(this);
}

Carregar::~Carregar()
{
    delete ui;
}

void Carregar::on_criar_clicked()
{
    fileload="";
    this->close();
}

void Carregar::on_carregar_clicked()
{
    fileload=QFileDialog::getOpenFileName(this,"abrir");
    this->close();
}
QString Carregar::returnfile(){
   return fileload;
}
