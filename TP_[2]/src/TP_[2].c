/*
 ============================================================================
 Name        : TP_[2].c
 Author      : German Molinari
 Version     : 1ra
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib_tp2.h"

int main(void)
{
		setbuf(stdout, NULL);
		char keepGoing = 's';
	    Employee list[1000];
	    int id = 0;
	    int auxId;
	    int option;
	    int optionOrder;
	    int position;
	    Employee aux;

	    initEmployees(list, 1000);
	    do
	    {

	        switch(menu())
	        {
	        case 1:
	            aux = recuestData(&id);
	            printf("%d %s", aux.id, aux.lastName);
	            addEmployee(list, 1000, id, aux.name, aux.lastName, aux.salary, aux.sector);
	            system("pause");
	            break;

	        case 2:
	            system("cls");
	            printf("Ingrese numero de ID del empleado a modificar\n");
	            scanf("%d", &auxId);
	            position = findEmployeeById(list, 1000, auxId);
	            if(position != -1)
	            {
	                if(modifyEmployee(list, 1000, position) == 1)
	                {
	                    printf("Modificacion exitosa \n");
	                }
	                else
	                {
	                    printf("No se pudo modificar. \n");
	                }
	            }
	            else
	            {
	                printf("Error, no se encontro empleado con el ID %d \n", auxId);
	            }
	            system("pause");
	            break;

	        case 3:
	            system("cls");
	            printf("Ingrese numero de ID del empleado que quiere dar de baja\n");
	            scanf("%d", &auxId);
	            if(removeEmployee(list,1000,auxId) == 1)
	            {
	                system("cls");
	                printf("Baja exitosa \n");
	            }
	            else
	            {
	                printf("No se efectuo la baja \n");
	            }

	            system("pause");
	            break;

	        case 4:
	            system("cls");
	            printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n 3. Volver al menu\n");
	            scanf("%d", &option);
	            while(option != 1 && option != 2 &&option != 3)
	            {
	                printf("Error. Ingrese nuevamente la opcion.");
	                printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector. \n 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio. \n 3. Volver al menu\n");
	                scanf("%d", &option);
	            }
	            if(option == 1)
	            {
	                printf("1- Ordenar de A - Z \n 2- Ordenar de Z - A");
	                scanf("%d", &optionOrder);
	                while(optionOrder != 1 && optionOrder != 2)
	                {
	                    printf("ERROR, 1- Ordenar de A - Z \n 2- Ordenar de Z - A");
	                    scanf("%d", &optionOrder);
	                }
	                if(optionOrder == 1)
	                {
	                    sortEmployees(list, 1000, 1);
	                    printEmployees(list, 1000);
	                }
	                else
	                {
	                    sortEmployees(list, 1000, 2);
	                    printEmployees(list, 1000);
	                }
	            }
	            else if (option == 2)
	            {   system("cls");
	                printf("el salario promedio es %.2f, y la cantidad de empleados que lo supera es %d",
	                        promedySalary(list, 1000), EmployeePromedy(list, 1000, promedySalary(list, 1000)));

	            }
	            else if(option == 3)
	            {
	                break;
	            }

	            system("pause");
	            break;
	        case 5:
	            keepGoing='n';
	            break;

	        default:
	            system("cls");
	            printf("Error.. Seleccione una opcion valida..\n");
	            system("pause");
	        }
	    }
	    while(keepGoing=='s');
	    system("pause");

	    return EXIT_SUCCESS;
}
