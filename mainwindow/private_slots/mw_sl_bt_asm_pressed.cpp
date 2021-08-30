#include "mainwindow/mainwindow.h"

#include "parsers/parsertools.h"

#include <fstream>
#include <QMessageBox>

void MainWindow::sl_bt_z80asm_pressed(){
    FUN();

    std::string teContent = this->_te_z80asm->toPlainText().toStdString();

    {
        //A string containing no spaces, newlines, tabs
        std::string checkString = ParserTools::stripChar(teContent, ' ');
        checkString = ParserTools::stripChar(checkString, '\n');
        checkString = ParserTools::stripChar(checkString, '\t');
        if (checkString.empty()){
            size_t id = STARTLOGTRACE();
            LOGE("Not assembling an empty text field!");
            QMessageBox msg;
            msg.setWindowTitle("ASM");
            msg.setInformativeText(QString().fromStdString(LOGTRACE.getLevelTraceStr(id, Log::E, false, false)));
            STOPLOGTRACE(id);
            msg.exec();
            return;
        }
    }

    std::ofstream outfile;
    outfile.open("prog.asm");

    if (outfile.is_open()){
        outfile << this->_te_z80asm->toPlainText().toStdString() << std::endl;
    }

    outfile.close();

    size_t traceId = STARTLOGTRACE();

    this->_z80asm->loadSource("prog.asm");
    //Assemble program with starting address of 0x1000
    if (!this->_z80asm->assemble(0x1000)){
        QMessageBox msg;
        msg.setWindowTitle("ASM error");
        msg.setText("Error in assembling source code:");
        msg.setInformativeText(QString().fromStdString(hlog->trace.getLevelTraceStr(traceId, Log::E, false, false)));
        STOPLOGTRACE(traceId);
        msg.exec();
        return;
    }
    if (!this->_z80asm->link()){
        QMessageBox msg;
        msg.setWindowTitle("ASM error");
        msg.setText("Error in linking source code:");
        msg.setInformativeText(QString().fromStdString(hlog->trace.getLevelTraceStr(traceId, Log::E, false, false)));
        msg.exec();
        STOPLOGTRACE(traceId);
        return;
    }

    outfile.open("prog.hex");

    {
        auto prog = this->_z80asm->getProg();
        for (auto i : prog){
            outfile << i;
        }
    }

    outfile.close();

    //Load program at 0x0000 and point PC to 0x1000 (start)
    this->_emu->mM->loadProgFromFile("prog.hex", 0x0000);
    this->_emu->PC(0x1000);
    this->_emu->HALT(false);

    hlog->trace.stopTrace(traceId);

    this->refreshCPU();

    LOGD("Loaded new program");
}
