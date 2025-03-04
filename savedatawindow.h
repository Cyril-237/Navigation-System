#ifndef SAVEDATAWINDOW_H
#define SAVEDATAWINDOW_H

#include <QWidget>

class SaveDataWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SaveDataWindow(QWidget *parent = nullptr);
    ~SaveDataWindow();

private slots:
    void saveData();
};

#endif // SAVEDATAWINDOW_H
