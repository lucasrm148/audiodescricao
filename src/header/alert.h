#ifndef ALERT_H
#define ALERT_H


#include <QDialog>
#include <QWidget>
//#include <QFileDialog>
#include <iostream>
#include "diretorio.h"

namespace Ui {
    class alert;
}
class QMediaPlayer;
class  QVideoWidget;
class alert : public QDialog
{
    Q_OBJECT

public:
    explicit alert(QWidget *parent = nullptr);
    ~alert();

    QString return_name();

    bool return_result();

    void reset();

    QString return_fileLocal();

    void erro();
private slots:
    void on_salvar_clicked();

    void on_cancelar_clicked();

private:
    bool result = true;
    QString name="dafault";
    QString fileLocal;
    Diretorio *diretorio= new Diretorio;


    Ui::alert *ui;

};

#endif // ALERT_H
