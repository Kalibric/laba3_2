#include "storage.h"

Storage::Storage(QObject *parent)
    : QObject(parent)
{

}

void Storage::setValueA(const int iA)
{
    a = iA;
    if (a > c)
        c = a;
    validateValues();
}

void Storage::setValueB(const int iB)
{
    b = iB;
    validateValues();
}

void Storage::setValueC(const int iC)
{
    c = iC;
    if (a > c)
        a = c;
    validateValues();
}

void Storage::validateValues()
{
    if (a > b)
        b = a;
    else if (b > c)
        b = c;
    emit valuesUpdated();
}

int Storage::getValueA()
{
    return a;
}

int Storage::getValueB()
{
    return b;
}

int Storage::getValueC()
{
    return c;
}

void Storage::loadValues()
{
    QFile file(SAVE_FILE);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл";
        return;
    }

    QTextStream in(&file);
    if (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(";");
        if (parts.size() >= 3)
        {
            a = parts[0].toInt();
            b = parts[1].toInt();
            c = parts[2].toInt();
        }
    }
    file.close();
    qDebug() << "Loaded";

    emit valuesUpdated();
}

void Storage::uploadValues()
{
    QFile file(SAVE_FILE);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Не удалось открыть файл";
        return;
    }

    QTextStream out(&file);
    out << a << ";" << b << ";" << c;
    file.close();
}

void Storage::closeProgram()
{
    uploadValues();
}
