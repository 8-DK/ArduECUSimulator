#ifndef STYLE_H
#define STYLE_H

#include <QObject>
#include <QtDebug>
#include <QQmlProperty>
#include <QQuickItem>
#include <QQmlProperty>
#include <QQuickItem>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qjsondocument.h>
#include <qfileinfo.h>
#include <qdir.h>

class GStyle : public QObject{
    Q_OBJECT

    QJsonArray jsonThemeArray;
    QJsonObject jsonCurrentThemeData;

public:
    explicit GStyle(QObject *parent = nullptr);

    static GStyle *getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

    typedef  enum{
        LARGE_1 = 28,
        LARGE_2 = 26,
        LARGE_3 = 24,
        LARGE_4 = 22,
        MEDIUM_1 = 20,
        MEDIUM_2 = 18,
        MEDIUM_3 = 17,
        MEDIUM_4 = 16,
        SMALL_1 = 15,
        SMALL_2 = 14,
        SMALL_3 = 12,
        SMALL_4 = 11,
        TINY_1 = 10,
        TINY_2 = 9,
        TINY_3 = 8,
        TINY_4 = 6
    } New_Fonts;
    Q_ENUM(New_Fonts)

    void readThemeFile(QString loadDefaultTheme = "default");
    QString getThemeData(QString themeID);

public slots:
    Q_INVOKABLE int windowHeight();
    Q_INVOKABLE int windowWidth();
    Q_INVOKABLE double getRectWidth();
    Q_INVOKABLE double getRectHeight();
    Q_INVOKABLE double getVehicleDetailsRectWidth();
    Q_INVOKABLE double getVehicleDetailsRectHeight();
    Q_INVOKABLE double getSwitchWidth();
    Q_INVOKABLE double getSwitchHeight();
    Q_INVOKABLE double getSwitchRadius();

    Q_INVOKABLE double defaultButtonWidth();
    Q_INVOKABLE double defaultButtonHeight();
    Q_INVOKABLE double defaultButtonRadius();
    Q_INVOKABLE double updateButtonWidth();
    Q_INVOKABLE double updateButtonHeight();
    Q_INVOKABLE double rpaSettingsTextEditRadius();
    Q_INVOKABLE double rpaSettingsTextEditWidth();
    Q_INVOKABLE double rpaSettingsTextEditHeight();

    Q_INVOKABLE   int getTextEditPixelSize();
    Q_INVOKABLE   int getButtonPixelSize();
    Q_INVOKABLE   int getTextEditLabelPixelSize();
    Q_INVOKABLE   int getRPASettingsLabelPixelSize();
    Q_INVOKABLE   int getSmallLabelPixelSize();
    Q_INVOKABLE   int getConnectedLabelPixelSize();
    Q_INVOKABLE   int getMinMaxLabelPixelSize();
    Q_INVOKABLE   int getMainLabelPixelSixe();
    Q_INVOKABLE   int getNavbarHeadingPixelSize();
    Q_INVOKABLE   int getMessageBoxTextPixelSize();

    Q_INVOKABLE   int getCameraScrollViewHeight();
    Q_INVOKABLE   int getSerialParamScrollViewHeight();
    Q_INVOKABLE   int getBatteryFailsafeScrollViewHeight();
    Q_INVOKABLE   int getReturnToLaunchScrollViewHeight();
    Q_INVOKABLE   int getGeofenceScrollViewHeight();
    Q_INVOKABLE   int getFailsafeTriggerScrollViewHeight();
    Q_INVOKABLE   int getArmingChecksScrollViewHeight();

    Q_INVOKABLE   int getCardRadius(){return 12;}


    Q_INVOKABLE   inline int getDropshadowHorizontalOffset() {return m_dropshadowHorizontalOffset;}
    Q_INVOKABLE   inline int getDropshadowVerticalOffset() {return m_dropshadowVerticalOffset;}
    Q_INVOKABLE   inline int getDropshadowRadius() {return m_dropshadowRadius;}
    Q_INVOKABLE   inline int getDropshadowSamples() {return m_dropshadowSamples;}
    Q_INVOKABLE   inline QString getDropshadowColor(){ return m_dropeShadowColor;}
    Q_INVOKABLE   inline QString blueColor(){return m_blueColor;}
    Q_INVOKABLE   inline QString whiteColor(){return m_whiteColor;}
    Q_INVOKABLE   inline QString borderColor(){return m_borderColor;}
    Q_INVOKABLE   inline QString greenColor() {return m_greenColor;}
    Q_INVOKABLE   inline QString blackColor() {return m_blackColor;}
    Q_INVOKABLE   inline QString lightGrayColor() {return m_lightGrayColor;}
    Q_INVOKABLE   inline QString parrotGreenColor() {return m_parrotGreenColor;}
    Q_INVOKABLE   inline QString darkGrayColor() {return m_darkGrayColor;}
    Q_INVOKABLE   inline QString redColor() {return m_redColor;}
    Q_INVOKABLE   inline QString linkerColor() {return m_linkerColor;}
    Q_INVOKABLE   inline QString mainThemeColor() {return m_mainThemeColor;}
    Q_INVOKABLE   inline QString mainThemeActiveColor() {return m_mainThemeActiveColor;}
    Q_INVOKABLE   inline QString disableColor() {return m_disableColor;}

    Q_INVOKABLE   QString padzero(double val,int zeroCount);
    Q_INVOKABLE   int getRandomeInt(int min,int max);
    Q_INVOKABLE   double getRandomeFloat(double min,double max);
    Q_INVOKABLE   bool isBitSet(double num,int bitNum);
    Q_INVOKABLE   double clearBitSet(double num,int bitNum);
    Q_INVOKABLE   double setBitSet(double num,int bitNum);
    Q_INVOKABLE   double toggleBit(double num,int bitNum);
    Q_INVOKABLE   QString numToHexStr(double num);
    Q_INVOKABLE double hexstrToNum(QString numStr);

    //Theme palette
    Q_INVOKABLE QString gP(QString textID);

private:
    static GStyle *m_instance;
    int m_windowWidth;
    int m_windowHeight;

    double m_rectWidth;
    double m_rectHeight;

    double m_vehicleDetailsRectWidth;
    double m_vehicleDetailsRectHeight;

    double m_switchWidth;
    double m_switchHeight;
    double m_switchRadius;

    double m_defaultButtonWidth;
    double m_defaultButtonHeight;
    double m_defaultButtonRadius;
    double m_updateButtonWidth;
    double m_updateButtonHeight;

    double m_rpaSettingsTextEditRadius;
    double m_rpaSettingsTextEditWidth;
    double m_rpaSettingsTextEditHeight;

    int m_textEditPixelSize;
    int m_ButtonPixelSize;
    int m_textEditLabelPixelSize;
    int m_rpaSettingsLabelPixelSize;
    int m_smallLabelPixelSize;
    int m_connectedLabelPixelSize;
    int m_minMaxLabelPixelSize;
    int m_mainLabelPixelSize;
    int m_navbarHeadingPixelSize;
    int m_messageBoxTextPixelSize;

    int m_cameraScrollViewHeight;
    int m_serialParamScrollViewHeight;
    int m_batteryFailsafeScrollViewHeight;
    int m_returnToLaunchScrollViewHeight;
    int m_geofenceScrollViewHeight;
    int m_failsafeTriggerScrollViewHeight;
    int m_armingChecksScrollViewHeight;

    int m_dropshadowHorizontalOffset = 3;
    int m_dropshadowVerticalOffset = 3;
    int m_dropshadowRadius = 10;
    int m_dropshadowSamples = 10;
    QString m_dropeShadowColor = "#758691";
    QString m_blueColor="#48B0E5";
    QString m_whiteColor="#FFFFFF";
    QString m_borderColor="#979797";
    QString m_greenColor = "#26A69A";
    QString m_blackColor = "#040404";
    QString m_lightGrayColor = "#C9C7C5";
    QString m_parrotGreenColor = "#0FD80B";
    QString m_darkGrayColor = "#666666";
    QString m_redColor = "#ff0000";
    QString m_linkerColor = "#EDEEF3";
    QString m_dropShadowColor = "lightgray";

    QString m_mainThemeColor = "#00c99e";
    QString m_mainThemeActiveColor = "#006f4e";
    QString m_disableColor = "#d3d3d3";

    QString themePrimaryColor = "#E9ECF3";
};

#endif // STYLE_H
