#ifndef DBFRAMEWORK_H
#define DBFRAMEWORK_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

class dbFramework : public QObject
{
    Q_OBJECT
public:
    explicit dbFramework(QObject *parent = 0);

    ~dbFramework();

    // token update
    void updateVkData(QString*);
    // token and user_id update
    void updateVkData(QString*,QString*);


    QString getVkToken();
signals:

public slots:

private:

    QSqlDatabase db;
    QSqlQuery* query;

};

#endif // DBFRAMEWORK_H
