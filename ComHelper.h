#ifndef ComHelper_H
#define ComHelper_H

#include <QObject>
#include <QSerialPort>
#include "commlinksettings.h"
#include <QQmlProperty>
#include <QQuickItem>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qjsondocument.h>
#include <QTimer>
#include <QNetworkProxy>
#include "ardusim/mavlink.h"
#include "mavlink_helpers.h"
#include <QTcpSocket>
#include <QUdpSocket>
#include "bluetoothlink.h"

typedef enum COMM_INTERFACE{
    INTERFACE_SERIAL,           /// 0 connected via Serial interface
    INTERFACE_TCP,              /// 1 connected via TCP interface
    INTERFACE_UDP,              /// 2
    INTERFACE_BLUETOOTH         /// 3
}COMM_INTERFACE;


class ComHelper : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ComHelper)
    explicit ComHelper(QObject *parent = nullptr);

    SerialPortSettings m_serialSetting;

    QByteArray m_message;

    QTimer *m_autoConnectTimer = nullptr;
    QTimer *m_heartBeatTimer = nullptr;
    bool isDeviceDisconnected = false;

    static QSerialPort *m_serial;
    QTcpSocket *m_socket = nullptr;
    QUdpSocket *m_udpSocket = nullptr;
    BluetoothLink* m_bluetoothLink = nullptr;
    COMM_INTERFACE selectedInterface = INTERFACE_SERIAL;

    QString tcpHostAddr = "192.168.56.104";                 // set default Host address. User may change it
    quint16 tcpPort = 5762;                                 // set default port address. user may change
    QString targetAddr = "";
    quint16 targetPort = 0;
    QHostAddress sender;
    quint16 senderPort = 0;
    bool isOpendUdp = false;
    QMutex udpReadLockMutex;

public:

    Q_ENUM(COMM_INTERFACE)

    qint64 m_unixTimeStamp;    

    bool isSerialPortConnected = false;
    float m_ProgressBarvalue = 0.0001;
    static ComHelper* instance;
    static ComHelper* getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}
    static QByteArray message;
    void autoConnect();
    void connectIfNotConnected();
    void autoConnecTimerEvent(QTimerEvent *event);

    void sendData(mavlink_message_t msg);

    void writeData(const QByteArray &data);
    /// @brief This function is responsible to write data over serial port using varioys protocols.
    quint64 write(const char *m_data, qint64 len);

    /// @brief This function is responsible to open the Serial port connection on various modes or interfaces such as serial interface, TCP interfave or UDP interface.
    bool open(QIODevice::OpenModeFlag mode);

    /// @brief This function is responsible to close the serial port connection.
    void close();

    /// @brief This function is responsible to check that currently serial port is open or not.
    bool isOpen();

    /// @brief This function is responsible to read data from serial port
    QByteArray readAll();

    /// @brief This function is responsible to read data over UDP protocol
    QByteArray readAllUDPBytes();

signals:
    void comHelperSendsMessage(QString msg,QString receiver);
    void setupCompleteChanged(bool setupComplete);
    void serialPortConnected(QString);
    void showStatusMessage(const QString &message);
    void showMessageBoxToConnectSerialPort();
    void showMessageBoxUnableToConnectSeralPort();
    void showMessageBoxSerialPortAlreadyConnected();
    void showMessageBoxSerialPortDisconnected();

    void heartBeatSign(mavlink_heart_beat_t);
    void readRawCanData(mavlink_read_can_raw_t);
    void sendRawCanData(mavlink_send_can_raw_t);
public slots:
    Q_INVOKABLE void openSerialPort();
    Q_INVOKABLE void closeSerialPort(int showPopup);
    Q_INVOKABLE void readData();    
    Q_INVOKABLE float updateProgressBarValue();
    Q_INVOKABLE bool isSerialPortOpen();    
    void handleError(QSerialPort::SerialPortError error);
    void disconnectDevice();
    void bytesWritten(qint64 bytes);

    void setInterFace(int interfaceNum);
    int getInterFace();
};

#endif // ComHelper_H
