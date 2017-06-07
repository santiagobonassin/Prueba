#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
int main()
{
    eProgramador plantilla[50];
    eCategoria clase[3];
    eProyecto proyectos[10];
    eProyecto_Programador proyectosPorprogramador[100];
int i;
for(i=0; i<50; i++)
    {
        plantilla[i].estado=0;
        plantilla[i].id=0;
    }
    for(i=0; i<100; i++)
    {
        proyectosPorprogramador[i].idProyecto=0;
        proyectosPorprogramador[i].idProgramador=0;
        proyectosPorprogramador[i].estado=0;
    }

    cargarCategoria(clase);
    cargarProyectos(proyectos);
    cargarprogramadores(plantilla);
    cargarProyectosporProgramador(proyectosPorprogramador);

    char seguir='s';
    int opcion;

    do
    {
        printf(" ------------------------------------------------------------------------------\n");
        printf("\t\t\tMenu Principal del Sistema\t\t\n");
        printf(" ------------------------------------------------------------------------------\n");
        printf("Elija una opcion: \n\n");
        printf("1. Alta\n2. Modificaciones\n3. Bajas\n4. Asignar programador a proyecto\n5. Listado de Programadores\n6.Listado de todos los proyectos\n7.Listar proyectos de programador\n8.Proyecto demandante\n9.salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:

        system("cls");
        tomarDato(plantilla);
        system("cls");

        break;

        case 2:

        system("cls");
        modificarProgramador(plantilla,clase);
        system("cls");

        break;

        case 3:

        system("cls");
        eliminarProgramador(plantilla,clase);
        system("cls");

        break;

        case 4:

        system("cls");
        derivarProyectos(plantilla,proyectos,proyectosPorprogramador,clase);
        system("cls");

        break;

        case 5:

        system("cls");
        organizar(plantilla,proyectos,clase,proyectosPorprogramador);
        system("cls");

        break;

        case 6:

        system("cls");
        listadoProyectos(plantilla,proyectos,proyectosPorprogramador);
        system("cls");

        break;

        case 7:

        system("cls");
        listarProyectosdeProgramador(plantilla,proyectos,proyectosPorprogramador,clase);
        system("cls");

        break;

        case 8:

        system("cls");
        proyectoMasGrande(plantilla,proyectos,proyectosPorprogramador);
        system("cls");

        break;

        case 9:

        seguir = 'n';

        break;

        default:

        printf("La opcion ingresada no es valida: ");
        system("pause");
        printf("\n");
        system("cls");

        }

        }while(seguir=='s');

    return 0;
}
