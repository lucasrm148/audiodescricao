#include "header/diretorio.h"
#include <QString>
#include <iostream>
#include <string>
#include <windows.h>
#include <string>
#include <fileapi.h>
using namespace std;

Diretorio::Diretorio()
{

}
QString Diretorio::diretorio_create(QString name){
    QString local="erro";
    if(Diretorio::item_past(name)){
        local="C:/Users/lucas/Desktop/teste/"+name;
    }

    return local;
}

bool Diretorio::item_past(QString name){
    QString diretorio ="c:\\users\\lucas\\desktop\\teste\\audiodescricao\\"+name;
     bool var=false;
     if (DirectoryExists(diretorio)){
          QString local=" C:\\Users\\lucas\\Desktop\\teste\\pymix/E/I "+diretorio;
          string locale_text = local.toLocal8Bit().constData();
          var =true;
     }
     printf("%s",(var)?"true":"false");
return var;
//ao copiar o arquivo caso a pagina nao exista ela e criada;
//C:\Listening TV Pt-br alterado-20200602T193402Z-001\Listening TV Pt-br alterado\ListenTV\ListeningTV
}

bool Diretorio::DirectoryExists(QString path)
{
    QString test= "cd "+path;
    string test_d=test.toLocal8Bit().constData();
     return system((test_d).c_str());
// função que testa se o diretorio ja existe ou nao caso nao exista retorna false  teste e feito pelo cd do smd;
}





//system(("mkdir"+locale_text).c_str())//cria uma pasta vazia mais n precisa ja que o comp cria a pasta;
