#include "header/mix_class.h"

#include <QFileDialog>
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <iostream>
#include <string>

mix_class::mix_class()
{
    /*QString oi="legal";
    QString nao="e nao";
    oi+=nao;
    qDebug() << oi;
    std::cout << oi.toStdString();
    printf(oi.toStdString().c_str());*/
}
bool mix_class::createAudio(QString fileDirectory,QString fileName){
    fileDirectory+="/"+fileName+".wav";
    QFile file(fileDirectory);
       file.open(QIODevice::WriteOnly | QIODevice::Text);
       QTextStream out(&file);
       file.close();
       return true;
}
bool mix_class::audio_mix(QString audio1,QString audio2,QString fileLocal){
    QString a="'",b="(";
    QString scriptFile =""
                        "C:/Users/lucas/Documents/pyqt/audio descrição/audiodescricao/src/mix.py";
    QStringList pythoncommand= QStringList()<< "python -c \"from "+scriptFile+" import mix;mix('"+audio1+"','"+audio2+"','"+fileLocal+"')\"";
    //QStringList pythoncommand = QStringList() <<'-c'+a+'from mix import mix; mix'+b + audio1 + a + ',' + a + audio2 + a + ',' + a + fileLocal + a + ')'+a;
    //QStringList pythoncommands = QStringList() <<'form mix import mix;mix('+a+','+b+','+c+')';
    //QStringList pythoncommand = QStringList() <<"python"<<"from mix import mix;mix(C:/Users/lucas/Documents/pyqt/webdescrica/test.wav,C:/Users/lucas/Documents/pyqt/webdescrica/test.wav,C:/Users/lucas/Music)";

    QProcess p;
    QString oi="python C:/Users/lucas/Documents/pyqt/webdescrica/mix.py";
    QString oi1="\"python -c \"from "+scriptFile+" import mix;mix('"+audio1+"','"+audio2+"','"+fileLocal+"')\"\"";
   // p.setWorkingDirectory(scriptFile);
    p.start(oi1);
    p.execute(oi1);
    p.waitForFinished();

    return true;
}
