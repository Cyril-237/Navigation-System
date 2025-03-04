#include "displaywindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "ort.h"

DisplayWindow::DisplayWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Liste des angelegten Orten");
    resize(700, 600);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Objektliste :", this);
    listWidget = new QListWidget(this);

    QPushButton *closeButton = new QPushButton("Schliessen", this);
    connect(closeButton, &QPushButton::clicked, this, &DisplayWindow::close);

    layout->addWidget(titleLabel);
    layout->addWidget(listWidget);
    layout->addWidget(closeButton);

    populateList(); // Charger les données existantes
}

DisplayWindow::~DisplayWindow() {}

void DisplayWindow::populateList()
{
    listWidget->clear();
    const auto &orte = Ort::getOrte();

    if (orte.empty()) {
        listWidget->addItem("Keine Orte wurden angelegt.");
        return;
    }

    for (const auto &ort : orte) {
        listWidget->addItem(QString::fromStdString(ort->toString()));
    }
}
