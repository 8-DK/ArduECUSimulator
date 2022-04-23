#include "styleglobalsconsts.h"
#include <QDebug>
#include "QApplication"
#include "QDesktopWidget"
#include <random>
#include "QDateTime"

GStyle::GStyle(QObject *parent) : QObject(parent)
{
    readThemeFile("default");
}

GStyle* GStyle::m_instance;

GStyle* GStyle::getInstance()
{
    if (GStyle::m_instance == nullptr)
    {
        GStyle::m_instance = new GStyle(nullptr);
    }
    return GStyle::m_instance;
}

int GStyle::windowWidth()
{
    m_windowWidth = QApplication::desktop()->width();
    return m_windowWidth;
}

int GStyle::windowHeight()
{
    m_windowHeight = QApplication::desktop()->height();
    return m_windowHeight;
}

double GStyle::getRectWidth()
{
    m_rectWidth = m_windowWidth * 0.483;
    return m_rectWidth;
}

double GStyle::getRectHeight()
{
    m_rectHeight = m_windowHeight * 0.725;
    return m_rectHeight;
}

double GStyle::getVehicleDetailsRectWidth()
{
    m_vehicleDetailsRectWidth = m_rectWidth * 0.4;
    return m_vehicleDetailsRectWidth;
}

double GStyle::getVehicleDetailsRectHeight()
{
    m_vehicleDetailsRectHeight = m_rectHeight * 0.8;
    return m_vehicleDetailsRectHeight;
}

double GStyle::getSwitchWidth()
{
    m_switchWidth = m_windowWidth * 0.03;
    return m_switchWidth;
}

double GStyle::getSwitchHeight()
{
    m_switchHeight = m_windowHeight * 0.028;
    return m_switchHeight;
}

double GStyle::getSwitchRadius()
{
    m_switchRadius = m_windowHeight * 0.028;
    return m_switchRadius;
}

double GStyle::defaultButtonWidth()
{
    m_defaultButtonWidth = m_windowWidth * 0.1;
    return m_defaultButtonWidth;
}

double GStyle::defaultButtonHeight()
{
    m_defaultButtonHeight = m_windowHeight * 0.05;
    return m_defaultButtonHeight;
}

double GStyle::defaultWdgtRadius()
{
    m_defaultWdgtRadius = defaultButtonHeight() * 0.15;
    return m_defaultWdgtRadius;
}

double GStyle::updateButtonWidth()
{
    m_updateButtonWidth = m_windowWidth * 0.145;
    return m_updateButtonWidth;
}

double GStyle::updateButtonHeight()
{
    m_updateButtonHeight = m_windowHeight * 0.05;
    return m_updateButtonHeight;
}

double GStyle::rpaSettingsTextEditWidth()
{
    m_rpaSettingsTextEditWidth = m_windowWidth * 0.262;
    return m_rpaSettingsTextEditWidth;
}

double GStyle::rpaSettingsTextEditHeight()
{
    m_rpaSettingsTextEditHeight = m_windowHeight * 0.07;
    return m_rpaSettingsTextEditHeight;
}

double GStyle::rpaSettingsTextEditRadius()
{
    m_rpaSettingsTextEditRadius = m_rectHeight * 0.01;
    return m_rpaSettingsTextEditRadius;
}

int GStyle::getMessageBoxTextPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_messageBoxTextPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_messageBoxTextPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_messageBoxTextPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_messageBoxTextPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_messageBoxTextPixelSize = SMALL_2;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_messageBoxTextPixelSize = SMALL_3;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_messageBoxTextPixelSize = TINY_1;
    }
    if(m_windowWidth < 800)
    {
        m_messageBoxTextPixelSize = TINY_2;
    }
//    qDebug() << "Messagebox Text Pixel size :" << m_messageBoxTextPixelSize;
    return m_messageBoxTextPixelSize;
}

int GStyle::getNavbarHeadingPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_navbarHeadingPixelSize = LARGE_1 + 2;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_navbarHeadingPixelSize = LARGE_1;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_navbarHeadingPixelSize = LARGE_2;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_navbarHeadingPixelSize = LARGE_3;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_navbarHeadingPixelSize = LARGE_4;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_navbarHeadingPixelSize = MEDIUM_1;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_navbarHeadingPixelSize = MEDIUM_2;
    }
    if(m_windowWidth < 800)
    {
        m_navbarHeadingPixelSize = MEDIUM_3;
    }
    return m_navbarHeadingPixelSize;
}

int GStyle::getTextEditPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_textEditPixelSize = LARGE_3;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_textEditPixelSize = LARGE_4;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_textEditPixelSize = MEDIUM_1;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_textEditPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_textEditPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_textEditPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_textEditPixelSize = SMALL_1;
    }
    if(m_windowWidth < 800)
    {
        m_textEditPixelSize = SMALL_2;
    }
    return m_textEditPixelSize;
}

int GStyle::getButtonPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_ButtonPixelSize = LARGE_2;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_ButtonPixelSize = LARGE_3;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_ButtonPixelSize = LARGE_4;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_ButtonPixelSize = MEDIUM_1;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_ButtonPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_ButtonPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_ButtonPixelSize = MEDIUM_4;
    }
    if(m_windowWidth < 800)
    {
        m_ButtonPixelSize = SMALL_1;
    }

    return m_ButtonPixelSize;
}

int GStyle::getTextEditLabelPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_textEditLabelPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_textEditLabelPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_textEditLabelPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_textEditLabelPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1300)
    {
        m_textEditLabelPixelSize = SMALL_2;
    }
    if(m_windowWidth <= 1299 && m_windowWidth >= 1200)
    {
        m_textEditLabelPixelSize = SMALL_3;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1100)
    {
        m_textEditLabelPixelSize = SMALL_4;
    }
    if(m_windowWidth <= 1099 && m_windowWidth >= 1000)
    {
        m_textEditLabelPixelSize = TINY_1;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_textEditLabelPixelSize = TINY_2;
    }
    if(m_windowWidth < 800)
    {
        m_textEditLabelPixelSize = TINY_3;
    }

    return m_textEditLabelPixelSize;
}

int GStyle::getRPASettingsLabelPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_rpaSettingsLabelPixelSize = LARGE_4;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_rpaSettingsLabelPixelSize = MEDIUM_1;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_rpaSettingsLabelPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_rpaSettingsLabelPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_rpaSettingsLabelPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_rpaSettingsLabelPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_rpaSettingsLabelPixelSize = SMALL_2;
    }
    if(m_windowWidth < 800)
    {
        m_rpaSettingsLabelPixelSize = SMALL_3;
    }

    return m_rpaSettingsLabelPixelSize;
}

int GStyle::getSmallLabelPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_smallLabelPixelSize = MEDIUM_3;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_smallLabelPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_smallLabelPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_smallLabelPixelSize = SMALL_2;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1300)
    {
        m_smallLabelPixelSize = SMALL_3;
    }
    if(m_windowWidth <= 1299 && m_windowWidth >= 1200)
    {
        m_smallLabelPixelSize = SMALL_4;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1100)
    {
        m_smallLabelPixelSize = TINY_1;
    }
    if(m_windowWidth <= 1099 && m_windowWidth >= 1000)
    {
        m_smallLabelPixelSize = TINY_2;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_smallLabelPixelSize = TINY_3;
    }
    if(m_windowWidth < 800)
    {
        m_smallLabelPixelSize = TINY_4;
    }

    return m_smallLabelPixelSize;
}

int GStyle::getConnectedLabelPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_connectedLabelPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_connectedLabelPixelSize = SMALL_2;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_connectedLabelPixelSize = SMALL_3;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_connectedLabelPixelSize = SMALL_4;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_connectedLabelPixelSize = TINY_1;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_connectedLabelPixelSize = TINY_2;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_connectedLabelPixelSize = TINY_3;
    }
    if(m_windowWidth < 800)
    {
        m_connectedLabelPixelSize = TINY_4;
    }

    return m_connectedLabelPixelSize;
}

int GStyle::getMinMaxLabelPixelSize()
{
    if(m_windowWidth >= 2000)
    {
        m_minMaxLabelPixelSize = MEDIUM_4;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_minMaxLabelPixelSize = SMALL_1;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_minMaxLabelPixelSize = SMALL_2;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_minMaxLabelPixelSize = SMALL_3;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_minMaxLabelPixelSize = SMALL_4;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_minMaxLabelPixelSize = TINY_1;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_minMaxLabelPixelSize = TINY_2;
    }
    if(m_windowWidth < 800)
    {
        m_minMaxLabelPixelSize = TINY_3;
    }

    return m_minMaxLabelPixelSize;
}

int GStyle::getMainLabelPixelSixe()
{
    if(m_windowWidth >= 2000)
    {
        m_mainLabelPixelSize = LARGE_1;
    }
    if(m_windowWidth <= 1999 && m_windowWidth >= 1800)
    {
        m_mainLabelPixelSize = LARGE_2;
    }
    if(m_windowWidth <= 1799 && m_windowWidth >= 1600)
    {
        m_mainLabelPixelSize = LARGE_3;
    }
    if(m_windowWidth <= 1599 && m_windowWidth >= 1400)
    {
        m_mainLabelPixelSize = LARGE_4;
    }
    if(m_windowWidth <= 1399 && m_windowWidth >= 1200)
    {
        m_mainLabelPixelSize = MEDIUM_1;
    }
    if(m_windowWidth <= 1199 && m_windowWidth >= 1000)
    {
        m_mainLabelPixelSize = MEDIUM_2;
    }
    if(m_windowWidth <= 999 && m_windowWidth >= 800)
    {
       m_mainLabelPixelSize = MEDIUM_3;
    }
    if(m_windowWidth < 800)
    {
        m_mainLabelPixelSize = MEDIUM_4;
    }

    return m_mainLabelPixelSize;
}

int GStyle::getCameraScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_cameraScrollViewHeight = 3350;
    }
    if(m_windowHeight == 1050)
    {
        m_cameraScrollViewHeight = 3310;
    }
    if(m_windowHeight == 1024)
    {
        m_cameraScrollViewHeight = 3200;
    }
    if(m_windowHeight == 900)
    {
        m_cameraScrollViewHeight = 2850;
    }
    if(m_windowHeight == 800)
    {
       m_cameraScrollViewHeight = 2550;
    }
    if(m_windowHeight == 768)
    {
        m_cameraScrollViewHeight = 2480;
    }
    if(m_windowHeight == 720)
    {
        m_cameraScrollViewHeight = 2350;
    }
    if(m_windowHeight == 600)
    {
        m_cameraScrollViewHeight = 2000;
    }
    return m_cameraScrollViewHeight;
}

int GStyle::getSerialParamScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_serialParamScrollViewHeight = 1340;
    }
    if(m_windowHeight == 1050)
    {
        m_serialParamScrollViewHeight = 1300;
    }
    if(m_windowHeight == 1024)
    {
        m_serialParamScrollViewHeight = 1270;
    }
    if(m_windowHeight == 900)
    {
        m_serialParamScrollViewHeight = 1130;
    }
    if(m_windowHeight == 800)
    {
       m_serialParamScrollViewHeight = 1000;
    }
    if(m_windowHeight == 768)
    {
        m_serialParamScrollViewHeight = 960;
    }
    if(m_windowHeight == 720)
    {
        m_serialParamScrollViewHeight = 900;
    }
    if(m_windowHeight == 600)
    {
        m_serialParamScrollViewHeight = 750;
    }
    return m_serialParamScrollViewHeight;
}

int GStyle::getBatteryFailsafeScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_batteryFailsafeScrollViewHeight = 1000;
    }
    if(m_windowHeight == 1050)
    {
        m_batteryFailsafeScrollViewHeight = 970;
    }
    if(m_windowHeight == 1024)
    {
        m_batteryFailsafeScrollViewHeight = 930;
    }
    if(m_windowHeight == 900)
    {
        m_batteryFailsafeScrollViewHeight = 840;
    }
    if(m_windowHeight == 800)
    {
        m_batteryFailsafeScrollViewHeight = 750;
    }
    if(m_windowHeight == 768)
    {
        m_batteryFailsafeScrollViewHeight = 710;
    }
    if(m_windowHeight == 720)
    {
        m_batteryFailsafeScrollViewHeight = 680;
    }
    if(m_windowHeight == 600)
    {
        m_batteryFailsafeScrollViewHeight = 570;
    }
    return m_batteryFailsafeScrollViewHeight;
}

int GStyle::getReturnToLaunchScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_returnToLaunchScrollViewHeight = 780;
    }
    if(m_windowHeight == 1050)
    {
        m_returnToLaunchScrollViewHeight = 750;
    }
    if(m_windowHeight == 1024)
    {
        m_returnToLaunchScrollViewHeight = 710;
    }
    if(m_windowHeight == 900)
    {
        m_returnToLaunchScrollViewHeight = 650;
    }
    if(m_windowHeight == 800)
    {
        m_returnToLaunchScrollViewHeight = 590;
    }
    if(m_windowHeight == 768)
    {
        m_returnToLaunchScrollViewHeight = 575;
    }
    if(m_windowHeight == 720)
    {
        m_returnToLaunchScrollViewHeight = 560;
    }
    if(m_windowHeight == 600)
    {
        m_returnToLaunchScrollViewHeight = 470;
    }
    return m_returnToLaunchScrollViewHeight;
}

int GStyle::getGeofenceScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_geofenceScrollViewHeight = 600;
    }
    if(m_windowHeight == 1050)
    {
        m_geofenceScrollViewHeight = 570;
    }
    if(m_windowHeight == 1024)
    {
        m_geofenceScrollViewHeight = 540;
    }
    if(m_windowHeight == 900)
    {
        m_geofenceScrollViewHeight = 500;
    }
    if(m_windowHeight == 800)
    {
        m_geofenceScrollViewHeight = 460;
    }
    if(m_windowHeight == 768)
    {
        m_geofenceScrollViewHeight = 455;
    }
    if(m_windowHeight == 720)
    {
        m_geofenceScrollViewHeight = 440;
    }
    if(m_windowHeight == 600)
    {
        m_geofenceScrollViewHeight = 400;
    }
    return m_geofenceScrollViewHeight;
}

int GStyle::getFailsafeTriggerScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_failsafeTriggerScrollViewHeight = 600;
    }
    if(m_windowHeight == 1050)
    {
        m_failsafeTriggerScrollViewHeight = 570;
    }
    if(m_windowHeight == 1024)
    {
        m_failsafeTriggerScrollViewHeight = 540;
    }
    if(m_windowHeight == 900)
    {
        m_failsafeTriggerScrollViewHeight = 500;
    }
    if(m_windowHeight == 800)
    {
        m_failsafeTriggerScrollViewHeight = 460;
    }
    if(m_windowHeight == 768)
    {
        m_failsafeTriggerScrollViewHeight = 425;
    }
    if(m_windowHeight == 720)
    {
        m_failsafeTriggerScrollViewHeight = 410;
    }
    if(m_windowHeight == 600)
    {
        m_failsafeTriggerScrollViewHeight = 350;
    }
    return m_failsafeTriggerScrollViewHeight;
}

int GStyle::getArmingChecksScrollViewHeight()
{
    if(m_windowHeight == 1080)
    {
        m_armingChecksScrollViewHeight = 1000;
    }
    if(m_windowHeight == 1050)
    {
        m_armingChecksScrollViewHeight = 970;
    }
    if(m_windowHeight == 1024)
    {
        m_armingChecksScrollViewHeight = 960;
    }
    if(m_windowHeight == 900)
    {
        m_armingChecksScrollViewHeight = 870;
    }
    if(m_windowHeight == 800)
    {
        m_armingChecksScrollViewHeight = 800;
    }
    if(m_windowHeight == 768)
    {
        m_armingChecksScrollViewHeight = 785;
    }
    if(m_windowHeight == 720)
    {
        m_armingChecksScrollViewHeight = 760;
    }
    if(m_windowHeight == 600)
    {
        m_armingChecksScrollViewHeight = 680;
    }
    return m_armingChecksScrollViewHeight;
}

QString GStyle::padzero(double val,int zeroCount)
{
    char buff[500]= {'0'};
    //memset(buff,'0',sizeof(buff));
    char frmt[] = "%.0lf\0";
    sprintf(buff,frmt,val);
    QString outStr = QString(buff);
    for(int i = 0 ; i < (zeroCount-outStr.length());i++)
    {

    }
    qDebug() << "Out  : " << QString(buff);
    return QString(buff);
}

int GStyle::getRandomeInt(int min,int max){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(min, max);
    return uid(gen);
}

double GStyle::getRandomeFloat(double min,double max){
    float random = ((float) rand()) / (float) max;
    float diff = max - min;
    float r = random * diff;
    return (double)(min + r);
}

bool GStyle::isBitSet(double num,int bitNum)
{
    uint64_t numU64 = (uint64_t)num;
    return (bool)(numU64 & (1<<bitNum));
}

double GStyle::clearBitSet(double num,int bitNum)
{
    uint64_t numU64 = (uint64_t)num;
    return (double)(numU64 & ~(1<<bitNum));
}

double GStyle::setBitSet(double num,int bitNum)
{
    uint64_t numU64 = (uint64_t)num;
    qDebug() << "setBitSet : "<<numU64<<" Bit:"<<bitNum<<" After bit shift : "<<(double)(numU64 | (1<<bitNum));
    return (double)(numU64 | (1<<bitNum));
}

double GStyle::toggleBit(double num,int bitNum)
{
    uint64_t numU64 = (uint64_t)num;
    qDebug() << "setBitSet : "<<numU64<<" Bit:"<<bitNum<<" After bit toggleBit : "<<(double)(numU64 ^ (1<<bitNum));
    return (int)(numU64 ^ (1<<bitNum));
}

QString GStyle::numToHexStr(double num)
{
    QString strNum = QString("0x%1").arg((ulong)num, 8, 16, QLatin1Char( '0' ));
    qDebug() << strNum;
    return strNum;
}

double GStyle::hexstrToNum(QString numStr)
{
    bool ok;
    double hex = numStr.toULong(&ok, 16);
    return hex;
}


QString GStyle::gP(QString textID)
{
    QString pallete = jsonCurrentThemeData.value(textID).toString();
    return pallete;
}

void GStyle::readThemeFile(QString loadDefaultTheme)
{
    QByteArray val;
    QString fileName = ":/localFiles/Theme.json";
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
        jsonThemeArray = doc.array();
        getThemeData(loadDefaultTheme);
    }
    else
    {
        qDebug() << " Theme file not exits" << endl;
    }
}

QString GStyle::getThemeData(QString m_themeID)
{

    for (int i=0; i < jsonThemeArray.size(); i++)
    {
        if(i!=1 && jsonThemeArray.size()>=1)
        {
           QJsonObject temp =  jsonThemeArray.at(i).toObject();
            QString themId = temp.value("Theme").toObject().value("themeID").toString();
            if(themId == m_themeID)
            {
               jsonCurrentThemeData = temp.value("Theme").toObject();
               qDebug().noquote() << "Current theme : " << themId << ", Data : "<<jsonCurrentThemeData;
               return themId;
            }
        }
    }
    return  "";
}

