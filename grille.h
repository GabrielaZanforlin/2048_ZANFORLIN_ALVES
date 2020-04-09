#ifndef GRILLE_H
#define GRILLE_H

#include <QObject>                                                                          // Héritage de QObjet
#include<time.h>                                                                            // Initialisation de la fonction radom
#include<stdlib.h>                                                                          // Prendre la fonction random
#include<QStringList>
#include<vector>
#include"bouton.h"                                                                          // Créations des boutons de la grille



class Grille : public QObject
{
    Q_OBJECT
public:
    Grille(QObject *parent = 0);                                                            // Constructeur
    ~Grille();                                                                              // Déstructeur

    // Functions
    //void creationBoutons();                                                                 // Creations des boutons

    // Set fonctions
    void setScore(int scoreModifie);

    // Fonctions pour le mouvement des pieces

    // GUI: Methods de l'interface graphique --> qml
    Q_PROPERTY(int x READ positionX NOTIFY signalGrille)                                    // envoye la position x du bouton
    int positionX();
    Q_PROPERTY(int y READ positionY NOTIFY signalGrille)                                    // envoye la position y du bouton
    int positionY();

    Q_PROPERTY(bool gagneur READ gagnerQML() NOTIFY signalGrille);                          // Dit s'il a gagne
    bool gagnerQML();
    Q_PROPERTY(bool perdu READ perduQML() NOTIFY signalGrille);                             // Dit s'il a perdu
    bool perduQML();

    Q_PROPERTY(int score READ scoreQML NOTIFY signalGrille);
    int scoreQML();
    Q_PROPERTY(int bestscore READ bestscoreQML NOTIFY signalGrille);
    int bestscoreQML();

    Q_PROPERTY(QString couleurBouton READ couleurBoutonGUI NOTIFY signalGrille)             // Prendre la couleur du bouton
    QString couleurBoutonGUI();
    Q_PROPERTY(QString couleurBoutonTexte READ couleurBoutonTexteGUI NOTIFY signalGrille)   // Prendre la couleur du text du bouton
    QString couleurBoutonTexteGUI();
    Q_PROPERTY(QString boutonTexte READ boutonTexteGUI NOTIFY signalGrille)                 // Prendre le text du bouton
    QString boutonTexteGUI();

signals:                
    void signalGrille();                                                                    // Le signal résponsable pour changer le qml
private:
    int x;
    int y;
    int score;                                                                              // Score du jeu
    int bestscore;                                                                          // Best score du jeu
    int dimension;

    Bouton **tableBouton;                                                                   // Création de la matrice de boutons
    Bouton *bouton;                                                                         // Teste

    bool finJeu;
    bool gagneur;
    bool perdu;

    // Informations utilises dans qml
    int QMLBlockIndexColor;
    int QMLBlockIndexTextColor;
    int QMLBoutonX;
    int QMLBoutonY;

    // Fonctions
    void initialisationGrille();
    void destructeurGrille();


};

#endif // GRILLE_H
