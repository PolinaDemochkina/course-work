#include "step5.h"
#include "ui_step5.h"
#include "QFileDialog"

#include <QProcess>

step5::step5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step5)
{
    ui->setupUi(this);
}

step5::~step5()
{
    delete ui;
}

void step5::on_pushButton_7_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with the input images");
    ui->textEdit_5->setText(filePath);
}

void step5::on_pushButton_8_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with the json files (from VOTT)");
    ui->textEdit_6->setText(filePath);
}

void step5::on_pushButton_9_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder to save the result");
    ui->textEdit_7->setText(filePath);
}

class step4;
class stpe6;

void step5::on_pushButton_10_clicked()
{
    hide();
    Step3 = new step3(this);
    Step3->show();
}

void step5::on_pushButton_11_clicked()
{
    hide();
    Step4 = new step4(this);
    Step4->show();
}

void step5::run_to_object_detection(QString path, QString input, QString json, QString save, QString label_map, QString object_detection)
{
    QString  command("python");
    QStringList params = QStringList() << "to_object_detection.py" << input << json << save << label_map << object_detection;
    QProcess process;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    process.setWorkingDirectory(path);
    process.start(command, params);
    //QProcess::startDetached(command, params, path);
    process.waitForFinished(-1);
    QApplication::restoreOverrideCursor();
}

void step5::on_pushButton_clicked()
{
    QString path = QCoreApplication::applicationDirPath() + "/../../obj_det_path.txt";
    if ((QFileInfo::exists(path) && QFileInfo(path).isFile()) != true)
    {
        QString filePath=QFileDialog::getExistingDirectory(this, "Configure path to Object Detection API");
        QFile file( path );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << filePath << endl;
        }
    }

    QFile file(path);
    QString object_detection;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        object_detection = stream.readLine();
    }
    file.close();



    QString input = ui->textEdit_5->toPlainText();
    QString json = ui->textEdit_6->toPlainText();
    QString save = ui->textEdit_7->toPlainText();
    QString label_map = ui->textEdit_8->toPlainText();

    path = QCoreApplication::applicationDirPath() + "/../../scripts/";

    run_to_object_detection(path, input, json, save, label_map, object_detection);
}

void step5::on_pushButton_12_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, "Choose a folder with label_map.pbtxt", "/home", "(*.pbtxt)");
    ui->textEdit_8->setText(filePath);
}
