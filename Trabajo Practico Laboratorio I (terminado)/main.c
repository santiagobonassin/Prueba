#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1;
    float num2;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

            printf("Ingrese el primer numero: ");
            scanf("%f",&num1);
            break;

            case 2:

            printf("Ingrese el segundo numero: ");
            scanf("%f",&num2);

            break;

            case 3:

            suma(num1,num2);

            break;

            case 4:

            resta(num1,num2);

            break;

            case 5:

            division(num1,num2);

            break;

            case 6:

            multiplicacion(num1,num2);

            break;

            case 7:

            factorial(num1);

            break;

            case 8:

            suma(num1,num2);
            resta(num1,num2);
            division(num1,num2);
            multiplicacion(num1,num2);
            factorial(num1);
            break;

            case 9:

            seguir = 'n';

            break;
        }
     }

    return 0;
}
