#include "localstrings.h"

LocalStrings::LocalStrings(QObject *parent) : QObject(parent)
{
    this->readLocalStringFile();
    this->readGCSThemeFile();
}
LocalStrings* LocalStrings::m_instance;

LocalStrings* LocalStrings::getInstance()
{
    if (LocalStrings::m_instance == nullptr)
    {
        LocalStrings::m_instance = new LocalStrings(nullptr);
    }

    return LocalStrings::m_instance;
}
void LocalStrings::readLocalStringFile()
{
    QByteArray val;
    QString fileName = ":/localFiles/LocalStrings.json";
    if(QFile::exists(fileName))
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();

        QJsonParseError jspe{};
        const QJsonDocument doc = QJsonDocument::fromJson(val, &jspe);
        if (doc.isNull())
        {
          qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
        }
        jsonArray = doc.array();

    }
    else
    {
        qDebug() << " Local String file not exits" << endl;
    }

}
QString LocalStrings::getLocalTextValue(QString textID)
{
    for (int i=0; i < jsonArray.size(); i++)
    {
        if(i!=1 && jsonArray.size()>=1)
        {
           QJsonObject temp =  jsonArray.at(i).toObject();
            QString x = temp.value("StringData").toObject().value(textID).toString();
            if(x == nullptr)
            {
                return  nullptr;
            }
            else
            {
                return x;
            }
        }
    }
    return  nullptr;
}

void LocalStrings::readGCSThemeFile()
{
    QByteArray val;
    QString fileName = ":/localFiles/AeroGCSTheme.json";
    if(QFile::exists(fileName))
    {
        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        qDebug() << "Reading from aerogcs file";
        file.close();

        QJsonParseError jspe{};
        const QJsonDocument doc = QJsonDocument::fromJson(val, &jspe);
        if (doc.isNull())
        {
          qWarning() << "Error loading JSON:" << jspe.errorString() << "@" << jspe.offset;
        }
        jsonThemeArray = doc.array();

    }
    else
    {
        qDebug() << " AeroGCS Theme file not exits" << endl;
    }
}

QString LocalStrings::getThemeData(QString themeID)
{

    for (int i=0; i < jsonThemeArray.size(); i++)
    {
        if(i!=1 && jsonThemeArray.size()>=1)
        {
           QJsonObject temp =  jsonThemeArray.at(i).toObject();
            QString x = temp.value("AeroGCSTheme").toObject().value(themeID).toString();
            if(x == nullptr)
            {
                return  nullptr;
            }
            else
            {
                return x;
            }
        }
    }
    return  nullptr;
}
