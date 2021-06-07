#include "uimenu.h"

#include <QFileDialog>

void UIMenu::sl_file_openHex_p(){
    FUN();

    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString file = dialog.getOpenFileName();

    if (!file.isEmpty()){
        LOGI("Selected file \"" + file.toStdString() + "\"");
        emit this->on_openHex(file);
    }else{
        LOGE("No file selected");
    }
}
