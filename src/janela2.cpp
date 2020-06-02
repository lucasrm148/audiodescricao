#include "header/janela2.h"
#include "ui_janela2.h"
#include "header/alert.h"

#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include <QAudioRecorder>
#include <QFileDialog>
#include <QProcess>
#include <iostream>
using namespace std;

janela2::janela2(QWidget *parent,QString njanela ,QString filename):
    QDialog(parent),
    ui(new Ui::janela2)
{
    ui->setupUi(this);
    form= new alert(this);
    AudioRecorder = new QAudioRecorder(this);
    QAudioEncoderSettings AudioSettings;
    AudioSettings.setCodec("audio/wav");
    AudioSettings.setQuality(QMultimedia :: HighQuality);
    AudioRecorder->setOutputLocation(QUrl :: fromLocalFile(local));
    AudioRecorder->setAudioSettings(AudioSettings);


     mMediaPlayer=new QMediaPlayer(this);
     mVideoWidget = new QVideoWidget(this);

     mMediaPlayer->setVideoOutput(mVideoWidget);
     mVideoWidget->setGeometry(130,10,841,441);
     mVideoWidget->setStyleSheet("* { background-color: rgb(50, 50, 50); }");

     ui->teste->setText(njanela);
     layout();

     connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos ){
         //ui->slide->setValue(pos);
         ui->slide->setValue(pos);
     });
     connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 duracao){
        ui->slide->setMaximum(duracao);
     });
     connect(ui->slide,&QSlider::sliderMoved,mMediaPlayer,&QMediaPlayer::setPosition);
     mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
     mMediaPlayer->setVolume(50);
}

janela2::~janela2()
{
    delete ui;
}
    int clicks=0;
void janela2::on_gravar_clicked()
{
    if(clicks==0){
         AudioRecorder->record();
         clicks=1;
    }else{
        AudioRecorder->pause();
        form->exec();
        form->show();
        bool variavel=form->return_result(); 
        if (variavel){
             name=form->return_name();
             ui->teste->setText(name);
             local=form->return_fileLocal();

             ListAudioLocal.insert(i,local);
             ListAudioName+=name;//ListAudioName.insert(i++,name);
             listAudioDuration.insert(i++,AudioRecorder->duration());
             AudioRecorder->setOutputLocation(QUrl :: fromLocalFile(local));
             AudioRecorder->stop();
             std::cout << "adicionado"<< std::endl;

        }else{

            AudioRecorder->stop();
        }

        clicks=0;

    }
}

void janela2::on_play_clicked()
{
  mMediaPlayer->play();
}

void janela2::on_pause_clicked()
{
 mMediaPlayer->stop();
}

void janela2::on_pushButton_clicked()
{

}
