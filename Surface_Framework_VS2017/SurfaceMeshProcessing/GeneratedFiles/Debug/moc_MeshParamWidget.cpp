/****************************************************************************
** Meta object code from reading C++ file 'MeshParamWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MeshParamWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshParamWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeshParamWidget_t {
    QByteArrayData data[8];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshParamWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshParamWidget_t qt_meta_stringdata_MeshParamWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MeshParamWidget"
QT_MOC_LITERAL(1, 16, 15), // "PrintInfoSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 30), // "GaussianCurvatureProcessSignal"
QT_MOC_LITERAL(4, 64, 26), // "MeanCurvatureProcessSignal"
QT_MOC_LITERAL(5, 91, 16), // "SimpleMeshSignal"
QT_MOC_LITERAL(6, 108, 10), // "myStringdd"
QT_MOC_LITERAL(7, 119, 17) // "buttonProcessSLOT"

    },
    "MeshParamWidget\0PrintInfoSignal\0\0"
    "GaussianCurvatureProcessSignal\0"
    "MeanCurvatureProcessSignal\0SimpleMeshSignal\0"
    "myStringdd\0buttonProcessSLOT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshParamWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MeshParamWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeshParamWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PrintInfoSignal(); break;
        case 1: _t->GaussianCurvatureProcessSignal(); break;
        case 2: _t->MeanCurvatureProcessSignal(); break;
        case 3: _t->SimpleMeshSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->myStringdd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->buttonProcessSLOT(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MeshParamWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshParamWidget::PrintInfoSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MeshParamWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshParamWidget::GaussianCurvatureProcessSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MeshParamWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshParamWidget::MeanCurvatureProcessSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MeshParamWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshParamWidget::SimpleMeshSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MeshParamWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshParamWidget::myStringdd)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeshParamWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_MeshParamWidget.data,
    qt_meta_data_MeshParamWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeshParamWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshParamWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeshParamWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MeshParamWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MeshParamWidget::PrintInfoSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MeshParamWidget::GaussianCurvatureProcessSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MeshParamWidget::MeanCurvatureProcessSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MeshParamWidget::SimpleMeshSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MeshParamWidget::myStringdd(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
