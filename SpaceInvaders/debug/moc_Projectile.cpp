/****************************************************************************
** Meta object code from reading C++ file 'Projectile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Projectile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Projectile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Projectile_t {
    QByteArrayData data[4];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Projectile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Projectile_t qt_meta_stringdata_Projectile = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Projectile"
QT_MOC_LITERAL(1, 11, 7), // "animate"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7) // "collide"

    },
    "Projectile\0animate\0\0collide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Projectile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Projectile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Projectile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->animate(); break;
        case 1: _t->collide(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Projectile::staticMetaObject = { {
    &Sprites::staticMetaObject,
    qt_meta_stringdata_Projectile.data,
    qt_meta_data_Projectile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Projectile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Projectile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Projectile.stringdata0))
        return static_cast<void*>(this);
    return Sprites::qt_metacast(_clname);
}

int Projectile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Sprites::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE