#ifndef POIWINDOW_H
#define POIWINDOW_H

#include <QWidget>

class QLineEdit;

class POIWindow : public QWidget
{
    Q_OBJECT

public:
    explicit POIWindow(QWidget *parent = nullptr);
    ~POIWindow();

signals:
    void dataUpdated(); // Signal pour notifier les mises à jour

private slots:
    void savePOI();

private:
    QLineEdit *categoryEdit;
    QLineEdit *remarkEdit;
    QLineEdit *longitudeEdit;
    QLineEdit *latitudeEdit;
};

#endif // POIWINDOW_H
