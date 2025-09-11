#include<stdio.h>
#include<string.h>

struct Compte 
{
    char nom[60];
    float solde ;
};
  void ajouterMontant(struct Compte *c, float montant) {
    c->solde += montant;
}
int main () 
{
    struct Compte client ;
    
     strcpy(client.nom, "Paul");
     client.solde = 1000.0;

    printf("Avant ajout : %s a %.2f euros\n", client.nom, client.solde);

    ajouterMontant(&client, 300.0);

    printf("Après ajout : %s a %.2f euros\n", client.nom, client.solde);

    return 0;
}
  
