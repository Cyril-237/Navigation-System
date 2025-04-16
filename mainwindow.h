

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

    void saveData();
    void loadData();

    void moveMeinOrt();
    void refreshDisplay();
    void on_exit_clicked();

    QCheckBox* addNewOrt(double breite, double laenge, const QString& gemeinde, int ortId);
    QPoint     convertGPStoPixel(double breite, double laenge);

    void on_pushButton_Radio_Entfernung_clicked();
    void on_pushButton_Information_clicked();
    void on_pushButton_standort_clicked();
    void on_pushButton_addneworrt_clicked();
    void on_pushButton_PPOI_clicked();
    void on_pushButton_OrtHinzufuegen_clicked();
    void on_pushButton_OrtLoeschen_clicked();
    void on_pushButton_Routing_clicked();
    void on_pushButton_dysplayButton_clicked();

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
    QPixmap currentMap;  

    QLabel* meinOrtLabel;
    QPoint meinOrtPosition;
    QPoint previousPosition;

    QCheckBox* meinStandortButton;

    int findNearestNeighbor(Ort* newOrt);

    void afterLoadRecalculateNeighbors();

    void updateMeinOrtPosition(double latitude, double longitude);
    void highlightMeinOrt();

    QList<QCheckBox*> ausgewaehlteButtons() const;
    void markAsMeinStandort(QCheckBox* button);

    void drawAllEdgesOnMap();
    void drawRouteOnMap(const std::vector<int> &route);
};

#endif // MAINWINDOW_H
