#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <janela1.h>
#include "janela1.h"
#include "alert.h"
#include "diretorio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     QString name;
     diretorio *app= new diretorio();
public slots:

private slots:
    void on_novoProj_clicked();

    void abrirProj();

private:
    Ui::MainWindow *ui;
    janela1 *form1;
    alert *alert1;
};
#endif // MAINWINDOW_H
