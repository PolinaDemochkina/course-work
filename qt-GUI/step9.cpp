#include "step9.h"
#include "ui_step9.h"

step9::step9(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step9)
{
    ui->setupUi(this);
}

step9::~step9()
{
    delete ui;
}

void step9::on_pushButton_7_clicked()
{
    hide();
    Step6 = new step6(this);
    Step6->show();
}

void step9::on_pushButton_8_clicked()
{
    hide();
    Step10 = new step10(this);
    Step10->show();
}
