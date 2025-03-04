/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "dataUpdated",
    "",
    "openAdresseWindow",
    "openPOIWindow",
    "openDisplayWindow",
    "openDistanceWindow",
    "saveData",
    "loadData",
    "moveMeinOrt",
    "refreshDisplay",
    "on_exit_clicked",
    "addNewOrt",
    "QCheckBox*",
    "breite",
    "laenge",
    "gemeinde",
    "ortId",
    "convertGPStoPixel",
    "on_pushButton_Radio_Entfernung_clicked",
    "on_pushButton_Information_clicked",
    "on_pushButton_standort_clicked",
    "on_pushButton_addneworrt_clicked",
    "on_pushButton_PPOI_clicked",
    "on_pushButton_OrtHinzufuegen_clicked",
    "on_pushButton_OrtLoeschen_clicked",
    "on_pushButton_Routing_clicked",
    "on_pushButton_dysplayButton_clicked",
    "distanceBetween",
    "lat1",
    "lon1",
    "lat2",
    "lon2",
    "computeRouteDijkstra",
    "std::vector<int>",
    "startId",
    "zielId"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  152,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  153,    2, 0x08,    2 /* Private */,
       4,    0,  154,    2, 0x08,    3 /* Private */,
       5,    0,  155,    2, 0x08,    4 /* Private */,
       6,    0,  156,    2, 0x08,    5 /* Private */,
       7,    0,  157,    2, 0x08,    6 /* Private */,
       8,    0,  158,    2, 0x08,    7 /* Private */,
       9,    0,  159,    2, 0x08,    8 /* Private */,
      10,    0,  160,    2, 0x08,    9 /* Private */,
      11,    0,  161,    2, 0x08,   10 /* Private */,
      12,    4,  162,    2, 0x08,   11 /* Private */,
      18,    2,  171,    2, 0x08,   16 /* Private */,
      19,    0,  176,    2, 0x08,   19 /* Private */,
      20,    0,  177,    2, 0x08,   20 /* Private */,
      21,    0,  178,    2, 0x08,   21 /* Private */,
      22,    0,  179,    2, 0x08,   22 /* Private */,
      23,    0,  180,    2, 0x08,   23 /* Private */,
      24,    0,  181,    2, 0x08,   24 /* Private */,
      25,    0,  182,    2, 0x08,   25 /* Private */,
      26,    0,  183,    2, 0x08,   26 /* Private */,
      27,    0,  184,    2, 0x08,   27 /* Private */,
      28,    4,  185,    2, 0x108,   28 /* Private | MethodIsConst  */,
      33,    2,  194,    2, 0x08,   33 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 13, QMetaType::Double, QMetaType::Double, QMetaType::QString, QMetaType::Int,   14,   15,   16,   17,
    QMetaType::QPoint, QMetaType::Double, QMetaType::Double,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   29,   30,   31,   32,
    0x80000000 | 34, QMetaType::Int, QMetaType::Int,   35,   36,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'dataUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openAdresseWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openPOIWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDisplayWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openDistanceWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'saveData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveMeinOrt'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNewOrt'
        QtPrivate::TypeAndForceComplete<QCheckBox *, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'convertGPStoPixel'
        QtPrivate::TypeAndForceComplete<QPoint, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_pushButton_Radio_Entfernung_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Information_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_standort_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_addneworrt_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_PPOI_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_OrtHinzufuegen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_OrtLoeschen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Routing_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_dysplayButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'distanceBetween'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'computeRouteDijkstra'
        QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->openAdresseWindow(); break;
        case 2: _t->openPOIWindow(); break;
        case 3: _t->openDisplayWindow(); break;
        case 4: _t->openDistanceWindow(); break;
        case 5: _t->saveData(); break;
        case 6: _t->loadData(); break;
        case 7: _t->moveMeinOrt(); break;
        case 8: _t->refreshDisplay(); break;
        case 9: _t->on_exit_clicked(); break;
        case 10: { QCheckBox* _r = _t->addNewOrt((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QCheckBox**>(_a[0]) = std::move(_r); }  break;
        case 11: { QPoint _r = _t->convertGPStoPixel((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QPoint*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->on_pushButton_Radio_Entfernung_clicked(); break;
        case 13: _t->on_pushButton_Information_clicked(); break;
        case 14: _t->on_pushButton_standort_clicked(); break;
        case 15: _t->on_pushButton_addneworrt_clicked(); break;
        case 16: _t->on_pushButton_PPOI_clicked(); break;
        case 17: _t->on_pushButton_OrtHinzufuegen_clicked(); break;
        case 18: _t->on_pushButton_OrtLoeschen_clicked(); break;
        case 19: _t->on_pushButton_Routing_clicked(); break;
        case 20: _t->on_pushButton_dysplayButton_clicked(); break;
        case 21: { double _r = _t->distanceBetween((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 22: { std::vector<int> _r = _t->computeRouteDijkstra((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< std::vector<int>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::dataUpdated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
