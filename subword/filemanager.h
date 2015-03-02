#ifndef FILEMANAGER_H
#define FILEMANAGER_H


#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <string.h>

class fileManager : public QObject
{
    Q_OBJECT
public:
    explicit fileManager(QObject *parent = 0);
    ~fileManager();



private:
    // файл словаря
    QFile* sourceFile;
    // файл для записи результата
    QFile* finalFile;
public:
    // контейнер для хранения всех слов
    std::vector<QString> stringVector;

    // сохранение отсортированных слов в файл
    void saveToFile();

    //получение всех подслов,которое содержит слово
    QString getEnterString(QString);
    //заполняет stringVector на основе заданного слова
    int createWordVector(QString);
    // возвращает кол-во слов из вектора,которые содержатся в слове
    int getPowerOfWord(QString);
    // сортирует вектор методом quickSort
    void sortStringVector(std::vector<QString>&,int,int);
    //проверка подстроки
    bool getContain(QString,QString);
public slots:
};

#endif // FILEMANAGER_H
