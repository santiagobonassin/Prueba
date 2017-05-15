#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int estado;
    int id;
    char nombre[20];
    char apellido[20];
    int idCategoria;
}eProgramador;

typedef struct
{
    int id;
    int estado;
    char descripcion[20];
    int pagoXhora;
}eCategoria;

typedef struct{

    int idProyecto;
    int estado;
    char nombre[30];
}eProyecto;

typedef struct{

    int idProyecto;
    int idProgramador;
    int horas;

}eProyecto_Programador;

void tomarDato(eProgramador[]);

void eliminarProgramador(eProgramador[]);

void modificarProgramador(eProgramador[]);

void cargarCategoria(eCategoria[]);

void cargarProyectos(eProyecto[]);

void derivarProyectos(eProgramador programadores[],eProyecto proyectos[],eProyecto_Programador ProyectosporProgramador[]);

#endif // FUNCIONES_H_INCLUDED