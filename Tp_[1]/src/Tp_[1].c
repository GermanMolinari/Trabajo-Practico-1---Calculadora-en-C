/*
 ============================================================================
 Name        : Tp_[1].c
 Author      : Molinari German
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTp1.h"

int main(void)
{
	setbuf(stdout,NULL);

	char seguir = 's';
	int a=0;
	int b=0;
	int flagOperandoA = 0;
	int flagOperandoB = 0;
	int flagCalculos = 0;
	int DivisionOk = 0;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	int resultadoFactorial;
	int resultadoFactorialB;
	float resultadoDivicion;

	do
	{
		system("cls");

		switch(selecionarOpcion(a,b))
		{
		case 1: // ingresa el primer operando
			a = ingresarOperando();
			flagOperandoA = 1;
		break;

		case 2: // ingresa el segundo operando
			b = ingresarOperando();
			flagOperandoB = 1;
		break;

		case 3: // opera con los operandos
			if(flagOperandoA == 1 && flagOperandoB ==1)
			{
			resultadoSuma = sumarEnteros(a,b);
			resultadoResta = restarEnteros(a,b);
			resultadoMultiplicacion = multiplicarEnteros(a,b);
			DivisionOk = dividirEnteros(a,b,&resultadoDivicion);
			resultadoFactorial = factoriarNumero(a);
			resultadoFactorialB = factoriarNumero(b);
			flagCalculos = 1;
			}
			 else if(flagOperandoB == 0 && flagOperandoA == 0)
			{
				printf("Por favor, ingrese ambos operandos y luego calcule. \n");
				system("pause");
			}
			else if(flagOperandoB == 1 && flagOperandoA == 0)
			{
				printf("Por favor, ingrese el operando A y luego calcule. \n");
				system("pause");
			}
			else
			{
				printf("Por favor, ingrese el operando B y luego calcule. \n");
				system("pause");
			}
		break;

		case 4: // muestra los resultados
			if(flagCalculos == 1)
			{
				printf("El resultado de la suma es: %d \n", resultadoSuma);
				printf("El resultado de la resta es: %d \n", resultadoResta);
				printf("El resultado de la multiplicacion es: %d \n", resultadoMultiplicacion);

				if (DivisionOk == 1)
				{
					printf("El resultado de la division es: %.2f \n", resultadoDivicion);
				}
				else
				{
					 printf("No se puede dividir por 0. \n");
				}

				printf("El factorial de %d, es: %d y el factorial de %d es : %d\n",a,resultadoFactorial,b,resultadoFactorialB);
				system("pause");
			}
			else if(flagOperandoB == 0 && flagOperandoA == 0)
			{
				printf("Por favor, ingrese ambos operandos y luego calcule. \n");
				system("pause");
			}
			else if(flagOperandoB == 1 && flagOperandoA == 0)
			{
				printf("Por favor, ingrese el operando A y luego calcule. \n");
				system("pause");
			}
			else if(flagOperandoB == 0 && flagOperandoA == 1)
			{
				printf("Por favor, ingrese el operando B y luego calcule. \n");
				system("pause");
			}
			else
			{
				printf("Por favor, calcule antes de mostrar los valores. \n");
				system("pause");
			}

		break;

		case 5: // sale del bucle
			seguir = 'n';
		break;

		default:
			printf("Error... seleccione una opcion valida \n" );
			system("pause");
		break;
		}
	} while (seguir == 's');

	return EXIT_SUCCESS;
}
