#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include<conio.h>
#include <ctype.h>

int tomarDato(EPersona ingreso[])
{
    int flag=0;
    int i, j;
    char auxString [100];
    int dnivalidado;
    int edadvalidada;


    for(i=0; i<20; i++)
      {

       if(ingreso[i].estado==0)
         {
            do{
            printf("Ingrese DNI: ");
            scanf("%s", auxString);
            dnivalidado=validarDNI(auxString);
            for(j=0;j<20;j++)
            {
                if(ingreso[j].dni==atoi(auxString))
                {
                    printf("El DNI ingresado ya esta registrado, ");
                    dnivalidado=1;
                }
            }
            }while(dnivalidado==1);
            ingreso[i].dni=atoi(auxString);

            do{
            printf("Ingrese edad: ");
            scanf("%s", auxString);
            edadvalidada=validarEdad(auxString);
            if(atoi(auxString)<1)
            {
                edadvalidada=1;
            }
            }while(edadvalidada==1);
            ingreso[i].edad=atoi(auxString);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxString);

            while(strlen(auxString)>49)
                {
                    printf("Error, el nombre es demasiado largo, reingrese el dato: ");
                    gets(auxString);
                }
            strcpy(ingreso[i].nombre,auxString);

            ingreso[i].estado = 1;
            flag=1;
            break;
         }
      }

     if(flag==0)
        {
            printf("\nImposible cargar mas datos, almacenamiento lleno\n ");
        }
return i;
}
void borrarPersona(EPersona ingreso[])
{
    int flag =0;
    int auxInt;
    int i;
    char respuesta;

    printf("Ingrese el DNI de la persona a dar de baja: ");
    scanf("%d", &auxInt);

        for(i=0; i<20; i++)
          {
            if(ingreso[i].estado==1 && auxInt == ingreso[i].dni)
          {
           printf("Datos de la persona:\nDNI: %d \nNombre: %s\nEdad:%d\n", ingreso[i].dni, ingreso[i].nombre, ingreso[i].edad);
           printf("¿Desea confirmar la eliminacion? s/n: ");
           respuesta = getche();

           if(respuesta=='s')
             {
               ingreso[i].estado = 0;
             }
           else
             {
               printf("La accion ha sido cancelada\n");
             }
               flag=1;
               break;

              }
          }

            if(flag==0)
                {
                    printf("El numero de DNI ingresado no esta registrado\n");
                }

}
void organizar(EPersona ingreso[])
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
                        if(strcmp(ingreso[i].nombre,ingreso[j].nombre)>0)
                        {
                            strcpy(auxstring, ingreso[i].nombre);
                            strcpy(ingreso[i].nombre, ingreso[j].nombre);
                            strcpy(ingreso[j].nombre,auxstring);

                            auxint = ingreso[i].dni;
                            ingreso[i].dni = ingreso[j].dni;
                            ingreso[j].dni = auxint;

                            auxint = ingreso[i].edad;
                            ingreso[i].edad = ingreso[j].edad;
                            ingreso[j].edad = auxint;

                            auxint = ingreso[i].estado;
                            ingreso[i].estado = ingreso[j].estado;
                            ingreso[j].estado = auxint;

                        }
                        else
                        {
                            if(strcmp(ingreso[i].nombre,ingreso[j].nombre)==0)
                            {
                                if(ingreso[i].dni>ingreso[j].dni)
                                {
                                    auxint = ingreso[i].dni;
                                    ingreso[i].dni = ingreso[j].dni;
                                    ingreso[j].dni = auxint;

                                    auxint = ingreso[i].edad;
                                    ingreso[i].edad = ingreso[j].edad;
                                    ingreso[j].edad = auxint;

                                    auxint = ingreso[i].estado;
                                    ingreso[i].estado = ingreso[j].estado;
                                    ingreso[j].estado = auxint;
                                }
                            }
                        }
                    }
                }
            }

  printf("Datos de las personas registradas:\n\n");

  for(i=0; i<20; i++)
     {
        if(ingreso[i].estado!=0)
            {

                printf("DNI: %d\nNombre: %s\nEdad: %d\n\n", ingreso[i].dni, ingreso[i].nombre, ingreso[i].edad);
            }

     }

 }
int validarDNI(char dni[])
{
   int i;

   int dniValido=0;

    for(i=0;i<strlen(dni);i++)
            {

                if(isdigit(dni[i])!=1)
                    {

                        printf("El numero ingresado no es valido, ");
                        dniValido=1;
                        break;
                    }


            }
return dniValido;
}
int validarEdad(char edad[])
{
   int i;

   int edadValida=0;

    for(i=0;i<strlen(edad);i++)
            {

                if(isdigit(edad[i])!=1)
                    {

                        printf("La edad ingresada no es valida, ");
                        edadValida=1;
                        break;
                    }


            }
return edadValida;
}
void grafico (int contador1, int contador2, int contador3)
{
    int i;

    int flag=0;

    int barraMasGrande;

    if(contador1>=contador2&&contador1>=contador3)
    {
        barraMasGrande=contador1;
    }
    else
    {
        if(contador2>=contador3&&contador2>=contador1)
        {
            barraMasGrande=contador2;
        }
        else
        {
            barraMasGrande=contador3;
        }
    }
    for(i=barraMasGrande; i>0; i--)
        {
          if(i<= contador1)
            {
              printf("|X|");
            }
              if(i<= contador2)
                 {
                   flag=1;
                   printf("\t|X|");
                 }
                   if(i<= contador3)
                        {
                            if(flag==0)
                            printf("\t|X|");
                            if(flag==1)
                            printf("\t|X|");
                        }
            printf("\n");
        }
    printf("%d\t%d\t%d\n",contador1,contador2,contador3);
    printf("<18\t18<>35\t>35\n");
}




