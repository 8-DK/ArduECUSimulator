#include "mainwindowglobalcontext.h"
#include <QMessageBox>

MainWindowGlobalContext* MainWindowGlobalContext::m_MainWindowGlobalContext;

MainWindowGlobalContext::MainWindowGlobalContext(QObject *parent) :
    QObject(parent)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    appInit();
    QTimer *timerUiUpdate = new QTimer(this);
    timerUiUpdate->setInterval(1000);
    connect(timerUiUpdate, SIGNAL(timeout()), this, SLOT(uiUpdateLoop()));
    timerUiUpdate->start();
}

void MainWindowGlobalContext::mainWindowRegisterQML()
{
//    qmlRegisterType<SerialPortSettings>("SerialPortSettingsLib", 1, 0, "SerialPortSettings");
//    qmlRegisterType<CommLinkSettings>("CommLinkSettingLib", 1, 0, "CommLinkSettings");
//    qmlRegisterType<ArmingCheck>("ArmingCheckLib", 1, 0, "ArmingCheck");
//    qmlRegisterType<SafetyController>("safetyLib", 1, 0, "SafetyController");
//    qmlRegisterType<GeneraldatabaseUser>("GeneraldatabaseUser", 1, 0, "GeneraldatabaseUser");
//    qmlRegisterType<PowerSetup>("PowerSetupLib", 1, 0, "PowerSetup");
//    qmlRegisterType<FlightModes>("flightmodeLib", 1, 0, "FlightModes");
//    qmlRegisterType<AirFrame>("AirFrameLib", 1, 0, "AirFrame");
//    qmlRegisterType<CompassParameter>("CompassParameterLib", 1, 0, "CompassParameter");
//    qmlRegisterType<SetFlightParameters>("SetFlightParametersLib", 1, 0, "SetFlightParameters");
//    qmlRegisterType<ReadDatabase>("ReadDatabaseLib", 1, 0, "ReadDatabase");
//    qmlRegisterType<SensorsComponentController>("SensorComponentControllerLib", 1, 0, "SensorComponentController");
//    qmlRegisterType<PathController>("PathControllerLib",1,0,"PathController");
//    qmlRegisterType<Flightflyplanning>("FlightflyplanningLib", 1, 0, "Flightflyplanning");
//    qmlRegisterType<GeneralCalculation>("GeneralCalculation", 1,0,"GeneralCalculation");
////    qmlRegisterType<UIUpdater>("UIUpdaterLib", 1, 0, "UIUpdater");
//    qmlRegisterType<ReaderThread>("ReaderThreadLib", 1, 0, "ReaderThread");
//    qmlRegisterType<MapWrapper>("MapWrapperLib" ,1,0,"MapWrapper");
//    qmlRegisterType<AltitudeSetup>("AltitudeSetupLib" ,1,0,"AltitudeSetup");
//    qmlRegisterSingletonType<MySerialPort>("SerialPortLib", 1, 0, "MySerialPort",&MySerialPort::getInstance);
//    qmlRegisterSingletonType<RestApiHelper>("RestApiHelperLib", 1, 0, "RestApiHelper",&RestApiHelper::getInstance);
//    qmlRegisterSingletonType<NPNT_Data_helper>("NPNT_Data_helperLib", 1, 0, "NPNT_Data_helper",&NPNT_Data_helper::getInstance);
//    qmlRegisterType<LogController>("LogControllerLib", 1, 0, "LogController");
//    qmlRegisterType<FileOpenWrapper>("FileOpenWrapperLib", 1, 0, "FileOpenWrapper");
//    qmlRegisterSingletonType<ProjectStructure>("ProjectStructureLib", 1, 0, "ProjectStructure",&ProjectStructure::getInstance);
//    qmlRegisterSingletonType<FlightNotifications>("FlightNotificationsLib", 1, 0, "FlightNotifications",&FlightNotifications::getInstance);
//    qmlRegisterSingletonType<FlightNotificationList>("FlightNotificationListLib", 1, 0, "FlightNotificationList",&FlightNotificationList::getInstance);
//    qmlRegisterSingletonType<AeroGCSLogin>("AeroGCSLoginLib", 1, 0, "AeroGCSLogin",&AeroGCSLogin::getInstance);
//    qmlRegisterSingletonType<ProjectModelHelper>("ProjectModelHelperLib", 1, 0, "ProjectModelHelper",&ProjectModelHelper::getInstance);
//    qmlRegisterSingletonType<SelectPlanBackend>("SelectPlanBackendLib", 1, 0, "SelectPlanBackend",&SelectPlanBackend::getInstance);
//    qmlRegisterSingletonType<FlightStatestics>("FlightStatesticsLib", 1, 0, "FlightStatestics",&FlightStatestics::getInstance);
//    qmlRegisterSingletonType<SettingsHandler>("SettingsHandlerLib", 1, 0, "SettingsHandler",&SettingsHandler::getInstance);
//    qmlRegisterSingletonType<LocalStrings>("LocalStringsLib", 1, 0, "LocalStrings",&LocalStrings::getInstance);
//    qmlRegisterSingletonType<CommLinkSettings>("CommLinkSettingsLib", 1, 0, "CommLinkSettings",&CommLinkSettings::getInstance);
//    qmlRegisterSingletonType<LoginValidation>("LoginValidationLib", 1, 0, "LoginValidation",&LoginValidation::getInstance);
//    qmlRegisterSingletonType<HandleMavlinkResponse>("HandleMavlinkResponseLib", 1, 0, "HandleMavlinkResponse",&HandleMavlinkResponse::getInstance);
//    qmlRegisterSingletonType<StyleGlobalConsts>("StyleGlobalConstsLib", 1, 0, "StyleGlobalConsts",&StyleGlobalConsts::getInstance);

}
void MainWindowGlobalContext::uiUpdateLoop()
{
    app->processEvents();
}
int MainWindowGlobalContext::appInit(QApplication *appPtr)
{
    app = appPtr;
    return 1;
}
int MainWindowGlobalContext::appExec()
{
    return app->exec();
}

int MainWindowGlobalContext::loadEngine(QUrl url)
{
    qDebug()<< "----- load qml";
    //  app->quit();
    qDebug() << engine->rootObjects().at(0)->objectName() <<endl;
    rootObj = engine->rootObjects().at(0);
    qDebug() << " Class Name =" << rootObj->metaObject()->className();
    QQuickWindow *w = qobject_cast<QQuickWindow*>(rootObj);
    w->close();
    engine->load(url);
    //    app->exec();
    return 0;
}


int MainWindowGlobalContext::engineStart(QQmlApplicationEngine *m_engine)
{
//    m_engine->rootContext()->setContextProperty("Lists",&model);
//    m_engine->rootContext()->setContextProperty("pathController", &controller);
//    m_engine->load(QUrl(QStringLiteral("qrc:/LogInStackview.qml")));
//    if (m_engine->rootObjects().isEmpty())
//        return -1;
    engine = m_engine;
    return 1;
}

void MainWindowGlobalContext::addMessageBox(QString Title,QString Text,ALERT_TYPE type)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(Title);
    msgBox.setInformativeText(Text);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.setIcon((QMessageBox::Icon)type);
    /*int ret = */msgBox.exec();
}

MainWindowGlobalContext* MainWindowGlobalContext::getInstance()
{
    if(!m_MainWindowGlobalContext)
    {
        m_MainWindowGlobalContext = new MainWindowGlobalContext();
    }

    return m_MainWindowGlobalContext;
}
QObject* MainWindowGlobalContext::getRootObject()
{
    return rootObject;
}

void MainWindowGlobalContext::setRootObject(QObject* m_rootObject)
{
    rootObject = m_rootObject;
}
