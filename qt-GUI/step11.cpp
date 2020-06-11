#include "step11.h"
#include "ui_step11.h"

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

step11::step11(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::step11)
{
    ui->setupUi(this);
}

step11::~step11()
{
    delete ui;
}

void step11::on_pushButton_7_clicked()
{
    hide();
    Step7 = new step7(this);
    Step7->show();
}

void step11::on_pushButton_5_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with images to evaluate");
    ui->textEdit_3->setText(filePath);
}

void step11::replyFinished(QNetworkReply* reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "Reponse network error:" << reply->error();
    qDebug() << "Reponse HTTP status code:" << statusCode;
    QByteArray content=reply->readAll();
    qDebug() << "Reply content:" << content<<'\n';
    parseJSONResponse(content);
    reply->deleteLater();
}

void step11::parseJSONResponse(const QByteArray &json)
{
   QJsonDocument jsonDocument(QJsonDocument::fromJson(json));
   QJsonObject jsonObject = jsonDocument.object();
   QString recognitionResults="";
   if (jsonObject.contains("detection_results"))
   {
    QJsonValue val=jsonObject["detection_results"];

    QJsonObject detectionResults=val.toObject();
    foreach(const QString& key, detectionResults.keys()) {
        recognitionResults="";
        QJsonValue value = detectionResults[key];
        QJsonArray jsonArray=value.toArray();
        foreach (const QJsonValue & val, jsonArray) {
            //qDebug()<<val;
            QJsonArray jsonArray2=val.toArray();
            if(recognitionResults.size()>0)
                recognitionResults+=", ";
            recognitionResults+=jsonArray2[0].toString();//+" ("+QString::number(jsonArray2[2].toInt())+"%)";
        }
        ui->listWidgetRecognitionResults->addItem(key+": "+recognitionResults);
    }
   }

   if (jsonObject.contains("precision"))
    {
        ui->listWidgetRecognitionResults->addItem("precision: "+jsonObject["precision"].toVariant().toString());
    }

    if (jsonObject.contains("recall"))
    {
        ui->listWidgetRecognitionResults->addItem("recall: "+jsonObject["recall"].toVariant().toString());
    }
}

void step11::server_request(QString image_dir, QString json_dir)
{
    QUrl url("http://localhost:5000/process_request");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject data;
    data.insert("image_dir", QJsonValue::fromVariant(image_dir));
    data.insert("json_dir", QJsonValue::fromVariant(json_dir));

    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    manager->post(request, QJsonDocument(data).toJson());
}

void step11::on_pushButton_clicked()
{
    // arguments
    QString image_dir = ui->textEdit_3->toPlainText();
    QString json_dir = ui->textEdit_4->toPlainText();

    ui->listWidgetRecognitionResults->clear();

    // POST request to a flask server
    server_request(image_dir, json_dir);

}

void step11::on_pushButton_6_clicked()
{
    QString filePath=QFileDialog::getExistingDirectory(this, "Choose a folder with jsons");
    ui->textEdit_4->setText(filePath);
}
