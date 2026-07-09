/****************************************************************************
** Meta object code from reading C++ file 'DashboardView.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/presentation/views/DashboardView.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DashboardView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
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
struct qt_meta_tag_ZN13DashboardViewE_t {};
} // unnamed namespace

template <> constexpr inline auto DashboardView::qt_create_metaobjectdata<qt_meta_tag_ZN13DashboardViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DashboardView",
        "registerTrainerRequested",
        "",
        "registerStudentRequested",
        "createPlanRequested",
        "viewScheduleRequested",
        "bookClassRequested",
        "logoutRequested",
        "onRegisterTrainerClicked",
        "onRegisterStudentClicked",
        "onCreatePlanClicked",
        "onViewScheduleClicked",
        "onBookClassClicked",
        "onLogoutClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'registerTrainerRequested'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'registerStudentRequested'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'createPlanRequested'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'viewScheduleRequested'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'bookClassRequested'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'logoutRequested'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onRegisterTrainerClicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onRegisterStudentClicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCreatePlanClicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onViewScheduleClicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onBookClassClicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onLogoutClicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DashboardView, qt_meta_tag_ZN13DashboardViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DashboardView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DashboardViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DashboardViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13DashboardViewE_t>.metaTypes,
    nullptr
} };

void DashboardView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DashboardView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->registerTrainerRequested(); break;
        case 1: _t->registerStudentRequested(); break;
        case 2: _t->createPlanRequested(); break;
        case 3: _t->viewScheduleRequested(); break;
        case 4: _t->bookClassRequested(); break;
        case 5: _t->logoutRequested(); break;
        case 6: _t->onRegisterTrainerClicked(); break;
        case 7: _t->onRegisterStudentClicked(); break;
        case 8: _t->onCreatePlanClicked(); break;
        case 9: _t->onViewScheduleClicked(); break;
        case 10: _t->onBookClassClicked(); break;
        case 11: _t->onLogoutClicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::registerTrainerRequested, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::registerStudentRequested, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::createPlanRequested, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::viewScheduleRequested, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::bookClassRequested, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (DashboardView::*)()>(_a, &DashboardView::logoutRequested, 5))
            return;
    }
}

const QMetaObject *DashboardView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DashboardView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13DashboardViewE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DashboardView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void DashboardView::registerTrainerRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DashboardView::registerStudentRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DashboardView::createPlanRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DashboardView::viewScheduleRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DashboardView::bookClassRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DashboardView::logoutRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
