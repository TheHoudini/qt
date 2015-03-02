#include "vkwebauth.h"
#include "ui_vkwebauth.h"
#include <QDebug>

vkWebAuth::vkWebAuth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vkWebAuth)
{
    ui->setupUi(this);
    // opening the login page for the token.
    ui->webView->load(QUrl("https://oauth.vk.com/authorize?client_id=4532036&scope=audio&redirect_uri=https://oauth.vk.com/blank.html&response_type=token"));
    //will take place when the user authorization, he will go to the page with the token
    // takeToken checks whether the address bar token and, if so, sends it to record in DB
    connect(ui->webView,SIGNAL(loadFinished(bool)),this,SLOT(takeToken()));
}

vkWebAuth::~vkWebAuth()
{
    delete ui;
}

void vkWebAuth::takeToken()
{
    // record url to string
    url = ui->webView->url().toString();

    // check url that contains the token and record token to url(if it is)
    if(url.startsWith("https://oauth.vk.com/blank.html#access_token=")){
            data.append( url.midRef(url.indexOf("token=")+6,url.indexOf("&expires")-url.indexOf("token=")-6))  ;

            // signal to alert the main window to update the token
            emit changeVkToken(&data);
    }


}
