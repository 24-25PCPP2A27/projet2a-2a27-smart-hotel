#include "connection.h"

Connection::Connection() {}

bool Connection::createConnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("CPP_Projet");
    db.setUserName("Mariem");
    db.setPassword("devmasters");

    if (db.open()) {
        test = true;
    }
    return test;
}

void Connection::closeConnection() {
    db.close();
}
