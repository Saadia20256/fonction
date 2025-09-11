#include<stdio.h>
#include<string.h>

struct produit 
{
    char nom[60];
    float prix ;
    int quantite ;
};

int main ()
{
    int n;
    printf("entrer le nombre de produits :");
    scanf("%d",&n);

    struct produit produits[n];

    for (int i = 0 ; i < n ;i++)
    {
        printf("\nproduit %d\n" , i+1);

        printf("entrer le nom du produit :");
        scanf("%s",produits[i].nom);

        printf("entrer le prix du produit :");
        scanf("%f",produits[i].prix);

        printf("entrer le quantite du produit :");
        scanf("%d",produits[i].quantite);
    }
    printf("\ninformations des produits :\n");
    for(int i=0 ; i < n ; i++)
    {
        printf("\nproduit %d\n",i+1);
        printf("nom:%s\n",produits[i].nom);
        printf("prix:%f\n",produits[i].prix);
        printf("quantite:%d\n",produits[i].quantite);
    }
    return 0 ;
}