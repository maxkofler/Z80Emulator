#include "registers.h"

#include <QMessageBox>

void Registers::sl_p_PC_ch(){
    FUN();
    std::string reg = this->_PC->text().toStdString();
    if (reg.length() >= 2){
        try{
            this->_emu->PC(stoul(reg, nullptr, 16));
        }catch(...){
            size_t trID = STARTLOGTRACE();
            LOGE("Invalid argument for register PC");
            QMessageBox msg;
            msg.setWindowTitle("Invalid value");
            msg.setInformativeText(QString().fromStdString(LOGTRACE.getLevelTraceStr(trID, Log::E, false, false)));
            msg.exec();
            STOPLOGTRACE(trID);
        }

        this->refresh();
    }
}
