#include "styleglobalsconsts.h"
#include <QDebug>
#include "QApplication"
#include "QDesktopWidget"
#include <random>
#include "QDateTime"

StyleGlobalConsts::StyleGlobalConsts(QObject *parent) : QObject(parent)
{

}

StyleGlobalConsts* StyleGlobalConsts::m_instance;

StyleGlobalConsts* StyleGlobalConsts::getInstance()
{
    if (StyleGlobalConsts::m_instance == nullptr)
    {
        StyleGlobalConsts::m_instance = new StyleGlobalConsts(nullptr);
    }
    return StyleGlobalConsts::m_instance;
}

int StyleGlobalConsts::windowWidth()
{
    m_windowWidth = QApplication::desktop()->width();
    return m_windowWidth;
}

int StyleGlobalConsts::windowHeight()
{
    m_windowHeight = QApplication::desktop()->height();
    return m_windowHeight;
}

double StyleGlobalConsts::getRectWidth()
{
    m_rectWidth = m_windowWidth * 0.483;
    return m_rectWidth;
}

double StyleGlobalConsts::getRectHeight()
{
    m_rectHeight = m_windowHeight * 0.725;
    return m_rectHeight;
}

double StyleGlobalConsts::getVehicleDetailsRectWidth()
{
    m_vehicleDetailsRectWidth = m_rectWidth * 0.4;
    return m_vehicleDetailsRectWidth;
}

double StyleGlobalConsts::getVehicleDetailsRectHeight()
{
    m_vehicleDetailsRectHeight = m_rectHeight * 0.8;
    return m_vehicleDetailsRectHeight;
}

double StyleGlobalConsts::getSwitchWidth()
{
    m_switchWidth = m_windowWidth * 0.03;
    return m_switchWidth;
}

double StyleGlobalConsts::getSwitchHeight()
{
    m_switchHeight = m_windowHeight * 0.028;
    return m_switchHeight;
}

double StyleGlobalConsts::getSwitchRadius()
{
    m_switchRadius = m_windowHeight * 0.028;
    return m_switchRadius;
}

double StyleGlobalConsts::defaultButtonWidth()
{
    m_defaultButtonWidth = m_windowWidth * 0.1;
    return m_defaultButtonWidth;
}

double StyleGlobalConsts::defaultButtonHeight()
{
    m_defaultButtonHeight = m_windowHeight * 0.05;
    return m_defaultButtonHeight;
}

double StyleGlobalConsts::defaultButtonRadius()
{
    m_defaultButtonRadius = m_windowHeight * 0.05;;
    return m_defaultButtonRadius;
}

double StyleGlobalConsts::updateButtonWidth()
{
    m_updateButtonWidth = m_windowWidth * 0.145;
    return m_updateButtonWidth;
}

double StyleGlobalConsts::updateButtonHeight()
{
    m_updateButtonHeight = m_windowHeight * 0.05;
    return m_updateButtonHeight;
}

double StyleGlobalConsts::rpaSettingsTextEditWidth()
{
    m_rpaSettingsTextEditWidth = m_windowWidth * 0.262;
    return m_rpaSettingsTextEditWidth;
}

double StyleGlobalConsts::rpaSettingsTextEditHeight()
{
    m_rpaSettingsTextEditHeight = m_windowHeight * 0.07;
    return m_rpaSettingsTextEditHeight;
}

double StyleGlobalConsts::rpaSettingsTextEditRadius()
{
    m_rpaSettingsTextEditRadius = m_rectHeight * 0.01;
    return m_rpaSettingsTextEditRadius;
}

int StyleGlobalConsts::getMessageBoxTextPixelSize()
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

int StyleGlobalConsts::getNavbarHeadingPixelSize()
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

int StyleGlobalConsts::getTextEditPixelSize()
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

int StyleGlobalConsts::getButtonPixelSize()
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

int StyleGlobalConsts::getTextEditLabelPixelSize()
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

int StyleGlobalConsts::getRPASettingsLabelPixelSize()
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

int StyleGlobalConsts::getSmallLabelPixelSize()
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

int StyleGlobalConsts::getConnectedLabelPixelSize()
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

int StyleGlobalConsts::getMinMaxLabelPixelSize()
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

int StyleGlobalConsts::getMainLabelPixelSixe()
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

int StyleGlobalConsts::getCameraScrollViewHeight()
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

int StyleGlobalConsts::getSerialParamScrollViewHeight()
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

int StyleGlobalConsts::getBatteryFailsafeScrollViewHeight()
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

int StyleGlobalConsts::getReturnToLaunchScrollViewHeight()
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

int StyleGlobalConsts::getGeofenceScrollViewHeight()
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

int StyleGlobalConsts::getFailsafeTriggerScrollViewHeight()
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

int StyleGlobalConsts::getArmingChecksScrollViewHeight()
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

QString StyleGlobalConsts::padzero(double val,int zeroCount)
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

int StyleGlobalConsts::getRandomeInt(int min,int max){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(min, max);
    return uid(gen);
}

double StyleGlobalConsts::getRandomeFloat(double min,double max){
    float random = ((float) rand()) / (float) max;
    float diff = max - min;
    float r = random * diff;
    return (double)(min + r);
}
