#ifndef GRILLE_H
#define GRILLE_H

#include <QObject>                               // Héritage de QObjet
#include<time.h>                                 // Initialisation de la fonction radom
#include<stdlib.h>                               // Prendre la fonction random
#include<QStringList>
#include<vector>
#include<iostream>
#include<fstream>
#include"bouton.h"                               // Créations des boutons de la grille


using namespace std;


class Grille : public QObject
{
    Q_OBJECT
public:
    Grille(QObject *parent = 0);                            // Constructeur
    ~Grille();                                              // Déstructeur

    Q_INVOKABLE void redemarrerGrille();                    // Rédemarrer le jeu
    Q_INVOKABLE void revenir();                             // Revenir un round
    Q_INVOKABLE void setDimension(int dimensionModifie);
    Q_INVOKABLE void setContinuerJeu();
    Q_INVOKABLE void effacerHistoriqueQML();

    // Fonctions pour le mouvement des pieces
    Q_INVOKABLE void UP();
    Q_INVOKABLE void Down();
    Q_INVOKABLE void Left();
    Q_INVOKABLE void Right();

    // GUI: Methods de l'interface graphique --> qml
    // Proprietes du bouton
    Q_PROPERTY(int dimensionGUI READ getDimension NOTIFY signalGrille)                      // Prendre la dimension de la grille du jeu
    int getDimension();

    // Position du bouton
    Q_PROPERTY(int x READ positionX NOTIFY signalGrille)                                    // envoye la position x du bouton
    int positionX();
    Q_PROPERTY(int y READ positionY NOTIFY signalGrille)                                    // envoye la position y du bouton
    int positionY();

    // Status du jeu
    Q_PROPERTY(bool gagneur READ gagnerQML() NOTIFY signalGrille);                          // Dit s'il a gagne
    bool gagnerQML();
    Q_PROPERTY(bool perdeur READ perduQML() NOTIFY signalGrille);                           // Dit s'il a perdu
    bool perduQML();

    // Score et Best score
    Q_PROPERTY(int score READ scoreQML NOTIFY signalGrille);
    int scoreQML();
    Q_PROPERTY(int bestscore READ bestscoreQML NOTIFY signalGrille);
    int bestscoreQML();
    Q_PROPERTY(QString bestscorehistorique READ bestscorehistoriqueQML NOTIFY signalGrille);
    QString bestscorehistoriqueQML();
    Q_INVOKABLE void setHistorique(int nouvelleBestScore);

    // Proprietes du bouton
    Q_PROPERTY(QString couleurBouton READ couleurBoutonGUI NOTIFY signalGrille)             // Prendre la couleur du bouton
    QString couleurBoutonGUI();
    Q_PROPERTY(QString couleurBoutonTexte READ couleurBoutonTexteGUI NOTIFY signalGrille)   // Prendre la couleur du text du bouton
    QString couleurBoutonTexteGUI();
    Q_PROPERTY(QString boutonTexte READ boutonTexteGUI NOTIFY signalGrille)                 // Prendre le text du bouton
    QString boutonTexteGUI();
    Q_PROPERTY(QString dimensionQML READ text WRITE setText NOTIFY signalGrille);           // Definir dimension du tableau (4-10)
    QString text();
    void setText(const QString &text);

signals:                
    void signalGrille();                    // Le signal résponsable pour changer le qml
private:
    int score;                              // Score du jeu
    int bestscore;                          // Best score du jeu
    QString bestscorehistorique;
    int rounds;                             // Numero de rounds
    int dimension;

    fstream historique;                     // archive pour sauvegarder le progres

    Bouton **tableBouton;                   // Création de la matrice de boutons
    int ***tableauMemoire;
    QString dimensionQML;

    bool gagneur;
    bool perdeur;

    bool continuerJeu;

    // Informations utilises dans qml
    int QMLCompteurCouleurBoutonTexte;
    int QMLCompteurCouleurBouton;
    int QMLCompteuBoutonTexte;
    int QMLBoutonX;
    int QMLBoutonY;

    // Fonctions
    void constructeurGrille();
    void initialisationGrille();
    void destructeurGrille();
    void randomBouton();
    void reinitialiserFusion();
    void initialiserGestionMomoire();
    void sauvegarder();                     // Faire la gestion de memoire des mouvements
    bool checkGagneur();
    bool checkPerdeur();
    void effacerHistorique();
};

#endif // GRILLE_H
