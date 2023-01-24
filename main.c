#include "Ghannoum.h"

MATRICE mat_adj;
VECTEUR vect;

int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("le système prend 3 paramètres !\n");
        exit(0);
    }
    
    mat_adj.taille = atoi(argv[1]);
    double facteur_amort = atoi(argv[2]);
    double tolerance = atoi(argv[3]);

    mat_adj = allouer_matrice_carree(mat_adj.taille);
    //generer_matrice_adj(mat_adj);
    //afficher_matrice(mat_adj);

}