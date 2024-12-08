#include "qrcodedialog.h"
#include "ui_qrcodedialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include "Qrcode.hpp" // Include the QR code generation library

qrcodedialog::qrcodedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qrcodedialog)
{
    ui->setupUi(this);
}

qrcodedialog::~qrcodedialog()
{
    delete ui;
}

void qrcodedialog::on_pushButton_generate_clicked()
{
    QString id = ui->lineEdit_ID->text();  // Get supplier ID from input

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a supplier ID.");
        return;
    }

    // Fetch supplier data from the database
    QString supplierData = getSupplierDataByID(id);
    if (supplierData.isEmpty()) {
        QMessageBox::warning(this, "Error", "No supplier found with the given ID.");
        return;
    }

    // Generate QR code for the supplier data
    QPixmap qrPixmap = generateQRCode(supplierData);

    // Display the QR code in the label
    ui->label_QRCode->setPixmap(qrPixmap);
}

// Fetch supplier data by ID from the database
QString qrcodedialog::getSupplierDataByID(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT NOM, ADRESSE, EMAIL, TELEPHONE, SECTEUR_ACTIVITE, ID_R "
                  "FROM FOURNISSEUR WHERE ID_F = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to query the database: " + query.lastError().text());
        return QString();
    }

    if (query.next()) {
        // Format the supplier data into a string
        QString supplierData = QString("ID: %1\nName: %2\nAddress: %3\nEmail: %4\nPhone: %5\nSector: %6\nReservation ID: %7")
                               .arg(id)                                      // Supplier ID
                               .arg(query.value("NOM").toString())           // Supplier Name
                               .arg(query.value("ADRESSE").toString())       // Address
                               .arg(query.value("EMAIL").toString())         // Email
                               .arg(query.value("TELEPHONE").toString())     // Phone
                               .arg(query.value("SECTEUR_ACTIVITE").toString()) // Sector
                               .arg(query.value("ID_RESERVATION").toString()); // Reservation ID

        return supplierData;
    }

    return QString();  // Return an empty string if no data is found
}

// Generate a QR code for the provided data
QPixmap qrcodedialog::generateQRCode(const QString &data)
{
    using namespace qrcodegen;

    QrCode qr = QrCode::encodeText(data.toUtf8().constData(), QrCode::Ecc::LOW);
    const int size = qr.getSize();

    QImage image(size, size, QImage::Format_RGB32);
    image.fill(Qt::white);  // Fill background with white

    // Draw the QR code
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            QColor color = qr.getModule(x, y) ? Qt::black : Qt::white;
            image.setPixelColor(x, y, color);
        }
    }

    // Scale up the QR code for better visibility
    return QPixmap::fromImage(image.scaled(200, 200, Qt::KeepAspectRatio));
}
