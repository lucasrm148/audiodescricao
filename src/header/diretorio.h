#ifndef DIRETORIO_H
#define DIRETORIO_H
#include <QString>

class Diretorio
{
public:
    Diretorio();
    QString diretorio_create(QString name="app");

    bool item_past(QString name="app");
private:
    bool DirectoryExists(QString path);

};
#endif // DIRETORIO_H
