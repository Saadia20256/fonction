#include <stdio.h>
#include <string.h>

struct personne 
{
    char nom[20] ;
    char prenom [20] ;
    int age  ;
}personne ;

int main () {
    strcpy (personne .nom ,"haddach");
    strcpy (personne .prenom , "saadia") ;
    personne. age = 30 ;

    printf("\n nom :%s\n  prenom :%s\n age:%d\n\n", personne.nom , personne.prenom , personne.age);
    return 0 ;
}