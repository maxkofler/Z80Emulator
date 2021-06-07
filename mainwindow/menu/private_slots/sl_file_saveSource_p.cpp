#include "uimenu.h"

#include <QFileDialog>

void UIMenu::sl_file_saveSource_p(){
    FUN();

    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    QString file = dialog.getSaveFileName();

    if (!file.isEmpty()){
        LOGI("Selected file \"" + file.toStdString() + "\"");
        emit this->on_saveSource(file);
    }else{
        LOGE("No file selected");
    }
}
