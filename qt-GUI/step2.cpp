#include "step2.h"
#include "ui_step2.h"
#include <QDesktopServices>
#include <QDir>
#include <QDirIterator>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>

step2::step2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step2)
{
    ui->setupUi(this);
}

step2::~step2()
{
    delete ui;
}

void step2::on_pushButton_8_clicked()
{
    hide();
    Step8 = new step8(this);
    Step8->show();
}

void step2::on_pushButton_4_clicked()
{
    QString link = "https://github.com/microsoft/VoTT/releases";
    QDesktopServices::openUrl(QUrl(link));
}

void step2::on_pushButton_clicked()
{
    QString path = QCoreApplication::applicationDirPath() + "/../../vott_path.txt";
    if ((QFileInfo::exists(path) && QFileInfo(path).isFile()) != true)
    {
        QString filePath=QFileDialog::getOpenFileName(this, "Configure path to vott.exe", "/home", "(*.exe)");
        QFile file( path );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << filePath << endl;
        }
    }

    QFile file(path);
    QString vott;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        vott = stream.readLine();
    }
        file.close();

    if(vott != "")
    {
        QDesktopServices::openUrl(QUrl("file:///"+vott, QUrl::TolerantMode));
    }
}
