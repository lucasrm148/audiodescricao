#ifndef JANELA1_H
#define JANELA1_H

#include <QDialog>
#include "janela2.h"
#include <QWidget>
#include "carregar.h"
namespace Ui {
    class janela1;
}

class QMediaPlayer;
class  QVideoWidget;

class janela1 : public QDialog
{
    Q_OBJECT
public:
    explicit janela1(QWidget *parent = nullptr,QString name="",QString local="");
    ~janela1();
    QString filelocal;
    QString fileload;
private slots:
    void on_cenarios_clicked();

    void on_cenas_clicked();

    void on_personagem_clicked();

    void on_titulo_clicked();

    void on_sinopse_clicked();

    void on_play_clicked();

    void on_stop_clicked();

    void on_caregar_clicked();

    void on_slide_valueChanged(int value);



private:
    Ui::janela1 *ui;
    janela2 *form2;
    QMediaPlayer *mMediaPlayer;
    QVideoWidget *mVideoWidget;
    Carregar *carregar;
};

#endif // JANELA1_H
