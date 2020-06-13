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
    int x=ui->tela->x();
    int y=ui->tela->y();
    int wt=ui->tela->width();
    int hg=ui->tela->height();
    ui->tela->destroyed();
    mVideoWidget->setGeometry(x,y,wt,hg);
    mVideoWidget->setStyleSheet("*{ background-color: rgb(50, 50, 50); }");
    filelocal=local;

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
    Carregar *carregar=new Carregar();
    carregar->show();
    carregar->exec();
    QString teste=carregar->returnfile();
    if(teste==""){
        form2=new janela2(this,tela,fileload,filelocal);
        form2->show();
        form2->exec();
    }
}

void janela1::on_cenas_clicked()
{
    QString tela="cenas";
    Carregar *carregar=new Carregar(this);
    carregar->show();
    carregar->exec();
    QString teste=carregar->returnfile();
    if(teste==""){
        form2=new janela2(this,tela,fileload,filelocal);
        form2->show();
        form2->exec();
    }
}
void janela1::on_personagem_clicked()
{
    QString tela="personagem";
    Carregar *carregar=new Carregar(this);
    carregar->show();
    carregar->exec();
    QString teste=carregar->returnfile();
    if(teste==""){
        form2=new janela2(this,tela,fileload,filelocal);
        form2->show();
        form2->exec();
    }
}

void janela1::on_titulo_clicked()
{
    QString tela="titulo";
    Carregar *carregar=new Carregar(this);
    carregar->show();
    QString teste=carregar->returnfile();
    if(teste==""){
        form2=new janela2(this,tela,fileload,filelocal);
        form2->show();
        form2->exec();
    }
}

void janela1::on_sinopse_clicked()
{
   QString tela="sinopse";
   Carregar *carregar=new Carregar(this);
   carregar->show();
   QString teste=carregar->returnfile();
   if(teste==""){
       form2=new janela2(this,tela,fileload,filelocal);
       form2->show();
       form2->exec();
   }
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
    fileload=QFileDialog::getOpenFileName(this,"abrir");
    if(fileload.isEmpty()){
        return;
    }
   mMediaPlayer->setMedia(QUrl::fromLocalFile(fileload));
   mMediaPlayer->setVolume(50);
    on_play_clicked();
}

void janela1::on_slide_valueChanged(int value)
{
    ui->slide->setValue(value);
}
