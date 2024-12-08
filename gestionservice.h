// GestionService.h

#ifndef GestionService_H
#define GestionService_H

#include <QMainWindow>
#include "ui_GestionService.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "service.h"
#include <QMap>
#include <QDateTime>
#include <QSerialPort>  // Inclure QSerialPort
#include <QSerialPortInfo>
namespace Ui {
class GestionService;
}

class GestionService : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionService(QWidget *parent = nullptr);
    ~GestionService();

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
    void on_pushButton_menu_clicked();
private:
    Ui::GestionService *ui;
    QSerialPort *arduino;
};

#endif // GestionService_H
