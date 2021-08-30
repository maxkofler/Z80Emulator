cmake_minimum_required(VERSION 3.5)

project(Z80Emulator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        #CPP
        main.cpp
        #MainWindow
            mainwindow/mainwindow.cpp
            mainwindow/mainwindow_refreshCPU.cpp
            mainwindow/mainwindow_newMenu.cpp
            mainwindow/mainwindow_connectShortcuts.cpp

                #Registers
                mainwindow/registers/registers.cpp
                mainwindow/registers/rgs_refresh.cpp
                mainwindow/registers/rgs_connectSlots.cpp

                #slots
                mainwindow/registers/private_slots/rgs_sl_A_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_B_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_C_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_D_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_E_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_H_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_L_ch.cpp

                mainwindow/registers/private_slots/rgs_sl_PC_ch.cpp
                mainwindow/registers/private_slots/rgs_sl_SP_ch.cpp

            #slots
            mainwindow/private_slots/mw_sl_bt_asm_pressed.cpp
            mainwindow/private_slots/mw_sl_bt_step_pressed.cpp
            mainwindow/private_slots/mw_sl_loadSrc.cpp
            mainwindow/private_slots/mw_sl_saveSrc.cpp
            mainwindow/private_slots/mw_sl_loadHex.cpp

                #Menu
                mainwindow/menu/uimenu.cpp
                mainwindow/menu/uimenu_p_addActions.cpp
                mainwindow/menu/uimenu_p_connectActions.cpp
                    #private slots
                        mainwindow/menu/private_slots/sl_file_openSource_p.cpp
                        mainwindow/menu/private_slots/sl_file_saveSource_p.cpp
                        mainwindow/menu/private_slots/sl_file_openHex_p.cpp

        #H
        mainwindow/mainwindow.h
        mainwindow/registers.h
        mainwindow/uimenu.h
        #UI
        mainwindow/mainwindow.ui
)

include_directories(
    mainwindow/
    Log/include
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Z80Emulator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Z80Emulator SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Z80Emulator
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories(Z80Asm/include)
include_directories(Z80Emu/include)

add_subdirectory(Z80Asm/libz80asm)
add_subdirectory(Z80Emu/libz80emu)
add_subdirectory(Log)

target_link_libraries(Z80Emulator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets libz80emu libz80asm log)
add_dependencies(Z80Emulator libz80emu libz80asm log)

set_target_properties(Z80Emulator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Z80Emulator)
endif()
