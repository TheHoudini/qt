#include "filemanager.h"


fileManager::fileManager(QObject *parent) : QObject(parent)
{

    sourceFile = new QFile("source.txt");
}



int fileManager::createWordVector(QString str)
{
    stringVector.clear();
    if(!sourceFile->open(QIODevice::ReadOnly | QIODevice::Text)){
      qDebug() << "file not found";
      return 0;
    } else
    {
        qDebug() << "writing..";
        QString string;
        while(!sourceFile->atEnd()){
            string = sourceFile->readLine();
            if(string.contains(str)){
            stringVector.push_back(string);
            }


        }

    }
    sourceFile->close();
    return 1;

}



int fileManager::getPowerOfWord(QString str)
{
   int power = 0;
   QString buf;

   for (unsigned int i=0; i < stringVector.size() ; i++ ){

       if(getContain(str,stringVector.at(i))){
           power++;
       }
   }

   return power;
}

void fileManager::sortStringVector(std::vector<QString> &vec, int left, int right) {


      qDebug() << left << " " << right;
      int i = left, j = right;
      int pivot = getPowerOfWord(vec[(left + right) / 2]);

      while (i <= j) {
            while (getPowerOfWord(vec[i]) < pivot)
                  i++;
            while (getPowerOfWord(vec[j]) > pivot)
                  j--;
            if (i <= j) {
                  std::swap(vec[i],vec[j]);
                  i++;
                  j--;
            }
      };

      if (left < j)
            sortStringVector(vec, left, j);
      if (i < right)
          sortStringVector(vec, i, right);
}

bool fileManager::getContain(QString str1,  QString str2)
{
   bool flag = false;
    for(int i = 0; i< str1.size();i++){
        if(flag) {
            break;
        }
        if(str1[i]==str2[0]){
            flag = true;
            for(int j = 0;j<str2.size()-1;j++){

                if(i+j > str1.size()){
                 flag = false;
                 break;
                }else if(str1[i+j] != str2[j]){
                    flag= false ;
                    break;
                }
            }




        }

    }


    return flag;
}




fileManager::~fileManager()
{
    delete sourceFile;
    delete finalFile;
}

void fileManager::saveToFile()
{
    finalFile = new QFile("result.txt");
    finalFile->open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    QTextStream out(finalFile);

    for(int i = stringVector.size()-1;i!=0;i--){
        out << stringVector.at(i) << "consist of" << getPowerOfWord(stringVector.at(i)) << " words :"
                << getEnterString(stringVector.at(i)) << "\n\n";
    }


}

QString fileManager::getEnterString(QString str)
{
    QString res;
    for (unsigned int i=0; i < stringVector.size() ; i++ ){

        if(getContain(str,stringVector.at(i))){
            res.append(stringVector.at(i)).append(" ");
        }
    }
    return res;
}



