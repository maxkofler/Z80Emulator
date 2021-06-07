#include "mainwindow.h"

void MainWindow::sl_loadHex(QString path){
    FUN();

    this->_emu->mM->loadProgFromFile(path.toStdString(), 0);
}
