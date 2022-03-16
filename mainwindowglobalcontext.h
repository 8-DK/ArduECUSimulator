#include <QObject>
#include <QApplication>
#include <QMessageBox>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTimer>
#include <random>
#include <QQuickWindow>
#include <QSplashScreen>
#include <QtWidgets>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickView>
#include <QQmlContext>

#include "myserialport.h"
#include "commlinksettings.h"
#include "serialportsettings.h"
#include "styleglobalsconsts.h"
#include "localstrings.h"
#include "pidencoderdecoder.h"




#ifndef MAINWINDOWGLOBALCONTEXT_H
#define MAINWINDOWGLOBALCONTEXT_H
typedef enum ALERT_TYPE{
    NOT_DEF,
    INFO,
    WARNING,
    CRITICAL,
    QUESTION
}ALERT_TYPE;

class MainWindowGlobalContext : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWindowGlobalContext)
//      MainWindowGlobalContext();
    explicit MainWindowGlobalContext(QObject *parent = nullptr);
    QObject* rootObject;
public:    
    QGuiApplication *app = nullptr;
    QQmlApplicationEngine *engine = nullptr;
    QObject *rootObj = nullptr;

    void mainWindowRegisterQML();
    int appInit(QApplication *appPtr);
    int appExec();
    int loadEngine(QUrl url);
    int engineStart(QQmlApplicationEngine *engine);
    void addMessageBox(QString Title,QString Text,ALERT_TYPE type);
    QObject* getRootObject();
    void setRootObject(QObject*);

    static MainWindowGlobalContext* m_MainWindowGlobalContext;
    static MainWindowGlobalContext*  getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

public slots:
    void uiUpdateLoop();
};

#endif // MAINWINDOWGLOBALCONTEXT_H
