#ifndef COMMLINKSETTINGS_H
#define COMMLINKSETTINGS_H

#include <QObject>
#include <QSerialPort>
#include <QSql>
#include <QSqlDatabase>
#include "serialportsettings.h"
#include <QQmlProperty>
#include <QQuickItem>

class QIntValidator;

class CommLinkSettings : public QObject
{
    Q_OBJECT

public:
    explicit CommLinkSettings(QObject *parent = nullptr);
    ~CommLinkSettings();

    struct Settings {
        QString name;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
    };

    struct SerialParam {
        QString serialPort;
        QList<qint32> baudrate;
        QString serialNumber;
        QString description;
        QString manufacturer;
        QString systemLocation;
    };

    SerialParam m_serialParam;

    Settings settings() const;
    SerialParam serialParam() const;

public:
    //void updateSettings();
    void serialParamData();
    Q_INVOKABLE QStringList getSerialPort();
    static CommLinkSettings *getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}
    Q_INVOKABLE void connectSerialPort(QString, qint32, QString, QString, QString);

private:
    QString stringComPort;
    QString stringBaudRate;
    QString stringDataBits;
    QString stringParity;
    QString stringStopBits;
    QString stringFlowControl;
    static CommLinkSettings *m_instance;

    void selectSerialPort();
    void selectBaudRate();
    void selectDataBits();
    void selectParity();
    void selectStopBits();
    void selectFlowControl();

    Settings m_currentSettings;

//    Settings m_currentSettings = {
//        .name = "Custom",
//        .baudRate = 57600,
//        .dataBits = QSerialPort::Data8,
//        .parity = QSerialPort::NoParity,
//        .stopBits = QSerialPort::OneStop,
//        .flowControl = QSerialPort::NoFlowControl
//    };
    SerialPortSettings m_serialSettings;



signals:

public slots:
};

#endif // COMMLINKSETTINGS_H
