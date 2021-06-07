#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

#include "z80emu.h"
#include "z80asm.h"

#include "uimenu.h"

#include "log.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Z80*, Z80Asm*, QWidget *parent = nullptr);
    ~MainWindow();

    void                            refreshCPU();

    void                            connectShortcuts();

    QMenu*                          newMenu(QString name);

private slots:
    void                            sl_bt_asm_pressed();
    void                            sl_bt_step_pressed();

    void                            sl_loadSrc(QString);
    void                            sl_saveSrc(QString);
    void                            sl_loadHex(QString);

private:
    Ui::MainWindow*                 _ui;
    Z80*                            _emu;
    Z80Asm*                         _asm;

    QLineEdit*                      _le_regA;
    QLineEdit*                      _le_regB;
    QLineEdit*                      _le_regC;
    QLineEdit*                      _le_regD;
    QLineEdit*                      _le_regE;
    QLineEdit*                      _le_regH;
    QLineEdit*                      _le_regL;

    QLineEdit*                      _le_regPC;

    QTextEdit*                      _te_asm;

    QPushButton*                    _bt_asm;
    QPushButton*                    _bt_step;

    //Menu
    QMenuBar*                       _menuBar;
    UIMenu*                         _menu;
};
#endif // MAINWINDOW_H
