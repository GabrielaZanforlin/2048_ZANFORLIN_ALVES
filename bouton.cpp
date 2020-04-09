#include "bouton.h"

Bouton::Bouton(int lig, int col)
{
    ligne = lig;
    colonne = col;
    valeur = 2;
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
QString Bouton :: getCouleurBouton(){
    return couleur_Bouton;
}
QString Bouton :: getCouleurText(){
    return couleur_Text;
}

// Methode set
void Bouton :: setLigne(int ligne2){
    ligne = ligne2;
}
void Bouton :: setColonne(int colonne2){
    colonne=colonne2;
}
void Bouton :: setCouleursBT(){ // creation des coulers utilisees
    // Couleurs Boutons
    couleursBoutons << "D0D0D0" << "#90EE90"<<"#20B2AA"<<"#8A2BE2"<<"#EE82EE"<<"#FF1493"<<"#F08080"<<"#D2691E"<<"#F0E68C"<<"#FFD700"<<"#FF8C00"<<"#FF0000";
    // Couleurs Texts
    couleursTexts << "D0D0D0" << "#008000"<<"#556B2F"<<"#4B0082"<<"#FF00FF"<<"#C71585"<<"#FFC0CB"<<"#F4A460"<<"#FFD700"<<"#FF4500"<<"#FF4500"<<"#FFFAFA";
}
void Bouton :: setCouleur(){
    switch (this->getValeur()) {
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
