#ifndef ACTIONWINDOW_H
#define ACTIONWINDOW_H

#include <QWidget>

class QPushButton;

class ActionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ActionWindow(const QString &title, QWidget *parent = nullptr);
    ~ActionWindow();


    QPushButton *getCloseButton() const;

private:
    QPushButton *closeButton;
};

#endif // ACTIONWINDOW_H
