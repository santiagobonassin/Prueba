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
void derivarProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador proyectoPorProgramador[],int tam,int tamp, int tampp)
{

    char auxStringId[100];
    char auxStringIdProyecto[100];
    char auxStringHoras[100];
    int auxId;
    int auxIdProyecto;
    int auxHoras;
    int flag=0;
    int flag2=0;
    int flag3=0;
    int IDValidada;
    int i;
    int j;
    int k;

    for(i=0; i<tam;i++)
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

    for(i=0;i<tam;i++)
    {
        if(auxId==programadores[i].id && programadores[i].estado==1)
        {
            flag2=1;
            for(j=0;j<tamp;j++)
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
            for(j=0;j<tamp;j++)
            {
                if(auxIdProyecto==proyectos[j].idProyecto)
                {
                    flag3=1;
                    for(k=0;k<tampp;k++)
                    {
                        if(proyectoPorProgramador[k].estado==0)
                        {
                            do{
                                printf("Ingrese la cantidad de horas: ");
                                scanf("%s",auxStringHoras);
                                IDValidada=validarID(auxStringHoras);
                                }while(IDValidada==1);
                                auxHoras=atoi(auxStringHoras);
                                proyectoPorProgramador[k].idProgramador=auxId;
                                proyectoPorProgramador[k].idProyecto=auxIdProyecto;
                                proyectoPorProgramador[k].horas=auxHoras;
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
    eProgramador auxiliar;

    for(i=0;i<50-1;i++)
    {
        for(j=i+1;j<50;j++)
        {
            if(ingreso[i].id>ingreso[j].id)
            {
                auxiliar=ingreso[i];
                ingreso[i]=ingreso[j];
                ingreso[j]=auxiliar;
            }
        }
    }
}

void listarProyectosdeProgramador(eProgramador programador[],eProyecto proyectos[],eProyecto_Programador proyectosPorProgramador[])
{
    int i;
    int j;
    int k;
    int auxID;

    for(i=0;i<4;i++)
    {
        printf("ID: %d\nNombre: %s\nApellido:%s\nID categoria: %d\n\n",programador[i].id,programador[i].nombre,programador[i].apellido,programador[i].idCategoria);
    }
       printf("Seleccione un ID para mostrar: ");
       scanf("%d",&auxID);

    for(i=0;i<4;i++)
    {
        if(auxID==programador[i].id)
        {
            for(j=0;j<10;j++)
            {
                if(programador[i].id==proyectosPorProgramador[j].idProgramador)
                {
                    for(k=0;k<3;k++)
                    {
                        if(proyectosPorProgramador[j].idProyecto==proyectos[k].idProyecto)
                        {
                           printf("\nID: %d\nNombre: %s\nApellido:%s\nID categoria: %d\n",programador[i].id,programador[i].nombre,programador[i].apellido,programador[i].idCategoria);
                            printf("%s\n",proyectos[k].nombre);
                        }
                    }
                }
            }
        }

    }

}

void proyectoMasGrande (eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador proyectosPorProgramador[],int tam, int tamp, int tampp)
{
    int max;
    int flag=0;
    int cantProg;
    int idMax;
    char nombreMaximo[50];
    int i;
    int j;

    for(i=0;i<tamp;i++)
    {
        cantProg=0;
        if(proyectos[i].idProyecto!=0)
        {
            for(j=0;j<tampp;j++)
            {
               if(proyectos[i].idProyecto==proyectosPorProgramador[j].idProyecto)
                    {
                        cantProg++;
                    }
            }
            if(!flag)
                {
                    max=cantProg;
                    idMax=proyectos[i].idProyecto;
                    strcpy(nombreMaximo,proyectos[i].nombre);
                    flag=1;
                }
        }
        if(cantProg>max)
        {
            max=cantProg;
            idMax=proyectos[i].idProyecto;
            strcpy(nombreMaximo,proyectos[i].nombre);
        }

    }
    printf("El proyecto %s (ID: %d)es el que cuenta con mas programadores con: %d\n",nombreMaximo,idMax,max);
}
