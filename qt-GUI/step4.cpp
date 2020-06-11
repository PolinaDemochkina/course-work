#include "step4.h"
#include "ui_step4.h"

#include "QFileDialog"
#include <QDebug>
#include <QProcess>

step4::step4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step4)
{
    ui->setupUi(this);
    ui->comboBox->addItem("ssd_mobilenet");
    ui->comboBox->addItem("ssd_inception");
    ui->comboBox->addItem("faster_rcnn_inception");
}

step4::~step4()
{
    delete ui;
}

void step4::on_pushButton_4_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, "Path to label_map.pbtxt", "/home", "(*.pbtxt)");
    ui->textEdit_2->setText(filePath);
}

void step4::on_pushButton_6_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, "Path to train_ds", "/home", "(*.record)");
    ui->textEdit_4->setText(filePath);
}

void step4::on_pushButton_7_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, "Path to test_ds", "/home", "(*.record)");
    ui->textEdit_5->setText(filePath);
}

void step4::on_pushButton_8_clicked()
{
    hide();
    Step5 = new step5(this);
    Step5->show();
}

void step4::on_pushButton_9_clicked()
{
    hide();
    Step6 = new step6(this);
    Step6->show();
}

void step4::on_pushButton_10_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Path to a directory to save the result");
    ui->textEdit->setText(filePath);
}

void step4::run_autoPipeline(QString path, QString pipeline_path, QString train_steps, QString label_map_path, QString size, QString fine_tune_checkpoint, QString train_path, QString test_path, QString save_dir, QString obj_det)
{
    QString  command("python");
    QStringList params = QStringList()<<"autoPipeline.py"<<pipeline_path<<train_steps<<label_map_path<<size<<fine_tune_checkpoint<<train_path<<test_path<<save_dir<<obj_det;
    QProcess process;
    QApplication::setOverrideCursor(Qt::WaitCursor);
    process.setWorkingDirectory(path);
    process.start(command, params);
    //QProcess::startDetached(command, params, path);
    process.waitForFinished(-1);
    QApplication::restoreOverrideCursor();
}

void step4::on_pushButton_clicked()
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
    QString obj_det;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        obj_det = stream.readLine();
    }
    file.close();

    QString model = ui->comboBox->currentText();
    QString pipeline_path;
    QString fine_tune_checkpoint;
    if(model == "ssd_mobilenet")
    {
        pipeline_path = QCoreApplication::applicationDirPath() + "/../../pipelines/ssd_mobilenet.config";
        fine_tune_checkpoint = QCoreApplication::applicationDirPath() + "/../../pipelines/ssd_mobilenet_v1_coco_2018_01_28/model.ckpt";
    }
    else if(model == "ssd_inception")
    {
        pipeline_path = QCoreApplication::applicationDirPath() + "/../../pipelines/ssd_inception.config";
        fine_tune_checkpoint = QCoreApplication::applicationDirPath() + "/../../pipelines/ssd_inception_v2_coco_2018_01_28/model.ckpt";
    }
    else
    {
        pipeline_path = QCoreApplication::applicationDirPath() + "/../../pipelines/rcnn_inception.config";
        fine_tune_checkpoint = QCoreApplication::applicationDirPath() + "/../../pipelines/faster_rcnn_inception_v2_coco_2018_01_28/model.ckpt";
    }
    QString train_steps = ui->spinBox->text();
    QString size = "512";
    QString label_map_path = ui->textEdit_2->toPlainText();
    QString train_path = ui->textEdit_4->toPlainText();
    QString test_path = ui->textEdit_5->toPlainText();
    QString save_dir = ui->textEdit->toPlainText();
    path = QCoreApplication::applicationDirPath() + "/../../scripts/";

    run_autoPipeline(path, pipeline_path, train_steps, label_map_path, size, fine_tune_checkpoint, train_path, test_path, save_dir, obj_det);
}
