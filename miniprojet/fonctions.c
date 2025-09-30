#include <stdio.h>
#include <string.h>
#define MAX_AVIONS 100   

struct Date {
    int jour;
    int mois;
    int annee;
};

struct Avion {
    int idAvion;
    char modele[50];
    int capacite;
    char statut[20];
    struct Date dateEntree;
};
 struct Avion flotte[MAX_AVIONS];
int nbAvions = 0;
int nextId = 1;

void ajouterAvion() {
    if (nbAvions >= MAX_AVIONS) {
        printf("Flotte pleine !\n");
        return;
    }
    struct Avion a;
    a.idAvion = nextId++;

    printf("Modèle : ");
    scanf(" %[^\n]", a.modele);
    printf("Capacité : ");
    scanf("%d", &a.capacite);
    printf("Statut : ");
    scanf(" %[^\n]", a.statut);
    printf("Date (jour mois année) : ");
    scanf("%d %d %d", &a.dateEntree.jour, &a.dateEntree.mois, &a.dateEntree.annee);

    flotte[nbAvions++] = a;
    printf("Avion ajouté (ID=%d)\n", a.idAvion);
}

void afficherAvions() {
    if (nbAvions == 0) {
        printf("Aucun avion enregistré.\n");
        return;
    }
    for (int i = 0; i < nbAvions; i++) {
        struct Avion a = flotte[i];
        printf("ID:%d | %s | Capacité:%d | Statut:%s | %02d/%02d/%04d\n",
               a.idAvion, a.modele, a.capacite, a.statut,
               a.dateEntree.jour, a.dateEntree.mois, a.dateEntree.annee);
    }
}

int rechercherAvionParId(int id) {
    for (int i = 0; i < nbAvions; i++) {
        if (flotte[i].idAvion == id) return i;
    }
    return -1;
}

void modifierAvion() {
    int id;
    printf("ID avion à modifier : ");
    scanf("%d", &id);
    int idx = rechercherAvionParId(id);
    if (idx == -1) {
        printf("Avion introuvable.\n");
        return;
    }
    printf("Nouveau modèle : ");
    scanf(" %[^\n]", flotte[idx].modele);
    printf("Nouvelle capacité : ");
    scanf("%d", &flotte[idx].capacite);
    printf("Nouveau statut : ");
    scanf(" %[^\n]", flotte[idx].statut);
    printf("Avion modifié.\n");
}

void supprimerAvion() {
    int id;
    printf("ID avion à supprimer : ");
    scanf("%d", &id);
 int idx = rechercherAvionParId(id);
    if (idx == -1) {
        printf("Avion introuvable.\n");
        return;
    }
    for (int i = idx; i < nbAvions - 1; i++) {
        flotte[i] = flotte[i + 1];
    }
    nbAvions--;
    printf("Avion supprimé.\n");
}
void trierParCapacite() {
    for (int i = 0; i < nbAvions - 1; i++) {
        for (int j = 0; j < nbAvions - i - 1; j++) {
            if (flotte[j].capacite > flotte[j + 1].capacite) {
                struct Avion temp = flotte[j];
                flotte[j] = flotte[j + 1];
                flotte[j + 1] = temp;
            }
        }
    }
        printf(" Les avions ont été triés par capacité.\n");
    }
                