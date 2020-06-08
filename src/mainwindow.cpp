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
    QString local= alert1->return_fileLocal();
    name=alert1->return_name();
    bool result =alert1->return_result();
    if (result){
        this->close();
        form1=new janela1(this,name,local);
        form1->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    diretorio->diretorio_create(name);
}
