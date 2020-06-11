#ifndef STEP7_H
#define STEP7_H

#include <QMainWindow>
#include <QNetworkReply>
#include "step10.h"
#include "step11.h"

class step10;
class step11;

namespace Ui {
class step7;
}

class step7 : public QMainWindow
{
    Q_OBJECT

public:
    explicit step7(QWidget *parent = nullptr);
    ~step7();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

public slots:
    void replyFinished(QNetworkReply*);

private:
    void parseJSONResponse(const QByteArray &json);

    void server_request(QString int_file_path, QString mask_dir);

    Ui::step7 *ui;

    step10 *Step10;
    step11 * Step11;
};

#endif // STEP7_H
