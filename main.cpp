#include "mainwindow/mainwindow.h"

#include "z80emu.h"
#include "z80asm.h"

#include "log.h"

#include <QApplication>

Log* hlog;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hlog = new Log(Log::MEM, false);
    hlog->trace.startTrace();       //Trace 0 is the main trace
    Z80 z80emu;
    Z80Asm z80asm;

    z80asm.loadLookup("../Z80Asm/z80lookup.txt");
    z80emu.HALT(true);
    MainWindow w(&z80emu, &z80asm);
    w.show();
    w.refreshCPU();
    return a.exec();
}
