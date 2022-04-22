#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QString>
#include <QList>
#include <QMutex>
#include <QMutexLocker>
#include <QQueue>
#include <QByteArray>
#include <QBluetoothDeviceInfo>
#include <QtBluetooth/QBluetoothSocket>
#include <qbluetoothserviceinfo.h>
#include <qbluetoothservicediscoveryagent.h>
#include <QBluetoothDeviceDiscoveryAgent>

class QBluetoothDeviceDiscoveryAgent;
class QBluetoothServiceDiscoveryAgent;

class BluetoothData
{
public:
    BluetoothData()
    {
    }
    BluetoothData(const BluetoothData& other)
    {
        *this = other;
    }
    bool operator==(const BluetoothData& other)
    {
#ifdef __ios__
        return uuid == other.uuid && name == other.name;
#else
        return name == other.name && address == other.address;
#endif
    }
    BluetoothData& operator=(const BluetoothData& other)
    {
        name = other.name;
#ifdef __ios__
        uuid = other.uuid;
#else
        address = other.address;
#endif
        return *this;
    }
    QString name;
#ifdef __ios__
    QBluetoothUuid uuid;
#else
    QString address;
#endif
};

class BluetoothConfiguration : public QObject
{
    Q_OBJECT

public:
    explicit BluetoothConfiguration(QObject *parent = nullptr);
    BluetoothConfiguration(BluetoothConfiguration* source);
    ~BluetoothConfiguration();


    static BluetoothConfiguration* m_instance;
    static BluetoothConfiguration* getInstance()
    {
        if (BluetoothConfiguration::m_instance == nullptr)
        {
            BluetoothConfiguration::m_instance = new BluetoothConfiguration();
        }
        return BluetoothConfiguration::m_instance;
    }
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}


    Q_PROPERTY(QString      devName     READ devName    WRITE setDevName  NOTIFY devNameChanged)
    Q_PROPERTY(QString      address     READ address                      NOTIFY addressChanged)
    Q_PROPERTY(QStringList  nameList    READ nameList                     NOTIFY nameListChanged)
    Q_PROPERTY(bool         scanning    READ scanning                     NOTIFY scanningChanged)

    Q_INVOKABLE void        startScan   ();
    Q_INVOKABLE void        stopScan    ();
    Q_INVOKABLE bool        isBluetoothAvailable    ();
    Q_INVOKABLE QString     getDeviceNameAt (int m_index);
    QString     devName                 () { return _device.name; }
    QString     address                 ();
    QStringList nameList                () { return _nameList; }
    bool        scanning                () { return _deviceDiscover != NULL; }

    BluetoothData    device             () { return _device; }

    /// From LinkConfiguration
    void        updateSettings          ();
    QString     settingsURL             () { return "BluetoothSettings.qml"; }
    QString     settingsTitle           ();

public slots:
    void        setDevName              (const QString& name);
    void        setDevName              (const int currIndex);
    void        deviceDiscovered        (QBluetoothDeviceInfo info);
    void        doneScanning            ();

signals:
    void        newDevice               (QBluetoothDeviceInfo info);
    void        devNameChanged          ();
    void        addressChanged          ();
    void        nameListChanged         ();
    void        scanningChanged         ();

private:
    QBluetoothDeviceDiscoveryAgent*     _deviceDiscover;
    BluetoothData                       _device;
    QStringList                         _nameList;
    QList<BluetoothData>                _deviceList;
};

class BluetoothLink : public QObject
{
    Q_OBJECT

    friend class BluetoothConfiguration;

public:


    Q_PROPERTY(BluetoothConfiguration*  m_config     READ getConfig   NOTIFY configChanged)

    explicit BluetoothLink(QObject *parent = nullptr);

    static BluetoothLink* m_instance;
    static BluetoothLink* getInstance()
    {
        if (BluetoothLink::m_instance == nullptr)
        {
            BluetoothLink::m_instance = new BluetoothLink(nullptr);
        }
        return BluetoothLink::m_instance;
    }
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

    void    requestReset            () { }
    bool    isConnected             () const;
    QString getName                 () const;

    // Extensive statistics for scientific purposes
    qint64  getConnectionSpeed      () const;
    qint64  getCurrentInDataRate    () const;
    qint64  getCurrentOutDataRate   () const;

    void run();

    // These are left unimplemented in order to cause linker errors which indicate incorrect usage of
    // connect/disconnect on link directly. All connect/disconnect calls should be made through LinkManager.
    bool    connect                 (void);
    bool    disconnect              (void);

public slots:
    // From LinkInterface
    bool _connect               (void);
    void _disconnect            (void);

    bool _hardwareConnect       ();
    void _restartConnection     ();
    void    readBytes               ();
    void _writeBytes            (const QByteArray bytes);
    void _writeBytes(const char *data, qint64 len);
    void    deviceConnected         ();
    void    deviceDisconnected      ();
    void    deviceError             (QBluetoothSocket::SocketError error);
    BluetoothConfiguration* getConfig(){return _config;}
#ifdef __ios__
    void    serviceDiscovered       (const QBluetoothServiceInfo &info);
    void    discoveryFinished       ();
#endif

protected:

    BluetoothConfiguration*     _config;
    bool                        _connectState;

private:
    // Links are only created/destroyed by LinkManager so constructor/destructor is not public
    BluetoothLink();
    ~BluetoothLink();
    void _createSocket          ();
    QBluetoothSocket*           _targetSocket;
#ifdef __ios__
    QBluetoothServiceDiscoveryAgent* _discoveryAgent;
#endif

    bool                        _shutDown;

signals:
    void bytesReceived(QByteArray data);
    void connected();
    void disconnected();
    void communicationError(const QString& title, const QString& error);
    void configChanged();
};
