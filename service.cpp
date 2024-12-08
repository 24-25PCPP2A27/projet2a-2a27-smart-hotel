#include "service.h"
#include <QDebug>
#include <QSqlError>

// Constructeurs
Service::Service() : id(0), prix(0.0) {}

Service::Service(int id, const QString &nom, const QString &description, double prix, const QString &categorie)
    : id(id), nom(nom), description(description), prix(prix), categorie(categorie) {}

// Getters
int Service::getId() const { return id; }
QString Service::getNom() const { return nom; }
QString Service::getDescription() const { return description; }
double Service::getPrix() const { return prix; }
QString Service::getCategorie() const { return categorie; }

// Setters
void Service::setId(int id) { this->id = id; }
void Service::setNom(const QString &nom) { this->nom = nom; }
void Service::setDescription(const QString &description) { this->description = description; }
void Service::setPrix(double prix) { this->prix = prix; }
void Service::setCategorie(const QString &categorie) { this->categorie = categorie; }

// Méthode pour ajouter un service
bool Service::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO SERVICE (ID_S, NOM_S, DESCRIPTION, PRIX, CATEGORIE) "
                  "VALUES (:id, :nom, :description, :prix, :categorie)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":prix", prix);
    query.bindValue(":categorie", categorie);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout du service: " << query.lastError();
        return false;
    }
}

// Méthode pour afficher les services dans un QSqlQueryModel
QSqlQueryModel* Service::afficher()
{
    QSqlQuery query;
    query.prepare("SELECT ID_S, NOM_S, DESCRIPTION, PRIX, CATEGORIE FROM SERVICE");
    if (!query.exec()) {
        qDebug() << "Erreur d'exécution de la requête d'affichage: " << query.lastError();
        return nullptr;
    }

    while (query.next()) {
        qDebug() << "ID_S:" << query.value(0).toInt()
                 << ", NOM_S:" << query.value(1).toString()
                 << ", DESCRIPTION:" << query.value(2).toString()
                 << ", PRIX:" << query.value(3).toDouble()
                 << ", CATEGORIE:" << query.value(4).toString();
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    return model;
}

// Méthode pour modifier un service existant
bool Service::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE SERVICE SET NOM_S = :nom, DESCRIPTION = :description, PRIX = :prix, CATEGORIE = :categorie "
                  "WHERE ID_S = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":prix", prix);
    query.bindValue(":categorie", categorie);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la modification du service: " << query.lastError();
        return false;
    }
}

// Méthode pour supprimer un service par son id
bool Service::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SERVICE WHERE ID_S = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression du service: " << query.lastError();
        return false;
    }
}

// Dans service.cpp

QSqlQueryModel* Service::trierParPrix()
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Préparer la requête SQL pour trier les services par prix
    query.prepare("SELECT ID_S, NOM_S, DESCRIPTION, PRIX, CATEGORIE FROM AHMED.SERVICE ORDER BY PRIX ASC");

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur d'exécution de la requête de tri : " << query.lastError();
        return nullptr; // Retourner nullptr si la requête échoue
    }

    // Remplir le modèle avec les résultats de la requête
    model->setQuery(query);

    return model;
}

QSqlQueryModel* Service::rechercherParNom(const QString &nom)
{
    QSqlQuery query;
    QSqlQueryModel *model = new QSqlQueryModel();

    // Préparer la requête pour rechercher le service par nom
    query.prepare("SELECT ID_S, NOM_S, DESCRIPTION, PRIX, CATEGORIE "
                  "FROM SERVICE WHERE NOM_S LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête de recherche:" << query.lastError();
        delete model;  // Libérer le modèle en cas d'erreur
        return nullptr;
    }

    // Remplir le modèle avec les résultats
    model->setQuery(query);

    // Vérifier le nombre de lignes trouvées
    qDebug() << "Nombre de résultats trouvés:" << model->rowCount();

    return model;
}
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QMap<QString, int> Service::statistique()
{
    QMap<QString, int> stats;  // Contient le nombre de services par catégorie
    QSqlQuery query;

    // Préparer la requête pour compter les services par catégorie
    query.prepare("SELECT CATEGORIE, COUNT(*) AS count FROM SERVICE GROUP BY CATEGORIE");

    // Exécuter la requête
    if (query.exec()) {
        while (query.next()) {
            QString categorie = query.value(0).toString();
            int count = query.value(1).toInt();
            stats.insert(categorie, count);
        }
    } else {
        qDebug() << "Erreur lors de la récupération des statistiques :" << query.lastError();
    }

    return stats;
}


