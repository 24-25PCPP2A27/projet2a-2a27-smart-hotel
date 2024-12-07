#include "connection.h"

connection::connection(){}

bool connection::createconnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("CPP_Projet");//CPP_PROJECT
    db.setUserName("Mariem"); //Amine
    db.setPassword("devmasters"); //oracle
    if (db.open()) test=true;
    return test;
}

void connection::closeconnection(){db.close();}
