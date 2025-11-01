#ifndef STORAGE_H
#define STORAGE_H

#include <QObject>
#include <QFile>
#include <QDebug>

class Storage : public QObject
{
    Q_OBJECT
public:
    explicit Storage(QObject *parent = nullptr);

    void setValueA(int iA);
    void setValueB(int iB);
    void setValueC(int iC);
    int getValueA();
    int getValueB();
    int getValueC();
    void closeProgram();
    void loadValues();

signals:
    void valuesUpdated();

private:
    int a = 0;
    int b = 0;
    int c = 0;
    void validateValues();
    void uploadValues();
    const QString SAVE_FILE = "save.txt";
};

#endif // STORAGE_H
