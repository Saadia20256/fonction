#include <stdio.h>
#include <string.h>

void supprimer_ponctuation(char *texte) {
    int i = 0, j = 0;
    char resultat[100];  

    while (texte[i] != '\0') {
        if (texte[i] != '.' && texte[i] != ',' && texte[i] != '!' &&
            texte[i] != '?' && texte[i] != ';' && texte[i] != ':') {
            resultat[j] = texte[i];
            j++;
        }
        i++;
    }

    resultat[j] = '\0';       
    strcpy(texte, resultat);   
}

int main() {
    char texte[] = "Le chat noir dort. Le chien joue !";

    supprimer_ponctuation(texte);

    printf("Texte sans ponctuation: %s\n", texte);

    return 0;
}

   

    