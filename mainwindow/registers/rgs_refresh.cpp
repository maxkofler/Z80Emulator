#include "registers.h"

void Registers::refresh(){
    FUN();

    LOGD("Refreshing CPU registers");

    this->_A->setText(QString().fromStdString(Log::toHexString(this->_emu->A())));
    this->_B->setText(QString().fromStdString(Log::toHexString(this->_emu->B())));
    this->_C->setText(QString().fromStdString(Log::toHexString(this->_emu->C())));
    this->_D->setText(QString().fromStdString(Log::toHexString(this->_emu->D())));
    this->_E->setText(QString().fromStdString(Log::toHexString(this->_emu->E())));
    this->_H->setText(QString().fromStdString(Log::toHexString(this->_emu->H())));
    this->_L->setText(QString().fromStdString(Log::toHexString(this->_emu->L())));

    this->_PC->setText(QString().fromStdString(Log::toHexString(this->_emu->PC())));
}
