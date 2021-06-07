#ifndef REGISTERS_H
#define REGISTERS_H

class Registers;

#include <QObject>
#include <QMainWindow>
#include <QLineEdit>

#include "mainwindow.h"

#include "z80asm.h"
#include "z80emu.h"

class Registers : public QObject
{
    Q_OBJECT
public:
    Registers(Z80* _emu, Z80Asm* _asm);

    void                                refresh();

    friend class                        MainWindow;
private:
    Z80*                                _emu;
    Z80Asm*                             _asm;

    QLineEdit*                          _A;
    QLineEdit*                          _B;
    QLineEdit*                          _C;
    QLineEdit*                          _D;
    QLineEdit*                          _E;
    QLineEdit*                          _H;
    QLineEdit*                          _L;
    QLineEdit*                          _PC;
};

#endif // REGISTERS_H
