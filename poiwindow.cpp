#include "poiwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "point_of_interest.h"
#include "ort.h"

POIWindow::POIWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Point of Interest anlegen");
    resize(400, 300);

    QGridLayout *gridLayout = new QGridLayout(this);

    QLabel *categoryLabel = new QLabel("Kategorie :", this);
    categoryEdit = new QLineEdit(this);

    QLabel *remarkLabel = new QLabel("Bemerkung :", this);
    remarkEdit = new QLineEdit(this);

    QLabel *longitudeLabel = new QLabel("Laenge :", this);
    longitudeEdit = new QLineEdit(this);

    QLabel *latitudeLabel = new QLabel("Breite :", this);
    latitudeEdit = new QLineEdit(this);

    QPushButton *saveButton = new QPushButton("Speichern", this);
    connect(saveButton, &QPushButton::clicked, this, &POIWindow::savePOI);

    QPushButton *closeButton = new QPushButton("Schliessen", this);
    connect(closeButton, &QPushButton::clicked, this, &POIWindow::close);

    gridLayout->addWidget(categoryLabel, 0, 0);
    gridLayout->addWidget(categoryEdit, 0, 1);
    gridLayout->addWidget(remarkLabel, 1, 0);
    gridLayout->addWidget(remarkEdit, 1, 1);
    gridLayout->addWidget(longitudeLabel, 2, 0);
    gridLayout->addWidget(longitudeEdit, 2, 1);
    gridLayout->addWidget(latitudeLabel, 3, 0);
    gridLayout->addWidget(latitudeEdit, 3, 1);
    gridLayout->addWidget(saveButton, 4, 0, 1, 2);
    gridLayout->addWidget(closeButton, 5, 0, 1, 2);
}

POIWindow::~POIWindow() {}

void POIWindow::savePOI()
{
    QString category = categoryEdit->text();
    QString remark = remarkEdit->text();
    bool okLon, okLat;
    double longitude = longitudeEdit->text().toDouble(&okLon);
    double latitude = latitudeEdit->text().toDouble(&okLat);

    if (category.isEmpty() || remark.isEmpty() || !okLon || !okLat) {
        QMessageBox::warning(this, "Error", "Alle Felder muessen ausgefuellte werden.");
        return;
    }

    Ort *poi = new Point_of_interest(longitude, latitude, category.toStdString(), remark.toStdString());
    Ort::getOrte().push_back(poi);

    emit dataUpdated(); // Notifier la mise à jour
    QMessageBox::information(this, "Succès", "Point of Interest erfolgreich angelegt !");
    close();
}
