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
