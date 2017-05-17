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
    int estado;
}eProyecto_Programador;

void tomarDato(eProgramador[]);

void eliminarProgramador(eProgramador[]);

void modificarProgramador(eProgramador[]);

void cargarCategoria(eCategoria[]);

void cargarProyectos(eProyecto[]);

void derivarProyectos(eProgramador[],eProyecto[],eProyecto_Programador[],int, int, int);

int validarID(char ID[]);

void organizar(eProgramador[]);



void listarProyectosdeProgramador(eProgramador[],eProyecto[],eProyecto_Programador[]);

void proyectoMasGrande (eProgramador[],eProyecto[],eProyecto_Programador[],int, int, int);

#endif // FUNCIONES_H_INCLUDED
