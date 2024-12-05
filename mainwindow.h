// mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "service.h"
#include <QMap>
#include <QDateTime>
#include <QMainWindow>
#include <QSerialPort>  // Inclure QSerialPort
#include <QSerialPortInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_trier_clicked();
    void on_pushButton_rechercher_clicked();
    void on_pushButton_statistique_clicked();
    void on_pushButton_afficher_clicked();
    void on_pushButton_PDF_clicked();
    void on_pushButton_calculerPromotion_clicked();
    void verifierIDReservation();
private:
    Ui::MainWindow *ui;
    QSerialPort *arduino;
};

#endif // MAINWINDOW_H
