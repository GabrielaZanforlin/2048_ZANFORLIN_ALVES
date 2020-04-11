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
    constructeurGrille();
}
void Grille::constructeurGrille(){
    score = 0;
    rounds = 1;
    dimension = 4;                                      // le taille du tableau du jeu
    //finJeu = false;
    gagneur = false;
    perdeur = false;
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
    // Pour sauvegarder le début du jeu
    tableauMemoire = new int**[1];
    tableauMemoire[0] = new int*[dimension];
    for(int i=0;i<dimension;i++){
        (tableauMemoire[0])[i] = new int[dimension];

    }
    for(int i=0;i<dimension;i++){
        for(int j=0; j<dimension; j++){
            ((tableauMemoire[0])[i])[j] = tableBouton[j+dimension*i]->getValeur();
        }
    }
}

void Grille :: randomBouton(){
    srand(time(NULL)*time(NULL));
    double val = ((double) rand() / (RAND_MAX));
    int comp=0;
    bool contientZero = false;
    for(int i =0; i<dimension;i++){
        for(int j = 0; j<dimension;j++){
            if(tableBouton[i*dimension+j]->getValeur()==0){
                while(comp==0){
                    int random_i = rand()%dimension;
                    int random_j = rand()%dimension;
                    if(tableBouton[random_i*dimension + random_j]->getValeur()==0){
                        if(val<0.85){
                            tableBouton[random_i*dimension + random_j]->setValeur(2);
                            score +=2;
                        }else
                        {
                            tableBouton[random_i*dimension + random_j]->setValeur(4);
                            score +=4;
                        }
                        comp++;
                    }
                }
                contientZero = true;
                if(bestscore<score)
                    setBestScore(score);
                signalGrille();
                break;
            }
        }
        if(contientZero)
            break;
    }
}
void Grille::reinitialiserFusion(){
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            tableBouton[i*dimension+j]->setFusion(true);
        }
    }
}
// Mouvement
void Grille::UP(){
    bool mouvementPossible = false;
    for(int k=0; k<dimension-1;k++){
        for(int i=1;i<dimension;i++){
            for(int j=0;j<dimension;j++){
                if(tableBouton[i*dimension+j]->getValeur()!=0){
                    if(tableBouton[dimension*(i-1)+j]->getValeur()==0){
                        tableBouton[dimension*(i-1)+j]->setValeur(tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        mouvementPossible = true;
                    } else if(tableBouton[dimension*(i-1)+j]->getValeur()==tableBouton[i*dimension+j]->getValeur() && tableBouton[i*dimension+j]->getFusion() && tableBouton[dimension*(i-1)+j]->getFusion()){
                        tableBouton[dimension*(i-1)+j]->setValeur(2*tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        tableBouton[dimension*(i-1)+j]->setFusion(false);
                        mouvementPossible = true;
                    }
                }
            }
        }
    }
    reinitialiserFusion();
    if(checkGagneur()){
        gagneur = true;
    } else if(checkPerdeur()){
        perdeur = true;
    }
    if(mouvementPossible){
        randomBouton();
        sauvegarder();
        rounds++;
    }
    signalGrille();
}
void Grille :: Down(){
    bool mouvementPossible = false;
    for(int k=0;k<dimension-1;k++){
        for(int i=dimension-2;i>=0;i--){
            for(int j=0;j<dimension;j++){
                if(tableBouton[i*dimension+j]->getValeur() !=0){
                    if(tableBouton[dimension*(i+1)+j]->getValeur()==0){
                        tableBouton[dimension*(i+1)+j]->setValeur(tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        mouvementPossible = true;
                    } else if(tableBouton[dimension*(i+1)+j]->getValeur()==tableBouton[i*dimension+j]->getValeur() && tableBouton[i*dimension+j]->getFusion() && tableBouton[dimension*(i+1)+j]->getFusion()){
                        tableBouton[dimension*(i+1)+j]->setValeur(2*tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        tableBouton[dimension*(i+1)+j]->setFusion(false);
                        mouvementPossible = true;
                    }
                }
            }
        }
    }
    reinitialiserFusion();
    if(checkGagneur()){
        gagneur = true;
    } else if(checkPerdeur()){
        perdeur = true;
    }
    if(mouvementPossible){
        randomBouton();
        sauvegarder();
        rounds++;
    }
    signalGrille();
}
void Grille:: Left(){
    bool mouvementPossible = false;
    for(int k=0;k<dimension-1;k++){
        for(int j=1;j<dimension;j++){
            for(int i=0;i<dimension;i++){
                if(tableBouton[i*dimension+j]->getValeur() !=0){
                    if(tableBouton[dimension*i+j-1]->getValeur()==0){
                        tableBouton[dimension*i+j-1]->setValeur(tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        mouvementPossible = true;
                    } else if(tableBouton[dimension*i+j-1]->getValeur()==tableBouton[i*dimension+j]->getValeur() && tableBouton[i*dimension+j]->getFusion() && tableBouton[dimension*i+j-1]->getFusion()){
                        tableBouton[dimension*i+j-1]->setValeur(2*tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        tableBouton[dimension*i+j-1]->setFusion(false);
                        mouvementPossible = true;
                    }
                }
            }
        }
    }
    reinitialiserFusion();
    if(checkGagneur()){
        gagneur = true;
    } else if(checkPerdeur()){
        perdeur = true;
    }
    if(mouvementPossible){
        randomBouton();
        sauvegarder();
        rounds++;
    }
    signalGrille();
}
void Grille::Right(){
    bool mouvementPossible = false;
    for(int k=0;k<dimension-1;k++){
        for(int j=dimension-2;j>=0;j--){
            for(int i=0;i<dimension;i++){
                if(tableBouton[i*dimension+j]->getValeur() !=0){
                    if(tableBouton[dimension*i+j+1]->getValeur()==0){
                        tableBouton[dimension*i+j+1]->setValeur(tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        mouvementPossible = true;
                    } else if(tableBouton[dimension*i+j+1]->getValeur()==tableBouton[i*dimension+j]->getValeur() && tableBouton[i*dimension+j]->getFusion() && tableBouton[dimension*i+j+1]->getFusion()){
                        tableBouton[dimension*i+j+1]->setValeur(2*tableBouton[i*dimension+j]->getValeur());
                        tableBouton[i*dimension+j]->setValeur(0);
                        tableBouton[dimension*i+j+1]->setFusion(false);
                        mouvementPossible = true;
                    }
                }
            }
        }
    }
    reinitialiserFusion();
    if(checkGagneur()){
        gagneur = true;
    } else if(checkPerdeur()){
        perdeur = true;
    }
    if(mouvementPossible){
        randomBouton();
        sauvegarder();
        rounds++;
    }
    signalGrille();
}

void Grille::sauvegarder(){
    int ***memoireAux;
    memoireAux = new int**[rounds+1];
    // Création d'une matrice pour passer les valeurs d'avant
    for(int i=0;i<rounds+1;i++){
        memoireAux[i]=new int*[dimension];
    }
    for(int i=0;i<rounds+1;i++){
        for(int j=0;j<dimension;j++){
            (memoireAux[i])[j]= new int[dimension];
        }
    }
    // Sauvegarder les valeurs d'avant
    for(int i=0;i<rounds;i++){
        for(int j=0; j<dimension; j++){
            for(int k=0;k<dimension;k++){
                ((memoireAux[i])[j])[k] = (tableauMemoire[i])[j][k];
            }
        }
    }
    // Sauvegarder le round
    int sommeScoreRound=0;
    for(int i=0;i<dimension;i++){
        for(int j=0;j<dimension;j++){
            (memoireAux[rounds])[i][j] = tableBouton[i*dimension+j]->getValeur();
            sommeScoreRound+=tableBouton[i*dimension+j]->getValeur();
        }
    }
    // Check best Score
    if(sommeScoreRound>bestscore){
        setBestScore(sommeScoreRound);
    }
    // Supprimer le tableu de memoire d'avant
    for(int i=0;i<rounds;i++){
        for(int j=0;j<dimension;j++){
            delete (tableauMemoire[i])[j];
        }
        delete tableauMemoire[i];
    }
    delete [] tableauMemoire;
    tableauMemoire=memoireAux;
    // Delete memoireAux
    for(int i=0;i<rounds;i++){
        for(int j=0;j<dimension;j++){
            delete (memoireAux[i])[j];
        }
        delete memoireAux[i];
    }
    delete [] memoireAux;
    memoireAux = NULL;
}

bool Grille::checkGagneur(){
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            if(tableBouton[i*dimension + j]->getValeur()==2048)
                return true;
        }
    }
    return false;
}
bool Grille::checkPerdeur(){
    // Voir colonnes
    for(int i=0;i<dimension -1;i++){
        for(int j=0;j<dimension;j++){
            if(tableBouton[dimension*i+j]->getValeur()==tableBouton[dimension*(i+1)+j]->getValeur())
                return false;
        }
    }
    // Voir lignes
    for(int j=0;j<dimension -1;j++){
        for(int i=0;i<dimension;i++){
            if(tableBouton[dimension*i+j]->getValeur()==tableBouton[dimension*i+j+1]->getValeur())
                return false;
        }
    }
    return true;
}

// Get methodes --> utilisés dans le qml
bool Grille:: gagnerQML(){
    return gagneur;
}

bool Grille:: perduQML(){
    return perdeur;
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
void Grille::setBestScore(int bestScoreModifie){
    bestscore=bestScoreModifie;
}
void Grille:: setRound(int round2){
    rounds=round2;
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

// Revenir
void Grille::revenir(){
    if(rounds>1){
        rounds--;
        int sommeScore=0;
        for(int i=0;i<dimension;i++){
            for(int j=0; j<dimension;j++){
                tableBouton[i*dimension+j]->setValeur(tableauMemoire[rounds-1][i][j]);
                sommeScore +=tableBouton[i*dimension+j]->getValeur();
            }
        }
        setScore(sommeScore);
        if(sommeScore>bestscore){
            setBestScore(sommeScore);
        }
        signalGrille();
    }
}

// Rédemarrer le jeu
void Grille::redemarrerGrille(){
    destructeurGrille();
    constructeurGrille();
}

// Destructeur
Grille :: ~Grille(){
    destructeurGrille();
}

void Grille::destructeurGrille(){
    if(tableBouton != NULL){
        for(int i=0;i<dimension*dimension;i++){
            delete tableBouton[i];
        }
        delete [] tableBouton;
    }
    if(tableauMemoire != NULL){
        for(int i=0;i<rounds;i++){
            for(int j=0;j<dimension;j++){
                delete (tableauMemoire[i])[j];
            }
            delete tableauMemoire[i];
        }
        delete [] tableauMemoire;
    }
    tableBouton=NULL;
    tableauMemoire=NULL;
}

