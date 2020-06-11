#ifndef STEP11_H
#define STEP11_H

#include <QMainWindow>
#include <QNetworkReply>
#include "step7.h"

class step7;

namespace Ui {
class step11;
}

class step11 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step11(QWidget *parent = nullptr);
    ~step11();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

public slots:
    void replyFinished(QNetworkReply*);

private:
    void parseJSONResponse(const QByteArray &json);

    void server_request(QString image_dir, QString json_dir);

    Ui::step11 *ui;
    step7 *Step7;
};

#endif // STEP11_H
