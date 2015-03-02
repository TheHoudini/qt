#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);
    // opening vk auth window if user click on auth-vk
    connect(ui->action,SIGNAL(triggered()),this,SLOT(showVkAuth()));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(handleVkReply(QNetworkReply*)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete vkAuthWindow;
    delete manager;
}

void MainWindow::doVkRequest(const char* method ,const char* parameters)
{

    manager->get(QNetworkRequest(QUrl(QString()
                                      .append("https://api.vk.com/method/")
                                      .append(method).append("?")
                                      .append(parameters)
                                      .append("&v=5.24")
                                      .append("&access_token=").append(db.getVkToken())
                                       )
                                 )
                 );


}



void MainWindow::showVkAuth()
{
    vkAuthWindow = new vkWebAuth();
    vkAuthWindow->show();
    // update token for vk,if user passed authentication and allows access vkontakte
    connect(vkAuthWindow,SIGNAL(changeVkToken(QString*)),this,SLOT(updateVkData(QString*)));
}



//[SLOT]
void MainWindow::updateVkData(QString* str)
{
    db.updateVkData(str);
}
//[SLOT]
void MainWindow::handleVkReply(QNetworkReply *reply)
{

    this->ui->textBrowser->setText(reply->readAll());
}
//[SLOT]
void MainWindow::on_pushButton_clicked()
{

    doVkRequest("audio.get.xml","count=2");
}
