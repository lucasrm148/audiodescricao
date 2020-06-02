#include "header/diretorio.h"
#include <QString>
#include <iostream>
#include <string>
using namespace std;

diretorio::diretorio()
{

}
QString diretorio::diretorio_create(QString name){
    QString local=" \"C:\\Users\\lucas\\Desktop\\teste\\audiodescrição\\"+name+"\\\"";
    //local.toStdString()
    string locale_text = local.toLocal8Bit().constData();
    //system(("mkdir"+locale_text).c_str());
    diretorio::item_past(name);
    local="C:/Users/lucas/Desktop/teste/"+name;
    return local;
}
bool diretorio::item_past(QString name){
    bool oi=true;
    system("XCOPY C:\\Users\\lucas\\Desktop\\teste\\pymix/E/I c:\\Users\\lucas\\Desktop\\teste\\audiodescricao\\oi2");
return oi;
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
