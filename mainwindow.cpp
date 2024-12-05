                                                                                                                              #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "service.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMap>
#include <QString>
#include <QBrush>
#include <QPdfWriter>
#include <QPainter>
#include <QTableView>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDateTime>
#include <QMap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , arduino(new QSerialPort(this))
{

    ui->setupUi(this);

    // Créez un objet Service
    Service Rtmp;

    // Affichez les services dans le tableau
    ui->tableView->setModel(Rtmp.afficher());

        // Configuration du port série
        arduino->setPortName("COM5");
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

        if (!arduino->open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, "Erreur", "Impossible de se connecter à l'Arduino.");
        }

        // Connecte le bouton "Vérifier" à l'action
        connect(ui->verifierIDReservation, &QPushButton::clicked, this, &MainWindow::verifierIDReservation);
    }


MainWindow::~MainWindow()
{
    if (arduino->isOpen()) {
        arduino->close();
    }
    delete ui;
}

void MainWindow::on_pushButton_afficher_clicked()
{
    Service service;  // Créer une instance de la classe Service
    QSqlQueryModel *model = service.afficher();  // Récupérer le modèle des services

    if (model) {
        // Si le modèle a été récupéré, l'afficher dans le tableau
        ui->tableView->setModel(model);  // Assurez-vous d'avoir un QTableView dans l'interface
    } else {
        // Afficher un message d'erreur si l'affichage a échoué
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les services.");
    }
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id_service = ui->lineEdit->text().toInt();  // ID du service
    QString nom_service = ui->lineEdit_3->text();   // Nom du service
    QString categorie = ui->lineEdit_4->text();     // Catégorie du service
    QString description = ui->lineEdit_5->text();   // Description du service
    double prix = ui->lineEdit_6->text().toDouble(); // Prix du service en double (conversion correcte)

    // Création de l'objet Service avec les données récupérées
    Service S(id_service, nom_service, description, prix, categorie);

    // Appel de la méthode ajouter() pour insérer le service dans la base de données
    bool test = S.ajouter();

    if (test) {
        // Affichage du message de succès
        QMessageBox::information(nullptr, QObject::tr("Ajout réussi"),
                    QObject::tr("Le service a été ajouté avec succès.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        // Rafraîchissement de l'affichage des services dans la table
        ui->tableView->setModel(S.afficher());
    } else {
        // Affichage du message d'erreur
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                 QObject::tr("L'ajout du service a échoué.\n"
                             "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}
void MainWindow::on_pushButton_supprimer_clicked()
{
    int id_service = ui->lineEdit->text().toInt();

    // Vérifiez que l'ID est valide
    if (id_service <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    Service Rtmp;
    bool test = Rtmp.supprimer(id_service);

    if (test) {
        QMessageBox::information(this, "Suppression réussie", "Le service a été supprimé avec succès.");
        ui->tableView->setModel(Rtmp.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "La suppression a échoué.");
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    // Récupérer les informations du service à modifier
    int id_service = ui->lineEdit->text().toInt();
    QString nom_service = ui->lineEdit_3->text();
    QString categorie = ui->lineEdit_4->text();
    QString description = ui->lineEdit_5->text();
    double prix = ui->lineEdit_6->text().toDouble();  // Utilisation de double pour le prix

    // Créer une instance de Service avec les nouvelles données
    Service S(id_service, nom_service, description, prix, categorie);

    // Appeler la méthode modifier sans passer l'ID car il est déjà dans l'objet S
    bool test = S.modifier();

    // Vérifier si la modification a réussi
    if (test) {
        // Afficher un message de succès
        QMessageBox::information(nullptr, QObject::tr("Modification réussie"),
                    QObject::tr("Le service a été modifié avec succès.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        // Rafraîchir l'affichage des services dans la table
        ui->tableView->setModel(S.afficher());
    } else {
        // Afficher un message d'erreur si la modification a échoué
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                    QObject::tr("La modification du service a échoué.\n"
                                "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

Service Rtmp; // Déclarer un objet Service de manière globale dans la classe MainWindow

void MainWindow::on_pushButton_trier_clicked()
{
    // Appeler la méthode de tri dans la classe Service
    QSqlQueryModel *model = Rtmp.trierParPrix();

    if (model) {
        // Si le modèle a été correctement généré, l'afficher dans la table
        ui->tableView->setModel(model);
    } else {
        // Afficher un message d'erreur si le tri a échoué
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                             QObject::tr("Le tri des services par prix a échoué.\n"
                                         "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_rechercher_clicked()
{
    QString nom_service = ui->lineEdit_recherche->text().trimmed();  // Récupérer et nettoyer le texte
    qDebug() << "Nom recherché :" << nom_service;

    Service S;
    QSqlQueryModel *model = S.rechercherParNom(nom_service);

    if (model && model->rowCount() > 0) {
        // Afficher les résultats dans le tableau
        ui->tableView->setModel(model);
        qDebug() << "Table mise à jour avec" << model->rowCount() << "lignes.";
    } else {
        qDebug() << "Aucun résultat trouvé.";
        QMessageBox::information(this, QObject::tr("Aucun résultat"),
                                 QObject::tr("Aucun service correspondant trouvé."), QMessageBox::Ok);
    }
}


void MainWindow::on_pushButton_statistique_clicked()
{
    // Étape 1 : Récupérer les statistiques des services
    Service service;
    QMap<QString, int> stats = service.statistique();

    // Créer une scène graphique pour afficher le graphique en barres
    QGraphicsScene *scene = new QGraphicsScene();

    // Créer un QGraphicsView pour afficher la scène
    QGraphicsView *view = new QGraphicsView(scene);
    view->setWindowTitle("Statistiques des Services (Graphique en Barres)");

    // Paramètres du graphique en barres
    int barWidth = 50;       // Largeur de chaque barre
    int maxBarHeight = 200;  // Hauteur maximale des barres
    int spacing = 20;        // Espacement entre les barres

    // Calculer la valeur maximale pour ajuster la hauteur des barres
    int maxCount = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        if (it.value() > maxCount) {
            maxCount = it.value();
        }
    }

    // Dessiner les barres pour chaque catégorie
    int xOffset = 0;  // Position X de la première barre
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        QString category = it.key(); // Nom de la catégorie
        int count = it.value();      // Nombre de services dans cette catégorie

        // Calculer la hauteur de la barre en fonction du nombre de services
        int barHeight = static_cast<int>((static_cast<double>(count) / maxCount) * maxBarHeight);

        // Créer un rectangle (barre) et l'ajouter à la scène
        QGraphicsRectItem *bar = scene->addRect(xOffset, maxBarHeight - barHeight, barWidth, barHeight);
        bar->setBrush(QBrush(Qt::blue));  // Définir la couleur de la barre

        // Ajouter une étiquette avec le nom de la catégorie sous chaque barre
        QGraphicsTextItem *label = scene->addText(category);
        label->setPos(xOffset, maxBarHeight + 10);

        // Ajouter une étiquette avec le nombre de services au-dessus de chaque barre
        QGraphicsTextItem *countLabel = scene->addText(QString::number(count));
        countLabel->setPos(xOffset + barWidth / 4, maxBarHeight - barHeight - 20);

        // Déplacer la position X pour la prochaine barre
        xOffset += barWidth + spacing;
    }

    // Ajuster la taille de la scène pour inclure toutes les barres
    scene->setSceneRect(0, 0, xOffset, maxBarHeight + 50);

    // Afficher la vue graphique dans une nouvelle fenêtre
    view->setScene(scene);
    view->setMinimumSize(xOffset + 50, maxBarHeight + 100);  // Ajuster la taille de la fenêtre
    view->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    view->show();
}
void MainWindow::on_pushButton_PDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Enregistrer sous"), "", tr("PDF Files (*.pdf)"));

    if (fileName.isEmpty()) {
        return;
    }

    QPdfWriter writer(fileName);
    writer.setPageSize(QPagedPaintDevice::A4);

    QPainter painter;
    if (!painter.begin(&writer)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Impossible de créer le PDF."));
        return;
    }

    QFont titleFont("Arial", 12, QFont::Bold);
    QFont dataFont("Arial", 10);

    // Titre
    painter.setFont(titleFont);
    painter.drawText(100, 50, tr("Liste des Services"));

    // Colonnes
    painter.setFont(dataFont);
    int x[] = { 100, 200, 400, 600, 800 }; // Position horizontale des colonnes
    int y = 100; // Position verticale initiale

    painter.drawText(x[0], y, tr("ID"));
    painter.drawText(x[1], y, tr("Nom du Service"));
    painter.drawText(x[2], y, tr("Catégorie"));
    painter.drawText(x[3], y, tr("Description"));
    painter.drawText(x[4], y, tr("Prix"));

    // Dessiner une ligne sous les en-têtes
    y += 20;
    painter.drawLine(100, y, 900, y);

    // Contenu
    QSqlQueryModel *model = Rtmp.afficher();
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, tr("Avertissement"), tr("Aucun service à exporter."));
        return;
    }

    y += 20;
    for (int row = 0; row < model->rowCount(); ++row) {
        painter.drawText(x[0], y, model->data(model->index(row, 0)).toString());
        painter.drawText(x[1], y, model->data(model->index(row, 1)).toString());
        painter.drawText(x[2], y, model->data(model->index(row, 2)).toString());
        painter.drawText(x[3], y, model->data(model->index(row, 3)).toString());
        painter.drawText(x[4], y, model->data(model->index(row, 4)).toString());
        y += 20;
    }

    // Finalisation
    painter.end();
    QMessageBox::information(this, tr("Succès"), tr("Le fichier PDF a été créé avec succès."));
}

void MainWindow::on_pushButton_calculerPromotion_clicked()
{
    // Récupérer le pourcentage de promotion
    double pourcentage = ui->lineEdit_pourcentage->text().toDouble();
    if (pourcentage <= 0 || pourcentage > 100) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un pourcentage valide (1-100).");
        return;
    }

    // Récupérer la liste des services
    Service S;
    QSqlQueryModel *model = S.afficher();

    // Créer un tableau temporaire pour afficher les prix après promotion
    QTableWidget *table = new QTableWidget();
    table->setRowCount(model->rowCount());
    table->setColumnCount(3); // Colonnes : Nom, Prix Initial, Prix Après Promotion

    table->setHorizontalHeaderLabels(QStringList() << "Nom" << "Prix Initial" << "Prix Avec Promotion");

    for (int i = 0; i < model->rowCount(); ++i) {
        QString nom = model->record(i).value("NOM_S").toString();
        double prixInitial = model->record(i).value("PRIX").toDouble();
        double prixApresPromo = prixInitial * (1 - pourcentage / 100.0);

        // Remplir le tableau
        table->setItem(i, 0, new QTableWidgetItem(nom));
        table->setItem(i, 1, new QTableWidgetItem(QString::number(prixInitial, 'f', 2)));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(prixApresPromo, 'f', 2)));
    }

    // Ajuster les colonnes
    table->resizeColumnsToContents();

    // Afficher dans une nouvelle fenêtre
    QMainWindow *promoWindow = new QMainWindow(this);
    promoWindow->setCentralWidget(table);
    promoWindow->resize(600, 400);
    promoWindow->setWindowTitle("Prix avec Promotion");
    promoWindow->show();
}

void MainWindow::verifierIDReservation()
{
    QString idReservations = ui->lineEditID->text(); // Récupérer l'ID depuis le lineEdit

    if (idReservations.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID de réservation.");
        return;
    }

    // Vérifier l'existence de l'ID dans la base de données
    QSqlQuery query;
    query.prepare("SELECT * FROM reservations WHERE ID_R = :id");
    query.bindValue(":id", idReservations);

    if (query.exec() && query.next()) {
        // ID trouvé
        ui->labelResult->setText("WELCOME");
        if (arduino->isWritable()) {
            arduino->write("WELCOME");
        } else {
            qDebug() << "Erreur d'écriture sur le port série.";
        }
    } else {
        // ID non trouvé
        ui->labelResult->setText("NO ACCESS");
        if (arduino->isWritable()) {
            arduino->write("NO ACCESS");
        } else {
            qDebug() << "Erreur d'écriture sur le port série.";
        }
    }
}
