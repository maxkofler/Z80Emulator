#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "z80emu.h"
#include "z80asm.h"

#include "log.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Z80*, Asm*, QWidget *parent = nullptr);
    ~MainWindow();

    void                            refreshCPU();

private slots:
    void                            sl_bt_asm_pressed();

private:
    Ui::MainWindow*                 _ui;
    Z80*                            _emu;
    Asm*                            _asm;

    QLineEdit*                      _le_regA;
    QLineEdit*                      _le_regB;
    QLineEdit*                      _le_regC;
    QLineEdit*                      _le_regD;
    QLineEdit*                      _le_regE;
    QLineEdit*                      _le_regH;
    QLineEdit*                      _le_regL;

    QTextEdit*                      _te_asm;

    QPushButton*                    _bt_asm;
};
#endif // MAINWINDOW_H
