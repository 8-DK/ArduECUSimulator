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
equals(QT_MINOR_VERSION, 12) {
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

SOURCES += \
    ComHelper.cpp \
    commlinksettings.cpp \
    localstrings.cpp \
    main.cpp \
    mainwindowglobalcontext.cpp \
    pidencoderdecoder.cpp \
    serialportsettings.cpp \
    styleglobalsconsts.cpp

HEADERS += \
    ComHelper.h \
    commlinksettings.h \
    localstrings.h \
    mainwindowglobalcontext.h \
    moduls/mavlink/ardusim/ardusim.h \
    moduls/mavlink/ardusim/mavlink.h \
    moduls/mavlink/ardusim/mavlink_msg_ahrs.h \
    moduls/mavlink/ardusim/mavlink_msg_ahrs2.h \
    moduls/mavlink/ardusim/mavlink_msg_ahrs3.h \
    moduls/mavlink/ardusim/mavlink_msg_airspeed_autocal.h \
    moduls/mavlink/ardusim/mavlink_msg_ap_adc.h \
    moduls/mavlink/ardusim/mavlink_msg_autopilot_version_request.h \
    moduls/mavlink/ardusim/mavlink_msg_battery2.h \
    moduls/mavlink/ardusim/mavlink_msg_camera_feedback.h \
    moduls/mavlink/ardusim/mavlink_msg_camera_status.h \
    moduls/mavlink/ardusim/mavlink_msg_compassmot_status.h \
    moduls/mavlink/ardusim/mavlink_msg_data16.h \
    moduls/mavlink/ardusim/mavlink_msg_data32.h \
    moduls/mavlink/ardusim/mavlink_msg_data64.h \
    moduls/mavlink/ardusim/mavlink_msg_data96.h \
    moduls/mavlink/ardusim/mavlink_msg_deepstall.h \
    moduls/mavlink/ardusim/mavlink_msg_digicam_configure.h \
    moduls/mavlink/ardusim/mavlink_msg_digicam_control.h \
    moduls/mavlink/ardusim/mavlink_msg_efi_status.h \
    moduls/mavlink/ardusim/mavlink_msg_ekf_status_report.h \
    moduls/mavlink/ardusim/mavlink_msg_fence_fetch_point.h \
    moduls/mavlink/ardusim/mavlink_msg_fence_point.h \
    moduls/mavlink/ardusim/mavlink_msg_gimbal_control.h \
    moduls/mavlink/ardusim/mavlink_msg_gimbal_report.h \
    moduls/mavlink/ardusim/mavlink_msg_gimbal_torque_cmd_report.h \
    moduls/mavlink/ardusim/mavlink_msg_gopro_get_request.h \
    moduls/mavlink/ardusim/mavlink_msg_gopro_get_response.h \
    moduls/mavlink/ardusim/mavlink_msg_gopro_heartbeat.h \
    moduls/mavlink/ardusim/mavlink_msg_gopro_set_request.h \
    moduls/mavlink/ardusim/mavlink_msg_gopro_set_response.h \
    moduls/mavlink/ardusim/mavlink_msg_hwstatus.h \
    moduls/mavlink/ardusim/mavlink_msg_led_control.h \
    moduls/mavlink/ardusim/mavlink_msg_limits_status.h \
    moduls/mavlink/ardusim/mavlink_msg_mag_cal_progress.h \
    moduls/mavlink/ardusim/mavlink_msg_mag_cal_report.h \
    moduls/mavlink/ardusim/mavlink_msg_meminfo.h \
    moduls/mavlink/ardusim/mavlink_msg_mount_configure.h \
    moduls/mavlink/ardusim/mavlink_msg_mount_control.h \
    moduls/mavlink/ardusim/mavlink_msg_mount_status.h \
    moduls/mavlink/ardusim/mavlink_msg_pid_tuning.h \
    moduls/mavlink/ardusim/mavlink_msg_radio.h \
    moduls/mavlink/ardusim/mavlink_msg_rally_fetch_point.h \
    moduls/mavlink/ardusim/mavlink_msg_rally_point.h \
    moduls/mavlink/ardusim/mavlink_msg_rangefinder.h \
    moduls/mavlink/ardusim/mavlink_msg_remote_log_block_status.h \
    moduls/mavlink/ardusim/mavlink_msg_remote_log_data_block.h \
    moduls/mavlink/ardusim/mavlink_msg_rpm.h \
    moduls/mavlink/ardusim/mavlink_msg_sensor_offsets.h \
    moduls/mavlink/ardusim/mavlink_msg_set_mag_offsets.h \
    moduls/mavlink/ardusim/mavlink_msg_simstate.h \
    moduls/mavlink/ardusim/mavlink_msg_wind.h \
    moduls/mavlink/ardusim/testsuite.h \
    moduls/mavlink/ardusim/version.h \
    moduls/mavlink/checksum.h \
    moduls/mavlink/mavlink_conversions.h \
    moduls/mavlink/mavlink_helpers.h \
    moduls/mavlink/mavlink_types.h \
    moduls/mavlink/protocol.h \
    pidencoderdecoder.h \
    serialportsettings.h \
    styleglobalsconsts.h

TRANSLATIONS += \
    ArduOBDSim_en_IN.ts
