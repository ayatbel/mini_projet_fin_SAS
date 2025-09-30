#ifndef HEADER_H
#define HEADER_H
#include "fonctions.c"




void ajouterAvion();
void afficherAvions();
int rechercherAvionParId(int id);
int rechercherAvionParModele(char modele[]);
void modifierAvion();
void supprimerAvion();

#endif