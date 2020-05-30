/****************************************************************************
** Meta object code from reading C++ file 'MeshViewerWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MeshViewer/MeshViewerWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeshViewerWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MeshViewerWidget_t {
    QByteArrayData data[6];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshViewerWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshViewerWidget_t qt_meta_stringdata_MeshViewerWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MeshViewerWidget"
QT_MOC_LITERAL(1, 17, 16), // "LoadMeshOKSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "PrintMeshInfo"
QT_MOC_LITERAL(4, 49, 24), // "GaussianCurvatureProcess"
QT_MOC_LITERAL(5, 74, 20) // "MeanCurvatureProcess"

    },
    "MeshViewerWidget\0LoadMeshOKSignal\0\0"
    "PrintMeshInfo\0GaussianCurvatureProcess\0"
    "MeanCurvatureProcess"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshViewerWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   39,    2, 0x0a /* Public */,
       4,    0,   40,    2, 0x0a /* Public */,
       5,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MeshViewerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MeshViewerWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->LoadMeshOKSignal((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->PrintMeshInfo(); break;
        case 2: _t->GaussianCurvatureProcess(); break;
        case 3: _t->MeanCurvatureProcess(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MeshViewerWidget::*)(bool , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MeshViewerWidget::LoadMeshOKSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MeshViewerWidget::staticMetaObject = { {
    &QGLViewerWidget::staticMetaObject,
    qt_meta_stringdata_MeshViewerWidget.data,
    qt_meta_data_MeshViewerWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MeshViewerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshViewerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MeshViewerWidget.stringdata0))
        return static_cast<void*>(this);
    return QGLViewerWidget::qt_metacast(_clname);
}

int MeshViewerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLViewerWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MeshViewerWidget::LoadMeshOKSignal(bool _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
