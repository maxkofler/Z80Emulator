#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtGui>

MainWindow::MainWindow(Z80* z80emu, Z80Asm* z80asm, QWidget *parent)
    : QMainWindow(parent)
    , _ui(new Ui::MainWindow)
{
    FUN();

    _ui->setupUi(this);

    this->_menuBar = new QMenuBar(nullptr);
    setMenuBar(this->_menuBar);
    this->_menu = new UIMenu(this);

    this->_le_regA = _ui->regA;
    this->_le_regB = _ui->regB;
    this->_le_regC = _ui->regC;
    this->_le_regD = _ui->regD;
    this->_le_regE = _ui->regE;
    this->_le_regH = _ui->regH;
    this->_le_regL = _ui->regL;

    this->_le_regPC = _ui->regPC;

    this->_te_asm = _ui->codeEdit;
    this->_te_asm->setLineWrapMode(QTextEdit::NoWrap);
    this->_te_asm->setTabStopDistance(40);

    this->_bt_asm = _ui->bt_assemble;
    this->_bt_step = _ui->bt_step;

    connect(this->_bt_asm, &QPushButton::clicked, this, &MainWindow::sl_bt_asm_pressed);
    connect(this->_bt_step, &QPushButton::clicked, this, &MainWindow::sl_bt_step_pressed);

    connect(this->_menu, &UIMenu::on_openSource, this, &MainWindow::sl_loadSrc);
    connect(this->_menu, &UIMenu::on_saveSource, this, &MainWindow::sl_saveSrc);
    connect(this->_menu, &UIMenu::on_openHex, this, &MainWindow::sl_loadHex);

    this->_emu = z80emu;
    this->_asm = z80asm;


    this->connectShortcuts();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

