#include "pidencoderdecoder.h"

PIDEncoderDecoder::PIDEncoderDecoder(QObject *parent) : QObject(parent)
{
//    parsePIDJsonLookUpFile();
    parsePIDCSVLookUpFile();
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

void PIDEncoderDecoder::parsePIDJsonLookUpFile(uint8_t msh)
{

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

    qDebug() <<"Headers : " << pidStringList[0];

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
                                 l[4],
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

