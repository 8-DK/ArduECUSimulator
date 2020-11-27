#include "commlinksettings.h"
#include <QIntValidator>
#include <QLineEdit>
#include <QSerialPortInfo>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

CommLinkSettings::CommLinkSettings(QObject *parent) : QObject(parent)//m_speedUnit(nullptr)
{

}

CommLinkSettings* CommLinkSettings::m_instance;

CommLinkSettings* CommLinkSettings::getInstance()
{
    if (CommLinkSettings::m_instance == nullptr)
    {
        CommLinkSettings::m_instance = new CommLinkSettings(nullptr);
    }

    return CommLinkSettings::m_instance;
}


CommLinkSettings::~CommLinkSettings()
{

}

CommLinkSettings::Settings CommLinkSettings::settings() const
{
    return m_currentSettings;
}

CommLinkSettings::SerialParam CommLinkSettings::serialParam() const
{
    return m_serialParam;
}


//void CommLinkSettings::updateSettings()
//{
//    //m_serialSettings.readFromDatabase();
//    selectSerialPort();
//    selectBaudRate();
//    selectDataBits();
//    selectParity();
//    selectStopBits();
//    selectFlowControl();
//}

QStringList CommLinkSettings::getSerialPort()
{
    QStringList lport;
    QList<QSerialPortInfo> ListPort;
    ListPort = QSerialPortInfo::availablePorts();
    //qDebug() << "Number of serial ports:" << ListPort.count();
    for (int i=0; i < ListPort.size();i++)
    {
        //qDebug() << "Names of serial ports:" << ListPort.at(i).portName();
        QString dataStr = ListPort.at(i).portName();
        if(!ListPort.at(i).description().isEmpty())
            dataStr += " ("+ListPort.at(i).description()+")";
        lport << dataStr;
    }
    return lport;
}

void CommLinkSettings::connectSerialPort(QString comPort, qint32 baudRate , QString dataBits,
                                         QString parity, QString flowControl)
{
    m_currentSettings.name = comPort;
    m_currentSettings.baudRate = baudRate;

       if(dataBits == QStringLiteral("6"))
       {
           m_currentSettings.dataBits = QSerialPort::Data6;
       }
       if(dataBits == QStringLiteral("7"))
       {
           m_currentSettings.dataBits = QSerialPort::Data7;
       }
       if(dataBits == QStringLiteral("8"))
       {
           m_currentSettings.dataBits = QSerialPort::Data8;
       }

       if(parity == QStringLiteral("None"))
       {
           m_currentSettings.parity = QSerialPort::NoParity;
       }
       if(parity == QStringLiteral("Even"))
       {
           m_currentSettings.parity = QSerialPort::EvenParity;
       }
       if(parity == QStringLiteral("Odd"))
       {
           m_currentSettings.parity = QSerialPort::OddParity;
       }

       if(flowControl == QStringLiteral("None"))
       {
          m_currentSettings.flowControl = QSerialPort::NoFlowControl;
       }
       if(flowControl == QStringLiteral("RTS/CTS"))
       {
          m_currentSettings.flowControl = QSerialPort::HardwareControl;
       }
       if(flowControl == QStringLiteral("XON/XOFF"))
       {
           m_currentSettings.flowControl = QSerialPort::SoftwareControl;
       }
}



void CommLinkSettings::serialParamData()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    qDebug() << "No of Serial ports Available" << serialPortInfos.count();

    const QString blankString = "N/A";

    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        m_serialParam.serialPort = serialPortInfo.portName();
        m_serialParam.baudrate = serialPortInfo.standardBaudRates();
        m_serialParam.description = serialPortInfo.description();
        m_serialParam.manufacturer = serialPortInfo.manufacturer();
        m_serialParam.serialNumber = serialPortInfo.serialNumber();
        m_serialParam.systemLocation = serialPortInfo.systemLocation();


//            qDebug() << "Port: " << serialPortInfo.portName();
//            qDebug() << "Available baudrates :" << serialPortInfo.standardBaudRates();
//            qDebug() << "Location: " << serialPortInfo.systemLocation();
//            qDebug() << "Description: " << (!m_serialParam.description.isEmpty() ? m_serialParam.description : blankString);
//            qDebug() << "Manufacturer: " << (!m_serialParam.manufacturer.isEmpty() ? m_serialParam.manufacturer : blankString);
//            qDebug() << "Serial number: " << (!m_serialParam.serialNumber.isEmpty() ? m_serialParam.serialNumber : blankString);
//            qDebug() << "Vendor Identifier: " << (serialPortInfo.hasVendorIdentifier()
//                                                  ? QByteArray::number(serialPortInfo.vendorIdentifier(), 16)
//                                                  : blankString);
//            qDebug() << "Product Identifier: " << (serialPortInfo.hasProductIdentifier()
//                                                   ? QByteArray::number(serialPortInfo.productIdentifier(), 16)
//                                                   : blankString);
//            qDebug() << "Busy: " << (serialPortInfo.isBusy() ? "Yes" : "No");



//            m_currentSettings.name = serialPortInfo.portName();
//            qDebug() << "Serial Ports :" << m_currentSettings.name;
    }

}

void CommLinkSettings::selectSerialPort()
{
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
    {
        m_currentSettings.name = serialPortInfo.portName();
        qDebug() << "Serial Port Available:" << m_currentSettings.name;
    }
}

void CommLinkSettings::selectBaudRate()
{
  stringBaudRate = SerialPortSettings::m_baudRate;

  qDebug() << "Commlink Baudrate :" << stringBaudRate;

  if(stringBaudRate == QStringLiteral("9600"))
    {
       m_currentSettings.baudRate = QSerialPort::Baud9600;
    }

    if(stringBaudRate == QStringLiteral("19200"))
    {
        m_currentSettings.baudRate = QSerialPort::Baud19200;
    }

    if(stringBaudRate == QStringLiteral("38400"))
    {
        m_currentSettings.baudRate = QSerialPort::Baud38400;
    }

    if(stringBaudRate == QStringLiteral("57600"))
    {
        m_currentSettings.baudRate = QSerialPort::Baud57600;
    }

    if(stringBaudRate == QStringLiteral("115200"))
    {
       m_currentSettings.baudRate = QSerialPort::Baud115200;
    }
}

void CommLinkSettings::selectDataBits()
{
    stringDataBits = SerialPortSettings::m_dataBits;
    qDebug() << "Commlink Data Bits :" << stringDataBits;
    if(stringDataBits == QStringLiteral("5"))
    {
        m_currentSettings.dataBits = QSerialPort::Data5;
    }

    if(stringDataBits == QStringLiteral("6"))
    {
        m_currentSettings.dataBits = QSerialPort::Data6;
    }

    if(stringDataBits == QStringLiteral("7"))
    {
        m_currentSettings.dataBits = QSerialPort::Data7;
    }

    if(stringDataBits == QStringLiteral("8"))
    {
        m_currentSettings.dataBits = QSerialPort::Data8;
    }
}

void CommLinkSettings::selectParity()
{
    stringParity = SerialPortSettings::m_parity;
    qDebug() << "Commlink Parity :" << stringParity;

    if(stringParity == QStringLiteral("None"))
    {
        m_currentSettings.parity = QSerialPort::NoParity;
    }

    if(stringParity == QStringLiteral("Even"))
    {
        m_currentSettings.parity = QSerialPort::EvenParity;
    }

    if(stringParity == QStringLiteral("Odd"))
    {
        m_currentSettings.parity = QSerialPort::OddParity;
    }

    if(stringParity == QStringLiteral("Mark"))
    {
        m_currentSettings.parity = QSerialPort::MarkParity;
    }

    if(stringParity == QStringLiteral("Space"))
    {
        m_currentSettings.parity = QSerialPort::SpaceParity;
    }
}

void CommLinkSettings::selectStopBits()
{
    stringStopBits = SerialPortSettings::m_stopBits;
    qDebug() << "Commlink Stop Bits :" << stringStopBits;

    if(stringStopBits == QStringLiteral("1"))
    {
       m_currentSettings.stopBits = QSerialPort::OneStop;
    }

    if(stringStopBits == QStringLiteral("2"))
    {
       m_currentSettings.stopBits = QSerialPort::TwoStop;
    }

}

void CommLinkSettings::selectFlowControl()
{
    stringFlowControl = SerialPortSettings::m_flowControl;
    qDebug() << "Commlink Flow Control :" << stringFlowControl;

    if(stringFlowControl == QStringLiteral("None"))
    {
        m_currentSettings.flowControl = QSerialPort::NoFlowControl;
    }

    if(stringFlowControl == QStringLiteral("RTS/CTS"))
    {
        m_currentSettings.flowControl = QSerialPort::HardwareControl;
    }

    if(stringFlowControl == QStringLiteral("XON/XOFF"))
    {
        m_currentSettings.flowControl = QSerialPort::SoftwareControl;
    }
}


