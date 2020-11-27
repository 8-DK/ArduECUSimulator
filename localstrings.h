#ifndef LOCALSTRINGS_H
#define LOCALSTRINGS_H

#include <QObject>
#include <QQmlProperty>
#include <QQuickItem>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qjsondocument.h>
#include <qfileinfo.h>
#include <qdir.h>

class LocalStrings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(LocalStrings)

private:
    QJsonArray jsonArray;
    QJsonArray jsonThemeArray;
    static LocalStrings *m_instance;public:
public:
    explicit LocalStrings(QObject *parent = nullptr);
    Q_INVOKABLE void readLocalStringFile();
    Q_INVOKABLE QString getLocalTextValue(QString textID);
    Q_INVOKABLE void readGCSThemeFile();
    Q_INVOKABLE QString getThemeData(QString themeID);
    static LocalStrings *getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

signals:

};

#endif // LOCALSTRINGS_H
