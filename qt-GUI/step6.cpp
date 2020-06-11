#include "step6.h"
#include "ui_step6.h"

step6::step6(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step6)
{
    ui->setupUi(this);
}

step6::~step6()
{
    delete ui;
}

void step6::on_pushButton_7_clicked()
{
    hide();
    Step4 = new step4(this);
    Step4->show();
}

void step6::on_pushButton_8_clicked()
{
    hide();
    Step9 = new step9(this);
    Step9->show();
}
