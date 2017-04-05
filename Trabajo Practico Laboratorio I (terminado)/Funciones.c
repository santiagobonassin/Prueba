#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void suma(float x,float y)
{
    float resultado;
    resultado = x + y;
    printf("El resultado de la suma entre %.2f y %.2f es %.2f \n",x,y,resultado);
}

void resta(float x,float y)
{
    float resultado;
    resultado = x - y;
    printf("El resultado de la resta entre %.2f y %.2f es %.2f \n",x,y,resultado);
}

void division(float x,float y)
{
    float resultado;
    while(y==0)
    {
        printf("Error, no es posible dividir por 0, ingrese otro numero: ");
        scanf("%f",&y);
    }
    resultado = x / y;
    printf("El resultado de la division entre %.2f y %.2f es %.2f \n",x,y,resultado);
}

void multiplicacion(float x,float y)
{
    float resultado;
    resultado = x * y;
    printf("El resultado de la multiplicacion entre %.2f y %.2f es %.2f \n",x,y,resultado);
}


void factorial (float x)
{
    int factorial = 1;
    int i;
    int aux=(int)x;
    while(x<0 || (x-aux)!=0)
            {
                printf("Error, imposible calcular el factorial, ingrese un numero natural: ");
                scanf("%f",&x);
                aux=(int)x;
            }

            for(i=1;i<=aux;i++)
            {
                factorial = factorial * i;
            }

            printf("El factorial de %d es %d \n",aux,factorial);

}
