#include "mainwindow.h"

#include <fstream>

void MainWindow::sl_saveSrc(QString path){
    FUN();

    std::ofstream outfile;
    outfile.open(path.toStdString());

    if (outfile.is_open()){
        outfile << this->_te_z80asm->toPlainText().toStdString() << std::endl;
    }else{
        LOGE("Could not open file \"" + path.toStdString() + "\" for writing");
    }

    outfile.close();
}
