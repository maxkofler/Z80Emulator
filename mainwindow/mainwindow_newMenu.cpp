#include "mainwindow.h"

QMenu* MainWindow::newMenu(QString name){
    FUN();
    return this->_menuBar->addMenu(name);
}
