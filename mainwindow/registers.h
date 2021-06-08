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

    void                                connectSlots();

    friend class                        MainWindow;

private slots:
    void                                sl_p_A_ch();
    void                                sl_p_B_ch();
    void                                sl_p_C_ch();
    void                                sl_p_D_ch();
    void                                sl_p_E_ch();
    void                                sl_p_H_ch();
    void                                sl_p_L_ch();

    void                                sl_p_PC_ch();

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
