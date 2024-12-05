#ifndef SERVICE_H
#define SERVICE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Service
{
public:
    // Constructeurs
    Service();
    Service(int id, const QString &nom, const QString &description, double prix, const QString &categorie);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getDescription() const;
    double getPrix() const;
    QString getCategorie() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setDescription(const QString &description);
    void setPrix(double prix);
    void setCategorie(const QString &categorie);

    // CRUD Methods
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier();
    bool supprimer(int id);
    // les metiers
    QSqlQueryModel* trierParPrix();
    QSqlQueryModel* rechercherParNom(const QString &nom);
    QMap<QString, int> statistique();
private:
    int id;
    QString nom;
    QString description;
    double prix;
    QString categorie;
};

#endif // SERVICE_H
