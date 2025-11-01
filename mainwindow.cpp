#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->inputTextA->setValidator(new QIntValidator(0, 100));
    ui->inputTextB->setValidator(new QIntValidator(0, 100));
    ui->inputTextC->setValidator(new QIntValidator(0, 100));
    ui->spinBoxA->setRange(0, 100);
    ui->spinBoxB->setRange(0, 100);
    ui->spinBoxC->setRange(0, 100);
    ui->sliderA->setRange(0, 100);
    ui->sliderB->setRange(0, 100);
    ui->sliderC->setRange(0, 100);
    connect(ui->inputTextA, &QLineEdit::editingFinished, this, &MainWindow::textEditedA);
    connect(ui->inputTextB, &QLineEdit::editingFinished, this, &MainWindow::textEditedB);
    connect(ui->inputTextC, &QLineEdit::editingFinished, this, &MainWindow::textEditedC);
    connect(ui->spinBoxA, &QSpinBox::editingFinished, this, &MainWindow::spinEditedA);
    connect(ui->spinBoxB, &QSpinBox::editingFinished, this, &MainWindow::spinEditedB);
    connect(ui->spinBoxC, &QSpinBox::editingFinished, this, &MainWindow::spinEditedC);
    connect(ui->sliderA, &QSlider::sliderReleased, this, &MainWindow::sliderEditedA);
    connect(ui->sliderB, &QSlider::sliderReleased, this, &MainWindow::sliderEditedB);
    connect(ui->sliderC, &QSlider::sliderReleased, this, &MainWindow::sliderEditedC);
    connect(storage, &Storage::valuesUpdated, this, &MainWindow::updateValues);
    // ui->
    storage->loadValues();
}

void MainWindow::textEditedA()
{
    bool success;
    int value = ui->inputTextA->text().toInt(&success);
    storage->setValueA(success ? value : 0);
}

void MainWindow::textEditedB()
{
    bool success;
    int value = ui->inputTextB->text().toInt(&success);
    storage->setValueB(success ? value : 0);
}

void MainWindow::textEditedC()
{
    bool success;
    int value = ui->inputTextC->text().toInt(&success);
    storage->setValueC(success ? value : 0);
}

void MainWindow::spinEditedA()
{
    int value = ui->spinBoxA->value();
    storage->setValueA(value);
 }

void MainWindow::spinEditedB()
{
    int value = ui->spinBoxB->value();
    storage->setValueB(value);
}

void MainWindow::spinEditedC()
{
    int value = ui->spinBoxC->value();
    storage->setValueC(value);
}

void MainWindow::sliderEditedA()
{
    storage->setValueA(ui->sliderA->value());
}

void MainWindow::sliderEditedB()
{
    storage->setValueB(ui->sliderB->value());
}

void MainWindow::sliderEditedC()
{
    storage->setValueC(ui->sliderC->value());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    storage->closeProgram();
}

void MainWindow::updateValues()
{
    qDebug() << "value update";
    ui->inputTextA->setText(QString::number(storage->getValueA()));
    ui->inputTextB->setText(QString::number(storage->getValueB()));
    ui->inputTextC->setText(QString::number(storage->getValueC()));
    ui->spinBoxA->setValue(storage->getValueA());
    ui->spinBoxB->setValue(storage->getValueB());
    ui->spinBoxC->setValue(storage->getValueC());
    ui->sliderA->setValue(storage->getValueA());
    ui->sliderB->setValue(storage->getValueB());
    ui->sliderC->setValue(storage->getValueC());
}

MainWindow::~MainWindow()
{
    delete ui;
}
