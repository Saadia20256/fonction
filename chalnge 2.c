#include <stdio.h>
#include <stdlib.h>

 
   int max(int a ,int b)
   {
    int max = 0 ;
    if(a > b)
    {
        max = a ;
        printf("les max entr %d et %d est :%\n" ,a ,b,max);
    }
    else if (a < b)
    {
        max = b ;
        printf("le max enttre %d et %d est :%d\n" , a,b,max);
    }
    else if (a==b)
    {
        printf("la valeur de a:%d egale la valeur de b :%d\n", a, b);
    }
    }
    int main () 
    {
    max (5,4);
    max(1,1);
    max(7,9);
    return 0 ;
    }