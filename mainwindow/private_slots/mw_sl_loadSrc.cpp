#include "mainwindow.h"

#include <fstream>

void MainWindow::sl_loadSrc(QString path){
    FUN();

    std::ifstream file;
    file.open(path.toStdString());

    QString text;
    std::string buf;

    while(!file.eof()){
        getline(file, buf);
        text += QString().fromStdString(buf + "\n");
    }

    this->_te_asm->setText(text);
}
