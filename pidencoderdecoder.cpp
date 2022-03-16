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

void PIDEncoderDecoder::getPIDList()
{

}

void PIDEncoderDecoder::parsePIDJsonLookUpFile()
{
    if(!QFile::exists("PIDList.json"))
    {
       QFile::copy(":/localFiles/PIDList.json","PIDList.json");
    }

    QFile file("PIDList.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonParseError jspe{};
    const QJsonDocument doc = QJsonDocument::fromJson(jsonData, &jspe);
    if (doc.isNull())
    {
      qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
    }

    jsonArray = doc.array();
    if(jsonArray.count() == 0)
    {
        QFile::remove("PIDList.json");
        QFile::copy(":/localFiles/PIDList.json","PIDList.json");
    }
    foreach (const QJsonValue & v, jsonArray)
       qDebug() << v.toObject().value("PIDName").toString();
}
