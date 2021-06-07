#include "registers.h"

Registers::Registers(Z80* _emu, Z80Asm* _asm){
    FUN();
    this->_emu = _emu;
    this->_asm = _asm;
}
