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
#include "appcontext.h"

QSerialPort * ComHelper::m_serial;
ComHelper* ComHelper::instance;
QByteArray ComHelper::message;

namespace SIM {
    const ComHelper *comm(){ return ComHelper::getInstance();}
}

ComHelper* ComHelper::getInstance()
{
    if (ComHelper::instance == nullptr)
    {
        ComHelper::instance = new ComHelper(nullptr);

    }

    return ComHelper::instance;
}



ComHelper::ComHelper(QObject *parent) :
    QObject(parent),    
    m_autoConnectTimer(new QTimer),
    m_heartBeatTimer(new QTimer)
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
    ComHelper::instance = this;
}


bool ComHelper::isSerialPortOpen()
{
    return isSerialPortConnected;
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
        isSerialPortConnected = true;
        m_ProgressBarvalue = 0;
        if(m_autoConnectTimer->isActive())
        {
            m_autoConnectTimer->stop();
        }
        m_serial->clearError();
        m_heartBeatTimer->start();
        m_heartBeatTimer->setInterval(3000);
        connect(m_heartBeatTimer, SIGNAL(timeout()), this, SLOT(disconnectDevice()),Qt::UniqueConnection);

        emit commStatusChanged(COMM_CONNECTED);        
        connect(m_serial, &QSerialPort::readyRead, this, &ComHelper::readData);
    } else
    {
        if(m_autoConnectTimer->isActive())
        {
            closeSerialPort(0);
        }
        else if(isSerialPortOpen())
        {            
            emit commStatusChanged(COMM_ALREADYCONNECTED);
        }
        else{                        
            emit commStatusChanged(COMM_FAILED_TO_CONNECT);            
        }
    }
}

void ComHelper::closeSerialPort(int showPopup)
{
    m_heartBeatTimer->stop();
    isSerialPortConnected = false;
    if (m_serial->isOpen())
    {
        m_serial->close();
        if(!m_autoConnectTimer->isActive())
        {
            if(showPopup)           
             emit commStatusChanged(COMM_DISCONNECTED);            
        }
    }
    else {
        emit commStatusChanged(COMM_ALREADYDISCONNECTED);
    }
}

void ComHelper::readData()
{
    m_message = m_serial->readAll();
    mavlink_message_t msg;
    mavlink_status_t status;
    int count = m_message.size();

    if(count == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < m_message.size(); i++)          // read message byte by byte
        {
            if(mavlink_parse_char(MAVLINK_COMM_0, m_message.at(i), &msg, &status))     // parse the message
            {
                switch(msg.msgid)
                {
                    case MAVLINK_MSG_ID_HEART_BEAT :
                    {
                       mavlink_heart_beat_t heart_beat;
                       mavlink_msg_heart_beat_decode(&msg, &heart_beat);
                       m_heartBeatTimer->start();
//                       qDebug() << "MAVLINK_MSG_ID_HEART_BEAT : heart_beat.target_system" << heart_beat.target_system;
                       emit heartBeatSign(heart_beat);
                    }
                        break;

                    case MAVLINK_MSG_ID_READ_CAN_RAW :
                    {
                        mavlink_read_can_raw_t raw_can_data;
                        mavlink_msg_read_can_raw_decode(&msg, &raw_can_data);
                        emit readRawCanData(raw_can_data);
                    }
                        break;
                    case MAVLINK_MSG_ID_SEND_CAN_RAW:
                    {
                        mavlink_send_can_raw_t raw_can_data;
                        mavlink_msg_send_can_raw_decode(&msg, &raw_can_data);
                        emit sendRawCanData(raw_can_data);
                    }
                        break;

                    default:
                        break;
                }
            }
        }
    }

}

void ComHelper::sendData( mavlink_message_t msg)
{
    uint16_t messageLength;
    uint8_t mavlinkBuffer[MAVLINK_MAX_PACKET_LEN];
    messageLength = mavlink_msg_to_send_buffer(mavlinkBuffer, &msg);
    write((char *)mavlinkBuffer, messageLength);
}

void ComHelper::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        closeSerialPort(1);
        emit commStatusChanged(COMM_DISCONNECTED);
        //MainWindowGlobalContext::getInstance()->addMessageBox("Serial Port","Serial Port Disconnected",INFO);
    }
}

void ComHelper::disconnectDevice()
{    
    if(m_serial->error() > 0)
    {
        m_serial->clearError();        
        if(m_serial->isOpen())
            m_serial->close();
       // if(isDeviceDisconnected == true)
        {
            emit commStatusChanged(COMM_DISCONNECTED);
            isDeviceDisconnected = false;
            isSerialPortConnected = false;
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

/// @brief this function is used to write data over serial port
/// @param data : data need to be write on serial port
void ComHelper::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

/// @brief This function is responsible to check that currently serial port is open or not.
bool ComHelper::isOpen()
{
    if(selectedInterface == INTERFACE_SERIAL)
    {
        return m_serial->isOpen();
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        return m_socket->isOpen();
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        return isOpendUdp;
        // return m_udpSocket->isOpen();
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        return m_bluetoothLink->isConnected();
    }
    return false;
}
/// @brief This function is responsible to write data over serial port using varioys protocols.
quint64 ComHelper::write(const char *m_data, qint64 len)
{
    if(selectedInterface == INTERFACE_SERIAL)
    {
        return m_serial->write(m_data,len);
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        return m_socket->write(m_data,len);
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        //        QMutexLocker locker(&_sessionTargetsMutex);
        qint64 retVal = 0;

#if 1
        QHostAddress host(targetAddr);

        //retVal = m_udpSocket->writeDatagram(QByteArray(m_data),host,14552);

        if( (retVal = m_udpSocket->writeDatagram(m_data,len,host,targetPort)) < 0) {
            qDebug() << "Error writing to count:" <<retVal<<" "<< host.toString() <<"  "<< targetPort;
        }
        //        else
        //        {
        //            qDebug() << "Data write Success count:" <<retVal<< " " << host.toString() <<"  "<< targetPort;
        //        }
#endif
        //        locker.unlock();
        return retVal;
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        m_bluetoothLink->_writeBytes(m_data,len);
    }
    return  0;
}
/// @brief This function is responsible to open the Serial port connection on various modes or interfaces such as serial interface, TCP interfave or UDP interface.
bool ComHelper::open(QIODevice::OpenModeFlag mode)
{
    if(selectedInterface == INTERFACE_SERIAL)
    {
        connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
        return m_serial->open(mode);
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
        m_socket->connectToHost(QHostAddress(tcpHostAddr),tcpPort);
        qDebug() << "tcp Host address :"<< tcpHostAddr;
        qDebug() << "tcp port :" << tcpPort;
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        m_udpSocket->close();
        qDebug() << "udp Host address :"<< tcpHostAddr;
        qDebug() << "udp port :" << tcpPort;

#if 1
        QHostAddress host(tcpHostAddr);//QHostAddress::AnyIPv4;
        m_udpSocket->setProxy(QNetworkProxy::NoProxy);
        bool _connectState = m_udpSocket->bind(host, tcpPort,QAbstractSocket::ReuseAddressHint | QUdpSocket::ShareAddress);
        if (_connectState) {
            m_udpSocket->joinMulticastGroup(QHostAddress("224.0.0.1"));
            //-- Make sure we have a large enough IO buffers
            m_udpSocket->setSocketOption(QAbstractSocket::SendBufferSizeSocketOption,     64 * 1024);
            m_udpSocket->setSocketOption(QAbstractSocket::KeepAliveOption,1);
            m_udpSocket->setSocketOption(QAbstractSocket::ReceiveBufferSizeSocketOption, 128 * 1024);
            connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readData()),Qt::UniqueConnection);
            connect(m_udpSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)),Qt::UniqueConnection);
            qDebug() << "Success to open socket!!!!";
            isOpendUdp = true;
        } else {
            isOpendUdp = false;
            qDebug() << "Failed to open UDP socket !!!!" << tr("Error binding UDP port: %1").arg(m_udpSocket->errorString());
        }
#endif
        return _connectState;
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        //          m_bluetoothLink->_connect();
    }

    return true;
}

void ComHelper::bytesWritten(qint64 bytes)
{
    //    qDebug() << "bytesWritten : "<<bytes;
}

/// @brief This function is responsible to close the serial port connection for all interfaces.
void ComHelper::close()
{
    if(selectedInterface == INTERFACE_SERIAL)
    {
        disconnect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
        return m_serial->close();
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
        return m_socket->close();
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        disconnect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
        isOpendUdp = false;
        return m_udpSocket->close();
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        m_bluetoothLink->_disconnect();
    }
}

/// @brief This function is responsible to read data from serial port
QByteArray ComHelper::readAll()
{
    if(selectedInterface == INTERFACE_SERIAL)
    {
        return m_serial->readAll();
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        return m_socket->readAll();
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        return readAllUDPBytes();
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        return m_message;
    }
    return QByteArray("");
}

/// @brief This function is responsible to read data over UDP protocol
QByteArray ComHelper::readAllUDPBytes()
{
    QByteArray databuffer;
    QMutexLocker locker(&udpReadLockMutex);
    while (m_udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());
        //QHostAddress sender;
        // If the other end is reset then it will still report data available,
        // but will fail on the readDatagram call
        qint64 slen = m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        if (slen == -1) {
            break;
        }
        databuffer.append(datagram);
        //-- Wait a bit before sending it over
        if (databuffer.size() > 10 * 1024) {
            locker.unlock();
            return databuffer;
            databuffer.clear();
        }
        // TODO: This doesn't validade the sender. Anything sending UDP packets to this port gets
        // added to the list and will start receiving datagrams from here. Even a port scanner
        // would trigger this.
        // Add host to broadcast list if not yet present, or update its port
        QHostAddress asender = sender;
        //if(_isIpLocal(sender))
        {
            asender = QHostAddress(QString("127.0.0.1"));
        }
    }
    //-- Send whatever is left
    locker.unlock();
    return databuffer;
}

/// @brief This function is responsible to set the interface i.e. serial, tcp or udp
void ComHelper::setInterFace(int interfaceNum)
{
    close();
    selectedInterface = (COMM_INTERFACE)interfaceNum;
    if(selectedInterface == INTERFACE_SERIAL)
    {
        connect(m_serial, SIGNAL(readyRead()), this, SLOT(readData()));
    }
    else if(selectedInterface == INTERFACE_TCP)
    {
        connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
    }
    else if(selectedInterface == INTERFACE_UDP)
    {
        connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    }
    else if(selectedInterface == INTERFACE_BLUETOOTH)
    {
        connect(m_bluetoothLink, SIGNAL(bytesReceived(QByteArray)), this, SLOT(readDataBluetooth(QByteArray)));
    }
}

/// @brief This function will return selected interface
int ComHelper::getInterFace()
{
    return (int)selectedInterface;
}

