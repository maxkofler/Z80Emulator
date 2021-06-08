#include "registers.h"

void Registers::refresh(){
    FUN();

    LOGD("Refreshing CPU registers");

    this->_A->setText(QString().fromStdString(Log::toPHexString(this->_emu->A())));
    this->_B->setText(QString().fromStdString(Log::toPHexString(this->_emu->B())));
    this->_C->setText(QString().fromStdString(Log::toPHexString(this->_emu->C())));
    this->_D->setText(QString().fromStdString(Log::toPHexString(this->_emu->D())));
    this->_E->setText(QString().fromStdString(Log::toPHexString(this->_emu->E())));
    this->_H->setText(QString().fromStdString(Log::toPHexString(this->_emu->H())));
    this->_L->setText(QString().fromStdString(Log::toPHexString(this->_emu->L())));

    this->_PC->setText(QString().fromStdString(Log::toPHexString(this->_emu->PC())));
}
