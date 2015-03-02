#ifndef VKWEBAUTH_H
#define VKWEBAUTH_H

#include <QWidget>


namespace Ui {
class vkWebAuth;
}

class vkWebAuth : public QWidget
{
    Q_OBJECT

public:
    explicit vkWebAuth(QWidget *parent = 0);
    ~vkWebAuth();
    QString data;
public slots:
    void takeToken();

signals:
    void changeVkToken(QString*);

private:
    QString url;
    Ui::vkWebAuth *ui;
};

#endif // VKWEBAUTH_H
