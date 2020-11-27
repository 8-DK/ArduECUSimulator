#include "serialportsettings.h"
#include <QSerialPort>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

QString SerialPortSettings::m_comPort;
QString SerialPortSettings::m_baudRate;
QString SerialPortSettings::m_dataBits;
QString SerialPortSettings::m_parity;
QString SerialPortSettings::m_stopBits;
QString SerialPortSettings::m_flowControl;

SerialPortSettings::SerialPortSettings(QObject *parent) :
    QObject(parent)
{
    connectToDatabase();
    createSettingsTable();
}

void SerialPortSettings::connectToDatabase()
{
    m_db = QSqlDatabase::addDatabase( "QSQLITE" );
    m_db.setDatabaseName("gcs31.db");
    if( !m_db.open() )
    {
        qDebug( "Failed to connect database" );
    }
    qDebug( "Connected to Database." );
}

void SerialPortSettings::createSettingsTable()
{
    QSqlQuery query;
    if(m_db.open())
    {
        query.prepare( "CREATE TABLE IF NOT EXISTS Settings (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
                       "COM_Port VARCHAR(50), Baud_Rate INTEGER, Data_Bits INTEGER,"
                       "Parity VARCHAR(50), Stop_Bits INTEGER, Flow_Control VARCHAR(50))");
        if( !query.exec() )
          qDebug() << query.lastError();
        else
          qDebug() << "Settings Table created!";
    }
}

void SerialPortSettings::readSettings(QString comPortName, qint32 baudRate, QString dataBits,
                                             QString parity, QString stopBits,
                                             QString flowControl)
{
    QSqlQuery query;
    if(m_db.isOpen())
    {
        m_db.open();
        query.prepare( "INSERT INTO Settings (COM_Port, Baud_Rate, Data_Bits, Parity, "
                       "Stop_Bits, Flow_Control) "
                       "VALUES (:COM_Port, :Baud_Rate, :Data_Bits, :Parity, :Stop_Bits, :Flow_Control)" );
        query.addBindValue(comPortName);
        query.addBindValue(baudRate);
        query.addBindValue(dataBits);
        query.addBindValue(parity);
        query.addBindValue(stopBits);
        query.addBindValue(flowControl);
        if( !query.exec() )
        {
           qDebug() << query.lastError();
        }
        else
           {
           qDebug( "Record Inserted!" );
           }
    }
    readFromDatabase();
}

bool SerialPortSettings::readFromDatabase()
{
    QSqlQuery query;
    if(m_db.isOpen())
    {
        m_db.open();
        query.exec("SELECT * FROM Settings ORDER BY ID DESC LIMIT 1");
        while (query.next()) {
                m_comPort = query.value(1).toString();
                m_baudRate = query.value(2).toString();
                m_dataBits = query.value(3).toString();
                m_parity = query.value(4).toString();
                m_stopBits = query.value(5).toString();
                m_flowControl = query.value(6).toString();
              }

     if( !query.exec() )
        {
          qDebug() << query.lastError();
          return false;
        }
        else
        {
            //closeDatabase();
            return true;


        }
    }

    else {
       return false;
    }
}

void SerialPortSettings::closeDatabase()
{
    if(m_db.isOpen())
    {
        //QSqlDatabase m_db = QSqlDatabase::database();
        m_db.close();
        //QSqlDatabase::removeDatabase("QSQLITE");
        m_db.removeDatabase("gcs31.db");
        qDebug() << "Database closed";
    }

}
