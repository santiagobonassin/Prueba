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
void derivarProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador pp[],int tam,int tamp, int tampp)
{

    char auxStringId[100],auxStringIdProyecto[100],auxStringHoras[100];
    int auxId,auxIdProyecto,auxHoras,flag=0,flag2=0,flag3=0;

    for(int i=0; i<tam;i++)
    {
        if(programadores[i].estado==1)
        {
            if(!flag)
                printf("ID\t\tNombre\t\tApellido\t\tCategoria 1-J 2-SS 3-S\n");
            printf("%d\t\t%s\t\t%s\t\t\t%d\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido,programadores[i].idCategoria);
            flag=1;
        }

    }
    printf("Ingrese el ID del programador: ");
    gets(auxStringId);

    while(isalpha(auxStringId)==1)
    {
        printf("Error, reingrese: ");
        gets(auxStringId);
    }
    auxId=atoi(auxStringId);

    for(int i=0;i<tam;i++)
    {
        if(auxId==programadores[i].id && programadores[i].estado==1)
        {
            flag2=1;
            for(int j=0;j<tamp;j++)
            {
                if(proyectos[j].idProyecto!=-1)
                {
                    printf("%d\t%s\n",proyectos[j].idProyecto,proyectos[j].nombre);
                }
            }
            printf("Ingrese el ID del proyecto: ");
            gets(auxStringIdProyecto);

            while(isalpha(auxStringIdProyecto)==1)
                {
                    printf("Error, reingrese: ");
                    gets(auxStringIdProyecto);
                }
            auxIdProyecto=atoi(auxStringIdProyecto);
            for(int j=0;j<tamp;j++)
            {
                if(auxStringIdProyecto==proyectos[j].idProyecto)
                {
                    flag3=1;
                    for(int k=0;k<tampp;k++)
                    {
                        if(pp[k].idProgramador==-1 && pp[k].idProyecto==-1)
                        {
                            printf("Ingrese hhoras de trabajo: ");
                            gets(auxStringHoras);

                            while(isalpha(auxStringHoras)==1)
                                {
                                    printf("Error, reingrese: ");
                                    gets(auxStringHoras);
                                }
                                auxHoras=atoi(auxStringHoras);
                                pp[k].idProgramador=auxId;
                                pp[k].idProyecto=auxIdProyecto;
                                pp[k].horas=auxHoras;
                                break;
                        }
                    }
                }
            }
        }
    }
    if(!flag2)
    {
        printf("No se encontro el ID del programador");
    }
    if(!flag3)
    {
        printf("No se encontro el ID del proyecto");
    }

}


