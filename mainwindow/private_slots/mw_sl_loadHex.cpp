#include "mainwindow.h"

void MainWindow::sl_loadHex(QString path){
    FUN();

    this->_emu->mM->loadProgFromFile(path.toStdString(), 0);
    this->_emu->PC(0x0000);
    this->_emu->HALT(false);
}
