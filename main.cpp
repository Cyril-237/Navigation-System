#include "mainwindow.h"
#include "test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Test myTest;
    QTest::qExec(&myTest);
    return a.exec();
}
