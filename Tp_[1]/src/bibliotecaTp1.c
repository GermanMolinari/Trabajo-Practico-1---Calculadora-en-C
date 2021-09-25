#include <stdio.h>
#include <stdlib.h>

int selecionarOpcion (int a,int b)
{

    int opcionIngresada;

    printf(" Seleccione una opcion: \n 1) Ingresar primer operando (A = %d) \n 2) Ingresar segundo operando (B = %d) \n 3) Calcular operaciones \n 4) Mostrar resultados \n 5) Salir \n \n",a,b);
    scanf("%d", &opcionIngresada);

    return opcionIngresada;
}




int ingresarOperando()
{
    int numeroIngresado;

    printf("Ingrese un numero para operar");
    scanf("%d", &numeroIngresado);

    return numeroIngresado;
}




int sumarEnteros (int a, int b)
{
    int resultado;

    resultado = a + b;

    return resultado;
}




int restarEnteros (int a, int b)
{
    int resultado;

    resultado = a - b;

    return resultado;
}




int multiplicarEnteros (int a, int b)
{
    int resultado;

    resultado = a * b;

    return resultado;
}



int dividirEnteros(int a, int b, float* resultado)
{
    int todoOk=0;

    if(b != 0)
    {
        *resultado = (float) a/b;
        todoOk=1;
    }
    return todoOk;
}




int factoriarNumero (int a)
{
    int resultado;


    if (a == 1 || a==0)
    {
        resultado=1;
    }
    else
    {
        resultado = a * factoriarNumero(a-1);
    }

    return resultado;
}
