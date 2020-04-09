#include<iostream>
#include<QStringList>
#include <QObject>
#include "grille.h"
#include "bouton.h"
using namespace std;

// Constructeur
Grille::Grille(QObject *parent) :  QObject(parent)
{
    score = 0;
    dimension = 4;                                      // le taille du tableau du jeu

    finJeu = false;
    gagneur = false;
    perdu = false;
    bouton = new Bouton(1,1);                           // TESTE
    initialisationGrille();
}
void Grille::initialisationGrille(){
    tableBouton = new Bouton*[dimension*dimension];
    for(int i=0;i<dimension;i++){
        for(int j =0;j<dimension;j++){
            tableBouton[i*dimension +j] = new Bouton(i,j);
        }
    }
}

// Destructeur
Grille :: ~Grille(){
    destructeurGrille();
}
void Grille::destructeurGrille(){
    if(tableBouton != NULL){
        for(int i=0;i<dimension*dimension;i++){
            delete [] tableBouton[i];
            //delete tableBouton[i];
        }
        delete [] tableBouton;
    }
    tableBouton=NULL;
}

// Get methodes --> utilisés dans le qml
bool Grille:: gagnerQML(){
    return gagneur;
}
bool Grille:: perduQML(){
    return perdu;
}
int Grille :: scoreQML(){
    return score;
}
int Grille :: bestscoreQML(){
    return bestscore;
}

// Set methodes
void Grille :: setScore(int scoreModifie){
    score = scoreModifie;
}

//Sending data to GUI
QString Grille::couleurBoutonGUI()
{
    QString couleurBouton;
    couleurBouton = bouton->getCouleurBouton();
    return couleurBouton;
}

QString Grille::couleurBoutonTexteGUI()
{
    QString couleurBoutonTexte;
    couleurBoutonTexte = bouton->getCouleurText();
    return couleurBoutonTexte;
}

QString Grille::boutonTexteGUI()
{
    int boutonTexte;
    boutonTexte = bouton->getValeur();
    return QString::number(boutonTexte);
}


