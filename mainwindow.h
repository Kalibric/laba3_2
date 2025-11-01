#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "storage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void textEditedA();
    void textEditedB();
    void textEditedC();
    void spinEditedA();
    void spinEditedB();
    void spinEditedC();
    void sliderEditedA();
    void sliderEditedB();
    void sliderEditedC();
    void updateValues();


private:
    Ui::MainWindow *ui;
    Storage *storage = new Storage(this);;
    void closeEvent(QCloseEvent *event);


};
#endif // MAINWINDOW_H
