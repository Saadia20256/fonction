#include <stdio.h>
#include <stdlib.h>
 
int min(int a ,int b)
{
    int min =a ;
    if (a>b)
    {
        min =b ;
        printf("le min de %d et %d est : %d\n" , a ,b ,min);
    }
    else if (a<b)
    {
        min =a ;
        printf("le min de %d et %d est : %d\n" ,a , b , min);
    }
    else if (a==b)
    {
        printf("la valeur de a:%d egale la valeur de b :%d\n",a , b );
    }
}
    int main ()
    {
        min (1,2);
        min (2,4);
        min (3,3);
        return 0 ;
    }