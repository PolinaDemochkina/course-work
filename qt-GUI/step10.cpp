#include "step10.h"
#include "ui_step10.h"

step10::step10(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step10)
{
    ui->setupUi(this);
}

step10::~step10()
{
    delete ui;
}

void step10::on_pushButton_7_clicked()
{
    hide();
    Step9 = new step9(this);
    Step9->show();
}

void step10::on_pushButton_8_clicked()
{
    hide();
    Step7 = new step7(this);
    Step7->show();
}
