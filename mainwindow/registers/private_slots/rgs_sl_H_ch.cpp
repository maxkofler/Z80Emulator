#include "registers.h"

#include <QMessageBox>

void Registers::sl_p_H_ch(){
    FUN();
    std::string reg = this->_H->text().toStdString();
    if (reg.length() >= 2){
        try{
            this->_emu->H(stoul(reg, nullptr, 16));
        }catch(...){
            size_t trID = STARTLOGTRACE();
            LOGE("Invalid argument for register H");
            QMessageBox msg;
            msg.setWindowTitle("Invalid value");
            msg.setInformativeText(QString().fromStdString(LOGTRACE.getLevelTraceStr(trID, Log::E, false, false)));
            msg.exec();
            STOPLOGTRACE(trID);
        }

        this->refresh();
    }
}
