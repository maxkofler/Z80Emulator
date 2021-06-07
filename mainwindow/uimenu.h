#ifndef UIMENU_H
#define UIMENU_H

class UIMenu;

#include <QObject>
#include <QMenu>
#include <QMenuBar>

#include "mainwindow.h"

class UIMenu : public QObject
{
    Q_OBJECT
public:
    UIMenu(MainWindow* win);

private slots:
    //File menu
    void                    sl_file_openSource_p();
    void                    sl_file_saveSource_p();
    void                    sl_file_openHex_p();

signals:
    //File menu
    void                    on_openSource(QString);
    void                    on_saveSource(QString);
    void                    on_openHex(QString);

private:
    QMenu*                  _fileMenu;

    MainWindow*             _mainWindow;


    //Actions
    //File
    QAction*                _a_file_openSource;
    QAction*                _a_file_saveSource;
    QAction*                _a_file_openHex;


    void                    p_addActions();
    void                    p_connectActions();
};

#endif // UIMENU_H
