#include "header/alert.h"
#include "ui_alert.h"
#include <QVideoWidget>
#include <QFileDialog>
#include <iostream>
#include <string>
using namespace std;
alert::alert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alert)
{
    ui->setupUi(this);
}

alert::~alert()
{
    delete ui;
}

void alert::on_salvar_clicked()
{
    result=true;
    name=ui->texto->text();
    fileLocal=diretorio->diretorio_create(name);
    ui->label->setText(fileLocal);
    if (fileLocal!="erro"){
        this->close();
    }
    this->erro();
}

void alert::on_cancelar_clicked()
{
    result=false;
}
QString alert::return_name(){

    return name;
}
bool alert::return_result(){
    return result;
}
void alert::reset(){
    name="default";
    result=false;
    fileLocal="";
}
QString alert::return_fileLocal(){
    return fileLocal;
}

void alert::erro(){
    ui->label->setText("por favor coloque ontro nome");
}
