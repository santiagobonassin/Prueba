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
    int auxId,auxIdProyecto,auxHoras,flag=0,flag2=0,flag3=0,IDValidada;

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
    do{
        printf("Ingrese el ID del programador: ");
        scanf("%s",auxStringId);
        IDValidada=validarID(auxStringId);
    }while(IDValidada==1);
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
            do{
                printf("Ingrese el ID del proyecto: ");
                scanf("%s",auxStringIdProyecto);
                IDValidada=validarID(auxStringIdProyecto);
            }while(IDValidada==1);
            auxIdProyecto=atoi(auxStringIdProyecto);
            for(int j=0;j<tamp;j++)
            {
                if(auxIdProyecto==proyectos[j].idProyecto)
                {
                    flag3=1;
                    for(int k=0;k<tampp;k++)
                    {
                        if(pp[k].estado==0)
                        {
                            do{
                                printf("Ingrese la cantidad de horas: ");
                                scanf("%s",auxStringHoras);
                                IDValidada=validarID(auxStringHoras);
                                }while(IDValidada==1);
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
int validarID(char ID[])
{
   int i;

   int IDValido=0;

    for(i=0;i<strlen(ID);i++)
            {

                if(isdigit(ID[i])!=1)
                    {

                        printf("El numero ingresado no es valido, ");
                        IDValido=1;
                        break;
                    }


            }
return IDValido;
}
void organizar(eProgramador ingreso[])
 {
    int i;
    int j;
    int auxint;
    char auxstring [90];

    for(i=0; i<20-1; i++)
            {
                for(j=i+1; j<20; j++)
                {
                    if(ingreso[i].estado==1 && ingreso[j].estado==1)
                    {
                        if(ingreso[i].id>ingreso[j].id)
                        {
                            auxint = ingreso[i].id;
                            ingreso[i].id = ingreso[j].id;
                            ingreso[j].id = auxint;

                            strcpy(auxstring, ingreso[i].nombre);
                            strcpy(ingreso[i].nombre, ingreso[j].nombre);
                            strcpy(ingreso[j].nombre,auxstring);

                            strcpy(auxstring, ingreso[i].apellido);
                            strcpy(ingreso[i].apellido, ingreso[j].apellido);
                            strcpy(ingreso[j].apellido,auxstring);

                            auxint = ingreso[i].idCategoria;
                            ingreso[i].idCategoria = ingreso[j].idCategoria;
                            ingreso[j].idCategoria = auxint;

                            auxint = ingreso[i].estado;
                            ingreso[i].estado = ingreso[j].estado;
                            ingreso[j].estado = auxint;

                        }

                    }
                }
            }

  printf("Datos de las personas registradas:\n\n");

  for(i=0; i<20; i++)
     {
        if(ingreso[i].estado!=0)
            {

                printf("ID: %d\nNombre: %s\nApellido: %s\nID Categoria: %d\n\n", ingreso[i].id, ingreso[i].nombre, ingreso[i].apellido, ingreso[i].idCategoria);
            }

     }

 }
