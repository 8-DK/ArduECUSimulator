/****************************************************************************
** Meta object code from reading C++ file 'arcstyle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtKnobs-master/QtKnobs/styles/arcstyle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arcstyle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArcStyle_t {
    QByteArrayData data[27];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArcStyle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArcStyle_t qt_meta_stringdata_ArcStyle = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ArcStyle"
QT_MOC_LITERAL(1, 9, 12), // "valueChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "arg"
QT_MOC_LITERAL(4, 27, 15), // "minValueChanged"
QT_MOC_LITERAL(5, 43, 15), // "maxValueChanged"
QT_MOC_LITERAL(6, 59, 14), // "percentChanged"
QT_MOC_LITERAL(7, 74, 15), // "readOnlyChanged"
QT_MOC_LITERAL(8, 90, 11), // "modeChanged"
QT_MOC_LITERAL(9, 102, 4), // "Mode"
QT_MOC_LITERAL(10, 107, 12), // "colorChanged"
QT_MOC_LITERAL(11, 120, 8), // "setValue"
QT_MOC_LITERAL(12, 129, 11), // "setMinValue"
QT_MOC_LITERAL(13, 141, 11), // "setMaxValue"
QT_MOC_LITERAL(14, 153, 10), // "setPercent"
QT_MOC_LITERAL(15, 164, 17), // "endValueFromPoint"
QT_MOC_LITERAL(16, 182, 1), // "x"
QT_MOC_LITERAL(17, 184, 1), // "y"
QT_MOC_LITERAL(18, 186, 5), // "value"
QT_MOC_LITERAL(19, 192, 8), // "minValue"
QT_MOC_LITERAL(20, 201, 8), // "maxValue"
QT_MOC_LITERAL(21, 210, 7), // "percent"
QT_MOC_LITERAL(22, 218, 5), // "color"
QT_MOC_LITERAL(23, 224, 8), // "readOnly"
QT_MOC_LITERAL(24, 233, 4), // "mode"
QT_MOC_LITERAL(25, 238, 6), // "Normal"
QT_MOC_LITERAL(26, 245, 7) // "Percent"

    },
    "ArcStyle\0valueChanged\0\0arg\0minValueChanged\0"
    "maxValueChanged\0percentChanged\0"
    "readOnlyChanged\0modeChanged\0Mode\0"
    "colorChanged\0setValue\0setMinValue\0"
    "setMaxValue\0setPercent\0endValueFromPoint\0"
    "x\0y\0value\0minValue\0maxValue\0percent\0"
    "color\0readOnly\0mode\0Normal\0Percent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArcStyle[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       7,  126, // properties
       1,  154, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       7,    1,   96,    2, 0x06 /* Public */,
       8,    1,   99,    2, 0x06 /* Public */,
      10,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  105,    2, 0x09 /* Protected */,
      12,    1,  108,    2, 0x09 /* Protected */,
      13,    1,  111,    2, 0x09 /* Protected */,
      14,    1,  114,    2, 0x09 /* Protected */,

 // methods: name, argc, parameters, tag, flags
      15,    2,  117,    2, 0x02 /* Public */,
      15,    1,  122,    2, 0x22 /* Public | MethodCloned */,
      15,    0,  125,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 9,    3,
    QMetaType::Void, QMetaType::QColor,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // methods: parameters
    QMetaType::Int, QMetaType::QReal, QMetaType::QReal,   16,   17,
    QMetaType::Int, QMetaType::QReal,   16,
    QMetaType::Int,

 // properties: name, type, flags
      18, QMetaType::Int, 0x00495103,
      19, QMetaType::Int, 0x00495103,
      20, QMetaType::Int, 0x00495103,
      21, QMetaType::Int, 0x00495103,
      22, QMetaType::QColor, 0x00495003,
      23, QMetaType::Bool, 0x00495003,
      24, 0x80000000 | 9, 0x0049500b,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       6,
       4,
       5,

 // enums: name, alias, flags, count, data
       9,    9, 0x0,    2,  159,

 // enum data: key, value
      25, uint(ArcStyle::Normal),
      26, uint(ArcStyle::Percent),

       0        // eod
};

void ArcStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArcStyle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->minValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->maxValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->percentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->readOnlyChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->modeChanged((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 6: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 7: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setMinValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setMaxValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setPercent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: { int _r = _t->endValueFromPoint((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->endValueFromPoint((*reinterpret_cast< qreal(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->endValueFromPoint();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArcStyle::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::minValueChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::maxValueChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::percentChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::readOnlyChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(Mode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::modeChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ArcStyle::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArcStyle::colorChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ArcStyle *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->m_value; break;
        case 1: *reinterpret_cast< int*>(_v) = _t->m_minValue; break;
        case 2: *reinterpret_cast< int*>(_v) = _t->m_maxValue; break;
        case 3: *reinterpret_cast< int*>(_v) = _t->m_percent; break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->m_color; break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->m_readOnly; break;
        case 6: *reinterpret_cast< Mode*>(_v) = _t->m_mode; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ArcStyle *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setMinValue(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setMaxValue(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setPercent(*reinterpret_cast< int*>(_v)); break;
        case 4:
            if (_t->m_color != *reinterpret_cast< QColor*>(_v)) {
                _t->m_color = *reinterpret_cast< QColor*>(_v);
                Q_EMIT _t->colorChanged(_t->m_color);
            }
            break;
        case 5:
            if (_t->m_readOnly != *reinterpret_cast< bool*>(_v)) {
                _t->m_readOnly = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->readOnlyChanged(_t->m_readOnly);
            }
            break;
        case 6:
            if (_t->m_mode != *reinterpret_cast< Mode*>(_v)) {
                _t->m_mode = *reinterpret_cast< Mode*>(_v);
                Q_EMIT _t->modeChanged(_t->m_mode);
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ArcStyle::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_ArcStyle.data,
    qt_meta_data_ArcStyle,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArcStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArcStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArcStyle.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int ArcStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ArcStyle::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArcStyle::minValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ArcStyle::maxValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ArcStyle::percentChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ArcStyle::readOnlyChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ArcStyle::modeChanged(Mode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ArcStyle::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
