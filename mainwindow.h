// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H
// class Test;

// #include <QMainWindow>
// #include "adressewindow.h"
// #include "ort.h"
// #include "poiwindow.h"
// #include "displaywindow.h"
// #include "distancewindow.h"
// #include "qcheckbox.h"
// #include "qlabel.h"
// #include "test.h"
// #include <vector>
// #include <QList>
// #include <map>
// QT_BEGIN_NAMESPACE
// namespace Ui { class MainWindow; }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT
//     friend class Test;

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// signals:
//     void dataUpdated(); // Signal pour notifier une mise à jour des données

// private slots:
//     void openAdresseWindow();
//     void openPOIWindow();
//     void openDisplayWindow();
//     void openDistanceWindow();
//     void saveData();
//     void loadData();
//     void moveMeinOrt();
//     void refreshDisplay();
//     void on_exit_clicked();
//     QCheckBox *addNewOrt(double breite, double laenge, const QString& gemeinde, int ort);
//     QPoint convertGPStoPixel(double breite, double laenge);
//     void on_pushButton_Radio_Entfernung_clicked();
//     void on_pushButton_Information_clicked();
//     void on_pushButton_standort_clicked();
//     void on_pushButton_addneworrt_clicked();
//     void on_pushButton_PPOI_clicked();
//     QList<QCheckBox*> ausgewaehlteButtons() const ;
//     void markAsMeinStandort(QCheckBox* button);
//     void afterLoadRecalculateNeighbors();
//         void on_pushButton_OrtHinzufuegen_clicked();
//         void on_pushButton_OrtLoeschen_clicked();
//         void on_pushButton_Routing_clicked();
//         void on_pushButton_dysplayButton_clicked();
//         double distanceBetween(double lat1, double lon1, double lat2, double lon2) const ;
//         std::vector<int> omputeRouteDijkstra(int startId, int zielId);


// private:
//     Ui::MainWindow *ui;

//     AdresseWindow *adresseWindow;
//     POIWindow *poiWindow;
//     DisplayWindow *displayWindow;
//     DistanceWindow *distanceWindow;
//     QList<QCheckBox*> checkButtons;
//     QPixmap currentMap; // Contiendra la carte avec les lignes



//     // Label pour représenter MeinOrt graphiquement
//     QLabel *meinOrtLabel;
//     QPoint meinOrtPosition;   // Position pixel actuelle de MeinOrt
//     QPoint previousPosition;  // Ancienne position pixel de MeinOrt

//   //  QCheckBox* meinStandortButton = nullptr;
//     int findNearestNeighbor(Ort* newOrt);

//     // Méthodes pour gérer MeinOrt
//     void updateMeinOrtPosition(double latitude, double longitude);
//     void highlightMeinOrt();

//     // Ceci stockera le bouton correspondant à MeinOrt (si vous le gardez)
//     QCheckBox* meinStandortButton;

// };

// #endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLabel>
#include <QPixmap>
#include <QPoint>
#include <vector>
#include <QList>
#include <map>

#include "adressewindow.h"
#include "poiwindow.h"
#include "displaywindow.h"
#include "distancewindow.h"
#include "test.h"
#include "ort.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Test;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void dataUpdated();

private slots:
    void openAdresseWindow();
    void openPOIWindow();
    void openDisplayWindow();
    void openDistanceWindow();

    // Sauvegarde / Chargement
    void saveData();
    void loadData();

    // Gérer “MeinOrt”
    void moveMeinOrt();
    void refreshDisplay();
    void on_exit_clicked();

    // Conversion lat/lon -> pixel
    QCheckBox* addNewOrt(double breite, double laenge, const QString& gemeinde, int ortId);
    QPoint     convertGPStoPixel(double breite, double laenge);

    // Boutons
    void on_pushButton_Radio_Entfernung_clicked();
    void on_pushButton_Information_clicked();
    void on_pushButton_standort_clicked();
    void on_pushButton_addneworrt_clicked();
    void on_pushButton_PPOI_clicked();
    void on_pushButton_OrtHinzufuegen_clicked();
    void on_pushButton_OrtLoeschen_clicked();
    void on_pushButton_Routing_clicked();
    void on_pushButton_dysplayButton_clicked();

    // Distance + Dijkstra
    double distanceBetween(double lat1, double lon1,
                           double lat2, double lon2) const;
    std::vector<int> computeRouteDijkstra(int startId, int zielId);

private:
    Ui::MainWindow *ui;

    AdresseWindow   *adresseWindow;
    POIWindow       *poiWindow;
    DisplayWindow   *displayWindow;
    DistanceWindow  *distanceWindow;

    QList<QCheckBox*> checkButtons;
    QPixmap currentMap;  // Fond de carte

    QLabel* meinOrtLabel;
    QPoint meinOrtPosition;
    QPoint previousPosition;

    QCheckBox* meinStandortButton;

    // (optionnel) nearest neighbor
    int findNearestNeighbor(Ort* newOrt);

    // Recalcule l’adjacence après loadData()
    void afterLoadRecalculateNeighbors();

    // Pour MeinOrt
    void updateMeinOrtPosition(double latitude, double longitude);
    void highlightMeinOrt();

    // Outils
    QList<QCheckBox*> ausgewaehlteButtons() const;
    void markAsMeinStandort(QCheckBox* button);

    // --- NOUVEAU : dessiner le graphe ---
    void drawAllEdgesOnMap();
    void drawRouteOnMap(const std::vector<int> &route);
};

#endif // MAINWINDOW_H
