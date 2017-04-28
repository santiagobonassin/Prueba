#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    EPersona cliente[20];
    int i;
    int index;
    int contadorMenorA18=0;
    int contadorEntre19y35=0;
    int contadorMayorA35=0;

    for(i=0; i<20; i++)
    {
        cliente[i].estado=0;
    }

    int continuar=1;
    int opcion=0;

    while(continuar==1)
    {
        printf("Elija una opcion:\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
         case 1:

         index=tomarDato(cliente);

         if(cliente[index].edad<18)
         {
            contadorMenorA18++;
         }
         else
         {
             if(cliente[index].edad>18 && cliente[index].edad<=35)
             {
                 contadorEntre19y35++;
             }
             else
             {
                 contadorMayorA35++;
             }
         }

         break;

         case 2:

         borrarPersona(cliente);

         break;

         case 3:

         organizar(cliente);

         break;

         case 4:

         grafico(contadorMenorA18, contadorEntre19y35, contadorMayorA35);

         break;

         case 5:

         continuar=0;

         break;

         default:

         printf("Opcion seleccionada incorrecta, porfavor ingrese una accion valida\n");

        }
    }

    return 0;
}
