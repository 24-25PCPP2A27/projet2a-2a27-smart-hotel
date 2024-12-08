#include "arduinoo.h"

// Constructor
Arduino::Arduino()
    : serial(new QSerialPort),
      arduinoPortName(""),
      arduinoIsAvailable(false),
      dataBuffer("")
{
}

// Destructor
Arduino::~Arduino()
{
    if (serial->isOpen())
        serial->close();
    delete serial;
}

// Connect to Arduino
int Arduino::connectToArduino()
{
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == vendorID &&
                serialPortInfo.productIdentifier() == productID) {
                arduinoIsAvailable = true;
                arduinoPortName = serialPortInfo.portName();
                break;
            }
        }
    }

    if (arduinoIsAvailable) {
        serial->setPortName(arduinoPortName);
        if (serial->open(QSerialPort::ReadWrite)) {
            configureSerialPort();
            qDebug() << "Connected to Arduino on port:" << arduinoPortName;
            return 0; // Success
        } else {
            qDebug() << "Failed to open serial port:" << serial->errorString();
            return 1; // Port open failure
        }
    }

    qDebug() << "Arduino not found. Check connection or device IDs.";
    return -1; // Arduino not available
}

// Disconnect from Arduino
int Arduino::disconnectFromArduino()
{
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Disconnected from Arduino.";
        return 0; // Success
    }
    qDebug() << "No open connection to Arduino.";
    return 1; // Failure
}

// Send data to Arduino
int Arduino::sendDataToArduino(const QString &data)
{
    if (serial->isWritable()) {
        serial->write(data.toUtf8());
        return 0; // Success
    } else {
        qDebug() << "Failed to write to Arduino!";
        return 1; // Write failure
    }
}

// Receive data from Arduino
QByteArray Arduino::receiveDataFromArduino()
{
    if (serial->isReadable()) {
        dataBuffer = serial->readAll();
    }
    return dataBuffer;
}

// Display message on Arduino LCD
int Arduino::showMessageOnLCD(const QString &message)
{
    QByteArray data = message.toUtf8();
    return sendDataToArduino(data);
}

// Get Arduino port name
QString Arduino::getPortName() const
{
    return arduinoPortName;
}

// Get serial object
QSerialPort* Arduino::getSerial() const
{
    return serial;
}

// Configure the serial port
void Arduino::configureSerialPort()
{
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
}
