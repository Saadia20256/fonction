#include<stdio.h>
#include<string.h>

struct Rectangle 
{
    float longueur ;
    float largeur ;
} rectangle ;
    float aire (float longueur , float largeur) {
        return longueur * largeur ;
    }
int main () 
{
    printf("entrer la valeur de longueur :");
    scanf ("%f",&rectangle.longueur);

    printf("entrer la valeur de largeur :") ;
    scanf("%f",&rectangle.largeur);

    printf("l'aire = .2%f cn carre",aire(rectangle.longueur,rectangle.largeur));

    return 0 ;

}
   


