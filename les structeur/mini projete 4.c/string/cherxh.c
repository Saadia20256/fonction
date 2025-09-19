#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOTS 200
#define LENG_MOTS 50
#define MAX_TEXTE 2000

typedef struct {
    char mots[LENG_MOTS];
    int occ;           
    int len;           
    int Tpo[100];      
    int posi;          
} mots;

mots dictionnaire[MAX_MOTS];
int nb_mots = 0;


void nettoyer_Mot(char *mot);
void ajouter_Mot(char *mot, int position);
void analyser_Texte(char *texte);
void afficher_Dictionnaire();
void recherche_Exacte();



void nettoyer_Mot(char *mot) {
    char tmp[LENG_MOTS];
    int j = 0;
    for (int i = 0; mot[i] != '\0'; i++) {
        if (isalpha((unsigned char)mot[i])) {
            tmp[j++] = tolower((unsigned char)mot[i]);
        }
    }
    tmp[j] = '\0';
    strcpy(mot, tmp);
}

void ajouter_Mot(char *mot, int position) {
    for (int i = 0; i < nb_mots; i++) {
        if (strcmp(dictionnaire[i].mots, mot) == 0) {
            if (dictionnaire[i].posi < 100)
                dictionnaire[i].Tpo[dictionnaire[i].posi++] = position;
            dictionnaire[i].occ++;
            return;
        }
    }

    if (nb_mots < MAX_MOTS) {
        strcpy(dictionnaire[nb_mots].mots, mot);
        dictionnaire[nb_mots].occ = 1;
        dictionnaire[nb_mots].len = strlen(mot);
        dictionnaire[nb_mots].Tpo[0] = position;
        dictionnaire[nb_mots].posi = 1;
        nb_mots++;
    } else {
        printf("Attention: nombre maximum de mots atteint!\n");
    }
}

void analyser_Texte(char *texte) {
    char *mot = strtok(texte, " ,.;:!?()\n\t");
    int position = 1;
    while (mot != NULL) {
        nettoyer_Mot(mot);
        if (strlen(mot) > 0) {
            ajouter_Mot(mot, position);
            position++;
        }
        mot = strtok(NULL, " ,.;:!?()\n\t");
    }
}

void afficher_Dictionnaire() {
    printf("\n--- Dictionnaire ---\n");
    for (int i = 0; i < nb_mots; i++) {
        printf("%s | occurrences: %d | longueur: %d | positions: ", 
                dictionnaire[i].mots, dictionnaire[i].occ, dictionnaire[i].len); 
        for (int j = 0; j < dictionnaire[i].posi; j++)
            printf("%d ", dictionnaire[i].Tpo[j]);
        printf("\n");
    }
}

void recherche_Exacte() {
    char m_rechercher[LENG_MOTS];
    printf("Entrer le mot à rechercher (exact): ");
    scanf("%49s", m_rechercher);
    getchar(); 
    nettoyer_Mot(m_rechercher);

    int trouve = 0;
    for (int i = 0; i < nb_mots; i++) {
        if (strcmp(dictionnaire[i].mots, m_rechercher) == 0) {
            printf("Mot trouvé: %s\nOccurrence: %d\nLongueur: %d\nPositions: ",
                    dictionnaire[i].mots, dictionnaire[i].occ, dictionnaire[i].len); 
            for (int j = 0; j < dictionnaire[i].posi; j++)
                printf("%d ", dictionnaire[i].Tpo[j]);
            printf("\n\n");
            trouve = 1;
            break;
        }
    }
    if (!trouve) 
        printf("Mot '%s' non trouvé.\n", m_rechercher);
}

int main() {
    char texte[MAX_TEXTE];
    int choix;

    while (1) {
        printf("\n=== Menu ===\n");
        printf("1. Saisir un texte et analyser\n");
        printf("2. Afficher tous les mots (dictionnaire)\n");
        printf("3. Rechercher un mot exact\n");
        printf("4. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar();

        switch(choix) {
            case 1:
                printf("Entrez le texte:\n");
                fgets(texte, MAX_TEXTE, stdin);
                analyser_Texte(texte);
                break;
            case 2:
                afficher_Dictionnaire();
                break;
            case 3:
                recherche_Exacte();
                break;
            case 4:
                printf("Au revoir!\n");
                return 0;
            default:
                printf("Choix invalide!\n");
        }
    }

    return 0;
}

