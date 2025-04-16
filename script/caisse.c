#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Déclaration des constantes pour les billets et pièces
const double denominations[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.5, 0.2, 0.05};
const int denomination_count = sizeof(denominations) / sizeof(denominations[0]);

// Fonction pour générer un montant aléatoire
double generate_random_amount() {
    return (rand() % 100000) / 100.0; // Génère un montant entre 0 et 999.99
}

int main() {
    srand(time(NULL)); // Initialisation de la graine aléatoire

    // Générer un montant aléatoire à payer
    double amount_to_pay = generate_random_amount();
    printf("Montant à payer: Rs%.2f\n", amount_to_pay);

    // Demander à l'utilisateur d'entrer la valeur donnée
    double given_amount;
    do {
        printf("Entrez la valeur donnée: ");
        scanf("%lf", &given_amount);
        if (given_amount < amount_to_pay) {
            printf("Vous devez donner au moins Rs%.2f\n", amount_to_pay);
        }
    } while (given_amount < amount_to_pay);

    return 0;
}
