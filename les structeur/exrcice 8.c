#include<stdio.h>
#include<string.h>

struct cercle 
{
    float rayon ;
};
float aire(struct cercle c)
{
  const float pi=3.14 ; 
  return pi*c.rayon*c.rayon ; 
}
int main ()
{
    struct cercle cercle ;

    printf("entrer le rayon du cercle :");
    scanf("%f",&cercle.rayon);

    float aircircel=aire(cercle);
    printf("l'aire du cercle est :%.2f\n",aircircel);

    return 0 ;
}

    