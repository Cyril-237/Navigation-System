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
#include <QtWidgets/QCheckBox>
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
    QPushButton *distanceButton;
    QPushButton *moveMeinOrtButton;
    QPushButton *exit;
    QLabel *imagelabel;
    QPushButton *pushButton_Radio_Entfernung;
    QPushButton *pushButton_Information;
    QCheckBox *checkBox_hamburg;
    QCheckBox *checkBox_nrnberg;
    QCheckBox *checkBox_rostock;
    QCheckBox *checkBox_berlin;
    QCheckBox *checkBox_dresden;
    QCheckBox *checkBox_stuttgart;
    QCheckBox *checkBox_mnchen;
    QCheckBox *checkBox_h_da;
    QCheckBox *checkBox_brennen;
    QCheckBox *checkBox_dortmund;
    QCheckBox *checkBox_saarbrcken;
    QCheckBox *checkBox_Jena;
    QCheckBox *checkBox_hannover;
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
        displayButton->setGeometry(QRect(720, 560, 191, 29));
        distanceButton = new QPushButton(centralwidget);
        distanceButton->setObjectName("distanceButton");
        distanceButton->setGeometry(QRect(720, 680, 201, 29));
        moveMeinOrtButton = new QPushButton(centralwidget);
        moveMeinOrtButton->setObjectName("moveMeinOrtButton");
        moveMeinOrtButton->setGeometry(QRect(720, 710, 201, 29));
        exit = new QPushButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(720, 740, 201, 29));
        imagelabel = new QLabel(centralwidget);
        imagelabel->setObjectName("imagelabel");
        imagelabel->setGeometry(QRect(30, 0, 681, 771));
        imagelabel->setPixmap(QPixmap(QString::fromUtf8(":/image/karte.png")));
        imagelabel->setScaledContents(true);
        pushButton_Radio_Entfernung = new QPushButton(centralwidget);
        pushButton_Radio_Entfernung->setObjectName("pushButton_Radio_Entfernung");
        pushButton_Radio_Entfernung->setGeometry(QRect(720, 650, 191, 29));
        pushButton_Information = new QPushButton(centralwidget);
        pushButton_Information->setObjectName("pushButton_Information");
        pushButton_Information->setGeometry(QRect(720, 620, 191, 29));
        checkBox_hamburg = new QCheckBox(centralwidget);
        checkBox_hamburg->setObjectName("checkBox_hamburg");
        checkBox_hamburg->setGeometry(QRect(350, 130, 93, 26));
        checkBox_nrnberg = new QCheckBox(centralwidget);
        checkBox_nrnberg->setObjectName("checkBox_nrnberg");
        checkBox_nrnberg->setGeometry(QRect(430, 560, 93, 26));
        checkBox_rostock = new QCheckBox(centralwidget);
        checkBox_rostock->setObjectName("checkBox_rostock");
        checkBox_rostock->setGeometry(QRect(500, 120, 93, 26));
        checkBox_berlin = new QCheckBox(centralwidget);
        checkBox_berlin->setObjectName("checkBox_berlin");
        checkBox_berlin->setGeometry(QRect(580, 250, 93, 26));
        checkBox_dresden = new QCheckBox(centralwidget);
        checkBox_dresden->setObjectName("checkBox_dresden");
        checkBox_dresden->setGeometry(QRect(590, 390, 93, 26));
        checkBox_stuttgart = new QCheckBox(centralwidget);
        checkBox_stuttgart->setObjectName("checkBox_stuttgart");
        checkBox_stuttgart->setGeometry(QRect(270, 630, 93, 26));
        checkBox_mnchen = new QCheckBox(centralwidget);
        checkBox_mnchen->setObjectName("checkBox_mnchen");
        checkBox_mnchen->setGeometry(QRect(430, 690, 93, 26));
        checkBox_h_da = new QCheckBox(centralwidget);
        checkBox_h_da->setObjectName("checkBox_h_da");
        checkBox_h_da->setGeometry(QRect(230, 530, 93, 26));
        checkBox_brennen = new QCheckBox(centralwidget);
        checkBox_brennen->setObjectName("checkBox_brennen");
        checkBox_brennen->setGeometry(QRect(260, 200, 93, 26));
        checkBox_dortmund = new QCheckBox(centralwidget);
        checkBox_dortmund->setObjectName("checkBox_dortmund");
        checkBox_dortmund->setGeometry(QRect(110, 390, 93, 26));
        checkBox_saarbrcken = new QCheckBox(centralwidget);
        checkBox_saarbrcken->setObjectName("checkBox_saarbrcken");
        checkBox_saarbrcken->setGeometry(QRect(120, 580, 111, 26));
        checkBox_Jena = new QCheckBox(centralwidget);
        checkBox_Jena->setObjectName("checkBox_Jena");
        checkBox_Jena->setGeometry(QRect(470, 310, 93, 26));
        checkBox_hannover = new QCheckBox(centralwidget);
        checkBox_hannover->setObjectName("checkBox_hannover");
        checkBox_hannover->setGeometry(QRect(310, 260, 93, 26));
        pushButton_standort = new QPushButton(centralwidget);
        pushButton_standort->setObjectName("pushButton_standort");
        pushButton_standort->setGeometry(QRect(720, 590, 191, 29));
        pushButton_addneworrt = new QPushButton(centralwidget);
        pushButton_addneworrt->setObjectName("pushButton_addneworrt");
        pushButton_addneworrt->setGeometry(QRect(720, 500, 191, 29));
        pushButton_PPOI = new QPushButton(centralwidget);
        pushButton_PPOI->setObjectName("pushButton_PPOI");
        pushButton_PPOI->setGeometry(QRect(720, 530, 191, 29));
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
        distanceButton->setText(QCoreApplication::translate("MainWindow", "Entfernung berechnen", nullptr));
        moveMeinOrtButton->setText(QCoreApplication::translate("MainWindow", "MeinOrt verschieben", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Programm beenden", nullptr));
        imagelabel->setText(QString());
        pushButton_Radio_Entfernung->setText(QCoreApplication::translate("MainWindow", "Entfernung", nullptr));
        pushButton_Information->setText(QCoreApplication::translate("MainWindow", "Information", nullptr));
        checkBox_hamburg->setText(QCoreApplication::translate("MainWindow", "Hamburg", nullptr));
        checkBox_nrnberg->setText(QCoreApplication::translate("MainWindow", "N\303\274rnberg", nullptr));
        checkBox_rostock->setText(QCoreApplication::translate("MainWindow", "Rostock", nullptr));
        checkBox_berlin->setText(QCoreApplication::translate("MainWindow", "Berlin", nullptr));
        checkBox_dresden->setText(QCoreApplication::translate("MainWindow", "Dresden", nullptr));
        checkBox_stuttgart->setText(QCoreApplication::translate("MainWindow", "Stuttgart", nullptr));
        checkBox_mnchen->setText(QCoreApplication::translate("MainWindow", "M\303\274nchen", nullptr));
        checkBox_h_da->setText(QCoreApplication::translate("MainWindow", "h-da", nullptr));
        checkBox_brennen->setText(QCoreApplication::translate("MainWindow", "Brennen", nullptr));
        checkBox_dortmund->setText(QCoreApplication::translate("MainWindow", "Dortmund", nullptr));
        checkBox_saarbrcken->setText(QCoreApplication::translate("MainWindow", "Saarbr\303\274cken", nullptr));
        checkBox_Jena->setText(QCoreApplication::translate("MainWindow", "Jena", nullptr));
        checkBox_hannover->setText(QCoreApplication::translate("MainWindow", "Hannover", nullptr));
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
