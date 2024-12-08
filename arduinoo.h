#ifndef ARDUINOO_H
#define ARDUINOO_H

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QByteArray>

class Arduino
{
public:
    Arduino();
    ~Arduino();

    // Connection management
    int connectToArduino();
    int disconnectFromArduino();

    // Data transfer
    int sendDataToArduino(const QString &data);
    QByteArray receiveDataFromArduino();

    // LCD functionality
    int showMessageOnLCD(const QString &message);

    // Getters
    QString getPortName() const;
    QSerialPort* getSerial() const;

private:
    QSerialPort *serial;               // Serial port object
    QString arduinoPortName;           // Port name for Arduino
    bool arduinoIsAvailable;           // Availability status
    QByteArray dataBuffer;             // Buffer for received data

    // Arduino hardware identifiers
    static const quint16 vendorID = 9025;  // Vendor ID for Arduino Uno
    static const quint16 productID = 67;   // Product ID for Arduino Uno

    // Helper method to configure the serial port
    void configureSerialPort();
};

#endif // ARDUINOO_H
