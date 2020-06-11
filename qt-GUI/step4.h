#ifndef STEP4_H
#define STEP4_H

#include <QMainWindow>
#include "step5.h"
#include "step6.h"

class step5;
class step6;

namespace Ui {
class step4;
}

class step4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step4(QWidget *parent = nullptr);
    ~step4();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

private:
    void run_autoPipeline(QString path, QString pipeline_path, QString train_steps, QString label_map_path, QString size, QString fine_tune_checkpoint, QString train_path, QString test_path, QString save_dir, QString obj_det);

private:
    Ui::step4 *ui;
    step5 *Step5;
    step6 *Step6;
};

#endif // STEP4_H
