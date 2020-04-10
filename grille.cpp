#include<iostream>
#include<QStringList>
#include <QObject>
#include<ctime>
#include<stdlib.h>
#include<time.h>
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
    cout << __PRETTY_FUNCTION__;
    tableBouton = new Bouton*[dimension*dimension];
    for(int i=0;i<dimension;i++){
        for(int j =0;j<dimension;j++){
            tableBouton[i*dimension +j] = new Bouton(i,j);
        }
    }
    randomBouton();
}

void Grille :: randomBouton(){
    cout << __PRETTY_FUNCTION__;
    srand(time(NULL)*time(NULL));
    double val = ((double) rand() / (RAND_MAX));
    int comp=0;
    while(comp==0){
        int random_i = rand()%dimension;
        int random_j = rand()%dimension;
        if(tableBouton[random_i*dimension + random_j]->getValeur()==0){
            if(val<0.85)
                tableBouton[random_i*dimension + random_j]->setValeur(2);
            else
                tableBouton[random_i*dimension + random_j]->setValeur(4);
            comp++;
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


