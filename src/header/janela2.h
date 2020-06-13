#ifndef JANELA2_H
#define JANELA2_H

#include <QDialog>
#include <QWidget>
#include "alert.h"
#include "time.h"
#include <list>
#include <iostream>

namespace Ui {
    class janela2;
}
class QAudioRecorder;
class QMediaPlayer;
class  QVideoWidget;

class janela2 : public QDialog
{
    Q_OBJECT

public:
     explicit janela2(QWidget *parent = nullptr, QString njanela=NULL, QString filename="",QString filelocal="Documentos");
    ~janela2();
    QStringList ListAudioName{};
    QStringList ListAudioLocal{};
    QList< long long int> listAudioDuration;
    QString name;
    QString filediretorio;
    QString local="audio.wav";

private slots:
    void on_gravar_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_pushButton_clicked();

    void on_espaso_clicked();

private:
    Ui::janela2 *ui;

    QAudioRecorder *AudioRecorder;
    QMediaPlayer *mMediaPlayer;
    QVideoWidget *mVideoWidget;
    time1 *timer;
    alert* form;
    int i=0;
};

#endif // JANELA2_H
