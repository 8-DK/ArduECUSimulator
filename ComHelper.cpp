#include "ComHelper.h"
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <QDebug>
#include <commlinksettings.h>
#include <stdlib.h>
#include <QMultiMap>
#include <qfile.h>
#include <QDateTime>
#include "mainwindowglobalcontext.h"

QSerialPort * ComHelper::m_serial;
ComHelper* ComHelper::m_serialPort;
QByteArray ComHelper::message;


ComHelper* ComHelper::getInstance()
{
    if (ComHelper::m_serialPort == nullptr)
    {
        ComHelper::m_serialPort = new ComHelper(nullptr);

    }

    return ComHelper::m_serialPort;
}



ComHelper::ComHelper(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer)
{    
    if(m_serial == NULL)
    {
        ComHelper::m_serial = new QSerialPort;
        if(QFile::exists("logfile.json"))
        {
            QFile::remove("logfile.json");
        }
    }
    qDebug() << "--------------------This is my Serial Port Constructor-----------------------------------";
    ComHelper::m_serialPort = this;
    m_autoConnectTimer = new QTimer(this);       
}


bool ComHelper::isSerialPortOpen()
{
    return serialPortIsOpenFlag1;
}

void ComHelper::openSerialPort()
{
    if(m_serial->isOpen())
    {
        m_serial->close();
    }
    const CommLinkSettings::Settings p = CommLinkSettings::getInstance()->settings();
    m_serial->setPortName(p.name);
    qDebug() << "COM Port : "<< p.name;
    m_serial->setBaudRate(p.baudRate);
    qDebug() << "Baud Rate : "<< p.baudRate;
    m_serial->setDataBits(p.dataBits);
    qDebug() << "Data Bits :" << p.dataBits;
    m_serial->setParity(p.parity);
    qDebug() << "Parity :" << p.parity;
    m_serial->setFlowControl(p.flowControl);
    qDebug() << "Flow Control :" << p.flowControl;

    if (m_serial->open(QIODevice::ReadWrite))
    {
        serialPortIsOpenFlag = " Connected ";
        serialPortIsOpenFlag1 = true;
        m_ProgressBarvalue = 0;
        if(m_autoConnectTimer->isActive())
        {
            m_autoConnectTimer->stop();
        }
        m_serial->clearError();
        m_timer->start();
        m_timer->setInterval(3000);
        connect(m_timer, SIGNAL(timeout()), this, SLOT(disconnectDevice()),Qt::UniqueConnection);

        emit showMessageBoxToConnectSerialPort();
        emit serialPortConnected("");
        showStatusMessage("Connected");
        connect(m_serial, &QSerialPort::readyRead, this, &ComHelper::readData);
    } else
    {
        if(m_autoConnectTimer->isActive())
        {
            closeSerialPort(0);
        }
        else if(isSerialPortOpen())
        {
            emit showMessageBoxSerialPortAlreadyConnected();
            //   MainWindowGlobalContext::getInstance()->addMessageBox("Serial Port","Serial Port is already Opened",INFO);
        }
        else{
            //  MainWindowGlobalContext::getInstance()->addMessageBox("Serial Port","Unable to open Serial Port",CRITICAL);
            emit showMessageBoxUnableToConnectSeralPort();
            showStatusMessage(tr("Open error"));
            serialPortIsOpenFlag = " Please Connect device ";
        }
    }
}


QString ComHelper::getStatusSerialPort()
{
    return serialPortIsOpenFlag;
}

void ComHelper::closeSerialPort(int showPopup)
{
    serialPortIsOpenFlag1 = false;

    if (m_serial->isOpen())
    {
        m_serial->close();
        if(!m_autoConnectTimer->isActive())
        {
            if(showPopup)
            emit showMessageBoxSerialPortDisconnected();
            //MainWindowGlobalContext::getInstance()->addMessageBox("Serial Port","Serial Port Disconnected",INFO);
            showStatusMessage(tr("Disconnected"));
        }
        serialPortIsOpenFlag=" Disconnected ";

    }
    else {
        showStatusMessage(tr("Serial Port not Connected"));
        serialPortIsOpenFlag=" not connected ";

    }
}


void ComHelper::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void ComHelper::readData()
{
    m_message = m_serial->readAll();
    int count = m_message.size();

//    QFile messagesJsonFile("logfile.json");
//    if(!messagesJsonFile.isOpen())
//    {
//        messagesJsonFile.open(QFile::Append);
//    }

    if(count == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < m_message.size(); i++)          // read message byte by byte
        {

        }
    }

}

void ComHelper::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        closeSerialPort(1);
        emit showMessageBoxSerialPortDisconnected();
        //MainWindowGlobalContext::getInstance()->addMessageBox("Serial Port","Serial Port Disconnected",INFO);
    }
}

void ComHelper::disconnectDevice()
{    
    if(m_serial->error() > 0)
    {
        m_serial->clearError();
        showStatusMessage("Device is Disconnected");
        if(m_serial->isOpen())
            m_serial->close();
       // if(isDeviceDisconnected == true)
        {
            emit showMessageBoxSerialPortDisconnected();
            isDeviceDisconnected = false;
            serialPortIsOpenFlag1 = false;
        }
    }
}

float ComHelper::updateProgressBarValue()
{
    return  m_ProgressBarvalue ;
}

void ComHelper::autoConnect()
{
    m_autoConnectTimer->stop();
    m_autoConnectTimer->setInterval(1000*6);
    connect(m_autoConnectTimer,SIGNAL(timeout()),this,SLOT(openSerialPort()));
    m_autoConnectTimer->start();
}

void ComHelper::connectIfNotConnected()
{
    if(!m_serial->isOpen())
    {
        closeSerialPort(0);
        openSerialPort();
    }
}
