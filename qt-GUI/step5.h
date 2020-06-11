#ifndef STEP5_H
#define STEP5_H

#include <QMainWindow>
#include "step4.h"
#include "step3.h"

class step4;
class step3;

namespace Ui {
class step5;
}

class step5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step5(QWidget *parent = nullptr);
    ~step5();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_12_clicked();

private:
    void run_to_object_detection(QString path, QString input, QString json, QString save, QString label_map, QString object_detection);

private:
    Ui::step5 *ui;
    step4 *Step4;
    step3 *Step3;
};

#endif // STEP5_H
