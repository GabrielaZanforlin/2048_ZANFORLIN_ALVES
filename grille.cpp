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
    QMLCompteurCouleurBoutonTexte = 0;
    QMLCompteurCouleurBouton = 0;
    QMLCompteuBoutonTexte = 0;
    QMLBoutonX = 0;
    QMLBoutonY = 0;
    initialisationGrille();
    signalGrille();
}

int Grille::getDimension(){
    return dimension;
}

void Grille::initialisationGrille(){
    tableBouton = new Bouton*[dimension*dimension];
    for(int i=0;i<dimension;i++){
        for(int j =0;j<dimension;j++){
            tableBouton[i*dimension +j] = new Bouton(i,j);
        }
    }
    randomBouton();
}

void Grille :: randomBouton(){
    srand(time(NULL)*time(NULL));
    double val = ((double) rand() / (RAND_MAX));
    int comp=0;
    while(comp==0){
        int random_i = rand()%dimension;
        int random_j = rand()%dimension;
        if(tableBouton[random_i*dimension + random_j]->getValeur()==0){
            if(val<0.85){
                tableBouton[random_i*dimension + random_j]->setValeur(2);
            }else
            {
                tableBouton[random_i*dimension + random_j]->setValeur(4);
            }
            comp++;
        }
    }
    signalGrille();
}

// Mouvement
void Grille::UP(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            if((i*dimension+j)>(dimension-1) && tableBouton[i*dimension+j]->getValeur()!=0){

                if(tableBouton[(i*dimension+j)%dimension]->getValeur()==0){
                    tableBouton[(i*dimension+j)%dimension]->setValeur(tableBouton[i*dimension+j]->getValeur());
                    tableBouton[i*dimension+j]->setValeur(0);
                    signalGrille();
                }

                /*if(tableBouton[dimension*(i-1)+j]->getValeur()==0){
                    tableBouton[dimension*(i-1)+j]->setValeur(tableBouton[i*dimension+j]->getValeur());
                    tableBouton[i*dimension+j]->setValeur(0);
                    signalGrille();

                }*/
                /*if(tableBouton[dimension*(i-1)+j]->getValeur()==tableBouton[i*dimension+j]->getValeur()){
                    //tableBouton[dimension*(i-1)+j]->setValeur(2*tableBouton[i*dimension+j]->getValeur());
                    //tableBouton[i*dimension+j]->setValeur(0);
                    signalGrille();

                } else if(tableBouton[dimension*(i-2)+j]->getValeur()==tableBouton[i*dimension+j]->getValeur()){

                } else if(tableBouton[dimension*(i-3)+j]->getValeur()==tableBouton[i*dimension+j]->getValeur()){

                }*/

            }
        }
    }
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
int Grille::positionX(){
    int x,colonne;
    if(QMLBoutonX==dimension*dimension)
        QMLBoutonX=0;
    colonne = tableBouton[QMLBoutonX]->getColonne();
    x=(colonne*(75+10))+10;
    QMLBoutonX++;
    return x;
}
int Grille::positionY(){
    int y,ligne;
    if(QMLBoutonY==dimension*dimension)
        QMLBoutonY=0;
    ligne = tableBouton[QMLBoutonY]->getLigne();
    y=(ligne*(75+10))+10;
    QMLBoutonY++;
    return y;
}
QString Grille::couleurBoutonGUI()
{
    QString couleurBouton;
    if(QMLCompteurCouleurBouton==dimension*dimension)
        QMLCompteurCouleurBouton=0;
    couleurBouton = tableBouton[QMLCompteurCouleurBouton]->getCouleurBouton();
    QMLCompteurCouleurBouton++;
    return couleurBouton;
}

QString Grille::couleurBoutonTexteGUI()
{
    QString couleurBoutonTexte;
    if(QMLCompteurCouleurBoutonTexte==dimension*dimension)
        QMLCompteurCouleurBoutonTexte=0;
    couleurBoutonTexte = tableBouton[QMLCompteurCouleurBoutonTexte]->getCouleurText();
    QMLCompteurCouleurBoutonTexte++;
    return couleurBoutonTexte;
}

QString Grille::boutonTexteGUI()
{
    int boutonTexte;
    if(QMLCompteuBoutonTexte==dimension*dimension)
        QMLCompteuBoutonTexte=0;
    boutonTexte = tableBouton[QMLCompteuBoutonTexte]->getValeur();
    QMLCompteuBoutonTexte++;
    return QString::number(boutonTexte);
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

