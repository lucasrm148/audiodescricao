#include "header/mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    alert1=new alert(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    alert1->show();
    alert1->exec();
    QString local;
    name=alert1->return_name();
    local=app->diretorio_create(name);
    form1=new janela1(this,name,local);
    form1->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    app->diretorio_create(name);

}
/*
 *
Bom, por aqui fiz assim:

criei uma pasta vazia para o destino e consegui copiar tudo o que tinha na pasta

de origem inclusive subpastas para ela deste jeito:

#include <conio.h>

#include <stdio.h>

#include <windows.h>

int main(){

system("XCOPY C:\\UDev/E/S G:\\UDev"); // Aqui UDev é uma pasta de programa

// G é o meu pendrive, e UDev em G foi uma pasta vazia criada para receber os arquivos da pasta de origem,

//copiou tudo inclusive as subpastas,funciona perfeitamente.

getche();

}

é isto...
*/
