#ifndef DIRETORIO_H
#define DIRETORIO_H
#include <QString>

class diretorio
{
public:
    diretorio();
    QString diretorio_create(QString name="app");

    bool item_past(QString name="app");
private:

};
#endif // DIRETORIO_H
