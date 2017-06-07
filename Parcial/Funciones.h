#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int estado;
    int id;
    char nombre[20];
    char apellido[30];
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

/** \brief Realiza el alta de un programador al sistema
 *
 * \param eProgramador Es la estructura de programador en la cual carga los datos
 *
 */
void tomarDato(eProgramador[]);
/** \brief Realiza la baja logica de un programador del sistema
 *
 * \param eProgramador Es la estructura programador de la cual toma los datos.
 * \param eCategoria Es la estructura de categorias de la cual recibe los datos para mostrar categoria de programador
 *
 */
void eliminarProgramador(eProgramador[],eCategoria[]);
/** \brief Crea un listado de los proyectos y la cantidad de programadores de cada categoria que posee
 *
 * \param eProgramador Es la estcructura de la que recibe los datos para hacer el listado
 * \param eProyecto Es la estructura de la que toma los datos de los proyectos
 * \param eProyecto_Programador Es la estructura que usa para hacer la relacion entre proyecto y programador
 *
 */
void listadoProyectos(eProgramador[],eProyecto[],eProyecto_Programador[]);
/** \brief Realiza la modificacion de categoria de un programador
 *
 * \param eProgramador Es la estructura de la cual saca los datos del programador a modificar
 * \param eCategoria Es la estructura de la que obtiene los datos de categoria
 *
 */
void modificarProgramador(eProgramador[],eCategoria[]);
/** \brief Realiza el harcodeo de las 3 categorias
 *
 * \param eCategoria Es la estructura en la que guarda los datos
 *
 */
void cargarCategoria(eCategoria[]);
/** \brief Realiza el harcodeo de 10 proyectos
 *
 * \param eProyecto Es la estructura en la que guarda los datos
 *
 */
void cargarProyectos(eProyecto[]);
/** \brief Realiza la asignacion de un programador a un proyecto
 *
 * \param eProgramador Es la estructura de la cual saca los datos del programador
 * \param eProyecto Es la estructura de la que saca los datos de los proyectos para hacer la asignacion
 * \param eProyecto_Programador Es la estructura que usa para unir proyectos y programadores
 * \param eCategoria Es la estructura que le da los datos de categorias para asignarselos a los programadores
 *
 */
void derivarProyectos(eProgramador[],eProyecto[],eProyecto_Programador[],eCategoria[]);
/** \brief Valida que el numero ingresado no contenga letras
 *
 * \param char Es la cadena de caracteres a revisar
 * \return Retorna 1 en caso de que halla letras y 0 en caso contrario
 *
 */
int validarID(char[]);
/** \brief Ordena por ID a los programadores y los muestra con sus proyectos y sueldos de los mismos
 *
 * \param eProgramador Es la estructura de la cual saca los datos del programador
 * \param eProyecto Es la estructura de la cual saca los datos de los proyectos
 * \param eCategoria Es la estructura de la cual saca los datos de las categorias para asignarselos a los programadores
 * \param eProyecto_Programador Es la estructura que hace la conexion entre programador y sus proyectos
 *
 */
void organizar(eProgramador[],eProyecto[],eCategoria[],eProyecto_Programador[]);
/** \brief Realiza el harcodeo de 5 programadores
 *
 * \param eProgramador Es la estructura a la que le asigna los datos
 *
 */
void cargarprogramadores(eProgramador[]);
/** \brief Valida que un nombre no tenga numeros
 *
 * \param char Es la cadena que evalua
 * \return Retorna 1 si hay un numero y 0 en caso contrario
 *
 */
int validarNombre(char[]);
/** \brief Muestra los proyectos en los que trabaja un determinado programador
 *
 * \param eProgramador Es la estructura de la cual saca los datos del programador
 * \param eProyecto Es la estructura de la cual saca los datos de los proyectos
 * \param eProyecto_Programador Es la estructura que hace la conexion entre programador y sus proyectos
 * \param eCategoria Es la estructura de la cual saca los datos de las categorias para asignarselos a los programadores
 *
 */
void listarProyectosdeProgramador(eProgramador[],eProyecto[],eProyecto_Programador[],eCategoria[]);
/** \brief Muestra al proyecto con mas programadores asignados a el
 *
 * \param eProgramador Es la estructura de la cual saca los datos del programador
 * \param eProyecto Es la estructura de la cual saca los datos de los proyectos para mostrar al mas grande
 * \param eProyecto_Programador Es la estructura que hace la conexion entre programador y sus proyectos
 *
 */
void proyectoMasGrande (eProgramador[],eProyecto[],eProyecto_Programador[]);
/** \brief Realiza el harcodeo de la relacion entre 5 programadores y 10 proyectos
 *
 * \param eProyecto_Programador Es la estructura en la que deposita los datos
 * \param
 * \return
 *
 */
void cargarProyectosporProgramador(eProyecto_Programador[]);

#endif // FUNCIONES_H_INCLUDED
