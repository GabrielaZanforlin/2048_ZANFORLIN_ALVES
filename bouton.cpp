#include "bouton.h"

Bouton::Bouton(int lig, int col)
{
    ligne = lig;
    colonne = col;
    valeur = 0;
    fusion = true;
    setCouleursBT();
    setCouleur();
}

// Methode get
int Bouton ::getLigne(){
    return ligne;
}
int Bouton :: getColonne(){
    return colonne;
}
int Bouton :: getValeur(){
    return valeur;
}
bool Bouton::getFusion(){
    return fusion;
}
QString Bouton :: getCouleurBouton(){
    return couleur_Bouton;
}
QString Bouton :: getCouleurText(){
    return couleur_Text;
}

// Methode set
void Bouton:: setValeur(int valeur2){
    valeur=valeur2;
    setCouleur();
}
void Bouton:: setFusion(bool fusion2){
    fusion=fusion2;
}
void Bouton :: setLigne(int ligne2){
    ligne = ligne2;
}
void Bouton :: setColonne(int colonne2){
    colonne=colonne2;
}

void Bouton :: setCouleursBT(){                     // creation des coulers utilisees
    // Couleurs Boutons
    couleursBoutons << "#8C8C8C" << "#90EE90"<<"#20B2AA"<<"#8A2BE2"<<"#EE82EE"<<"#FF1493"<<"#F08080"<<"#D2691E"<<"#F0E68C"<<"#FFD700"<<"#FF8C00"<<"#FF0000";
    // Couleurs Texts
    couleursTexts << "#8C8C8C" << "#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645"<<"#474645";
}
void Bouton :: setCouleur(){
    switch (valeur) {
        case 0:
            couleur_Bouton=couleursBoutons.at(0);
            couleur_Text=couleursTexts.at(0);
            break;
        case 2:
            couleur_Bouton=couleursBoutons.at(1);
            couleur_Text=couleursTexts.at(1);
            break;
        case 4:
            couleur_Bouton=couleursBoutons.at(2);
            couleur_Text=couleursTexts.at(2);
            break;
        case 8:
            couleur_Bouton=couleursBoutons.at(3);
            couleur_Text=couleursTexts.at(3);
            break;
        case 16:
            couleur_Bouton=couleursBoutons.at(4);
            couleur_Text=couleursTexts.at(4);
            break;
        case 32:
            couleur_Bouton=couleursBoutons.at(5);
            couleur_Text=couleursTexts.at(5);
            break;
        case 64:
            couleur_Bouton=couleursBoutons.at(6);
            couleur_Text=couleursTexts.at(6);
            break;
        case 128:
            couleur_Bouton=couleursBoutons.at(7);
            couleur_Text=couleursTexts.at(7);
            break;
        case 256:
            couleur_Bouton=couleursBoutons.at(8);
            couleur_Text=couleursTexts.at(8);
            break;
        case 512:
            couleur_Bouton=couleursBoutons.at(9);
            couleur_Text=couleursTexts.at(9);
            break;
        case 1024:
            couleur_Bouton=couleursBoutons.at(10);
            couleur_Text=couleursTexts.at(10);
            break;
        case 2048:
            couleur_Bouton=couleursBoutons.at(11);
            couleur_Text=couleursTexts.at(11);
            break;
    }
    if(valeur>2048){
        switch (valeur/2048) {
            case 0:
                couleur_Bouton=couleursBoutons.at(0);
                couleur_Text=couleursTexts.at(0);
                break;
            case 2:
                couleur_Bouton=couleursBoutons.at(1);
                couleur_Text=couleursTexts.at(1);
                break;
            case 4:
                couleur_Bouton=couleursBoutons.at(2);
                couleur_Text=couleursTexts.at(2);
                break;
            case 8:
                couleur_Bouton=couleursBoutons.at(3);
                couleur_Text=couleursTexts.at(3);
                break;
            case 16:
                couleur_Bouton=couleursBoutons.at(4);
                couleur_Text=couleursTexts.at(4);
                break;
            case 32:
                couleur_Bouton=couleursBoutons.at(5);
                couleur_Text=couleursTexts.at(5);
                break;
            case 64:
                couleur_Bouton=couleursBoutons.at(6);
                couleur_Text=couleursTexts.at(6);
                break;
            case 128:
                couleur_Bouton=couleursBoutons.at(7);
                couleur_Text=couleursTexts.at(7);
                break;
            case 256:
                couleur_Bouton=couleursBoutons.at(8);
                couleur_Text=couleursTexts.at(8);
                break;
            case 512:
                couleur_Bouton=couleursBoutons.at(9);
                couleur_Text=couleursTexts.at(9);
                break;
            case 1024:
                couleur_Bouton=couleursBoutons.at(10);
                couleur_Text=couleursTexts.at(10);
                break;
            case 2048:
                couleur_Bouton=couleursBoutons.at(11);
                couleur_Text=couleursTexts.at(11);
                break;
        }
    }
}
