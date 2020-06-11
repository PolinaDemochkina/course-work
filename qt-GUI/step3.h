#ifndef STEP3_H
#define STEP3_H

#include <QMainWindow>
#include "step8.h"
#include "step5.h"

class step8;
class step5;

namespace Ui {
class step3;
}

class step3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step3(QWidget *parent = nullptr);
    ~step3();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

private:
    void run_createLabelMap(QString json, QString save, QString path);

private:
    Ui::step3 *ui;
    step8 *Step8;
    step5 *Step5;
};

#endif // STEP3_H
