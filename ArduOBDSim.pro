QT += quick
QT += widgets serialport sql positioning location
QT += mqtt
QT += qml quick
QT += gui
QT += core
QT += network
QT += xml
QT += svg
QT += texttospeech
QT += multimedia
CONFIG += c++11
PKGCONFIG += openssl

DEFINES += QT_DEPRECATED_WARNINGS

unix:!symbian {
    LIBS += -L/usr/lib -lssl -lcrypto -lquazip -lz
    INCLUDEPATH+=/usr/local/zlib/include \
                 /include   \
                 /include/quazip \
                 $$PWD/mavlinkModule \
                 $$PWD/apiPorcessors \
                 $$PWD/cameraGimbleModule \
                 $$PWD/notificationModule \
                 $PWD/PAParsers/libnpnt
}

win32 {
    RC_ICONS +=  assets\sim_icon.ico
    equals(QT_MINOR_VERSION, 12){
       MSVC_PATH  = "C:/Qt/Qt5.12.0/5.12.0/mingw73_64"
    } else {
       MSVC_PATH  = "C:/Qt/Qt5.14/5.14.1/mingw73_64"
    }

    QTPLUGIN += /plugins

    QMAKE_LFLAGS += -Wl,--rpath=\$$ORIGIN/lib

    LIBS += -L$$MSVC_PATH/lib -lquazipd #-lssleay32 -llibeay32 -lcrypto -lssl

    INCLUDEPATH+=$$MSVC_PATH/include \
                 $$MSVC_PATH/../../Tools/OpenSSL/Win_x64/include \
                 $$MSVC_PATH/include/QtZlib \
                 $$MSVC_PATH/include/quazip \
}

RESOURCES += qml.qrc

INCLUDEPATH += $$PWD/moduls/mavlink \

SOURCES += \
    ComHelper.cpp \
    commlinksettings.cpp \
    localstrings.cpp \
    main.cpp \
    appcontext.cpp \
    pidencoderdecoder.cpp \
    serialportsettings.cpp \
    styleglobalsconsts.cpp

HEADERS += \
    ComHelper.h \
    commlinksettings.h \
    localstrings.h \
    appcontext.h \
    pidencoderdecoder.h \
    serialportsettings.h \
    styleglobalsconsts.h

TRANSLATIONS += \
    ArduOBDSim_en_IN.ts
