#include "step7.h"
#include "ui_step7.h"

#include <QFileDialog>
#include <qnetwork.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QEventLoop>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QSslSocket>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

step7::step7(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step7)
{
    ui->setupUi(this);
}

step7::~step7()
{
    delete ui;
}

void step7::on_pushButton_7_clicked()
{
    hide();
    Step10 = new step10(this);
    Step10->show();
}

void step7::on_pushButton_5_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this, "Choose valid file of original image",QString(),tr("INT (*.int);; Images (*.png *.jpg *.jpeg)"));
    ui->textEdit_3->setText(filePath);
}

void step7::replyFinished(QNetworkReply* reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Reponse network error:" << reply->error();
    qDebug() << "Reponse HTTP status code:" << statusCode;
    QByteArray content=reply->readAll();
    qDebug() << "Reply content:" << content<<'\n';
    parseJSONResponse(content);
    reply->deleteLater();
}

void step7::parseJSONResponse(const QByteArray &json)
{
   QJsonDocument jsonDocument(QJsonDocument::fromJson(json));
   QJsonObject jsonObject = jsonDocument.object();
   QString recognitionResults="";
   if (jsonObject.contains("detection_result"))
   {
    QJsonValue val=jsonObject["detection_result"];
    QJsonArray jsonArray=val.toArray();
    foreach (const QJsonValue & val, jsonArray) {
        //qDebug()<<val;
        QJsonArray jsonArray2=val.toArray();
        if(recognitionResults.size()>0)
            recognitionResults+=", ";
        recognitionResults+=jsonArray2[0].toString();
    }
    ui->label_detections->setText(recognitionResults);
   }

   if (jsonObject.contains("output_file"))
    {
       QPixmap pix(jsonObject["output_file"].toVariant().toString());
       int w = ui->label_output_image->width();
       int h = ui->label_output_image->height();
       ui->label_output_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void step7::server_request(QString int_file_path, QString mask_dir)
{
    QUrl url("http://localhost:5000/process_request");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject data;
    data.insert("int_file", QJsonValue::fromVariant(int_file_path));
    data.insert("mask_dir", QJsonValue::fromVariant(mask_dir));

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    manager->post(request, QJsonDocument(data).toJson());
}

void step7::on_pushButton_clicked()
{
    // arguments
    QString int_file_path = ui->textEdit_3->toPlainText();
    QString mask_dir = ui->textEdit_4->toPlainText();

    ui->label_output_image->clear();
    ui->label_detections->clear();
    // POST request to a flask server
    server_request(int_file_path, mask_dir);

}

void step7::on_pushButton_6_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with jsons");
    ui->textEdit_4->setText(filePath);
}

void step7::on_pushButton_8_clicked()
{
    hide();
    Step11 = new step11(this);
    Step11->show();

}
