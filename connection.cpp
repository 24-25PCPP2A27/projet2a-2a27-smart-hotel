#include "connection.h"

connection::connection(){}

bool connection::createconnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("smarthotel");//inserer le nom de la source de données
    db.setUserName("ahmed");//inserer nom de l'utilisateur
    db.setPassword("esprit18");
    if (db.open()) test=true;
    return test;
}

void connection::closeconnection(){db.close();}
