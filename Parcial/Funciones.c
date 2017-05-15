#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <string.h>
#include<conio.h>
#include <ctype.h>



void tomarDato(eProgramador plantilla[])
{

    int flag=0;
    char auxstring[35];
    char auxstring2[35];
int i;

            for(i=0; i<5; i++)
            {
                if(plantilla[i].estado==0)
                {
                    printf("Ingrese ID: ");
                    scanf("%d", &plantilla[i].id);
                    printf("Ingrese categoria: ");
                    scanf("%d", &plantilla[i].idCategoria);
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(auxstring);
                     while(strlen(auxstring)>19)
                        {
                            printf("Error, el nombre es demasiado largo, reingrese el dato: ");
                            gets(auxstring);
                        }
                    strcpy(plantilla[i].nombre,auxstring);

                    printf("Ingrese apellido: ");
                    fflush(stdin);
                    gets(auxstring2);
                    while(strlen(auxstring2)>19)
                        {
                            printf("Error, el nombre es demasiado largo, reingrese el dato: ");
                            gets(auxstring2);
                        }
                    strcpy(plantilla[i].apellido,auxstring2);


                    plantilla[i].estado = 1;
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                printf("No hay espacio!\n");
            }

}
void eliminarProgramador(eProgramador plantilla[])
{
    int flag =0;
    int auxInt;
    char respuesta;
    int i;

            printf("Ingrese la ID del programador a eliminar del registro: ");
            scanf("%d", &auxInt);

            for(i=0; i<5; i++)
            {
                if(plantilla[i].estado==1 && auxInt == plantilla[i].id)
                {
                    printf("%d--%s--%s--%d\n", plantilla[i].id, plantilla[i].nombre, plantilla[i].apellido,plantilla[i].idCategoria);

                    printf("Esta seguro de eliminar el programador del registro? s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                       plantilla[i].estado = 0;
                    }
                    else
                    {
                        printf("Accion cancelada!");
                    }
                    flag=1;
                    break;

                }
            }

            if(flag==0)
            {
                printf("ID inexistente");
            }

}
void modificarProgramador(eProgramador plantilla[])
{
    int flag =0;
    int auxInt;
    char respuesta;
    int i;

            printf("Ingrese la ID del registro a modificar: ");
            scanf("%d", &auxInt);

            for(i=0; i<5; i++)
            {
                if(plantilla[i].estado==1 && auxInt == plantilla[i].id)
                {
                    printf("%d--%s--%s--%d\n", plantilla[i].id, plantilla[i].nombre, plantilla[i].apellido,plantilla[i].idCategoria);
                    printf("Ingrese la nueva categoria: ");
                    scanf("%d", &auxInt);
                    printf("Esta seguro de realizar la modificacion? s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        plantilla[i].idCategoria = auxInt;
                    }
                    else
                    {
                        printf("Accion cancelada!");
                    }
                    flag=1;
                    break;

                }
            }

            if(flag==0)
            {
                printf("ID inexistente");
            }
}
void cargarCategoria(eCategoria clase[])
{
    int id[3] = {1,2,3};
    char nombres[3][30]= {"Junior","Semi Senior","Senior"};
    int estado[3]= {1,1,1};

    int salarioPorHora[3]={500,1000,1500};
    int i;

    for(i=0; i<3; i++)
    {
        clase[i].id = id[i];
        strcpy(clase[i].descripcion, nombres[i]);
        clase[i].pagoXhora = salarioPorHora[i];
        clase[i].estado = estado[i];
    }

}
void cargarProyectos(eProyecto proyecto[])
{
    int idProyecto[3]= {100,101,102};
    char titulo[3][30]= {"Proyecto Aura Sync","Proyecto Aorus","Proyecto Scorpio"};
    int estado[3]= {1,1,1};
    int i;
    for(i=0; i<5; i++)
    {
        proyecto[i].idProyecto = idProyecto[i];
        strcpy(proyecto[i].nombre, titulo[i]);
        proyecto[i].estado = estado[i];
    }

}
void derivarProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador ProyectosporProgramador[])
{
    int i;
    int j;
    int l;
    int auxint;
    int auxint2;

    for(i=0;i<5;i++)
    {
        printf("ID: %d\nNombre: %s\nApellido: %s\nCategoria:\n\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido,programadores[i].idCategoria);

    }
    for(i=0;i<3;i++)
    {
       printf("\nProyecto: %s\nID: %d\n\n",proyectos[i].nombre,proyectos[i].idProyecto);
    }

    printf("Ingrese ID de programador:");
    scanf("%d",&auxint);

    printf("Ingrese ID de proyecto:");
    scanf("%d",&auxint2);

    for(i=0;i<20;i++)
    {
        if(auxint==programadores[i].id)
        {
           for(j=0;j<3;j++)
            {
                if(auxint2==proyectos[j].idProyecto)
                {
                    for(l=0;l<10;l++)
                    {
                        if()
                        {
                            ProyectosporProgramador[l].idProgramador=auxint;
                            ProyectosporProgramador[l].idProyecto=auxint2;
                            printf("Ingrese la cantidad de horas de trabajo del programador: ");
                            scanf("%d",&ProyectosporProgramador[l].horas);

                            ProyectosporProgramador[l].estado=1;

                            break;
                        }
                    }
                }
            }
        }

    }
}


