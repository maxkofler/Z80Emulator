#include "mainwindow.h"

#include <QShortcut>
#include <QKeySequence>

void MainWindow::connectShortcuts(){
    FUN();

    //ASSEMBLE                      F7
    connect(new QShortcut(QKeySequence(Qt::Key_F7), this), &QShortcut::activated,
            this, &MainWindow::sl_bt_asm_pressed);

    //STEP                          F10
    connect(new QShortcut(QKeySequence(Qt::Key_F10), this), &QShortcut::activated,
            this, &MainWindow::sl_bt_step_pressed);
}
