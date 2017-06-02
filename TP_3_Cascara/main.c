#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
EMovie* new_movie();
int main()
{
    EMovie* peliculas;
    FILE *pFile;
    char seguir='s';
    int opcion=0;

    pFile=fopen("Peliculas.bin","wb+");

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

            peliculas=new_movie();

            fprintf(pFile, "%s--%s--%d--%s--%d",peliculas->titulo,peliculas->genero,peliculas->duracion,peliculas->descripcion,peliculas->puntaje);

                break;
            case 2:
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    fclose(pFile);
    return 0;
}
EMovie* new_movie()
{

   char titulo[20];
   char descripcion[50];
   char genero[20];
   int duracion;
   int puntaje;
   int id;


    EMovie* x=(EMovie*)malloc(sizeof(EMovie));
    if(x!=NULL)
    {
       printf("Ingrese la ID de la pelicula: ");
       scanf("%d",&id);
       printf("Ingrese el titulo de la pelicula: ");
       fflush(stdin);
       gets(titulo);
       while(isdigit(atoi(titulo))==1)
       {
           printf("Error, el titulo no puede contener letras, reingrese: ");
           gets(titulo);
       }
       printf("Ingrese el genero de la pelicula: ");
       fflush(stdin);
       gets(genero);
       printf("Ingrese la duracion de la pelicula en minutos: ");
       scanf("%d",&duracion);
       printf("Ingrese una breve descripcion de la pelicula: ");
       fflush(stdin);
       gets(descripcion);
       printf("Ingrese el puntaje de la pelicula: ");
       scanf("%d",&puntaje);

       x->id=id;
       strcpy(x->titulo,titulo);
       strcpy(x->genero,genero);
       x->duracion=duracion;
       strcpy(x->descripcion,descripcion);
       x->puntaje=puntaje;
       x->estado=1;
    }
    return x;
}
