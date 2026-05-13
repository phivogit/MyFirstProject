/****************************************************************************
** Meta object code from reading C++ file 'autoclicker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../Github repos/Bucket_Autoclicker/autoclicker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autoclicker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11AutoClickerE_t {};
} // unnamed namespace

template <> constexpr inline auto AutoClicker::qt_create_metaobjectdata<qt_meta_tag_ZN11AutoClickerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "AutoClicker",
        "handleMouseChange",
        "",
        "getClickSpeed",
        "type",
        "StartClick",
        "StopClick",
        "keyboardStartClick",
        "keyboardStopClick",
        "click",
        "speed",
        "keyboardClick",
        "panelChange",
        "enableKeyChangeListen",
        "disableKeyChangeListen",
        "enableMouseHotKeyChangeListen",
        "disableMouseHotKeyChangeListen",
        "enableHotKeyChangeListen",
        "disableHotKeyChangeListen",
        "enableMouse",
        "disableMouse",
        "enableKeyboard",
        "disableKeyboard"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'handleMouseChange'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'getClickSpeed'
        QtMocHelpers::SlotData<int(bool)>(3, 2, QMC::AccessPrivate, QMetaType::Int, {{
            { QMetaType::Bool, 4 },
        }}),
        // Slot 'StartClick'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'StopClick'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'keyboardStartClick'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'keyboardStopClick'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'click'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'keyboardClick'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Slot 'panelChange'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableKeyChangeListen'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableKeyChangeListen'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableMouseHotKeyChangeListen'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableMouseHotKeyChangeListen'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableHotKeyChangeListen'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableHotKeyChangeListen'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableMouse'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableMouse'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'enableKeyboard'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'disableKeyboard'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AutoClicker, qt_meta_tag_ZN11AutoClickerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject AutoClicker::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AutoClickerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AutoClickerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11AutoClickerE_t>.metaTypes,
    nullptr
} };

void AutoClicker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AutoClicker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->handleMouseChange(); break;
        case 1: { int _r = _t->getClickSpeed((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->StartClick(); break;
        case 3: _t->StopClick(); break;
        case 4: _t->keyboardStartClick(); break;
        case 5: _t->keyboardStopClick(); break;
        case 6: _t->click((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->keyboardClick((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->panelChange(); break;
        case 9: _t->enableKeyChangeListen(); break;
        case 10: _t->disableKeyChangeListen(); break;
        case 11: _t->enableMouseHotKeyChangeListen(); break;
        case 12: _t->disableMouseHotKeyChangeListen(); break;
        case 13: _t->enableHotKeyChangeListen(); break;
        case 14: _t->disableHotKeyChangeListen(); break;
        case 15: _t->enableMouse(); break;
        case 16: _t->disableMouse(); break;
        case 17: _t->enableKeyboard(); break;
        case 18: _t->disableKeyboard(); break;
        default: ;
        }
    }
}

const QMetaObject *AutoClicker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutoClicker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11AutoClickerE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AutoClicker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
