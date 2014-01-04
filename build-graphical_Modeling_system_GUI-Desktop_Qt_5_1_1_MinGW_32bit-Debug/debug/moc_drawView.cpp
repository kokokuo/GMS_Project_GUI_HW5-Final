/****************************************************************************
** Meta object code from reading C++ file 'drawView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphical_Modeling_system_GUI/drawView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawView_t {
    QByteArrayData data[5];
    char stringdata[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DrawView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DrawView_t qt_meta_stringdata_DrawView = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 17),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 25),
QT_MOC_LITERAL(4, 54, 6)
    },
    "DrawView\0GetDrawLinePoints\0\0"
    "WantedComponentBeSelected\0editId\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x05,
       3,    1,   29,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint, QMetaType::QPoint,    2,    2,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void DrawView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawView *_t = static_cast<DrawView *>(_o);
        switch (_id) {
        case 0: _t->GetDrawLinePoints((*reinterpret_cast< QPoint(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        case 1: _t->WantedComponentBeSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DrawView::*_t)(QPoint , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawView::GetDrawLinePoints)) {
                *result = 0;
            }
        }
        {
            typedef void (DrawView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawView::WantedComponentBeSelected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DrawView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawView.data,
      qt_meta_data_DrawView,  qt_static_metacall, 0, 0}
};


const QMetaObject *DrawView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawView.stringdata))
        return static_cast<void*>(const_cast< DrawView*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DrawView::GetDrawLinePoints(QPoint _t1, QPoint _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawView::WantedComponentBeSelected(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
