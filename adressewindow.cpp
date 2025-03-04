#include "adressewindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include "adresse.h"
#include "ort.h"

AdresseWindow::AdresseWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Adresse anlegen");
    resize(500, 400);

    QGridLayout *gridLayout = new QGridLayout(this);

    QLabel *nameLabel = new QLabel("Name :", this);
    nameEdit = new QLineEdit(this);

    QLabel *streetLabel = new QLabel("Strasse :", this);
    streetEdit = new QLineEdit(this);

    QLabel *houseNumberLabel = new QLabel("Hausnummer :", this);
    houseNumberEdit = new QLineEdit(this);

    QLabel *postalCodeLabel = new QLabel("Postleitzahl :", this);
    postalCodeEdit = new QLineEdit(this);

    QLabel *cityLabel = new QLabel("Gemeinde :", this);
    cityEdit = new QLineEdit(this);

    QLabel *longitudeLabel = new QLabel("Laenge :", this);
    longitudeEdit = new QLineEdit(this);

    QLabel *latitudeLabel = new QLabel("Breite :", this);
    latitudeEdit = new QLineEdit(this);

    QPushButton *saveButton = new QPushButton("Speichern", this);
    connect(saveButton, &QPushButton::clicked, this, &AdresseWindow::saveAdresse);

    QPushButton *closeButton = new QPushButton("Schliessen", this);
    connect(closeButton, &QPushButton::clicked, this, &AdresseWindow::close);

    gridLayout->addWidget(nameLabel, 0, 0);
    gridLayout->addWidget(nameEdit, 0, 1);
    gridLayout->addWidget(streetLabel, 1, 0);
    gridLayout->addWidget(streetEdit, 1, 1);
    gridLayout->addWidget(houseNumberLabel, 2, 0);
    gridLayout->addWidget(houseNumberEdit, 2, 1);
    gridLayout->addWidget(postalCodeLabel, 3, 0);
    gridLayout->addWidget(postalCodeEdit, 3, 1);
    gridLayout->addWidget(cityLabel, 4, 0);
    gridLayout->addWidget(cityEdit, 4, 1);
    gridLayout->addWidget(longitudeLabel, 5, 0);
    gridLayout->addWidget(longitudeEdit, 5, 1);
    gridLayout->addWidget(latitudeLabel, 6, 0);
    gridLayout->addWidget(latitudeEdit, 6, 1);
    gridLayout->addWidget(saveButton, 7, 0, 1, 2);
    gridLayout->addWidget(closeButton, 8, 0, 1, 2);
}

AdresseWindow::~AdresseWindow() {}

void AdresseWindow::saveAdresse()
{
    QString name = nameEdit->text();
    QString street = streetEdit->text();
    bool ok1, ok2, ok3, ok4;
    int houseNumber = houseNumberEdit->text().toInt(&ok1);
    int postalCode = postalCodeEdit->text().toInt(&ok2);
    double longitude = longitudeEdit->text().toDouble(&ok3);
    double latitude = latitudeEdit->text().toDouble(&ok4);

    if (name.isEmpty() || street.isEmpty() || !ok1 || !ok2 || !ok3 || !ok4) {
        QMessageBox::warning(this, "Erreur", "Alle Felder muessen ausgefuellt werden.");
        return;
    }

    Ort *adresse = new Adresse(longitude, latitude, houseNumber, name.toStdString(), postalCode, street.toStdString(), cityEdit->text().toStdString());
    Ort::getOrte().push_back(adresse);

    emit dataUpdated(); // Notifier la mise à jour
    QMessageBox::information(this, "Succès", "Adresse erfolgreich angelegt !");
    close(); // Fermer la fenêtre
}
