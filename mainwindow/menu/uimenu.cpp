#include "uimenu.h"

UIMenu::UIMenu(MainWindow* mainW){
    FUN();
    this->_mainWindow = mainW;
    this->_fileMenu = _mainWindow->newMenu("File");

    //Add all the actions to the menus
    this->p_addActions();
    this->p_connectActions();
}
