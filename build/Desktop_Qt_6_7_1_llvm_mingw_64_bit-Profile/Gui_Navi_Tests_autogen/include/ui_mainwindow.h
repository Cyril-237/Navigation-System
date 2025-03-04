/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSpeichern;
    QAction *actionLaden;
    QWidget *centralwidget;
    QPushButton *displayButton;
    QPushButton *moveMeinOrtButton;
    QPushButton *exit;
    QLabel *imagelabel;
    QPushButton *pushButton_Radio_Entfernung;
    QPushButton *pushButton_Information;
    QPushButton *pushButton_standort;
    QPushButton *pushButton_addneworrt;
    QPushButton *pushButton_PPOI;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(918, 850);
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName("actionSpeichern");
        actionLaden = new QAction(MainWindow);
        actionLaden->setObjectName("actionLaden");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        displayButton = new QPushButton(centralwidget);
        displayButton->setObjectName("displayButton");
        displayButton->setGeometry(QRect(720, 540, 191, 29));
        moveMeinOrtButton = new QPushButton(centralwidget);
        moveMeinOrtButton->setObjectName("moveMeinOrtButton");
        moveMeinOrtButton->setGeometry(QRect(720, 660, 201, 29));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(720, 690, 201, 29));
        imagelabel = new QLabel(centralwidget);
        imagelabel->setObjectName("imagelabel");
        imagelabel->setGeometry(QRect(0, 0, 751, 761));
        imagelabel->setPixmap(QPixmap(QString::fromUtf8(":/image/karte.png")));
        imagelabel->setScaledContents(true);
        imagelabel->setWordWrap(false);
        imagelabel->setOpenExternalLinks(false);
        pushButton_Radio_Entfernung = new QPushButton(centralwidget);
        pushButton_Radio_Entfernung->setObjectName("pushButton_Radio_Entfernung");
        pushButton_Radio_Entfernung->setGeometry(QRect(720, 630, 191, 29));
        pushButton_Information = new QPushButton(centralwidget);
        pushButton_Information->setObjectName("pushButton_Information");
        pushButton_Information->setGeometry(QRect(720, 600, 191, 29));
        pushButton_standort = new QPushButton(centralwidget);
        pushButton_standort->setObjectName("pushButton_standort");
        pushButton_standort->setGeometry(QRect(720, 570, 191, 29));
        pushButton_addneworrt = new QPushButton(centralwidget);
        pushButton_addneworrt->setObjectName("pushButton_addneworrt");
        pushButton_addneworrt->setGeometry(QRect(720, 480, 191, 29));
        pushButton_PPOI = new QPushButton(centralwidget);
        pushButton_PPOI->setObjectName("pushButton_PPOI");
        pushButton_PPOI->setGeometry(QRect(720, 510, 191, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 918, 25));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuDatei->menuAction());
        menuDatei->addAction(actionSpeichern);
        menuDatei->addAction(actionLaden);
        menuDatei->addSeparator();
        menuDatei->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
        actionLaden->setText(QCoreApplication::translate("MainWindow", "Laden", nullptr));
        displayButton->setText(QCoreApplication::translate("MainWindow", "Alle Orte", nullptr));
        moveMeinOrtButton->setText(QCoreApplication::translate("MainWindow", "MeinOrt verschieben", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Programm beenden", nullptr));
        imagelabel->setText(QString());
        pushButton_Radio_Entfernung->setText(QCoreApplication::translate("MainWindow", "Entfernung", nullptr));
        pushButton_Information->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        pushButton_standort->setText(QCoreApplication::translate("MainWindow", "Mein Standort", nullptr));
        pushButton_addneworrt->setText(QCoreApplication::translate("MainWindow", "Neue Adresse", nullptr));
        pushButton_PPOI->setText(QCoreApplication::translate("MainWindow", "Neuer POI", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
