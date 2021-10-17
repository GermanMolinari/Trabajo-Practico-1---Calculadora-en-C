#ifndef LIB_TP2_H_INCLUDED
#define LIB_TP2_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

/** \brief menu de opciones
 *
 * \return int retorna la opcion elegida
 *
 */
int menu();


/** \brief inicializa el array
 *
 * \param list[] lista de empleados
 * \param tam int tamaño del array
 * \return int si sale todo bien
 *
 */
int initEmployees(Employee list[], int tam);



/** \brief busca la primer posicion vacia en el array de empleados
 *
 * \param lista de empleados
 * \param  tamaño de la lista
 * \return  retorna la primera posicion encontrada o -1 si esta todo lleno
 *
 */
int findFree (Employee list[], int tam);



/** \brief añade un empleado
 *
 * \param lista de empleados
 * \param tamaño de la lista
 * \param id del empleado
 * \param nombre del empleado
 * \param apellido del empleado
 * \param salario del empleado
 * \param sector del empleado

 * \return
 *
 */
int addEmployee (Employee list [], int tam, int id, char name[], char lastName [], float salary, int sector);


/** \brief encuentra al empleado que tenga el id que ingresas
 *
 * \param lista de empleados
 * \param  tamaño de la lista
 * \return id del empleado
 *
 */

int findEmployeeById(Employee list[], int tam, int id);




/** \brief
 *
 * \param lista de empleados
 * \param tamaño de la lista
 * \param id idel empleado
 * \return int
 *
 */
int removeEmployee(Employee list[], int tam, int id);



/** \brief Ordena los empleados segun el criterio
 *
 * \param lista de empleados
 * \param tamaño de la lista
 * \param orden
 * \return si sale bien o no
 *
 */
int sortEmployees(Employee list[], int tam, int order);



/** \brief muestra todos los empleados cargados
 *
 * \param lista de empleados
 * \param tamaño
 * \return si se puede o no
 *
 */
int printEmployees(Employee list[], int tam);



/** \brief pide los datos de un empleado y genera el id
 *
 * \param direccion de memoria del id

 * \return los datos cargados en una estructura tipo empleado
 *
 */
Employee recuestData (int* id);



/** \brief muestra todos los datos de un solo empleado
 *
 * \param empleado
 * \return void
 *
 */
void printEmployee(Employee emp);



/** \brief permite modificar un empleado
 *
 * \param lista de empleados
 * \param tamaño de la lista
 * \param position donde se encuentra el empleado
 * \return si sale bien o mal
 *
 */
int modifyEmployee(Employee list[], int tam, int position);



/** \brief saca el promedio de los salario de todos los empleados cargados
 *
 * \param lista de empleados
 * \param tamaño de la lista
 * \return el promedio de los salarios
 *
 */
float promedySalary(Employee list[], int tam);



/** \brief averigua la cantidad de empleados que supera el salario promedio
 *
 * \param lista de empleados
 * \param tamaño
 * \param promedio de salarios
 * \return cantidad de empleados que supera el salario promedio
 *
 */
int EmployeePromedy(Employee list[], int tam, float promedy);


#endif // LIB_TP2_H_INCLUDED
