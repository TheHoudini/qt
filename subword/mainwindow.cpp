#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    fileMgr = new fileManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete fileMgr;
}

void MainWindow::on_pushButton_clicked()
{
    // очищаем виджет
    this->ui->listWidget->clear();
    // заполняем вектор на основе слова,содержажегося в lineEdit,в случае успешного заполнения обрабатываем вектор
    if( fileMgr->createWordVector(this->ui->lineEdit->text())){

        // сортировка вектора по кол-ву подслов
        fileMgr->sortStringVector(fileMgr->stringVector,0,fileMgr->stringVector.size()-1);
        // сохраняет результат в файл
        fileMgr->saveToFile();

        // для каждого слова добавляем итем в listWidget
        for(int i = fileMgr->stringVector.size()-1;i!=0;i--){

        this->ui->listWidget->addItem(QString::number(fileMgr->getPowerOfWord(fileMgr->stringVector.at(i)))
                                      .append(". ")
                                      .append(fileMgr->stringVector.at(i))
                                      .append(":")
                                      .append(fileMgr->getEnterString(fileMgr->stringVector.at(i))));
        }
    }else {
        // в случае неудачи выводим сообщение об ошибке
        QMessageBox box;
        box.setText("DICTIONARY NOT FOUND");
        box.exec();
    }

}

