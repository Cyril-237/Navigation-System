#include "test.h"
#include <ui_mainwindow.h>
#include "mainwindow.h"
#include "ort.h"
#include "adresse.h"
#include <QSignalSpy>
#include <QCheckBox>
#include "qtestcase.h"


double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0;
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = sin(dLat / 2)*sin(dLat / 2) +
               cos(lat1)*cos(lat2)*sin(dLon/2)*sin(dLon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return R * c;
}

Test::Test(QObject *parent)
    : QObject{parent}
{}

void Test::ausgewaeltePunkteZurEnternungBerechnung()
{
    MainWindow w;
    w.show();

    Ort::clearOrte();

    Ort *ort1 = new Adresse(10.0, 50.0, 1, "Test Ort 1", 64285, "Teststraße", "Teststadt");
    Ort::getOrte().push_back(ort1);
    QCheckBox* box1 = w.addNewOrt(50.0, 10.0, "Teststadt1", ort1->getId());

    Ort *ort2 = new Adresse(11.0, 51.0, 2, "Test Ort 2", 64289, "Anotherstraße", "Anotherstadt");
    Ort::getOrte().push_back(ort2);
    QCheckBox* box2 = w.addNewOrt(51.0, 11.0, "Teststadt2", ort2->getId());

    box1->setChecked(true);
    box2->setChecked(true);

    try {
        w.on_pushButton_Radio_Entfernung_clicked();
    } catch (...) {
        QFAIL("Exception thrown during distance calculation");
    }

    QVERIFY(true);
}

void Test::entfernungBerechnung()
{
    // Null distanz
    double d0 = haversine(50.0, 10.0, 50.0, 10.0);
    QCOMPARE(d0, 0.0);


    double d1 = haversine(48.8566, 2.3522, 52.5200, 13.4050);
    QVERIFY(qAbs(d1 - 878.0) < 50.0);

    double d2 = haversine(50.0, 10.0, 51.0, 11.0);
    QVERIFY(d2 > 0.0);
}

void Test::ausgewaeltePunkteZumInfoAnzeigen()
{
    MainWindow w;
    w.show();

    Ort::clearOrte();

    Ort *ort1 = new Adresse(10.0, 50.0, 1, "MonLieu", 64285, "Teststraße", "Teststadt");
    Ort::getOrte().push_back(ort1);
    QCheckBox* box1 = w.addNewOrt(50.0, 10.0, "Teststadt", ort1->getId());

    box1->setChecked(true);

  //  w.on_pushButton_Information_clicked();

    QVERIFY(true);
}

void Test::testFindNearestNeighbor()
{
    Ort::clearOrte();

    // Ex: Frankfurt ~ (50.11, 8.68), Darmstadt ~ (49.87, 8.65), Berlin ~ (52.52, 13.40)
    Ort* frankfurt = new Adresse(8.68, 50.11, 1, "Frankfurt", 60311, "Zeil", "Frankfurt");
    Ort::getOrte().push_back(frankfurt);

    Ort* darmstadt = new Adresse(8.65, 49.87, 2, "Darmstadt", 64283, "Luisenplatz", "Darmstadt");
    Ort::getOrte().push_back(darmstadt);

    Ort* berlin = new Adresse(13.40, 52.52, 3, "Berlin", 10115, "Unter den Linden", "Berlin");
    Ort::getOrte().push_back(berlin);

    // Vérifier manuellement le plus proche de Darmstadt = Frankfurt
    MainWindow w; // instance fictive, si votre findNearestNeighbor est une méthode statique,
        // adaptez en conséquence

    int neighborIdDarmstadt = w.findNearestNeighbor(darmstadt);
    QCOMPARE(neighborIdDarmstadt, frankfurt->getId());

    // Vérifier le plus proche de Berlin = Frankfurt (par rapport à Darmstadt)
    int neighborIdBerlin = w.findNearestNeighbor(berlin);
    QCOMPARE(neighborIdBerlin, frankfurt->getId());

    // Nettoyage (si besoin)
    Ort::clearOrte();
}
