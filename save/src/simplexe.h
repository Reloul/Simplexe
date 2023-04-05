#ifndef __SIMPLEXE_H_
#define __SIMPLEXE_H_

 /*!
 *  \file simplexe.h
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief 
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>

void liberation(float** tab, int taille);

void affichage(float** tab, int ligne, int colonne);

void initTab(int nbVar, int nbContrainte, float **tab, float** newTab);

int rechercheEntrant(float** newTab, int nbVar, int nbContrainte);

int rechercheSortant(float** newTab, int nbVar, int nbContrainte, int varEntr);

void simplexe();
#endif