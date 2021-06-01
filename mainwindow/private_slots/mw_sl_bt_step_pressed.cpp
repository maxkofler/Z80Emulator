#include "mainwindow/mainwindow.h"

void MainWindow::sl_bt_step_pressed(){
    FUN();

    Z80EmuInstrucion is;
    is = this->_emu->iManager->fetchIS();
    this->_emu->iManager->execIS(is);
    this->_emu->iManager->finalizeIS(is);
    this->_emu->logState();
    this->refreshCPU();
}
