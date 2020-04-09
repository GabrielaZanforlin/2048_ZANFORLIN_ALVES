#ifndef BOUTON_H
#define BOUTON_H

#include<vector>
#include<QGuiApplication>
#include<QString>
#include<QtQml>

class Bouton
{
public:
    Bouton(int ligne, int colonne); // Constructeur

    // Fonctions Get
    int getLigne();
    int getColonne();
    int getValeur();
    QString getCouleurBouton();
    QString getCouleurText();

    // Fonctions Set
    void setLigne(int ligne2);
    void setColonne(int colonne2);
    void setValeur(int valeur2);
    void setCouleursBT(); // on initialise les couleurs utilises dans les boutons et dans les texts
    void setCouleur(); // dans ce methode, on change les deux couleurs
private:
    int ligne;
    int colonne;
    int valeur;

    QString couleur_Bouton;
    QString couleur_Text;
    QStringList couleursBoutons;
    QStringList couleursTexts;
};

#endif // BOUTON_H
