#include "mainwindow/mainwindow.h"

#include <QMessageBox>

void MainWindow::sl_bt_step_pressed(){
    FUN();

    if (!this->_emu->HALT()){
        Z80EmuInstrucion is;
        is = this->_emu->iManager->fetchIS();
        this->_emu->iManager->execIS(is);
        this->_emu->iManager->finalizeIS(is);
        this->refreshCPU();
    }else{
        QMessageBox msg;
        msg.setText("CPU is currently in HALT-state!");
        msg.setWindowTitle("HALT");
        msg.exec();
    }
}
