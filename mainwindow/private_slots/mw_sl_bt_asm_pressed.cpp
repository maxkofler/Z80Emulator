#include "mainwindow/mainwindow.h"

#include <fstream>
#include <QMessageBox>

void MainWindow::sl_bt_asm_pressed(){
    FUN();

    std::ofstream outfile;
    outfile.open("prog.asm");

    if (outfile.is_open()){
        outfile << this->_te_asm->toPlainText().toStdString() << std::endl;
    }

    outfile.close();

    this->_asm->loadSource("prog.asm");
    if (!this->_asm->assemble(0x0000)){
        QMessageBox msg;
        msg.setWindowTitle("ASM error");
        msg.setText("Error in assembling this file!");
        msg.exec();
        return;
    }
    if (!this->_asm->link()){
        QMessageBox msg;
        msg.setWindowTitle("ASM error");
        msg.setText("Error in linking this file!");
        msg.exec();
        return;
    }

    outfile.open("prog.hex");

    {
        auto prog = this->_asm->getProg();
        for (auto i : prog){
            outfile << i;
        }
    }

    outfile.close();

    this->_emu->mM->loadProgFromFile("prog.hex", 0x0000);
    this->_emu->PC(0x0000);
    this->_emu->HALT(false);

    LOGD("Loaded new program");
}
