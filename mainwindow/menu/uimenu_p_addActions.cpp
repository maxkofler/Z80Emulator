#include "uimenu.h"

void UIMenu::p_addActions(){
    FUN();

    this->_a_file_openSource = this->_fileMenu->addAction("Open Source");
    this->_a_file_saveSource = this->_fileMenu->addAction("Save Source");
    this->_a_file_openHex = this->_fileMenu->addAction("Open Hex");
}
