/*bibliotheque permettant d'envoyer des commandes ANSI au terminal afin
de pouvoir jouer sur la mise en forme de la page affichee. */
/*realisee par Pisak Sebastien :
version 1.0 du 31/01/2013
*/

#ifndef TERMINAL_H
#define TERMINAL_H
#include "WProgram.h"
#include <stdio.h>


void terminalInit(void);    //initialistation du terminal avec les valeurs d'attributs par defaut
void terminalPosition (int col, int ligne);//position du curseur
void terminalCouleur(int text,int font);//couleur du texte et du fond d'ecran
void terminalEfface(void);


#endif
