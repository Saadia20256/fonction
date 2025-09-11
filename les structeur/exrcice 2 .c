#include <stdio.h>
#include <string.h>

struct etudiant 
{
    char nom [20] ;
    char prenom [20] ;
    float note [3] ;
} etudiant ;
int main () {
    strcpy (etudiant.nom , "haddach");
    strcpy (etudiant.prenom ,"saadia");
    etudiant.note[0]=3 ;
    etudiant.note[1]=5 ;
    etudiant.note[2]=18 ;
    
    printf("\n nom:%s\n prenom:%s\n" , etudiant.nom , etudiant.prenom);
    printf("note:");

    for(int i=0 ;i<=3 ;i++) {
        printf("%.2f\n",etudiant.note[i]);
    }
    
    return 0 ;
}