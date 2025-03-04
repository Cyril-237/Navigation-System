#include "savedatawindow.h"
#include <QBoxlayout>
#include <QPushbutton>
#include <QLabel>
#include <QMessageBox>
#include "ort.h"

SaveDataWindow::SaveDataWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Orte speichern");
    resize(300, 150);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QPushButton *saveButton = new QPushButton("Speichern", this);
    layout->addWidget(saveButton);

    connect(saveButton, &QPushButton::clicked, this, &SaveDataWindow::saveData);
}

SaveDataWindow::~SaveDataWindow()
{
}

void SaveDataWindow::saveData()
{
 //   Ort::karte_speichrn();
    QMessageBox::information(this, "Succès", "Orte erfolgreich geladen !");
    close();
}
