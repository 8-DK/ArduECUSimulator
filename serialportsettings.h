#ifndef SERIALPORTSETTINGS_H
#define SERIALPORTSETTINGS_H

#include <QObject>
#include <QString>
#include <QSerialPort>
#include <QSqlDatabase>
//#include <myserialport.h>

class SerialPortSettings : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortSettings(QObject *parent = nullptr);

signals:

private:
    void connectToDatabase();
    void createSettingsTable();
    bool readFromDatabase();

    QSqlDatabase m_db;

public:
    static QString m_comPort;
    static QString m_baudRate;
    static QString m_dataBits;
    static QString m_parity;
    static QString m_stopBits;
    static QString m_flowControl;

    void closeDatabase();

public slots:
    Q_INVOKABLE void readSettings(QString comPortName, qint32 baudRate, QString dataBits,
                                  QString parity, QString stopBits,
                                  QString flowControl);
};

#endif // SERIALPORTSETTINGS_H
