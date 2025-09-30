#include <stdio.h>
#include "header.h"

int main() {
    int choix;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Ajouter avion\n");
        printf("2. Afficher avions\n");
        printf("3. Modifier avion\n");
        printf("4. Supprimer avion\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterAvion(); break;
            case 2: afficherAvions(); break;
            case 3: modifierAvion(); break;
            case 4: supprimerAvion(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
