#ifndef STEP10_H
#define STEP10_H

#include <QMainWindow>
#include "step7.h"
#include "step9.h"

class step7;
class step9;

namespace Ui {
class step10;
}

class step10 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step10(QWidget *parent = nullptr);
    ~step10();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::step10 *ui;
    step7 *Step7;
    step9 *Step9;
};

#endif // STEP10_H
