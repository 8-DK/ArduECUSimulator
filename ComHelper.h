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
#include <QTimer>

class ComHelper : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(ComHelper)

    explicit ComHelper(QObject *parent = nullptr);

public:
    qint64 m_unixTimeStamp;
    QJsonObject rootObject;
    QJsonArray rootObject1;
    QTimer *timer;


signals:

    void setupCompleteChanged(bool setupComplete);
    void serialPortConnected(QString);
    void showStatusMessage(const QString &message);
    void showMessageBoxToConnectSerialPort();
    void showMessageBoxUnableToConnectSeralPort();
    void showMessageBoxSerialPortAlreadyConnected();
    void showMessageBoxSerialPortDisconnected();


public slots:
    Q_INVOKABLE void openSerialPort();
    Q_INVOKABLE void closeSerialPort(int showPopup);
    Q_INVOKABLE void readData();    
    Q_INVOKABLE float updateProgressBarValue();
    Q_INVOKABLE bool isSerialPortOpen();

private slots:
    void writeData(const QByteArray &data);
    void handleError(QSerialPort::SerialPortError error);
    void disconnectDevice();

private:

    SerialPortSettings m_serialSetting;

    QByteArray m_message;

    QTimer *m_autoConnectTimer = nullptr;
    QTimer *m_timer = nullptr;
    bool isDeviceDisconnected = false;




public:
    static QSerialPort *m_serial;
    static ComHelper* m_serialPort;
    static ComHelper* getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}
    static QByteArray message;
    void autoConnect();
    void connectIfNotConnected();
    void autoConnecTimerEvent(QTimerEvent *event);
    Q_INVOKABLE QString getStatusSerialPort();

    QString  serialPortIsOpenFlag = "";
    bool serialPortIsOpenFlag1 = false;
    float m_ProgressBarvalue = 0.0001;
    QJsonObject m_pointData;
    QJsonObject rootJsonObj;
};

#endif // ComHelper_H
