#include "step8.h"
#include "ui_step8.h"

#include <QFileDialog>
#include <QProcess>

step8::step8(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step8)
{
    ui->setupUi(this);
}

step8::~step8()
{
    delete ui;
}

void step8::on_pushButton_7_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with the input images");
    ui->textEdit_5->setText(filePath);
}

void step8::on_pushButton_8_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder to save the result");
    ui->textEdit_6->setText(filePath);
}

void step8::run_image_processing(QString path, QString json_dir, QString save, QString cut_percentage, QString overlap_percentage, QString image_dir)
{
    QString  command("python");
    QStringList params = QStringList() << "image_processing.py" << json_dir << save << cut_percentage << overlap_percentage << image_dir;
    QProcess process;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    process.setWorkingDirectory(path);
    process.start(command, params);
    //QProcess::startDetached(command, params, path);
    process.waitForFinished(-1);
    QApplication::restoreOverrideCursor();
}

void step8::on_pushButton_clicked()
{
    QString image_dir = ui->textEdit_5->toPlainText();
    QString save = ui->textEdit_6->toPlainText();
    QString cut_percentage = ui->doubleSpinBox->text().replace(",",".");
    QString overlap_percentage = ui->doubleSpinBox_2->text().replace(",",".");
    QString json_dir = ui->textEdit_7->toPlainText();

    QString path = QCoreApplication::applicationDirPath() + "/../../scripts/";

    run_image_processing(path, json_dir, save, cut_percentage, overlap_percentage, image_dir);
}

void step8::on_pushButton_9_clicked()
{
    hide();
    Step2 = new step2(this);
    Step2->show();
}

void step8::on_pushButton_10_clicked()
{
    hide();
    Step3 = new step3(this);
    Step3->show();
}

void step8::on_pushButton_11_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Path to the json directory");
    ui->textEdit_7->setText(filePath);
}
