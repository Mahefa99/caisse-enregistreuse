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

// Fonction pour calculer la monnaie à rendre
void calcule_monnaie(double amount_to_pay, double given_amount, int *change, int *stock) {
    double change_amount = given_amount - amount_to_pay;
    for (int i = 0; i < denomination_count && change_amount > 0; i++) {
        int count = (int)(change_amount / denominations[i]);
        if (stock[i] >= count) {
            change[i] = count;
            stock[i] -= count;
            change_amount -= count * denominations[i];
        } else {
            change[i] = stock[i];
            stock[i] = 0;
            change_amount -= stock[i] * denominations[i];
        }
    }
}

// Fonction pour afficher l'état des stocks
void display_stock(int *stock) {
    printf("État des stocks:\n");
    for (int i = 0; i < denomination_count; i++) {
        printf("Rs%.2f: %d\n", denominations[i], stock[i]);
    }
}

int main() {
    srand(time(NULL)); // Initialisation de la graine aléatoire

    // Initialiser les stocks de billets et pièces
    int stock[denomination_count];
    for (int i = 0; i < denomination_count; i++) {
        stock[i] = 5; // Initialisation individuelle
    }

    while (1) {
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

        // Initialiser le tableau change
        int change[denomination_count] = {};

        // Calculer la monnaie à rendre
        calcule_monnaie(amount_to_pay, given_amount, change, stock);

        // Afficher la monnaie à rendre
        printf("Monnaie à rendre:\n");
        for (int i = 0; i < denomination_count; i++) {
            if (change[i] > 0) {
                printf("%d x Rs%.2f\n", change[i], denominations[i]);
            }
        }

        // Afficher l'état des stocks
        display_stock(stock);

        // Vérifier si les stocks sont suffisants pour continuer
        int total_stock = 0;
        for (int i = 0; i < denomination_count; i++) {
            total_stock += stock[i];
        }

        if (total_stock == 0) {
            printf("Vous ne pouvez plus rendre la monnaie.\n");
            printf("Souhaitez-vous fermer la caisse (F) ou remplir la caisse (R) ? ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'F' || choice == 'f') {
                break;
            } else if (choice == 'R' || choice == 'r') {
                // Remplir la caisse
                for (int i = 0; i < denomination_count; i++) {
                    stock[i] = 5; // Réinitialiser les stocks
                }
            }
        }
    }

    return 0;
}

