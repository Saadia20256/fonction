#include <stdio.h>
#include <string.h>

struct livre 
{
    char titre [60];
    char auteur [60];
    int annee ; 
};

   struct livre creelivre (char titre[], char auteur[], int annee)
   {
    struct livre livre ;

    strcpy (livre.titre, titre);
    strcpy (livre.auteur, auteur);
    livre.annee =annee ;
    return livre ;
   }
int main ()

{
    struct livre monlivre = creelivre ("the richest man in babylon","george s.clason",1992);

    printf("titre:%s\n", monlivre.titre);
    printf("auteur:%s\n", monlivre.auteur);
    printf("annee de publication:%d\n", monlivre.annee );

    return 0 ;
}