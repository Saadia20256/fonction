#include <stdio.h>
#include <stdlib.h>

long long fibonacci (int n) {
    if (n==0) return 0 ;
    else if (n==1) return 1;
    else return fibonacci (n-1)+fibonacci(n-2);
}
int main () {
    int n ;
    printf("entrer un entier n pour calculer F(n) :");
    scanf("%d",&n);
    if (n<0){
        printf("fibonacci n'est pas defini pour les entiers negatifs .\n");
    }else {
        printf("F(%d)=%lld\n" , n, fibonacci(n));
    }
    return 0 ;
}