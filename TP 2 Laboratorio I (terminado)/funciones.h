#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/** \brief Realiza el alta de una persona al registro tomando nombre, edad y DNI
 *
 * \param EPersona Es la estructura que toma para poder asignar los datos recibidos
 * \return i Retorna la posicion en la que se guardo a la persona
 *
 */

int tomarDato (EPersona[]);

/** \brief Realiza la baja logica de una persona del registro
 *
 * \param   EPersona Es la estructura de la cual toma los datos a modificar
 *
 */

void borrarPersona (EPersona[]);

/** \brief Ordena el registro de personas ingresadas por orden alfabetico
 *
 * \param EPersona Es la estructura que usa y sobre la cual trabaja al ordenar los registros
 *
 */

void organizar(EPersona[]);

/** \brief Valida que el DNI ingresado por el usuario no contenga letras, caracteres especiales o se repita
 *
 * \param dni Es el dato que toma de la funcion tomarDato
 * \return dniValido Es el entero que confirma que el DNI sea valido o no
 *
 */

int validarDNI(char[]);

/** \brief Valida que la edad ingresada por el usuario no contenga letras y caracteres especiales
 *
 * \param edad Es el dato que toma de la funcion tomarDato
 * \return edadValida Es el entero que confirma que la edad ingresada por el usuario sea valida o no
 *
 */

int validarEdad(char[]);

/** \brief Realiza el grafico de barras sobre la edad de las personas guardadas en el registro
 *
 * \param contador1 Es el contador perteneciente al grupo de personas menores a 18 años
 * \param contador2 Es el contador perteneciente al grupo de personas entre 19 y 35 años
 * \param contador3 Es el contador perteneciente al grupo de personas mayores a 35 años
 *
 */

void grafico (int, int, int);

#endif // FUNCIONES_H_INCLUDED
