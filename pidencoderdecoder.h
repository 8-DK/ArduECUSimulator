#ifndef PIDENCODERDECODER_H
#define PIDENCODERDECODER_H
#include <QObject>
#include <QQmlProperty>
#include <QQuickItem>
#include <qjsonarray.h>
#include <qjsonobject.h>
#include <qjsonvalue.h>
#include <qjsondocument.h>
#include <qfileinfo.h>
#include <qdir.h>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>

typedef struct PIDInfo{
    int Service;
    int PID_Dec;
    int DataCount;
    QString PIDName;
    QString Description;
    int Min;
    int Max;
    bool isEnabled;
    bool sendRandome;
    bool AllowToChange;
    int WidgetType;
}PIDInfo;

class PIDEncoderDecoder : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(PIDEncoderDecoder)

private:
    QJsonArray jsonArray;
    QList<PIDInfo> pidInfoList;
    static PIDEncoderDecoder *m_instance;public:
public:

    explicit PIDEncoderDecoder(QObject *parent = nullptr);
    static PIDEncoderDecoder *getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

    void parsePIDJsonLookUpFile();
public slots:
    Q_INVOKABLE void getPIDList();
signals:

};

#endif // PIDENCODERDECODER_H
