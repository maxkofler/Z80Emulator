#include "registers.h"

#include <QMessageBox>

void Registers::sl_p_SP_ch(){
    FUN();
    std::string reg = this->_SP->text().toStdString();
    if (reg.length() >= 2){
        try{
            this->_emu->SP(stoul(reg, nullptr, 16));
        }catch(...){
            size_t trID = STARTLOGTRACE();
            LOGE("Invalid argument for register SP");
            QMessageBox msg;
            msg.setWindowTitle("Invalid value");
            msg.setInformativeText(QString().fromStdString(LOGTRACE.getLevelTraceStr(trID, Log::E, false, false)));
            msg.exec();
            STOPLOGTRACE(trID);
        }

        this->refresh();
    }
}
