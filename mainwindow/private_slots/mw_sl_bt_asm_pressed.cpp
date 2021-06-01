#include "mainwindow/mainwindow.h"

#include <fstream>

void MainWindow::sl_bt_asm_pressed(){
    FUN();

    std::ofstream outfile;
    outfile.open("prog.asm");

    if (outfile.is_open()){
        outfile << this->_te_asm->toPlainText().toStdString() << std::endl;
    }

    outfile.close();

    this->_asm->loadSource("prog.asm");
    this->_asm->assemble(0x0000);
    this->_asm->link();

    outfile.open("prog.hex");

    {
        auto prog = this->_asm->getProg();
        for (auto i : prog){
            outfile << prog.at(i);
        }
    }

    outfile.close();

    this->_emu->mM->loadProgFromFile("prog.hex", 0x0000);

    LOGD("Loaded new program");
}
