#ifndef qrcodedialog_H
#define qrcodedialog_H

#include <QDialog>
#include <QPixmap>
#include "Qrcode.hpp"
#include "ui_qrcodedialog.h"


namespace Ui {
class qrcodedialog;
}

class qrcodedialog : public QDialog
{
    Q_OBJECT

public:
    explicit qrcodedialog(QWidget *parent = nullptr);
    ~qrcodedialog();

private slots:
    void on_pushButton_generate_clicked();  // Slot for QR code generation

private:
    Ui::qrcodedialog *ui;

    QString getSupplierDataByID(const QString &id);  // Fetch supplier data
    QPixmap generateQRCode(const QString &data);    // Generate QR code
};

#endif // qrcodedialog_H
