#ifndef STEP6_H
#define STEP6_H

#include <QMainWindow>
#include "step4.h"
#include "step9.h"

class step4;
class step9;

namespace Ui {
class step6;
}

class step6 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step6(QWidget *parent = nullptr);
    ~step6();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::step6 *ui;
    step4 *Step4;
    step9 *Step9;
};

#endif // STEP6_H
