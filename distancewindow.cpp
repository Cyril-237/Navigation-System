#include "distancewindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "ort.h"
// #include <cmath>
// #include <cmath> // Pour utiliser sin, cos, acos, etc.

// double haversine(double lat1, double lon1, double lat2, double lon2) {
//     const double R = 6371.0; // Rayon de la Terre en kilomètres
//     double dLat = (lat2 - lat1) * M_PI / 180.0; // Conversion en radians
//     double dLon = (lon2 - lon1) * M_PI / 180.0;

//     // Conversion des latitudes en radians
//     lat1 = lat1 * M_PI / 180.0;
//     lat2 = lat2 * M_PI / 180.0;

//     // Formule de Haversine
//     double a = sin(dLat / 2) * sin(dLat / 2) +
//                cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
//     double c = 2 * atan2(sqrt(a), sqrt(1 - a));

//     return R * c; // Distance en kilomètres
// }


DistanceWindow::DistanceWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Entfernung berechnen");
    resize(400, 200);

    QGridLayout *gridLayout = new QGridLayout(this);

    QLabel *id1Label = new QLabel("ID des ersten Objekts :", this);
    id1Edit = new QLineEdit(this);

    QLabel *id2Label = new QLabel("ID des zweiten Objekts :", this);
    id2Edit = new QLineEdit(this);

    QPushButton *calculateButton = new QPushButton("Berechnung", this);
    connect(calculateButton, &QPushButton::clicked, this, &DistanceWindow::calculateDistance);

    QPushButton *closeButton = new QPushButton("Schliessen", this);
    connect(closeButton, &QPushButton::clicked, this, &DistanceWindow::close);

    gridLayout->addWidget(id1Label, 0, 0);
    gridLayout->addWidget(id1Edit, 0, 1);
    gridLayout->addWidget(id2Label, 1, 0);
    gridLayout->addWidget(id2Edit, 1, 1);
    gridLayout->addWidget(calculateButton, 2, 0, 1, 2);
    gridLayout->addWidget(closeButton, 3, 0, 1, 2);
}

DistanceWindow::~DistanceWindow() {}

void DistanceWindow::calculateDistance()
{
    bool ok1, ok2;
    int id1 = id1Edit->text().toInt(&ok1);
    int id2 = id2Edit->text().toInt(&ok2);

    if (!ok1 || !ok2) {
        QMessageBox::warning(this, "Error", "Geben Sie zwei gueltige Id ein.");
        return;
    }

    const auto &orte = Ort::getOrte();
    Ort *ort1 = nullptr;
    Ort *ort2 = nullptr;

    for (const auto &ort : orte) {
        if (ort->getId() == id1) ort1 = ort;
        if (ort->getId() == id2) ort2 = ort;
    }

    if (!ort1 || !ort2) {
        QMessageBox::warning(this, "Error", "Entweder eine Id oder die zwei ID existieren nicht.");
        return;
    }

    // double lat1 = ort1->getBreite();
    // double lon1 = ort1->getLange();
    // double lat2 = ort2->getBreite();
    // double lon2 = ort2->getLange();

  //  double distance = haversine(lat1, lon1, lat2, lon2);

    // QMessageBox::information(this, "Ergebnis",
    //                          QString("Die Entfernung betraegt %1 km.").arg(distance));


 //   double distance = sqrt(pow(ort1->getLange() - ort2->getLange(), 2) +
 //                          pow(ort1->getBreite() - ort2->getBreite(), 2));

  //  QMessageBox::information(this, "Ergebnis", QString("Die Entfernung betraegt %1 Km.").arg(distance));
    close();
}
