#include "GHANNOUM.h"

MATRICE_CARREE mat;
VECTEUR vect;
   
int main(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("le système prend 3 paramètres !\n")
        exit(0);
    }

    int N = atoi(argv[1]);
    int facteur_amort = atoi(argv[2]);
    double tolerance = atoi(argv[3]);
}