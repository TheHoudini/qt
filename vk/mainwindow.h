#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "vkwebauth.h"
#include "dbframework.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void doVkRequest(const char*,const char*);



private slots:
    void showVkAuth();
    void updateVkData(QString*);
    void handleVkReply(QNetworkReply*);
    void on_pushButton_clicked();

private:
    vkWebAuth* vkAuthWindow;
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QFile* xmlReply;


    // class,who work in db
    dbFramework db;


};

#endif // MAINWINDOW_H
