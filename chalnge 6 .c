#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inverse_chaine (char str[]){
    int debut =0 ;
    int fin =strlen(str)-1 ;
    char temp ;

    while( debut < fin) {
        temp = str[debut] ;
        str[debut] = str[fin] ;
        str[fin] = temp ;

        debut ++ ;
        fin -- ;
    }
}
int main () {
    char texte [100];
    printf("entrer une chaine :") ;
    scanf ("%s",texte) ;

    inverse_chaine (texte);

    printf("chaine inversee :%s\n" , texte);
    return 0 ;
}