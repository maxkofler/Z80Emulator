#include "registers.h"

Registers::Registers(Z80* _emu, Z80Asm* _z80asm){
    FUN();
    this->_emu = _emu;
    this->_z80asm = _z80asm;
}
