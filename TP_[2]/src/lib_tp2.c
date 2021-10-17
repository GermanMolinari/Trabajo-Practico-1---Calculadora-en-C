#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lib_tp2.h"

int menu()
{
    int opcion;
    system("cls");
    printf("****ABM Employees**** \n\n");
    printf("1) Alta empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja empleado\n");
    printf("4) Informar\n");
    printf("5) Salir\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee list[], int tam)
{
    int todoOk=0;
    if(list != NULL && tam > 0)
    {
        for(int i= 0; i < tam; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 1 ;
    }

    return todoOk;
}

int findFree (Employee list[], int tam)
{
    int position=-1;

    if(list != NULL && tam>0)
    {

        for(int i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                position = i;
                break;
            }
        }
    }

    return position;
}


int addEmployee (Employee list [], int tam, int id, char name[], char lastName [], float salary, int sector)
{
    int todoOk = 0;
    int position;

    if(list != NULL && name != NULL && lastName!= NULL && tam>0)
    {
        system("cls");
        printf("***Alta persona***\n");
        position = findFree(list, tam);

        if(position != -1)
        {
            list[position].id = id;
            strcpy(list[position].name, name);
            strcpy(list[position].lastName, lastName);
            list[position].salary = salary;
            list[position].sector = sector;
            list[position].isEmpty = 0;

        }
        else
        {
            printf("No hay espacio para mas empleados.\n");
        }
        todoOk=1;
    }

    return todoOk;
}

Employee recuestData(int* id)
{
    Employee data;

    system("cls");

    printf("Ingrese nombre del empleado\n");
    fflush(stdin);
    gets(data.name);

    printf("Ingrese apellido del empleado\n");
    fflush(stdin);
    gets(data.lastName);

    printf("Ingrese salario del empleado\n");
    scanf("%f", &data.salary);
    while((data.salary < 1 || data.salary > 999999) && data.salary)
    {
        printf("ERROR.. ingrese el salario nuevamente (1 - 999999)\n");
        scanf("%f", &data.salary);
    }

    printf("Ingrese sector del empleado\n");
    scanf("%d", &data.sector);
    while(data.sector < 1)
    {
        printf("ERROR.. Ingrese sector del empleado nuevamente\n");
        scanf("%d", &data.sector);
    }

    data.id = *id;
    (*id)++;

    return data;
}

int printEmployees(Employee list[], int tam)
{
    int todoOk = 0;
    int flag = 0;

    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("      ***Empleados***\n\n");
        printf("------------------------------------------------\n");
        printf("ID      NOMBRE      APELLIDO        SUELDO      SECTOR\n\n");

        for(int i=0; i<tam; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            system("cls");
            printf("------------------------------------------------\n");
            printf("No hay empleados registrados\n");
        }
        todoOk=1;
    }
    return todoOk;
}

void printEmployee(Employee emp)
{
    printf("%04d      %s      %s        $%5.2f      %d\n", emp.id, emp.name, emp.lastName, emp.salary, emp.sector);
}

int findEmployeeById(Employee list[], int tam, int id)
{
    int position = -1;

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam-1; i++)
        {
            if(id == list[i].id && list[i].isEmpty == 0)
            {
                position = i;
            }
        }
    }
    return position;
}

int modifyEmployee(Employee list[], int tam, int position)
{
    int todoOk = 0;
    char confirm;
    if(list != NULL && tam > 0)
    {
        printEmployee(list[position]);
        printf("Desea modificar al empleado? s/n \n");
        fflush(stdin);
        scanf("%c", &confirm);

        while(confirm != 's' && confirm != 'n')
        {
            printf("Error.. ingrese solo s/n \n");
            scanf("%c", &confirm);
        }
        if (confirm == 's')
        {
            system("cls");
            printf("Ingrese nombre \n");
            fflush(stdin);
            gets(list[position].name);

            printf("Ingrese apellido \n");
            fflush(stdin);
            gets(list[position].lastName);

            printf("Ingrese sueldo \n");
            scanf("%f", &list[position].salary);

            printf("Ingrese sector \n");
            scanf("%d", &list[position].sector);

            todoOk = 1;

        }
    }
    return todoOk;
}


int removeEmployee(Employee list[], int tam, int id)
{
    int todoOk = 0;
    char confirm;
    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].id == id && list[i].isEmpty == 0)
            {
                system("cls");
                printEmployee(list[i]);
                printf("\n Desea eliminar empleado? s/n");
                fflush(stdin);
                scanf("%c", &confirm);

                while(confirm != 's' && confirm != 'n')
                {
                    printf("Error.. ingrese solo s/n \n");
                    scanf("%c", &confirm);
                }

                if(confirm == 's')
                {
                    list[i].isEmpty = 1;
                    todoOk = 1 ;
                    break;
                }
            }
        }
    }
    return todoOk;
}

int sortEmployees(Employee list[], int tam, int order)
{
    int todoOk=0;
    Employee aux;

    if(list!= NULL && tam>0)
    {
        for(int i = 0; i<tam-1; i++)
        {
            for(int j = i+1; j<tam; j++)
            {
                if(order == 1)
                {
                    if(list[i].isEmpty != 1 && (strcmp(list[i].lastName, list[j].lastName) > 0))
                    {
                        aux = list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        todoOk = 1;
                    }
                }
                else if(order == 2)
                {
                    if(list[i].isEmpty != 1 && (strcmp(list[i].lastName, list[j].lastName) < 0))
                    {
                        aux = list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        todoOk = 1;
                    }
                }
                else if(list[i].isEmpty != 1 && (strcmp(list[i].lastName, list[j].lastName) == 0))
                {
                    if(list[i].sector > list[j].sector)
                    {
                        aux = list[i];
                        list[i]=list[j];
                        list[j]=aux;
                        todoOk = 1;
                    }
                }
            }
        }
    }
    return todoOk;
}

float promedySalary(Employee list[], int tam)
{
   int result;
   int count = 0;
   float total = 0;

   if(list != NULL && tam > 0)
   {
       for(int i = 0; i < tam; i++)
       {
           if(list[i].isEmpty == 0)
           {
               total += list[i].salary;
               count++;
           }
        result = (float) total/count;
       }
   }
    return result;
}

int EmployeePromedy (Employee list[], int tam, float promedy)
{
    int count = 0;

    if(list != NULL && tam>0)
    {
        for(int i = 0; i < tam; i++)
        {
            if (list[i].salary > promedy)
            {
                count++;
            }
        }
    }
    return count;
}
