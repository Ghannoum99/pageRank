#include "Ghannoum.h"

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
    	printf("vect.tab_vect[%d] = %f\n",i, vect.tab_vect[i]);
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

MATRICE allouer_matrice_carree(int taille)
{
	MATRICE mat;
	int i;

	mat.taille = taille;
	mat.tab_mat =(double**)malloc(sizeof(double*)*taille);
	

    for(i=0; i<taille; i++)
    {
        mat.tab_mat[i] = (double*)malloc(sizeof(double)*taille);
    }

	if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}
    

    return mat;
} 

/***********************************************************
 *  Fonction permettant de remplir une matrice aléatoirement
 * ********************************************************/

MATRICE generer_matrice_aleatoire(MATRICE mat)
{	
	int i = 0;
	int j = 0;
    int colonne;
	int aleat = 0;
    
    if (mat.tab_mat == NULL)
	{
		exit(EXIT_FAILURE);
	}

    for(i=0; i<mat.taille; i++)
    {
		colonne = 0;
        for(j=0; j<mat.taille; j++)
        {
			if(i == j)
			{
				mat.tab_mat[i][j] = 0;
			}
			else{
				aleat = rand() % 2;
				mat.tab_mat[i][j] = aleat;
				if (aleat == 1)
					colonne+=1;

			}
			if(j == mat.taille - 1 && colonne == 0)
			{
				mat.tab_mat[i][j] = (double) 1;
			}
        }
		for(j=0; j<mat.taille; j++) 
		{
			if(i != j && colonne != 0)
			{
				mat.tab_mat[i][j] = mat.tab_mat[i][j] / colonne;
			}
		}
    }
    
    return mat;
}

/*********************************************
 *  Fonction permettant d'afficher une matrice
 * ******************************************/

void afficher_matrice(MATRICE mat)
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
            printf("mat.tab_mat[%d][%d] = %f\n",i,j, mat.tab_mat[i][j]);
        }
    }
}

/**************************************************************************
 *  Fonction permettant de désaouller l'espace mémoire d'une matrice carrée
 * ***********************************************************************/

void desallouer_matrice_carree(MATRICE mat)
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

void pageRank(MATRICE matP, double alpha, double tolerance)
{
	MATRICE matA;
    MATRICE res1;
    MATRICE res2;

	int k = 0;
	double x[4]= {1, 0, 0, 0};
    double x_moins_k[4]= {0, 0, 0, 0};
    double G [4][4];
    double x_plus_k[4];
    double resultat[4];
    double norme = 0;
    double normeRes;

	matA.taille = matP.taille;
    res1.taille = matP.taille;
    res2.taille = matP.taille;

	matA = allouer_matrice_carree(matA.taille);
    res1 = allouer_matrice_carree(res1.taille);
    res2 = allouer_matrice_carree(res2.taille);

	for (int i = 0; i < matP.taille; i++)
    {
        for (int j = 0; j < matP.taille; j++)
        {
            G[i][j] = (double) 1/4;
        }
    }

    // alpha * P
    for (int i = 0; i < matP.taille; i++)
    {
        for (int j = 0; j < matP.taille; j++)
        {
            res1.tab_mat[i][j] = matP.tab_mat[i][j] * alpha;
        }
    }

    // (1-alpha) * G
    for (int i = 0; i < matP.taille; i++)
    {
        for (int j = 0; j < matP.taille; j++)
        {
            res2.tab_mat[i][j] = G[i][j] * (1 - alpha);
        }
    }

    // initialisation de la matrice de probabilité A 
    for (int i = 0; i < matP.taille; i++)
    {
        for (int j = 0; j < matP.taille; j++)
        {
            matA.tab_mat[i][j] = res1.tab_mat[i][j] + res2.tab_mat[i][j];
        }
    }

    printf("le vecteur initial xo : ");
    for (int i = 0; i < matP.taille; i++)
    {
        printf("%f, ", x[i]);
		 puts("");
    }

    do 
    {
        k++;

        // A * vecteur de position
        for (int i = 0; i < matP.taille; i++)
        {
            x_plus_k[i] = 0;
            for (int j = 0; j < matP.taille; j++)
            {
                x_plus_k[i] += matA.tab_mat[i][j] * x[j];
            }
        }

        for (int i = 0; i < matP.taille; i++)
        {
            x_moins_k[i] = x[i];
        }

        printf("X%d : ", k-1);
        for (int i = 0; i < matP.taille; i++)
        {
            printf("%f, ", x_moins_k[i]);
			 puts("");
        }


        for (int i = 0; i < matP.taille; i++)
        {
            x[i] = x_plus_k[i];
			 puts("");
        }

        printf("X%d : ", k);

        for (int i = 0; i < matP.taille; i++)
        {
            printf("%f, ", x[i]);
			 puts("");
        }

       

        //xk - xk-1
        for (int i = 0; i < matP.taille; i++)
        {
            resultat[i] = x[i] - x_moins_k[i];
        }

        for (int i = 0; i < matP.taille; i++)
        {
            norme += resultat[i] * resultat[i];
        }

        normeRes = sqrt(norme);

        printf("la normalisation : %f\n", normeRes);

    }while(normeRes > tolerance);

    printf("la convergence est atteinte à l'itération %d\n", k);
}

