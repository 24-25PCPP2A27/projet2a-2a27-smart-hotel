/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *valeur;
    QTableView *aff;
    QPushButton *pushButton_statistiques;
    QGraphicsView *aff_stat;
    QFrame *line;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_ID_3;
    QLineEdit *nom;
    QLineEdit *lineEdit_ID_4;
    QLineEdit *prenom;
    QLineEdit *lineEdit_ID_5;
    QLineEdit *lineEdit_ID_6;
    QLineEdit *salaire;
    QPushButton *ajouter;
    QComboBox *role;
    QPushButton *annuler;
    QPushButton *modifier;
    QLineEdit *id_m;
    QPushButton *recuperer;
    QPushButton *pdf;
    QPushButton *rechercher;
    QComboBox *rech;
    QPushButton *trie;
    QComboBox *tri;
    QPushButton *supprimer;
    QLineEdit *id_supp;
    QGroupBox *groupBox_2;
    QLineEdit *id_em;
    QLineEdit *lineEdit_ID_7;
    QLineEdit *lineEdit_ID_8;
    QPushButton *ajouter_f;
    QComboBox *feedback;
    QGroupBox *groupBox_3;
    QTableView *aff_feed;
    QPushButton *actualiser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1306, 882);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        valeur = new QLineEdit(centralwidget);
        valeur->setObjectName("valeur");
        valeur->setGeometry(QRect(400, 590, 201, 31));
        valeur->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        aff = new QTableView(centralwidget);
        aff->setObjectName("aff");
        aff->setGeometry(QRect(20, 360, 591, 221));
        aff->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton_statistiques = new QPushButton(centralwidget);
        pushButton_statistiques->setObjectName("pushButton_statistiques");
        pushButton_statistiques->setGeometry(QRect(760, 20, 93, 28));
        aff_stat = new QGraphicsView(centralwidget);
        aff_stat->setObjectName("aff_stat");
        aff_stat->setGeometry(QRect(720, 60, 561, 221));
        aff_stat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(650, 20, 16, 591));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(50, 30, 481, 321));
        QFont font;
        font.setBold(true);
        groupBox->setFont(font);
        lineEdit_ID_3 = new QLineEdit(groupBox);
        lineEdit_ID_3->setObjectName("lineEdit_ID_3");
        lineEdit_ID_3->setGeometry(QRect(40, 40, 111, 41));
        lineEdit_ID_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(160, 40, 241, 41));
        nom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_ID_4 = new QLineEdit(groupBox);
        lineEdit_ID_4->setObjectName("lineEdit_ID_4");
        lineEdit_ID_4->setGeometry(QRect(40, 90, 111, 41));
        lineEdit_ID_4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        prenom = new QLineEdit(groupBox);
        prenom->setObjectName("prenom");
        prenom->setGeometry(QRect(160, 90, 241, 41));
        prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
""));
        lineEdit_ID_5 = new QLineEdit(groupBox);
        lineEdit_ID_5->setObjectName("lineEdit_ID_5");
        lineEdit_ID_5->setGeometry(QRect(40, 140, 111, 41));
        lineEdit_ID_5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_ID_6 = new QLineEdit(groupBox);
        lineEdit_ID_6->setObjectName("lineEdit_ID_6");
        lineEdit_ID_6->setGeometry(QRect(40, 200, 111, 41));
        lineEdit_ID_6->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        salaire = new QLineEdit(groupBox);
        salaire->setObjectName("salaire");
        salaire->setGeometry(QRect(160, 200, 241, 41));
        salaire->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ajouter = new QPushButton(groupBox);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(140, 270, 121, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(true);
        ajouter->setFont(font1);
        role = new QComboBox(groupBox);
        role->addItem(QString());
        role->addItem(QString());
        role->addItem(QString());
        role->setObjectName("role");
        role->setGeometry(QRect(160, 140, 241, 41));
        annuler = new QPushButton(groupBox);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(280, 270, 121, 41));
        annuler->setFont(font1);
        modifier = new QPushButton(centralwidget);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(30, 590, 91, 41));
        modifier->setFont(font1);
        id_m = new QLineEdit(centralwidget);
        id_m->setObjectName("id_m");
        id_m->setGeometry(QRect(30, 640, 91, 31));
        id_m->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        recuperer = new QPushButton(centralwidget);
        recuperer->setObjectName("recuperer");
        recuperer->setGeometry(QRect(30, 680, 101, 41));
        recuperer->setFont(font1);
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(540, 290, 101, 61));
        pdf->setFont(font1);
        pdf->setStyleSheet(QString::fromUtf8(""));
        rechercher = new QPushButton(centralwidget);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(400, 630, 121, 41));
        rechercher->setFont(font1);
        rech = new QComboBox(centralwidget);
        rech->addItem(QString());
        rech->addItem(QString());
        rech->setObjectName("rech");
        rech->setGeometry(QRect(530, 640, 76, 26));
        trie = new QPushButton(centralwidget);
        trie->setObjectName("trie");
        trie->setGeometry(QRect(260, 620, 101, 31));
        trie->setFont(font1);
        tri = new QComboBox(centralwidget);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(270, 590, 76, 26));
        supprimer = new QPushButton(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(140, 640, 101, 41));
        supprimer->setFont(font1);
        id_supp = new QLineEdit(centralwidget);
        id_supp->setObjectName("id_supp");
        id_supp->setGeometry(QRect(140, 600, 91, 31));
        id_supp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(720, 320, 521, 201));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(true);
        groupBox_2->setFont(font2);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        id_em = new QLineEdit(groupBox_2);
        id_em->setObjectName("id_em");
        id_em->setGeometry(QRect(170, 40, 241, 41));
        id_em->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_ID_7 = new QLineEdit(groupBox_2);
        lineEdit_ID_7->setObjectName("lineEdit_ID_7");
        lineEdit_ID_7->setGeometry(QRect(50, 40, 111, 41));
        lineEdit_ID_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        lineEdit_ID_8 = new QLineEdit(groupBox_2);
        lineEdit_ID_8->setObjectName("lineEdit_ID_8");
        lineEdit_ID_8->setGeometry(QRect(50, 100, 111, 41));
        lineEdit_ID_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        ajouter_f = new QPushButton(groupBox_2);
        ajouter_f->setObjectName("ajouter_f");
        ajouter_f->setGeometry(QRect(170, 150, 121, 41));
        ajouter_f->setFont(font1);
        feedback = new QComboBox(groupBox_2);
        feedback->addItem(QString());
        feedback->addItem(QString());
        feedback->setObjectName("feedback");
        feedback->setGeometry(QRect(170, 100, 61, 41));
        QFont font3;
        font3.setPointSize(18);
        feedback->setFont(font3);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(720, 540, 581, 241));
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        aff_feed = new QTableView(groupBox_3);
        aff_feed->setObjectName("aff_feed");
        aff_feed->setGeometry(QRect(30, 30, 531, 192));
        aff_feed->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        actualiser = new QPushButton(centralwidget);
        actualiser->setObjectName("actualiser");
        actualiser->setGeometry(QRect(560, 30, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1306, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        valeur->setText(QString());
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "STATIQTIQUE", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        lineEdit_ID_3->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        nom->setText(QString());
        lineEdit_ID_4->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        prenom->setText(QString());
        lineEdit_ID_5->setText(QCoreApplication::translate("MainWindow", "role", nullptr));
        lineEdit_ID_6->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        salaire->setText(QString());
        ajouter->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        role->setItemText(0, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        role->setItemText(1, QCoreApplication::translate("MainWindow", "secritaire", nullptr));
        role->setItemText(2, QCoreApplication::translate("MainWindow", "Stagiaire", nullptr));

        annuler->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        id_m->setText(QString());
        recuperer->setText(QCoreApplication::translate("MainWindow", "RECUPERER", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        rechercher->setText(QCoreApplication::translate("MainWindow", "RECHERCHER", nullptr));
        rech->setItemText(0, QCoreApplication::translate("MainWindow", "id_e", nullptr));
        rech->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));

        trie->setText(QCoreApplication::translate("MainWindow", "TRIER", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "role", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "salaire", nullptr));

        supprimer->setText(QCoreApplication::translate("MainWindow", "SUPPRIMER", nullptr));
        id_supp->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Ajouter FeeDBacK", nullptr));
        id_em->setText(QString());
        lineEdit_ID_7->setText(QCoreApplication::translate("MainWindow", "id_employe", nullptr));
        lineEdit_ID_8->setText(QCoreApplication::translate("MainWindow", "FeeDBacK", nullptr));
        ajouter_f->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        feedback->setItemText(0, QCoreApplication::translate("MainWindow", "+", nullptr));
        feedback->setItemText(1, QCoreApplication::translate("MainWindow", "-", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Employe status", nullptr));
        actualiser->setText(QCoreApplication::translate("MainWindow", "actualiser", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
