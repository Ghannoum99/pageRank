#ifndef GHANNOUM_H
#define GHANNOUM_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct MATRICE_CARREE
{
	int taille;
	double** tab_mat;
}MATRICE_CARREE;

typedef struct VECTEUR
{
	int taille;
	double* tab_vect;
}VECTEUR;

VECTEUR allouer_vecteur(int taille);
void afficher_vecteur(VECTEUR vect);
VECTEUR generer_vecteur_aleatoire(VECTEUR vect);
double normaliser_vecteur(VECTEUR vect);
void desallouer_vecteur(VECTEUR vect);
MATRICE_CARREE allouer_matrice_carree(int taille);
MATRICE_CARREE generer_matrice_aleatoire(MATRICE_CARREE mat);
void afficher_matrice(MATRICE_CARREE mat);
void desallouer_matrice_carree(MATRICE_CARREE mat);
VECTEUR multiplier_mat_vect(MATRICE_CARREE mat, VECTEUR vect, VECTEUR vectRes);
void pageRank(MATRICE_CARREE mat_adj, double alpha, double tolerance);

#endif