#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <QListWidget>

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();

public slots:
    void populateList(); // Slot pour mettre à jour la liste

private:
    QListWidget *listWidget;
};

#endif // DISPLAYWINDOW_H
