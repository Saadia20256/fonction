#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXM 2000
#define MAXLEN 50
#define MAXTXT 2000

typedef struct {
    char mot[MAXLEN];
    int occ;
    int len;
    int pos[100];
    int nbp;
} Mot;

Mot tab[MAXM];
int nb = 0;

void clean(char *m) {
    int i=0,j=0;
    char tmp[MAXLEN];
    while(m[i]) {
        if(isalpha((unsigned char)m[i])) {
            tmp[j++] = tolower((unsigned char)m[i]);
        }
        i++;
    }
    tmp[j] = '\0';
    strcpy(m,tmp);
}

int cherche(char *m) {
    for(int i=0;i<nb;i++){
        if(strcmp(tab[i].mot,m)==0) return i;
    }
    return -1;
}

void analyse(char *txt) {
    char *tok = strtok(txt," \t\n");
    int pos = 1;
    while(tok){
        clean(tok);
        if(strlen(tok)>0){
            int i = cherche(tok);
            if(i==-1){
                strcpy(tab[nb].mot,tok);
                tab[nb].occ = 1;
                tab[nb].len = strlen(tok);
                tab[nb].pos[0] = pos;
                tab[nb].nbp = 1;
                nb++;
            } else {
                tab[i].occ++;
                tab[i].pos[tab[i].nbp++] = pos;
            }
        }
        pos++;
        tok = strtok(NULL," \t\n");
    }
    printf("DEBUG: analyse ok (nb=%d)\n", nb);
}

void affiche() {
    printf("=== LISTE MOTS ===\n");
    for(int i=0;i<nb;i++){
        printf("%s (%d) len=%d pos:",tab[i].mot,tab[i].occ,tab[i].len);
        for(int j=0;j<tab[i].nbp;j++) printf("%d ",tab[i].pos[j]);
        printf("\n");
    }
}

void rech(char *m) {
    clean(m);
    int i = cherche(m);
    if(i!=-1)
        printf("Trouvé: %s occ=%d len=%d\n",tab[i].mot,tab[i].occ,tab[i].len);
    else
        printf("Non trouvé.\n");
}

void rech_part(char *m) {
    clean(m);
    printf("partiel: %s\n",m);
    int f=0;
    for(int i=0;i<nb;i++){
        if(strstr(tab[i].mot,m)){
            printf("%s (%d)\n",tab[i].mot,tab[i].occ);
            f=1;
        }
    }
    if(!f) printf("rien trouvé.\n");
}

void stats() {
    int tot=0,maxL=0,minL=999,maxO=0;
    char *pl=NULL,*pc=NULL,*pf=NULL;
    for(int i=0;i<nb;i++){
        tot += tab[i].occ;
        if(tab[i].len>maxL){maxL=tab[i].len; pl=tab[i].mot;}
        if(tab[i].len<minL){minL=tab[i].len; pc=tab[i].mot;}
        if(tab[i].occ>maxO){maxO=tab[i].occ; pf=tab[i].mot;}
    }
    printf("total:%d uniques:%d moy:%.2f\n",tot,nb,tot/(float)nb);
    printf("long:%s court:%s freq:%s\n",pl,pc,pf);
}

int main(){
    char txt[MAXTXT];
    char m[MAXLEN];
    int ch;

    do{
        printf("\n1-analyser\n2-afficher\n3-rech exacte\n4-rech partielle\n5-stats\n0-quitter\n> ");
        scanf("%d",&ch); getchar();

        if(ch==1){
            printf("texte:\n");
            fgets(txt,MAXTXT,stdin);
            analyse(txt);
        } 
        else if(ch==2){
            affiche();
        }
        else if(ch==3){
            printf("mot: ");
            scanf("%s",m);
            rech(m);
        }
        else if(ch==4){
            printf("mot: ");
            scanf("%s",m);
            rech_part(m);
        }
        else if(ch==5){
            stats();
        }
    }while(ch!=0);

    return 0;
}


        
