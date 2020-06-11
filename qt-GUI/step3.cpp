#include "step3.h"
#include "ui_step3.h"
#include "QFileDialog"

#include <QProcess>

step3::step3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step3)
{
    ui->setupUi(this);
}

step3::~step3()
{
    delete ui;
}

void step3::on_pushButton_4_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with the result from tagging images using VOTT (json files)");
    ui->textEdit_2->setText(filePath);
}

void step3::on_pushButton_5_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder to save the result");
    ui->textEdit->setText(filePath);
}

void step3::on_pushButton_7_clicked()
{
    hide();
    Step8 = new step8(this);
    Step8->show();
}

void step3::on_pushButton_8_clicked()
{
    hide();
    Step5 = new step5(this);
    Step5->show();
}

void step3::run_createLabelMap(QString json, QString save, QString path)
{
    QString  command("python");
    QStringList params = QStringList() << "createLabelMap.py" << json << save;

    QProcess process;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    process.setWorkingDirectory(path);
    process.start(command, params);
    //QProcess::startDetached(command, params, path);
    process.waitForFinished(-1);
    QApplication::restoreOverrideCursor();
}

void step3::on_pushButton_clicked()
{
    QString json = ui->textEdit_2->toPlainText();
    QString save = ui->textEdit->toPlainText();
    QString path = QCoreApplication::applicationDirPath() + "/../../scripts/";
    run_createLabelMap(json, save, path);
}
