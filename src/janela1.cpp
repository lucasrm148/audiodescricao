#include "header/janela1.h"
#include "ui_janela1.h"

#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include <QFileDialog>

janela1::janela1(QWidget *parent,QString name,QString local) :
    QDialog(parent),
    ui(new Ui::janela1)
{
    ui->setupUi(this);
    mMediaPlayer=new QMediaPlayer(this);
    mVideoWidget = new QVideoWidget(this);
    mMediaPlayer->setVideoOutput(mVideoWidget);
    mVideoWidget->setGeometry(230,10,691,631);
    mVideoWidget->setStyleSheet("*{ background-color: rgb(50, 50, 50); }");

    layout();
    connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos ){
        ui->slide->setValue(pos);

    });
    connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 duracao){
        ui->slide->setMaximum(duracao);

    });
    connect(ui->slide,&QSlider::sliderMoved,mMediaPlayer,&QMediaPlayer::setPosition);
}

janela1::~janela1()
{
    delete ui;
}
void janela1::on_cenarios_clicked()
{
    QString tela="cenarios";
    form2=new janela2(this,tela,filename);
    form2->show();
    form2->exec();
}

void janela1::on_cenas_clicked()
{
    QString tela="cenas";
    form2=new janela2(this,tela,filename);  
    form2->show();
    form2->exec();
}


void janela1::on_personagem_clicked()
{
    QString tela="personagem";
    form2=new janela2(this,tela,filename);

    form2->show();
    form2->exec();
}

void janela1::on_titulo_clicked()
{
    QString tela="titulo";
    form2=new janela2(this,tela,filename);

    form2->show();
    form2->exec();
}

void janela1::on_sinopse_clicked()
{
   QString tela="sinopse";
   form2=new janela2(this,tela,filename);

   form2->show();
   form2->exec();
}

void janela1::on_play_clicked()
{
   mVideoWidget->show();
    mMediaPlayer->play();

}

void janela1::on_stop_clicked()
{
    mMediaPlayer->pause();
}

void janela1::on_caregar_clicked()
{
    filename=QFileDialog::getOpenFileName(this,"abrir");
    if(filename.isEmpty()){
        return;
    }
   mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
   mMediaPlayer->setVolume(50);
    on_play_clicked();
}

void janela1::on_slide_valueChanged(int value)
{
    ui->slide->setValue(value);
}



