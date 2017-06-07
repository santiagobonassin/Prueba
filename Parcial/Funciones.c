#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#include <string.h>
#include<conio.h>
#include <ctype.h>

void cargarprogramadores(eProgramador programadores[])
{
    int id[5] = {1,2,3,4,5};
    char nombres[5][30]= {"Juan","Pedro","Luis","Jose","Luciano"};
    char apellido[5][30]= {"Perez","Rodriguez","Gonzalez","Gutierrez","Peralta"};
    int estado[5]= {1,1,1,1,1};
    int idCategoria[5]={1,2,3,1,3};
    int i;

    for(i=0; i<5; i++)
    {
        programadores[i].id = id[i];
        strcpy(programadores[i].nombre, nombres[i]);
        strcpy(programadores[i].apellido, apellido[i]);
        programadores[i].estado = estado[i];
        programadores[i].idCategoria=idCategoria[i];
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
    int idProyecto[10]= {100,101,102,103,104,105,106,107,108,109};
    char titulo[10][30]= {"Proyecto Aura Sync","Proyecto Aorus","Proyecto Scorpio","Proyecto Slate","Proyecto NZXT Hue","Project Freelancer","Proyecto Xeon","Project Trheadripper","Proyecto X299","Proyecto X399"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};
    int i;
    for(i=0; i<10; i++)
    {
        proyecto[i].idProyecto = idProyecto[i];
        strcpy(proyecto[i].nombre, titulo[i]);
        proyecto[i].estado = estado[i];
    }

}
void cargarProyectosporProgramador(eProyecto_Programador ProyectosporProgramador[])
{
    int idProyecto[10]= {100,101,102,103,104,105,106,107,108,109};
    int idProgramador[10]={1,2,3,4,5,4,5,2,3,1};
    int horas[10]={2,10,13,4,8,9,7,11,1,9};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};
    int i;
    for(i=0; i<10; i++)
    {
        ProyectosporProgramador[i].idProyecto = idProyecto[i];
        ProyectosporProgramador[i].idProgramador=idProgramador[i];
        ProyectosporProgramador[i].horas=horas[i];
        ProyectosporProgramador[i].estado = estado[i];
    }

}

void tomarDato(eProgramador plantilla[])
{

    int flag=0;
    char auxstring[35];
    int datoValido=0;
    int i;
    int j;

            for(i=0; i<50; i++)
            {
                if(plantilla[i].estado==0)
                {
                    do{
                        printf("Ingrese ID: ");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarID(auxstring);

                        for(j=0;j<50;j++)
                        {
                            if(atoi(auxstring)==plantilla[j].id)
                            {
                                printf("La ID ingresada ya esta registrada\n");
                                datoValido=1;
                                break;
                            }
                        }
                    }while(datoValido==1);
                    plantilla[i].id=atoi(auxstring);

                    do{
                        printf("Ingrese el id de categoria (1:Junior/2:Semi Senior/3:Senior): ");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarID(auxstring);
                            if(atoi(auxstring)<1||atoi(auxstring)>3)
                            {
                                printf("La categoria ingresada no existe\n");
                                datoValido=1;
                            }

                    }while(datoValido==1);
                    plantilla[i].idCategoria=atoi(auxstring);

                    do{
                        printf("Ingrese nombre: ");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarNombre(auxstring);
                        if(strlen(auxstring)>19)
                        {
                            printf("El nombre ingresado es demasiado largo\n");
                            datoValido=1;
                        }
                    }while(datoValido==1);
                    strcpy(plantilla[i].nombre,auxstring);

                    do{
                        printf("Ingrese apellido: ");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarNombre(auxstring);
                        if(strlen(auxstring)>29)
                        {
                            printf("El apellido ingresado es demasiado largo\n");
                            datoValido=1;
                        }
                    }while(datoValido==1);
                    strcpy(plantilla[i].apellido,auxstring);

                    plantilla[i].estado = 1;
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                printf("No hay espacio\n");
            }

}
void eliminarProgramador(eProgramador plantilla[],eCategoria categorias[])
{
    int flag =0;
    char auxstring[35];
    char respuesta;
    int datoValido=0;
    int i;
    int j;

            do{
                        printf("Ingrese la ID del programador a dar de baja: \n");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarID(auxstring);
                    }while(datoValido==1);

            for(i=0; i<50; i++)
            {
                if(plantilla[i].estado==1 && atoi(auxstring) == plantilla[i].id)
                {
                    printf("ID: %d\nNombre: %s\nApellido: %s\n", plantilla[i].id, plantilla[i].nombre, plantilla[i].apellido);
                    for(j=0;j<3;j++)
                            {
                                if(plantilla[i].idCategoria==categorias[j].id)
                                    {
                                        printf("Categoria: %s\n",categorias[j].descripcion);
                                    }
                            }
                    printf("Esta seguro de eliminar el programador del registro? s/n: \n");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                       plantilla[i].estado = 0;
                       plantilla[i].id=0;
                    }
                    else
                    {
                        printf("Accion cancelada\n");
                        system("pause");
                    }
                    flag=1;
                    break;

                }
            }

            if(flag==0)
            {
                printf("ID inexistente\n");
            }

}
void modificarProgramador(eProgramador plantilla[],eCategoria categorias[])
{
    int flag =0;
    char auxstring[35];
    char respuesta;
    int i;
    int j;
    int datoValido=0;


             do{
                        printf("Ingrese la ID del programador a modificar: \n");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarID(auxstring);
                    }while(datoValido==1);

            for(i=0; i<50; i++)
            {
                if(plantilla[i].estado==1 && atoi(auxstring) == plantilla[i].id)
                {
                    printf("\nID: %d\nNombre: %s\nApellido: %s\n", plantilla[i].id, plantilla[i].nombre, plantilla[i].apellido);
                     for(j=0;j<3;j++)
                            {
                                if(plantilla[i].idCategoria==categorias[j].id)
                                    {
                                        printf("Categoria: %s\n",categorias[j].descripcion);
                                    }
                            }
                     do{
                        printf("Ingrese el id de la nueva categoria (1:Junior/2:Semi Senior/3:Senior): \n");
                        fflush(stdin);
                        gets(auxstring);
                        datoValido=validarID(auxstring);
                            if(atoi(auxstring)<1||atoi(auxstring)>3)
                            {
                                printf("La categoria ingresada no existe\n");
                                datoValido=1;
                            }

                    }while(datoValido==1);
                    printf("Esta seguro de realizar la modificacion? s/n: \n");
                    respuesta = getche();
                    printf("\n");

                    if(respuesta=='s')
                    {
                        plantilla[i].idCategoria = atoi(auxstring);
                    }
                    else
                    {
                        printf("Accion cancelada\n");
                        system("pause");
                    }
                    flag=1;
                    break;

                }
            }

            if(flag==0)
            {
                printf("ID inexistente\n");
            }
}

void derivarProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador proyectoPorProgramador[],eCategoria categorias[])
{
    char auxstring[35];
    char auxstring2[35];
    char auxstring3[35];
    int datoValido=0;
    int i;
    int j;
    int k;
    int l;
    int flag1=0;
    int flag2=0;
    int flag3=0;
    int flag4=0;

    printf("Listado de programadores cargados en el sistema:\n\n");

    for(i=0;i<50;i++)
    {
        if(programadores[i].estado==1)
        {
            printf("ID: %d\nNombre: %s\nApellido: %s\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido);
            for(j=0;j<3;j++)
            {
                if(programadores[i].idCategoria==categorias[j].id)
                {
                    printf("Categoria: %s\n\n",categorias[j].descripcion);
                }

            }
        }
    }
    system("pause");
    printf("Listado de Proyectos:\n\n");
    for(i=0;i<10;i++)
    {
        if(proyectos[i].estado==1)
        {
            printf("ID: %d\nNombre: %s\n\n",proyectos[i].idProyecto,proyectos[i].nombre);
        }
    }

        do{
            printf("Ingrese una ID de programador:\n");
            fflush(stdin);
            gets(auxstring);
            datoValido=validarID(auxstring);
            }while(datoValido==1);


        for(i=0;i<50;i++)
        {
            if(atoi(auxstring)==programadores[i].id&&programadores[i].estado==1)
            {
                flag1=1;
                datoValido=0;
                do{
                printf("Ingrese una ID de proyecto:\n");
                fflush(stdin);
                gets(auxstring2);
                datoValido=validarID(auxstring2);
                }while(datoValido==1);

                for(j=0;j<10;j++)
                {
                    if(atoi(auxstring2)==proyectos[j].idProyecto&&proyectos[j].estado==1)
                    {

                        for(k=5;k<100;k++)
                        {
                           flag2=1;
                           if(proyectoPorProgramador[k].estado==0)
                           {
                               for(l=0;l<100;l++)
                               {
                                   if(proyectoPorProgramador[l].idProgramador==atoi(auxstring)&&proyectoPorProgramador[l].idProyecto==atoi(auxstring2))
                                    {
                                        printf("Este prgramador ya fue asignado a este proyecto\n");
                                        flag4=1;
                                        system("pause");
                                        break;
                                    }
                               }
                            if(flag4==1)
                            {
                               break;
                            }
                               datoValido=0;
                            do{
                                printf("Ingrese la cantidad de horas que trabajara el programador:\n");
                                fflush(stdin);
                                gets(auxstring3);
                                datoValido=validarID(auxstring3);
                            }while(datoValido==1);
                            proyectoPorProgramador[k].idProgramador=atoi(auxstring);
                            proyectoPorProgramador[k].idProyecto=atoi(auxstring2);
                            proyectoPorProgramador[k].horas=atoi(auxstring3);
                            proyectoPorProgramador[k].estado=1;
                            flag3=1;
                            break;
                           }


                        }
                        if(flag3==0&&flag4==0)
                           {
                               printf("No hay mas espacio en el sistema\n");
                               system("pause");
                           }
                    }

                }
                if(flag2==0)
                {
                    printf("ID de proyecto inexistente\n");
                    system("pause");
                }
            }

        }
        if(flag1==0)
            {
                printf("ID inexistente\n");
                system("pause");
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
void organizar(eProgramador ingreso[],eProyecto proyectos[],eCategoria categorias[],eProyecto_Programador proyectosPorProgramador[])
{
    eProgramador auxp;
    int i;
    int j;
    int k;
    int l;
    int sueldo;

    for(i=0; i<50-1; i++)
    {
        for(j=i+1; j<50; j++)
        {
            if(ingreso[i].id>ingreso[j].id)
            {
                auxp=ingreso[i];
                ingreso[i]=ingreso[j];
                ingreso[j]=auxp;
            }
        }
    }
    printf("Listado de Programadores\n\n");

    for(i=0;i<50;i++)
    {
        if(ingreso[i].estado==1)
        {
            printf("ID: %d\nNombre: %s\nApellido: %s\n",ingreso[i].id,ingreso[i].nombre,ingreso[i].apellido);
            for(j=0;j<3;j++)
            {
                if(ingreso[i].idCategoria==categorias[j].id)
                {
                    printf("Categoria: %s\n",categorias[j].descripcion);
                    printf("Proyectos: \n");
                    for(k=0;k<100;k++)
                    {
                        if(ingreso[i].id==proyectosPorProgramador[k].idProgramador&&proyectosPorProgramador[k].estado==1)
                        {


                            for(l=0;l<10;l++)
                            {

                                if(proyectosPorProgramador[k].idProyecto==proyectos[l].idProyecto)
                                {
                                    printf("%s\n",proyectos[l].nombre);
                                    sueldo=proyectosPorProgramador[k].horas*categorias[j].pagoXhora;
                                    printf("Sueldo recibido por el trabajo en el proyecto %s: %d\n",proyectos[l].nombre,sueldo);

                                }
                            }

                        }
                    }
                }
            }
        printf("\n\n");
        }

    }
    system("pause");


}
void listarProyectosdeProgramador(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador proyectosPorProgramador[],eCategoria categorias[])
{
    int i;
    int j;
    int k;
    int flag1=0;
    int flag2=0;
    char auxstring[35];
    int datoValido=0;


     printf("Listado de programadores cargados en el sistema:\n\n");

    for(i=0;i<50;i++)
    {
        if(programadores[i].estado==1)
        {
            printf("ID: %d\nNombre: %s\nApellido: %s\n",programadores[i].id,programadores[i].nombre,programadores[i].apellido);
            for(j=0;j<3;j++)
            {
                if(programadores[i].idCategoria==categorias[j].id)
                {
                    printf("Categoria: %s\n\n",categorias[j].descripcion);
                }

            }
        }
    }
    do{
            printf("Ingrese una ID de programador:\n");
            fflush(stdin);
            gets(auxstring);
            datoValido=validarID(auxstring);
            }while(datoValido==1);


        for(i=0;i<50;i++)
        {
            if(atoi(auxstring)==programadores[i].id&&programadores[i].estado==1)
            {
                printf("El programador %s %s (ID: %d) trabaja en los proyectos: \n",programadores[i].nombre,programadores[i].apellido,programadores[i].id);
                flag2=1;
                for(j=0;j<100;j++)
                {

                    if(programadores[i].id==proyectosPorProgramador[j].idProgramador&&proyectosPorProgramador[j].estado==1)
                    {

                        flag1=1;
                        for(k=0;k<10;k++)
                        {
                            if(proyectosPorProgramador[j].idProyecto==proyectos[k].idProyecto)
                            {
                                printf("- %s\n",proyectos[k].nombre);
                            }
                        }
                    }

                }
                system("pause");
                if(flag1==0)
                {
                    printf("El programador buscado no participa en ningun proyecto\n");
                    system("pause");
                }
            }
        }
        if(flag2==0)
        {
            printf("La ID ingresada no existe\n");
            system("pause");
        }

}

void proyectoMasGrande (eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador proyectosPorProgramador[])
{
    int max;
    int flag=0;
    int contadorProgramadores=0;
    int idProyectoMaximo;
    char nombreProyectoMaximo[50];
    int i;
    int j;
    int k;

    for(i=0;i<10;i++)
    {
        contadorProgramadores=0;
        if(proyectos[i].estado==1)
        {
            for(j=0;j<100;j++)
            {
               if(proyectos[i].idProyecto==proyectosPorProgramador[j].idProyecto&&proyectosPorProgramador[j].estado==1)
                    {
                        for(k=0;k<50;k++)
                        {
                            if(proyectosPorProgramador[j].idProgramador==programadores[k].id&&programadores[k].estado==1)
                            {
                                contadorProgramadores++;
                            }
                        }
                    }
            }
            if(flag==0)
                {
                    max=contadorProgramadores;
                    idProyectoMaximo=proyectos[i].idProyecto;
                    strcpy(nombreProyectoMaximo,proyectos[i].nombre);
                    flag=1;
                }
        }
        if(contadorProgramadores>max)
        {
            max=contadorProgramadores;
            idProyectoMaximo=proyectos[i].idProyecto;
            strcpy(nombreProyectoMaximo,proyectos[i].nombre);
        }

    }
    printf("El proyecto que cuenta con mas programadores es:\n %s (ID: %d) con: %d programadores asignados\n",nombreProyectoMaximo,idProyectoMaximo,max);
system("pause");
}
int validarNombre(char nombre[])
{
   int i;

   int NombreValido=0;

    for(i=0;i<strlen(nombre);i++)
            {

                if(isdigit(nombre[i])!=0)
                    {

                        printf("El nombre ingresado no es valido, ");
                        NombreValido=1;
                        break;
                    }


            }
return NombreValido;
}
void listadoProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador programadoresPorProyecto[])
{
    int contadorJunior;
    int contadorSemiSenior;
    int contadorSenior;
    int i;
    int j;
    int k;

    printf("\nListado de Proyectos en el sistema:\n\n");

    for(i=0; i<10; i++)
    {
        contadorJunior=0;
        contadorSemiSenior=0;
        contadorSenior=0;

        if(proyectos[i].estado==1)
        {

            printf("ID: %d\nNombre: %s\n",proyectos[i].idProyecto,proyectos[i].nombre);
            for(j=0; j<100; j++)
            {
                if(proyectos[i].idProyecto==programadoresPorProyecto[j].idProyecto)
                {
                    for(k=0; k<50; k++)
                    {
                        if(programadoresPorProyecto[j].idProgramador==programadores[k].id)
                        {
                            if(programadores[k].idCategoria==1)
                            {
                                contadorJunior++;
                            }
                            else
                            {
                                if(programadores[k].idCategoria==2)
                                    {
                                        contadorSemiSenior++;
                                    }
                                else
                                {
                                    if(programadores[k].idCategoria==3)
                                        {
                                            contadorSenior++;
                                        }
                                }
                            }
                        }
                    }
                }
            }
            printf("Junior: %d\nSemi Senior: %d\nSenior: %d\n\n",contadorJunior,contadorSemiSenior,contadorSenior);
        }
    }
system("pause");
}
