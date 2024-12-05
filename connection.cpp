#include "connection.h"

Connection::Connection(){}


bool Connection::createconnection()
{  db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
db.setDatabaseName("smarthotel");//inserer le nom de la source de données
db.setUserName("ahmed");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())test=true;
    return  test;
}
void Connection::closeConnection(){db.close();}
