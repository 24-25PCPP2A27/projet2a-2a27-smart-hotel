#include "fournisseur.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVariant>
#include <QMap>
#include <QSqlError>
//#include <QTcpSocket>
#include <QTextStream>
#include <QDebug>

Fournisseur::Fournisseur() : id(0), Nom_F(""), Adresse(""), Email(""), Telephone(""), Secteur(""), ID_Reservation(-1) {}

Fournisseur::Fournisseur(int id, QString Nom_F, QString Adresse, QString Email, QString Telephone, QString Secteur, int ID_Reservation)
    : id(id), Nom_F(Nom_F), Adresse(Adresse), Email(Email), Telephone(Telephone), Secteur(Secteur), ID_Reservation(ID_Reservation) {}


bool Fournisseur::ajouter() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database connection is not open!";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_F, NOM, ADRESSE, EMAIL, TELEPHONE, SECTEUR_ACTIVITE, ID_R) "
                  "VALUES (:ID_F, :NOM, :ADRESSE, :EMAIL, :TELEPHONE, :SECTEUR_ACTIVITE, :ID_R)");
    query.bindValue(":ID_F", id);
    query.bindValue(":NOM", Nom_F.trimmed());
    query.bindValue(":ADRESSE", Adresse.trimmed());
    query.bindValue(":EMAIL", Email.trimmed());
    query.bindValue(":TELEPHONE", Telephone.trimmed());
    query.bindValue(":SECTEUR_ACTIVITE", Secteur.trimmed());
    query.bindValue(":ID_R", ID_Reservation == -1 ? QVariant(QVariant::Int) : ID_Reservation);

    if (!query.exec()) {
        qDebug() << "Ajouter query failed!" << query.lastError().text();
        return false;
    }

    return true;
}





QSqlQueryModel* Fournisseur::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_F"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("SECTEUR_ACTIVITE"));
    return model;
}

bool Fournisseur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM FOURNISSEUR WHERE ID_F = :ID_F");
    query.bindValue(":ID_F", id);
    return query.exec();


}

bool Fournisseur::modifier() {
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Database connection is not open!";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEUR SET NOM = :NOM, ADRESSE = :ADRESSE, EMAIL = :EMAIL, TELEPHONE = :TELEPHONE, "
                  "SECTEUR_ACTIVITE = :SECTEUR_ACTIVITE, ID_R = :ID_R WHERE ID_F = :ID_F");
    query.bindValue(":ID_F", id);
    query.bindValue(":NOM", Nom_F.trimmed());
    query.bindValue(":ADRESSE", Adresse.trimmed());
    query.bindValue(":EMAIL", Email.trimmed());
    query.bindValue(":TELEPHONE", Telephone.trimmed());
    query.bindValue(":SECTEUR_ACTIVITE", Secteur.trimmed());
    query.bindValue(":ID_R", ID_Reservation == -1 ? QVariant(QVariant::Int) : ID_Reservation);

    if (!query.exec()) {
        qDebug() << "Modifier query failed!" << query.lastError().text();
        return false;
    }

    return true;
}


QSqlQueryModel* Fournisseur::rechercherParSecteur(const QString &secteur)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Prepare the SQL query to search by secteur
    query.prepare("SELECT * FROM FOURNISSEUR WHERE SECTEUR_ACTIVITE LIKE :secteur");
    query.bindValue(":secteur", "%" + secteur + "%");  // Use wildcards for partial match

    // Execute the query
    if (query.exec()) {
        model->setQuery(query);
        // Set the headers for the table view
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_F"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("TELEPHONE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("SECTEUR_ACTIVITE"));
    }

    return model;
}


QMap<QString, QMap<QString, double>> Fournisseur::getStatistics()
{
    QMap<QString, QMap<QString, double>> sectorStats;
    QSqlQuery query;

    // Récupérer tous les secteurs d'activité distincts
    query.exec("SELECT DISTINCT secteur FROM FOURNISSEUR");
    QStringList sectors;
    while (query.next()) {
        sectors << query.value(0).toString();
    }

    // Calculer les statistiques pour chaque secteur
    for (const QString &sector : sectors) {
        QMap<QString, double> stats;

        // Total des fournisseurs dans ce secteur
        query.prepare("SELECT COUNT(*) FROM FOURNISSEUR WHERE secteur = :sector");
        query.bindValue(":sector", sector);
        query.exec();
        if (query.next()) {
            stats["total"] = query.value(0).toDouble();
        }

        // Exemple de calcul de métrique moyenne (à adapter selon vos besoins)
        query.prepare("SELECT AVG(SOME_METRIC) FROM FOURNISSEUR WHERE secteur = :sector");  // Remplacez SOME_METRIC par une colonne pertinente
        query.bindValue(":sector", sector);
        query.exec();
        if (query.next()) {
            stats["average"] = query.value(0).toDouble();
        }

        // Valeur minimale de la métrique
        query.prepare("SELECT MIN(SOME_METRIC) FROM FOURNISSEUR WHERE secteur = :sector");
        query.bindValue(":sector", sector);
        query.exec();
        if (query.next()) {
            stats["min"] = query.value(0).toDouble();
        }

        // Valeur maximale de la métrique
        query.prepare("SELECT MAX(SOME_METRIC) FROM FOURNISSEUR WHERE secteur = :sector");
        query.bindValue(":sector", sector);
        query.exec();
        if (query.next()) {
            stats["max"] = query.value(0).toDouble();
        }

        sectorStats[sector] = stats;
    }

    return sectorStats;
}






