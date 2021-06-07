#include "mainwindow.h"

void MainWindow::refreshCPU(){
    FUN();

    LOGD("Refreshing all CPU values...");

    this->_le_regA->setText(QString().fromStdString(Log::toHexString(this->_emu->A())));
    this->_le_regB->setText(QString().fromStdString(Log::toHexString(this->_emu->B())));
    this->_le_regC->setText(QString().fromStdString(Log::toHexString(this->_emu->C())));
    this->_le_regD->setText(QString().fromStdString(Log::toHexString(this->_emu->D())));
    this->_le_regE->setText(QString().fromStdString(Log::toHexString(this->_emu->E())));
    this->_le_regH->setText(QString().fromStdString(Log::toHexString(this->_emu->H())));
    this->_le_regL->setText(QString().fromStdString(Log::toHexString(this->_emu->L())));

    this->_le_regPC->setText(QString().fromStdString(Log::toHexString(this->_emu->PC())));
}
