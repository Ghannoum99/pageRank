#ifndef GHANNOUM_H
#define GHANNOUM_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct MATRICE
{
	int taille;
	double** tab_mat;
}MATRICE;

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
MATRICE allouer_matrice_carree(int taille);
MATRICE generer_matrice_aleatoire(MATRICE mat);
MATRICE generer_matrice_adj(MATRICE mat);
void afficher_matrice(MATRICE mat);
void desallouer_matrice_carree(MATRICE mat);
VECTEUR multiplier_mat_vect(MATRICE mat, VECTEUR vect, VECTEUR vectRes);
void pageRank(MATRICE mat_adj, double alpha, double tolerance);

#endif