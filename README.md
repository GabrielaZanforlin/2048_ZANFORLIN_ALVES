# Projet 2048 en C++ et Qt
L'objectif de ce projet est de réaliser le jeu 2048 en utilisant C++ et QT afin d'appliquer les connaissances acquises sur le langage C++ et Qml dans le cours de Programmation des interfaces graphiqes en C++.

# Comment lancer le programme
Pour lancer le jeu, il faut suivre les étapes écrites ci-dessous :

- Téléchargez les fichiers de cette page dans le dossier que vous souhaitez (copiez le lien de cette page -> choisir le dossier souhaité -> toucher sur lui avec le bouton gauche de la souris -> choisir << Git Bash Here >> -> écrire << git clone ...>> plus le lien copié)
- Sur le logiciel QT Creator, cliquez sur << Ouvrir projet>>
- Seletionnez le fichier .pro
- Sur le projet ouvert, toucher << Crtl + R>>
- La fenêtre du jeu est affichée --> Jouez :)

# Description
Le jeu peut démarrer avec l'apparition au hasard d'une tesselle de valeur 2 (85% de probabilité) ou 4 (15% de probabilité). L'objective est de combiner les tesselles qui ont la même valeur, pour les combiner il faut déplacer les tesselles déjà affichées en utilisant les 4 flèches du clavier. Après chaque mouvement, une nouvelle tesselle apparaît au hasard sur une des cases sans valeur du tableau. La partie s'arrête lorsque le tableau est plein et n'y a pas de mouvementes possibles pour libérer une case ou lorsque une tesselle est numéroté en <<2048>>. Le jeu consiste en combine les plus de cases possibles avant le remplissage totale du tableau.

![jeu](https://user-images.githubusercontent.com/62310420/79222867-b34d3b80-7e2e-11ea-8467-e0b828104af6.PNG)

En lancant le programme, une fenêtre s'ouvre et un tableau de dimension 4 (dimension défaut du jeu) est affiché. Sur la fenêtre on trouve :

* << Score>> : la somme de toutes les tesselles de la partie
* << Best Score>> : la meilleure ponctuation de toutes les parties réaliser dans cette fenêtre
* << Historique>> : la plus haute ponctuation déjà réaliser
* << Effacer>> : effacer l'historique, dans ce cas la case << Historique>> affichera le << Best Score>>. Néanmoins, si on ferme la fenêtre du jeu et la rouvre le _Historique_ affichera la meilleure ponctuation réalisée dès la dernière touche dans le bouton _Effacer_ 
* << Redémarrer>>
* << Revenir>>
* Case pour mettre la dimension souhaitée

## Gestion de memoire
![boutons](https://user-images.githubusercontent.com/62310420/79225503-2c4e9200-7e33-11ea-957c-39666e799233.PNG)

Tout d'abord, le jouer peut voir sa ponctuation dans chaque partie. Il peut encore voir sa meilleure ponctuation réalisée dans cette fenêtre (c'est-à-dire, avant ferme la fenêtre du jeu) et voir aussi la meilleure ponctuation déjà réaliser. 
Pour enregistre la ponctuation plus haute déjà fait, on a créé un fichier _historiqueJeu.txt_ où on écrit cette ponctuation. 

## Boutons de <<Rédemarrer>> << Revenir>> et << Dimension>>

![boutonsRRD](https://user-images.githubusercontent.com/62310420/79225874-cf071080-7e33-11ea-9818-5300e2cd9d87.PNG)

Pendant une partie, le joueur peut choisir de redémarrer une nouvelle partie (la première case numéroté est au hasard aussi comme la valeur qu'elle porte). En outre, à chaque fois qu'on change la dimension, le jeu recommence. 

La possibilité de revenir les rounds précedants est grâces à l'utilisation d'une matrice _** *int_ de taille **[numéro de rounds][dimension][dimension]**, allocation dynamique avec une matrice 3 pointeurs. Pour chaque round, le tableau des cases est enregistré dans cette matrice, on peut donc revenir le jeu en changeant le tableau actuel du jeu pour celui enregistré par la matrice **[numéro de rounds -1][dimension][dimension]**. 

## Changement de la dimension du jeu

![dimensionss](https://user-images.githubusercontent.com/62310420/79225526-38d2ea80-7e33-11ea-9d38-23b351b6faac.PNG)

Le joueur peut choisir la dimension du jeu, il faut seulement écrire dans le case << Entre dimension>> **une valeur entre 4 et 10**, car on a mis dans notre code une restriction que permet le changement de dimension seulement si la valeur écrit est dans cet l'intervalle cite.

## Fenêtres << Gagneur>> et << Perdeur>>

![fenetres](https://user-images.githubusercontent.com/62310420/79225611-615ae480-7e33-11ea-96df-e35b77811db1.PNG)

### Fenêtre _GAGNEUR_
Après l'apparition de la première case numéroté en _2048_, la fenêtre du jeu disparaît et une nouvelle fenêtre est affichée avec le titre << Vous avez gagné :) >> et deux boutons
:
* Redémarrer: permettant le joueur de commencer une nouvelle partie
* Continuer: permettant le joueur de continuer la même et faire donc plus de 2048

### Fenêtre _PERDEUR_
Si le joueur n'a pas réussi en faire 2048 avant le remplissage totale du tableau et il n'y a plus de mouvement possible, une nouvelle fenêtre est affichée avec le titre << Vous avez perdu :( >> et un bouton :
* Redémarrer : le joueur peut seulement commencer une nouvelle partie.

# Groupe du projet
- **Gabriela GUARATO ZANFORLIN**: [GabrielaZanforlin](https://github.com/GabrielaZanforlin)
- **Pedro Henrique ALVES DA SILVA E SILVA**: [PedroSilvaeSilva](https://github.com/PedroSilvaeSilva)

# Enseignants
- **Emmanuel Dellandrea**
- **Stephane Derrode**

# Possibles améliorations
Les futures funcionnalités qui peuvent être ajouter au projet :

* Un historique différent pour chaque dimension
* La possibilité de changer les couleurs utilisé pour colorer les tesselles
* Programmer les mouvement des tesselles lors de son déplacement
* Ajouter un menu permettant de jeur en mode _multiplayer_

# Observation : Rédemarrer en place de Redémarrer
Désolée, mais seulement après avoir fini le projet on a vu que on a écrit << R**é**demarrer>> en place d'écrire << Red**é**demarrer>>. Le code enregistre est corrigé, mais les photos utilisées dans cette explication ont encore l'erreur, car on les a pris avant de faire la correction.
