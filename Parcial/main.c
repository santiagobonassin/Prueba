#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
int main()
{
    eProgramador plantilla[4];
    eCategoria clase[3];
    eProyecto proyectos[3];
    eProyecto_Programador proyectosPorprogramador[10];

    cargarCategoria(clase);
    cargarProyectos(proyectos);
    int i;

    for(i=0; i<5; i++)
    {
        plantilla[i].estado=0;
    }
    for(i=0; i<10; i++)
    {
        proyectosPorprogramador[i].estado=0;
    }

    char seguir='s';
    int opcion;


    do
    {
        printf("1. Alta\n2. Modificaciones\n3. Bajas\n4. Asignar programador a proyecto\n5. Listado de Programadores\n6.Listado de todos los proyectos\n7.Listar proyectos de programador\n8.Proyecto demandante\n9.salir\nElija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
        tomarDato(plantilla);
        break;

         case 2:
         modificarProgramador(plantilla);
            break;

        case 3:

            eliminarProgramador(plantilla);
            break;

            case 4:

                derivarProyectos(plantilla,proyectos,proyectosPorprogramador);


                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:

                seguir = 'n';

                break;

        }
        }while(seguir=='s');



    return 0;
}
