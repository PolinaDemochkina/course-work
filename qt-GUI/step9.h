#ifndef STEP9_H
#define STEP9_H

#include <QMainWindow>
#include "step6.h"
#include "step10.h"

class step6;
class step10;

namespace Ui {
class step9;
}

class step9 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step9(QWidget *parent = nullptr);
    ~step9();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::step9 *ui;
    step6 *Step6;
    step10 *Step10;
};

#endif // STEP9_H
