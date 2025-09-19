#include<stdio.h>
#include<ctype.h>

int main (){
    char texte[]="bonjour le monde" ;
    int i ;
    while (texte[i] !=0) {  
        texte[i] = tolower(texte[i]) ;  
        i++;  
    }
    printf("texte en minscules: %s\n", texte) ;
        return 0 ;
}