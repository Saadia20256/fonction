#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOTS 200
#define MAX_TAILLE_MOT 50
#define MAX_TEXTE 2000

typedef struct {
    char mot[MAX_TAILLE_MOT];
    int occurrences;
    int longueur;
    int positions[100];
    int nombrePositions;
} Mot;

Mot dictionnaire[MAX_MOTS];
int nombreMots = 0;


void nettoyer_Mot(char *mot) {
    char temporaire[MAX_TAILLE_MOT];
    int indexTemp = 0;
    for(int index=0; mot[index]; index++){
        if(isalpha((unsigned char)mot[index]))
            temporaire[indexTemp++] = tolower((unsigned char)mot[index]);
    }
    temporaire[indexTemp]='\0';
    strcpy(mot,temporaire);
}
while (choix != 0);

int chercherMot(char *mot) {
    for(int i=0;i<nombreMots;i++)
        if(strcmp(dictionnaire[i].mot,mot)==0) return i;
    return -1;
}


void analyser_Texte(char *texte) {
    char *motCourant = strtok(texte," \t\n");
    int positionActuelle = 1;
    while(motCourant){
        nettoyer_Mot(motCourant);
        if(strlen(motCourant)>0){
            int index = chercherMot(motCourant);
            if(index==-1){
                strcpy(dictionnaire[nombreMots].mot,motCourant);
                dictionnaire[nombreMots].occurrences = 1;
                dictionnaire[nombreMots].longueur = strlen(motCourant);
                dictionnaire[nombreMots].positions[0] = positionActuelle;
                dictionnaire[nombreMots].nombrePositions = 1;
                nombreMots++;
            } else {
                dictionnaire[index].occurrences++;
                dictionnaire[index].positions[dictionnaire[index].nombrePositions++] = positionActuelle;
            }
        }
        positionActuelle++;
        motCourant = strtok(NULL," \t\n");
    }
    printf("Analyse terminée (%d mots uniques)\n", nombreMots);
}

void afficher_Dictionnaire() {
    printf("\n--- Dictionnaire ---\n");
    for(int i=0;i<nombreMots;i++){
        printf("%s (%d) longueur=%d positions:",dictionnaire[i].mot,dictionnaire[i].occurrences,dictionnaire[i].longueur);
        for(int j=0;j<dictionnaire[i].nombrePositions;j++)
            printf("%d ",dictionnaire[i].positions[j]);
        printf("\n");
    }
}

void rechercher_MotExact(char *mot) {
    nettoyer_Mot(mot);
    int index = chercherMot(mot);
    if(index==-1) 
    printf("Mot non trouvé.\n");
    else
     printf("%s trouvé %d fois, longueur=%d\n",dictionnaire[index].mot,dictionnaire[index].occurrences,dictionnaire[index].longueur);
}

void rechercher_MotPartiel(char *mot) {
    nettoyer_Mot(mot);
    int trouve = 0;
    for(int i=0;i<nombreMots;i++)
        if(strstr(dictionnaire[i].mot,mot)){
            printf("%s (%d)\n",dictionnaire[i].mot,dictionnaire[i].occurrences);
            trouve=1;
        }
    if(!trouve)
     printf("Aucun mot trouvé\n");
}


void afficher_Statistiques() {
    int totalMots=0,longueurMax=0,longueurMin=999,maxOccurrence=0;
    char *motLePlusLong="",*motLePlusCourt="",*motLePlusFrequent="";
    for(int i=0;i<nombreMots;i++){
        totalMots += dictionnaire[i].occurrences;
        if(dictionnaire[i].longueur > longueurMax){
            longueurMax=dictionnaire[i].longueur; motLePlusLong=dictionnaire[i].mot;
        }
        if(dictionnaire[i].longueur < longueurMin){
            longueurMin=dictionnaire[i].longueur; motLePlusCourt=dictionnaire[i].mot;
        }
        if(dictionnaire[i].occurrences > maxOccurrence){
            
            maxOccurrence=dictionnaire[i].occurrences; motLePlusFrequent=dictionnaire[i].mot;
        }
    }
    printf("\n--- Statistiques ---\n");
    printf("Total de mots: %d\n",totalMots);
    printf("Nombre de mots uniques: %d\n",nombreMots);
    printf("Longueur moyenne: %.2f\n",totalMots/(float)nombreMots);
    printf("Mot le plus long: %s / Mot le plus court: %s / Mot le plus fréquent: %s\n",motLePlusLong,motLePlusCourt,motLePlusFrequent);
}


int estPalindrome(char *mot){
    int longueur = strlen(mot);
    for(int i=0;i<longueur/2;i++)
        if(mot[i] != mot[longueur-1-i]) return 0;
    return 1;
}

