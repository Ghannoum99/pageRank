#include "GHANNOUM.h"

/***********************************************************************
 *
 *                          LA PARTIE UTILITAIRE
 *
 * ********************************************************************/

/***********************************************
 *  Fonction permettant d'allouer un vecteur
 * @param taille: la taille du vecteur à allouer
 * ********************************************/

VECTEUR allouer_vecteur(int taille)
{
	VECTEUR vect;
	
	vect.taille = taille;
	
	vect.tab_vect = (double*)malloc(vect.taille*sizeof(double));
	
	if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	return vect;
}

/**********************************************************
 *  Fonction permettant de remplir un vecteur aléatoirement
 * *******************************************************/

VECTEUR generer_vecteur_aleatoire(VECTEUR vect)
{
    int i;
    
    if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<vect.taille; i++)
    {

       	vect.tab_vect[i] = rand() % 400 + 1;
    }
    
    return vect;
}

/*********************************************
 *  Fonction permettant d'afficher un vecteur
 * ******************************************/

void afficher_vecteur(VECTEUR vect)
{
	int i;
	
	if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<vect.taille; i++)
    {
    	printf("vect.tab_vect[%d] = %d\n",i, vect.tab_vect[i]);
    }
}

/***********************************************
 *  Fonction permettant de normaliser un vecteur
 * @param vecteur: vecteur à normaliser
 * *********************************************/

double normaliser_vecteur(VECTEUR vect)
{
	double somme;
	int i;
	
	if (vect.tab_vect == NULL)
	{
		exit(EXIT_FAILURE);
	}
	 
	#pragma omp shared(somme) for reduction(+: somme)
	for(i = 0; i < vect.taille; i++)
	{
		somme = somme + (vect.tab_vect[i] * vect.tab_vect[i]);
	}
	 
	return sqrt(somme); 
}

/*********************************************
 *  Fonction permettant de libérer un vecteur
 * ******************************************/
 
void desallouer_vecteur(VECTEUR vect)
{
	 if (vect.tab_vect == NULL)
	 {
		exit(EXIT_FAILURE);
	 }	
	 
	 free(vect.tab_vect);
	 
	 return;
}
 
/**********************************************************************
 *  Fonction permettant d'allouer l'espace mémoire d'une matrice carrée
 * *******************************************************************/

MATRICE_CARREE allouer_matrice_carree(int taille)
{
	MATRICE_CARREE mat;
	int i;

	mat.taille = taille;
	mat.tab_mat =(double**)malloc(taille*sizeof(double));
	

    for(i=0; i<taille; i++)
    {
        mat.tab_mat[i] = (double*)malloc(taille*sizeof(double));
    }
    

    return mat;
} 

/***********************************************************
 *  Fonction permettant de remplir une matrice aléatoirement
 * ********************************************************/

MATRICE_CARREE generer_matrice_aleatoire(MATRICE_CARREE mat)
{
    int i, j;
    
    if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
        for(j=0; j<mat.taille; j++)
        {
            mat.tab_mat[i][j] = rand() % 1 + 1; 
        }
    }
    
    return mat;
}

/*********************************************
 *  Fonction permettant d'afficher une matrice
 * ******************************************/

void afficher_matrice(MATRICE_CARREE mat)
{
	int i,j;
	
	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
        for(j=0; j<mat.taille; j++)
        {
            printf("mat.tab_mat[%d][%d] = %d\n",i,j, mat.tab_mat[i][j]);
        }
    }
}

/**************************************************************************
 *  Fonction permettant de désaouller l'espace mémoire d'une matrice carrée
 * ***********************************************************************/

void desallouer_matrice_carree(MATRICE_CARREE mat)
{
	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}
	

	for(int i=0; i<mat.taille; i++) {
        	free(mat.tab_mat[i]);
    }
    
    free(mat.tab_mat);
    
	return;
}
