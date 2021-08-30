#include "registers.h"

void Registers::connectSlots(){
    FUN();

    connect(this->_A, &QLineEdit::textChanged, this, &Registers::sl_p_A_ch);
    connect(this->_B, &QLineEdit::textChanged, this, &Registers::sl_p_B_ch);
    connect(this->_C, &QLineEdit::textChanged, this, &Registers::sl_p_C_ch);
    connect(this->_D, &QLineEdit::textChanged, this, &Registers::sl_p_D_ch);
    connect(this->_E, &QLineEdit::textChanged, this, &Registers::sl_p_E_ch);
    connect(this->_H, &QLineEdit::textChanged, this, &Registers::sl_p_H_ch);
    connect(this->_L, &QLineEdit::textChanged, this, &Registers::sl_p_L_ch);

    connect(this->_PC, &QLineEdit::textChanged, this, &Registers::sl_p_PC_ch);
    connect(this->_SP, &QLineEdit::textChanged, this, &Registers::sl_p_SP_ch);
}
