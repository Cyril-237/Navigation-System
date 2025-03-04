#ifndef DISTANCEWINDOW_H
#define DISTANCEWINDOW_H

#include <QWidget>

class QLineEdit;

class DistanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DistanceWindow(QWidget *parent = nullptr);
    ~DistanceWindow();

private slots:
    void calculateDistance();

private:
    QLineEdit *id1Edit;
    QLineEdit *id2Edit;
};

#endif // DISTANCEWINDOW_H
