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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSpeichern;
    QAction *actionLaden;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Information;
    QPushButton *pushButton_OrtLoeschen;
    QPushButton *pushButton_Radio_Entfernung;
    QPushButton *pushButton_PPOI;
    QPushButton *pushButton_Routing;
    QPushButton *pushButton_OrtHinzufuegen;
    QPushButton *exit;
    QPushButton *moveMeinOrtButton;
    QPushButton *pushButton_standort;
    QPushButton *displayButton;
    QPushButton *pushButton_addneworrt;
    QLabel *imagelabel;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1099, 935);
        actionSpeichern = new QAction(MainWindow);
        actionSpeichern->setObjectName("actionSpeichern");
        actionLaden = new QAction(MainWindow);
        actionLaden->setObjectName("actionLaden");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, -642, 1058, 1484));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        pushButton_Information = new QPushButton(scrollAreaWidgetContents);
        pushButton_Information->setObjectName("pushButton_Information");

        gridLayout_2->addWidget(pushButton_Information, 5, 1, 1, 1);

        pushButton_OrtLoeschen = new QPushButton(scrollAreaWidgetContents);
        pushButton_OrtLoeschen->setObjectName("pushButton_OrtLoeschen");

        gridLayout_2->addWidget(pushButton_OrtLoeschen, 6, 1, 1, 1);

        pushButton_Radio_Entfernung = new QPushButton(scrollAreaWidgetContents);
        pushButton_Radio_Entfernung->setObjectName("pushButton_Radio_Entfernung");

        gridLayout_2->addWidget(pushButton_Radio_Entfernung, 7, 0, 1, 1);

        pushButton_PPOI = new QPushButton(scrollAreaWidgetContents);
        pushButton_PPOI->setObjectName("pushButton_PPOI");

        gridLayout_2->addWidget(pushButton_PPOI, 8, 0, 1, 1);

        pushButton_Routing = new QPushButton(scrollAreaWidgetContents);
        pushButton_Routing->setObjectName("pushButton_Routing");

        gridLayout_2->addWidget(pushButton_Routing, 2, 1, 1, 1);

        pushButton_OrtHinzufuegen = new QPushButton(scrollAreaWidgetContents);
        pushButton_OrtHinzufuegen->setObjectName("pushButton_OrtHinzufuegen");

        gridLayout_2->addWidget(pushButton_OrtHinzufuegen, 4, 0, 1, 1);

        exit = new QPushButton(scrollAreaWidgetContents);
        exit->setObjectName("exit");

        gridLayout_2->addWidget(exit, 5, 0, 1, 1);

        moveMeinOrtButton = new QPushButton(scrollAreaWidgetContents);
        moveMeinOrtButton->setObjectName("moveMeinOrtButton");

        gridLayout_2->addWidget(moveMeinOrtButton, 6, 0, 1, 1);

        pushButton_standort = new QPushButton(scrollAreaWidgetContents);
        pushButton_standort->setObjectName("pushButton_standort");

        gridLayout_2->addWidget(pushButton_standort, 2, 0, 1, 1);

        displayButton = new QPushButton(scrollAreaWidgetContents);
        displayButton->setObjectName("displayButton");

        gridLayout_2->addWidget(displayButton, 4, 1, 1, 1);

        pushButton_addneworrt = new QPushButton(scrollAreaWidgetContents);
        pushButton_addneworrt->setObjectName("pushButton_addneworrt");

        gridLayout_2->addWidget(pushButton_addneworrt, 7, 1, 1, 1);

        imagelabel = new QLabel(scrollAreaWidgetContents);
        imagelabel->setObjectName("imagelabel");
        imagelabel->setPixmap(QPixmap(QString::fromUtf8(":/image/karte.png")));
        imagelabel->setScaledContents(false);
        imagelabel->setWordWrap(false);
        imagelabel->setOpenExternalLinks(false);

        gridLayout_2->addWidget(imagelabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 11, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1099, 25));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

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
        pushButton_Information->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        pushButton_OrtLoeschen->setText(QCoreApplication::translate("MainWindow", "Ort Loeschen", nullptr));
        pushButton_Radio_Entfernung->setText(QCoreApplication::translate("MainWindow", "Entfernung", nullptr));
        pushButton_PPOI->setText(QCoreApplication::translate("MainWindow", "Neuer POI", nullptr));
        pushButton_Routing->setText(QCoreApplication::translate("MainWindow", "Routing", nullptr));
        pushButton_OrtHinzufuegen->setText(QCoreApplication::translate("MainWindow", "Ort hinzufuegen", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Programm beenden", nullptr));
        moveMeinOrtButton->setText(QCoreApplication::translate("MainWindow", "MeinOrt verschieben", nullptr));
        pushButton_standort->setText(QCoreApplication::translate("MainWindow", "Mein Standort", nullptr));
        displayButton->setText(QCoreApplication::translate("MainWindow", "Alle Orte", nullptr));
        pushButton_addneworrt->setText(QCoreApplication::translate("MainWindow", "Neue Adresse", nullptr));
        imagelabel->setText(QString());
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
