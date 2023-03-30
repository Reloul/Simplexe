/*!
 *  \mainpage Programme pour appliquer l'algo du simplexe
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres & Léo-Paul Bigot qui permet de faire l'algorithme du simplexe
*/


 /*!
 *  \file nom_fichier
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1
 *  \brief Code permettant de faire l'algorithme du simplexe
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>

/*!
 *  \fn void liberation(float** tab, int taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 29 2023 - 15:22:37
 *  \brief procédure permettant de libérer la mémoire
 *  \param tab pointeur de pointeur de réel représentant un tableau de réel 2 dimensions
 *  \param taille entier représentant le nombre de ligne du tableau 2 dimensions
*/

void liberation(float** tab, int taille){
    int i;
    for(i=0;i<taille;i++){
        free(tab[i]);
    }
    free(tab);
}

/*!
 *  \fn void affichage(float** tab, int ligne, int colonne)
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 29 2023 - 09:54:37
 *  \brief procédure permettant d'afficher des tableaux
 *  \param tab pointeur de pointeur de réel qui sert de tableau 2 dimensions
 *  \param ligne entier correspondant au nombre de ligne
 *  \param colonne entier correspondant au nombre de colonne
*/

void affichage(float** tab, int ligne, int colonne){
    int i,j;
    for(i=0;i<ligne;i++){
        for(j=0;j<colonne;j++){
            //On affiche la grille
            printf("| %f ", tab[i][j]);   
        }
        printf("|\n");
    }
}

/*!
 *  \fn void initTab(int nbVar, int nbContrainte float **tab)
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 29 2023 - 09:57:02
 *  \brief porcédure permettant d'initialiser le premier tableau de l'algorithme
 *  \param nbVar entier qui représente le nombre de variable du problème
 *  \param nbContrainte entier qui représente le nombre de contrainte du problème
 *  \param tab pointeur de pointeur de réel qui sert de tableau 2 dimensions
*/

void initTab(int nbVar, int nbContrainte, float **tab, float** newTab){
    int i,j;
    for(i=0; i<(nbContrainte+1); i++){
        for(j=1; j<=nbVar; j++){
            newTab[i][j] = tab[i][j-1];
        }
    }
    for(i=1; i<(nbContrainte+1); i++){
        for(j=nbVar+1; j<nbContrainte+1+nbVar; j++){
            if(i == j-2){
                newTab[i][j] = 1;   
            }
        }
    }
    for(i=1;i<=nbContrainte;i++){
        newTab[i][0] =tab[i][2]; 
    }
    affichage(newTab,(nbContrainte+1), (nbVar+nbContrainte+1));
}

/*!
 *  \fn float rechercheEntrant(float** newTab, int nbVar, int nbContrainte)
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 29 2023 - 15:07:38
 *  \brief fonction permettant de chercher la variable entrante d'un tableau
 *  \param newTab pointeur de pointeur de réel représentant un tableau de réel de 2 dimensions
 *  \param nbVar entier représentant le nombre de variable du problème
 *  \param nbContrainte entier représentant le nombre de contrainte du problème
 *  \return max le réel qui représente la variable entrante
*/

float rechercheEntrant(float** newTab, int nbVar, int nbContrainte){
    int i;
    float max=0;
    for(i=1;i<(nbVar + nbContrainte + 1); i++){
        if(newTab[0][i]>max){
            max = newTab[0][i];
        }
    }
    return(max);
}


/*!
 *  \fn void simplexe()
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 28 2023 - 14:34:46
 *  \brief procédure permettant de commencer l'algorithme du simplexe
*/

void simplexe(){
    int i, nbVar, nbContrainte;
    float** tab, **newTab;
    tab = malloc(4*sizeof *tab);
    for (i=0;i<4;i++)
        tab[i] = malloc(3*sizeof tab);
    tab[0][0] = 1;
    tab[0][1] = 0.5;
    tab[1][0] = 1;
    tab[1][1] = 1;
    tab[1][2] = 4;
    tab[2][0] = -3;
    tab[2][1] = 1;
    tab[2][2] = 3;
    tab[3][0] = 1;
    tab[3][1] = -0.5;
    tab[3][2] = 1;nbContrainte = 3;
    nbContrainte = 3;
    nbVar = 2;
    newTab = malloc((nbContrainte+1)*sizeof *newTab);
    for(i=0;i<=nbContrainte;i++){
        newTab[i] = malloc((nbContrainte+nbVar+1)*sizeof newTab);
    }

    affichage(tab, 4, 3);
    printf("\n");
    initTab(2, 3, tab, newTab);
    printf("%f \n", rechercheEntrant(newTab, nbVar, nbContrainte ));
    liberation(newTab,nbContrainte+1);
    liberation(tab, 4);
}



/*!
 *  \fn int main()
 *  \author SERRES Valentin <serresvale@cy-tech.fr> BIGOT Léo-Paul <bigotleopa@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 28 2023 - 14:34:40
 *  \brief fonction main
 *  \return 0 quand tout se passe bien
*/

int main(){
    simplexe();
    return(0);
}
