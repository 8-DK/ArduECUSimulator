#include "pidencoderdecoder.h"

PIDEncoderDecoder::PIDEncoderDecoder(QObject *parent) : QObject(parent)
{
    parsePIDJsonLookUpFile();
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
