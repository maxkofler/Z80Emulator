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

    this->_registers = new Registers(z80emu, z80asm);

    this->_registers->_A = _ui->regA;
    this->_registers->_B = _ui->regB;
    this->_registers->_C = _ui->regC;
    this->_registers->_D = _ui->regD;
    this->_registers->_E = _ui->regE;
    this->_registers->_H = _ui->regH;
    this->_registers->_L = _ui->regL;
    this->_registers->_PC = _ui->regPC;
    this->_registers->_SP = _ui->regSP;

    this->_registers->connectSlots();

    this->_te_z80asm = _ui->codeEdit;
    this->_te_z80asm->setLineWrapMode(QTextEdit::NoWrap);
    this->_te_z80asm->setTabStopDistance(40);

    {//Create memory view
        this->_tv_z80mem = _ui->memView;
        QStandardItemModel _md_mem(UINT16_MAX, 2, this);
        this->_it_mem = new QStandardItem*[UINT16_MAX];
        QStandardItem *it_addr;
        QStandardItem *it_cont;

        //Switch level to Debug to supress all the MEMORY logs when loading in memory
        //int levelCache = hlog->getLevel();
        //hlog->setLevel(levelCache-1);

        //Load in all memory addresses
        for (uint16_t i = 0; i < UINT16_MAX; i++){
            it_addr = new QStandardItem(QString().fromStdString(Log::toPHexString(i)));
            it_cont = new QStandardItem(QString().fromStdString(Log::toPHexString(z80emu->mM->get(i))));
            this->_md_mem.setItem(i, 0, it_addr);
            this->_md_mem.setItem(i, 1, it_cont);
        }

        //Reset loglevel
        //hlog->setLevel(levelCache);
    }

    this->_tv_z80mem->setModel(&this->_md_mem);

    this->_bt_z80asm = _ui->bt_assemble;
    this->_bt_step = _ui->bt_step;

    connect(this->_bt_z80asm, &QPushButton::clicked, this, &MainWindow::sl_bt_z80asm_pressed);
    connect(this->_bt_step, &QPushButton::clicked, this, &MainWindow::sl_bt_step_pressed);

    connect(this->_menu, &UIMenu::on_openSource, this, &MainWindow::sl_loadSrc);
    connect(this->_menu, &UIMenu::on_saveSource, this, &MainWindow::sl_saveSrc);
    connect(this->_menu, &UIMenu::on_openHex, this, &MainWindow::sl_loadHex);

    this->_emu = z80emu;
    this->_z80asm = z80asm;


    this->connectShortcuts();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

