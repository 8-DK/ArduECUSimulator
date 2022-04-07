#include "mainwindowglobalcontext.h"

int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "0");
    QCoreApplication::addLibraryPath(".");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    MainWindowGlobalContext *m_MainWindowGlobalContext;

    m_MainWindowGlobalContext = MainWindowGlobalContext::getInstance();

    qmlRegisterSingletonType<LocalStrings>("LocalStringsLib", 1, 0, "LocalStrings",&LocalStrings::getInstance);
    qmlRegisterSingletonType<GStyle>("GStyleLib", 1, 0, "GStyle",&GStyle::getInstance);
    qmlRegisterType<SerialPortSettings>("SerialPortSettingsLib", 1, 0, "SerialPortSettings");
    qmlRegisterSingletonType<CommLinkSettings>("CommLinkSettingsLib", 1, 0, "CommLinkSettings",&CommLinkSettings::getInstance);
    qmlRegisterSingletonType<ComHelper>("ComHelperLib", 1, 0, "ComHelper",&ComHelper::getInstance);
    qmlRegisterSingletonType<PIDEncoderDecoder>("PIDEncoderDecoderLib", 1, 0, "PIDEncoderDecoder",&PIDEncoderDecoder::getInstance);    

    QApplication app(argc,argv);
    m_MainWindowGlobalContext->appInit(&app);

    app.processEvents(QEventLoop::AllEvents);

    QPixmap pixmap(":assets/splash_Screen.png");
    if(pixmap.isNull())
    {
        QMessageBox::warning(0, "Error", "Failed to load Splash Screen image!");
    }

    QDesktopWidget* desktopWidget = qApp->desktop();
    QRect screenGeometry = desktopWidget->screenGeometry();
    int screenWidth = screenGeometry.width()/2;
    int screenHeight = screenGeometry.height()/2;
    QPixmap pixmapForSplash = pixmap.scaled(screenWidth, screenHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QSplashScreen splash(pixmapForSplash, Qt::WindowStaysOnTopHint);
    splash.setEnabled(false); //Prevent user from closing the splash
//    splash.show();
    //    splash.showMessage(QObject::tr("Initiating your program now..."),Qt::AlignLeft | Qt::AlignTop, Qt::black);  //This line represents the alignment of text, color and position
    //QTimer::singleShot(5000 , &splash, &QWidget::close); // keep displayed for 5 seconds
    // app.processEvents();
    QQmlApplicationEngine engine;
    m_MainWindowGlobalContext->engineStart(&engine);

    engine.rootContext()->setContextProperty("PIDList", &PIDEncoderDecoder::getInstance()->pIDInfoModel);

#ifdef QT_DEBUG
    engine.rootContext()->setContextProperty("debug_mode", true);
#else
    engine.rootContext()->setContextProperty("debug_mode", false);
#endif

    engine.load(QUrl(QStringLiteral("qrc:/MainWindowStackView.qml")));

    //    QPixmap pixmap("/asset/splash_Screen.png");
    //    QSplashScreen splash(pixmap);
    //    splash.show();
    //    app.thread()->sleep(1); // wait for just 1 second and then show main window
    //    app.processEvents();

    if (engine.rootObjects().isEmpty())
        return -1;
    splash.close();

    QObject *rootObj = nullptr;

    rootObj = engine.rootObjects().at(0);
    //qDebug() << " Class Name =" << rootObj->metaObject()->className();
    QQuickWindow *w = qobject_cast<QQuickWindow*>(rootObj);
   // w->setFlags(Qt::Window | Qt::FramelessWindowHint );
    w->showMaximized();

    return app.exec();
}
