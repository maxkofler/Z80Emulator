#include "uimenu.h"

void UIMenu::p_connectActions(){
    FUN();

    //File
    connect(this->_a_file_openSource, &QAction::triggered, this, &UIMenu::sl_file_openSource_p);
    connect(this->_a_file_saveSource, &QAction::triggered, this,  &UIMenu::sl_file_saveSource_p);
    connect(this->_a_file_openHex, &QAction::triggered, this, &UIMenu::sl_file_openHex_p);
}
