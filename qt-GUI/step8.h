#ifndef STEP8_H
#define STEP8_H

#include <QMainWindow>
#include "step2.h"
#include "step3.h"

class step2;
class step3;

namespace Ui {
class step8;
}

class step8 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step8(QWidget *parent = nullptr);
    ~step8();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    void run_image_processing(QString path, QString json_dir, QString save, QString cut_percentage, QString overlap_percentage, QString image_dir);

private:
    Ui::step8 *ui;
    step3 *Step3;
    step2 *Step2;
};

#endif // STEP8_H
