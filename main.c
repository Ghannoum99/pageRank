#include "Ghannoum.h"
#define SIZE 4

int main()
{
    MATRICE matP;
    
    double alpha = 0.85;
    double tolerance = 0.000001;
    matP.taille = SIZE;
    
    matP = allouer_matrice_carree(matP.taille);
    generer_matrice_aleatoire(matP);
    afficher_matrice(matP);

    pageRank(matP, alpha, tolerance);

    return 0;
}