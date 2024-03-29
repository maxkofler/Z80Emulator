#ifndef MAINWINDOW_H
#define MAINWINDOW_H

class MainWindow;

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>

#include "z80emu.h"
#include "z80asm.h"

#include "uimenu.h"
#include "registers.h"

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

    Ui::MainWindow*                 get(){return this->_ui;}

private slots:
    void                            sl_bt_z80asm_pressed();
    void                            sl_bt_step_pressed();

    void                            sl_loadSrc(QString);
    void                            sl_saveSrc(QString);
    void                            sl_loadHex(QString);

private:
    Ui::MainWindow*                 _ui;
    Z80*                            _emu;
    Z80Asm*                         _z80asm;

    //UI fragments
    Registers*                      _registers;

    QTextEdit*                      _te_z80asm;
    QTableView*                     _tv_z80mem;
    QStandardItemModel              _md_mem;
    QStandardItem**                 _it_mem;

    QPushButton*                    _bt_z80asm;
    QPushButton*                    _bt_step;

    //Menu
    QMenuBar*                       _menuBar;
    UIMenu*                         _menu;
};
#endif // MAINWINDOW_H
