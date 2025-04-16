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

    // Initialiser le tableau change
    int change[denomination_count] = {};

    // Calculer la monnaie à rendre
    calcule_monnaie(amount_to_pay, given_amount, change);

    // Afficher la monnaie à rendre
    printf("Monnaie à rendre:\n");
    for (int i = 0; i < denomination_count; i++) {
        if (change[i] > 0) {
            printf("%d x Rs%.2f\n", change[i], denominations[i]);
        }
    }

    return 0;
}

