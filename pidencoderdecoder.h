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
#include <QAbstractListModel>

typedef struct PIDInfo_St{
    int Service;
    int PID_Dec;
    int DataCount;
    QString PIDName;
    QString Description;
    QString Unit;
    int Min;
    int Max;
    bool isEnabled;
    bool sendRandome;
    bool AllowToChange;
    int WidgetType;
}PIDInfo_St;


class PIDInfo
{
public:
    PIDInfo_St pidInfoSt;
    PIDInfo(int m_Service,int m_PID_Dec,int m_DataCount,
            QString m_PIDName,QString m_Description,QString m_Unit,
            int m_Min,int m_Max,bool m_isEnabled,
            bool m_sendRandome,bool m_AllowToChange,
            int m_WidgetType){
        pidInfoSt.Service = m_Service;
        pidInfoSt.PID_Dec = m_PID_Dec;
        pidInfoSt.DataCount = m_DataCount;
        pidInfoSt.PIDName = m_PIDName;
        pidInfoSt.Description = m_Description;
        pidInfoSt.Unit = m_Unit,
        pidInfoSt.Min = m_Min;
        pidInfoSt.Max = m_Max;
        pidInfoSt.isEnabled = m_isEnabled;
        pidInfoSt.sendRandome = m_sendRandome;
        pidInfoSt.AllowToChange = m_AllowToChange;
        pidInfoSt.WidgetType = m_WidgetType;
    }
};

class PIDInfoModel : public QAbstractListModel
{
    Q_OBJECT
    QList<PIDInfo> pidinfoList;
public:
    enum PIDInfoRoles {
        ServiceRole = Qt::UserRole + 1,
        PID_DecRole,
        DataCountRole,
        PIDNameRole,
        DescriptionRole,
        UnitRole,
        MinRole,
        MaxRole,
        isEnabledRole,
        sendRandomeRole,
        AllowToChangeRole,
        WidgetTypeRole,
    };

    explicit PIDInfoModel(QObject *parent = nullptr) : QAbstractListModel(parent){}

    QHash<int, QByteArray> roleNames() const {
        QHash<int, QByteArray> roles;
        roles[ServiceRole] = "service"; roles[PID_DecRole] = "pidDec";
        roles[DataCountRole] = "dataCount"; roles[PIDNameRole] = "pidName" ;roles[DescriptionRole] = "description"; roles[UnitRole] = "unit";roles[MinRole] = "min"; roles[MinRole] = "max";
        roles[isEnabledRole] = "isEnabled"; roles[sendRandomeRole] = "sendRandome";roles[AllowToChangeRole] = "allowToChange";roles[WidgetTypeRole] ="widgetType";
        return roles;
    }
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (!hasIndex(index.row(), index.column(), index.parent()))
            return {};
        const PIDInfo &item = pidinfoList.at(index.row());
        if (role == ServiceRole) return item.pidInfoSt.Service;
        if (role == PID_DecRole) return item.pidInfoSt.PID_Dec;
        if (role == DataCountRole) return item.pidInfoSt.DataCount;
        if (role == PIDNameRole) return item.pidInfoSt.PIDName;
        if (role == DescriptionRole) return item.pidInfoSt.Description;
        if (role == UnitRole) return item.pidInfoSt.Unit;
        if (role == MinRole)return item.pidInfoSt.Min;
        if (role == MaxRole) return item.pidInfoSt.Max;
        if (role == isEnabledRole) return item.pidInfoSt.isEnabled;
        if (role == sendRandomeRole) return item.pidInfoSt.sendRandome;
        if (role == AllowToChangeRole) return item.pidInfoSt.AllowToChange;
        if (role == WidgetTypeRole) return item.pidInfoSt.WidgetType;
        return {};
    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {if (parent.isValid())return 0;return pidinfoList.size();}
    bool setData(const QModelIndex &index, const QVariant &value, int role)  override
    {
        if (!hasIndex(index.row(), index.column(), index.parent()) || !value.isValid())
            return false;

        PIDInfo &item = pidinfoList[index.row()];
        if (role == ServiceRole)  item.pidInfoSt.Service = value.toInt();
        if (role == PID_DecRole)  item.pidInfoSt.PID_Dec = value.toInt();
        if (role == DataCountRole)  item.pidInfoSt.DataCount= value.toInt();
        if (role == PIDNameRole)  item.pidInfoSt.PIDName= value.toString();
        if (role == DescriptionRole)  item.pidInfoSt.Description= value.toString();
        if (role == UnitRole)  item.pidInfoSt.Unit= value.toString();
        if (role == MinRole) item.pidInfoSt.Min = value.toInt();
        if (role == MaxRole)  item.pidInfoSt.Max = value.toInt();
        if (role == isEnabledRole)  item.pidInfoSt.isEnabled = value.toBool();
        if (role == sendRandomeRole)  item.pidInfoSt.sendRandome = value.toBool();
        if (role == AllowToChangeRole)  item.pidInfoSt.AllowToChange = value.toBool();
        if (role == WidgetTypeRole) item.pidInfoSt.WidgetType= value.toInt();
        else{ return false;}

        emit dataChanged(index, index, { role } );
        return true ;
    }
    bool addAsset(int m_Service = 1,int m_PID_Dec = -1,int m_DataCount = 4,
                  QString m_PIDName = "NA" ,QString m_Description = "",
                  QString m_Unit = "NA",
                  int m_Min = 0,int m_Max = 65535,bool m_isEnabled = true,
                 bool m_sendRandome = false,bool m_AllowToChange = true,
                  int m_WidgetType = 0)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        PIDInfo it(m_Service, m_PID_Dec, m_DataCount,m_PIDName,m_Description,m_Unit,m_Min, m_Max,m_isEnabled,m_sendRandome,m_AllowToChange,m_WidgetType);
        pidinfoList << it;
        endInsertRows();
        return true;
    }
signals:
    void fenceModelDataChanged();
};

class PIDEncoderDecoder : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(PIDEncoderDecoder)

private:
    QJsonArray jsonArray;    
    static PIDEncoderDecoder *m_instance;public:
public:
    PIDInfoModel pIDInfoModel;
    explicit PIDEncoderDecoder(QObject *parent = nullptr);
    static PIDEncoderDecoder *getInstance();
    static QObject* getInstance(QQmlEngine *engine, QJSEngine *scriptEngine){Q_UNUSED(engine);Q_UNUSED(scriptEngine);return getInstance();}

    void parsePIDJsonLookUpFile();
public slots:
    Q_INVOKABLE QJsonArray getPIDList();
signals:

};

#endif // PIDENCODERDECODER_H
