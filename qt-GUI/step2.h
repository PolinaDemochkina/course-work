#ifndef STEP2_H
#define STEP2_H

#include <QMainWindow>
#include "step8.h"
#include <QDir>

class step8;
class MainWindow;

namespace Ui {
class step2;
}

class step2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step2(QWidget *parent = nullptr);
    ~step2();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::step2 *ui;
    MainWindow *Step1;
    step8 *Step8;
};

#endif // STEP2_H
