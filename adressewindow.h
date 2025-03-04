#ifndef ADRESSEWINDOW_H
#define ADRESSEWINDOW_H

#include <QWidget>

class QLineEdit;

class AdresseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdresseWindow(QWidget *parent = nullptr);
    ~AdresseWindow();

signals:
    void dataUpdated(); // Signal pour notifier les modifications

private slots:
    void saveAdresse();

private:
    QLineEdit *nameEdit;
    QLineEdit *streetEdit;
    QLineEdit *houseNumberEdit;
    QLineEdit *postalCodeEdit;
    QLineEdit *cityEdit;
    QLineEdit *longitudeEdit;
    QLineEdit *latitudeEdit;
};

#endif // ADRESSEWINDOW_H
