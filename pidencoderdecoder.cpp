#include "pidencoderdecoder.h"

PIDEncoderDecoder::PIDEncoderDecoder(QObject *parent) : QObject(parent)
{
//    parsePIDJsonLookUpFile(); //use json file to PID lookup
    parsePIDCSVLookUpFile(); //use CSV file to PID lookup
    connect(SIM::comm(),SIGNAL(readRawCanData(mavlink_read_can_raw_t)),this,SLOT(parsePIDJsonLookUpFile(mavlink_read_can_raw_t)));

}
PIDEncoderDecoder* PIDEncoderDecoder::m_instance;

PIDEncoderDecoder* PIDEncoderDecoder::getInstance()
{
    if (PIDEncoderDecoder::m_instance == nullptr)
    {
        PIDEncoderDecoder::m_instance = new PIDEncoderDecoder(nullptr);
    }

    return PIDEncoderDecoder::m_instance;
}

QJsonArray PIDEncoderDecoder::getPIDList()
{
    return jsonArray;
}

void PIDEncoderDecoder::setValueOfPIDtIndex(int indx,double val)
{
    pIDInfoModel.setByindex(indx,val,PIDInfoModel::ValueRole);
}

double PIDEncoderDecoder::getValueOfPIDtIndex(int indx)
{
    return pIDInfoModel.getByindex(indx,PIDInfoModel::ValueRole).toDouble();
}

void PIDEncoderDecoder::setIsrandome(int indx,bool val)
{
    pIDInfoModel.setByindex(indx,val,PIDInfoModel::sendRandomeRole);
}

bool PIDEncoderDecoder::getIsrandome(int indx)
{
    return pIDInfoModel.getByindex(indx,PIDInfoModel::sendRandomeRole).toBool();
}

void PIDEncoderDecoder::setIsEnabled(int indx,bool val)
{
    pIDInfoModel.setByindex(indx,val,PIDInfoModel::isEnabledRole);
}

bool PIDEncoderDecoder::getIsEnabled(int indx)
{
    return pIDInfoModel.getByindex(indx,PIDInfoModel::isEnabledRole).toDouble();
}

void PIDEncoderDecoder::setMaxLimit(int indx,double val)
{
    pIDInfoModel.setByindex(indx,val,PIDInfoModel::MaxRole);
}

double PIDEncoderDecoder::getMaxLimit(int indx)
{
    return pIDInfoModel.getByindex(indx,PIDInfoModel::MaxRole).toDouble();
}

void PIDEncoderDecoder::setMinLimit(int indx,double val)
{
    pIDInfoModel.setByindex(indx,val,PIDInfoModel::MinRole);
}

double PIDEncoderDecoder::getMinLimit(int indx)
{
    return pIDInfoModel.getByindex(indx,PIDInfoModel::MinRole).toDouble();
}



void PIDEncoderDecoder::printFrame(uint64_t msgId, uint8_t *buff,uint8_t len)
{
    QString data = "MsgId " + QString::number(msgId, 16)+", ";
    for(int i = 0; i <len ; i++)
    {
        data += "0x"+QString::number(buff[i], 16)+", ";
    }

    qDebug() <<data;
}

void PIDEncoderDecoder::printOBDRequest(uint64_t msgId, uint8_t *buff,QString tag)
{
    QString data = tag+" MsgID : " + QString::number(msgId, 16)+QString("\t");
    data += "Data Count : 0x"+QString::number(buff[0], 16)+QString("\t");
    data += "Service : 0x"+QString::number(buff[1], 16)+QString("\t");
    if((int)buff[0] > 2)
    {
         data += "PID : 0x"+QString::number(buff[2]<<8 | buff[3], 16)+QString("\t");
         data += "B4 : 0x"+QString::number(buff[4], 16)+QString("\t");
         data += "B5 : 0x"+QString::number(buff[5], 16)+QString("\t");
         data += "B6 : 0x"+QString::number(buff[6], 16)+QString("\t");
         data += "B7 : 0x"+QString::number(buff[7], 16)+QString("\t");
    }
    else
    {
        data += "PID : 0x"+QString::number(buff[2], 16)+QString("\t");
        data += "B3 : 0x"+QString::number(buff[3], 16)+QString("\t");
        data += "B4 : 0x"+QString::number(buff[4], 16)+QString("\t");
        data += "B5 : 0x"+QString::number(buff[5], 16)+QString("\t");
        data += "B6 : 0x"+QString::number(buff[6], 16)+QString("\t");
        data += "B7 : 0x"+QString::number(buff[7], 16)+QString("\t");
    }

    qDebug().noquote() << data;
}

void PIDEncoderDecoder::printOBDResponse(uint64_t msgId, uint8_t *buff, QString tag)
{
    QString data = tag+" MsgID : " + QString::number(msgId, 16)+QString("\t");
    data += "Data Count : 0x"+QString::number(buff[0], 16)+QString("\t");
    data += "Service : 0x"+QString::number(buff[1], 16)+QString("\t");
    data += "PID : 0x"+QString::number(buff[2], 16)+QString("\t");
    data += "B3 : 0x"+QString::number(buff[3], 16)+QString("\t");
    data += "B4 : 0x"+QString::number(buff[4], 16)+QString("\t");
    data += "B5 : 0x"+QString::number(buff[5], 16)+QString("\t");
    data += "B6 : 0x"+QString::number(buff[6], 16)+QString("\t");
    data += "B7 : 0x"+QString::number(buff[7], 16)+QString("\t");

    qDebug().noquote() << data;
}

void PIDEncoderDecoder::parsePIDJsonLookUpFile(mavlink_read_can_raw_t msg)
{
    uint64_t  canMessageId = msg.msgId;
    uint8_t dataLen  = msg.len;
    uint8_t databuffer[100];
    OBD2Request obdReq;
    OBD2Response obdResp;
    memset(databuffer,0,sizeof(databuffer));
    memcpy(databuffer,msg.buffer,100);

//    printFrame(canMessageId,databuffer,dataLen);
    if(canMessageId == 0x7df) //standard obd can identifier
    {
        printOBDRequest(canMessageId,databuffer,">>>> ");
        memcpy(&obdReq,&databuffer,OBD_DATA_LEN);
        for(int i = 0 ; i < pIDInfoModel.rowCount();i++)
        {
            if((uint8_t)pIDInfoModel.getByindex(i,PIDInfoModel::PID_DecRole).toInt() == obdReq.pidCode)
            {
                uint64_t value = (uint64_t)pIDInfoModel.getByindex(i,PIDInfoModel::ValueRole).toDouble();
                uint8_t *valPtr = (uint8_t *)&value;
                obdResp.service = obdReq.service+0x40;
                obdResp.numAddnDataBytes = (uint8_t)pIDInfoModel.getByindex(i,PIDInfoModel::DataCountRole).toInt();
                obdResp.pidCode = obdReq.pidCode;
                obdResp.byte0 = valPtr[0];
                obdResp.byte1 = valPtr[1];
                obdResp.byte2 = valPtr[2];
                obdResp.byte3 = valPtr[3];
                obdResp.byte4 = valPtr[4];
                memset(databuffer,0,sizeof(databuffer));
                memcpy(databuffer,&obdResp,OBD_DATA_LEN);
                printOBDResponse(0x7E8,databuffer,"<<<< ");
                sendCanBuffer(0x7E8,databuffer,OBD_DATA_LEN);
                qDebug()<<"\n";
                break;
            }
        }
    }
}

void PIDEncoderDecoder::sendCanBuffer(uint16_t canMsgId, uint8_t* dataBuffer,uint16_t len)
{
    mavlink_send_can_raw_t msg;
    mavlink_message_t mavMsg;
    uint16_t messageLength;

    memset(&msg, 0, sizeof(msg));
    msg.target_system =     0;
    msg.target_component =  0;
    msg.extByte = 0;
    msg.len = len;
    msg.msgId = canMsgId;
    memcpy(&msg.buffer,dataBuffer,len);
    mavlink_msg_send_can_raw_encode_chan(0,
                                         0,
                                         1 ,
                                         &mavMsg,
                                         &msg);
    ComHelper::getInstance()->sendData(mavMsg);
}

void PIDEncoderDecoder::parsePIDJsonLookUpFile()
{
    if(!QFile::exists("PIDList.json"))
    {
       QFile::copy(":/localFiles/PIDList.json","PIDList.json");
    }

    QFile file("PIDList.json");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    file.setPermissions(QFileDevice::ReadOther | QFileDevice::WriteOther);
    QString jsonData = file.readAll();
    file.close();

    QJsonParseError jspe{};
    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8(), &jspe);
    if (doc.isNull())
    {
      qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
    }

    jsonArray = doc.object().value("OBD2PID").toArray();
    if(jsonArray.count() == 0)
    {
        QDir dir;
        dir.remove("PIDList.json");
        QFile::copy(":/localFiles/PIDList.json","PIDList.json");
        QFile::setPermissions("PIDList.json",QFileDevice::ReadOther | QFileDevice::WriteOther);
        QFile newFile(":/localFiles/PIDList.json");
        newFile.open(QIODevice::ReadOnly | QIODevice::Text);
        jsonData = newFile.readAll();
        newFile.close();
        doc = QJsonDocument::fromJson(jsonData.toUtf8(), &jspe);
        if (doc.isNull())
        {
          qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
        }
        jsonArray = doc.object().value("OBD2PID").toArray();
        if(jsonArray.count() == 0)
            qWarning() << "Failed to parse PDI list";
    }
    foreach (const QJsonValue & v, jsonArray)
    {
       QJsonObject jobj = v.toObject();
       pIDInfoModel.addAsset(jobj.value("Service").toInt(),
                             jobj.value("PID_Dec").toInt(),
                             jobj.value("DataCount").toInt(),
                             jobj.value("PIDName").toString(),
                             jobj.value("Description").toString(),
                             jobj.value("Unit").toString(),
                             jobj.value("Min").toInt(),
                             jobj.value("Max").toInt(),
                             (bool)jobj.value("isEnabled").toInt(),
                             (bool)jobj.value("sendRandome").toInt(),
                             (bool)jobj.value("AllowToChange").toInt(),
                             jobj.value("WidgetType").toInt()
                             );
    }
}


void PIDEncoderDecoder::parsePIDCSVLookUpFile()
{
    if(!QFile::exists("pidList.csv"))
    {
       QFile::copy(":/localFiles/pidList.csv","pidList.csv");
    }

    QFile file("pidList.csv");
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    file.setPermissions(QFileDevice::ReadOther | QFileDevice::WriteOther);

    QList<QStringList> pidStringList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        pidStringList.append(QString(line).split(','));
    }

//    qDebug() <<"Headers : " << pidStringList[0];

    for(int i = 1 ; i < pidStringList.count(); i++)
    {
        qDebug() << pidStringList[i];
        QStringList l =  pidStringList[i];
//   0           1         2        3            4          5      6      7         8              9            10               11              12
//("Service", "PIDs", "PID_Dec", "DataCount", "PIDName", "Min", "Max", "Units", "Description", "isEnabled", "sendRanadome", "AllowToChange", "WidgetType  "Value\n")
//("1",       "0",        "0",      "4",  "PIDs supported","", "",      "",     "Bit encoded [A7..D0] == [PID $01..PID $20]?See below", "1", "0", "1", "1"  "0\n")
        if(l.count() == 14)
        {
           pIDInfoModel.addAsset(l[0].toInt(),
                                 l[2].toInt(),
                                 l[3].toInt(),
                                 l[4]+"(0x"+l[1]+")",
                                 l[8],
                                 l[7],
                                 l[5].toInt(),
                                 l[6].toInt(),
                                 l[9].toInt(),
                                 l[10].toInt(),
                                 l[11].toInt(),
                                 l[12].toInt(),
                                 l[13].toDouble());
        }
    }
}

