/*
 * bibliotecaTp1.h
 *
 *  Created on: 24 sep. 2021
 *      Author: German Molinari
 */

#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_


/** \brief muestra el menu, para que el usuario seleccione una opcion
 *
 * \param a int | se le pasa el parametro para que imprima
 * \param b int | se le pasa el parametro para que imprima
 * \return int |  retorna el entero que ingreso el usuario
 *
 */
int selecionarOpcion(int a, int b);


/** \brief sirve para que el usuario ingrese un entero para operar
 *
 * \return int | retorna el entero
 *
 */
int ingresarOperando();


/** \brief suma 2 enteros
 *
 * \param | enteros a sumar
 * \param | enteros a sumar
 * \return | retorna el resultado de la suma
 *
 */
int sumarEnteros (int a, int b);


/** \brief le resta el segundo entero al primero
 *
 * \param | primer entero
 * \param | segundo entero
 * \return | el resultado de la resta
 *
 */
int restarEnteros (int a, int b);


/** \brief multiplica dos enteros
 *
 * \param | enteros a multiplicar
 * \param | enteros a multiplicar
 * \return | retorna el resultado de la multiplicacion
 *
 */
int multiplicarEnteros (int a, int b);


/** \brief divide el primer entero por el segundo, guarda el resultado en una direccion de memoria de main y retorna 1 o 0 (si pudo o no pudo)
 *
 * \param | primer entero
 * \param | segundo entero
 * \param | direccion de memoria de la variable que guarda el resultado de la divicion
 * \return | retorna 0 o 1 dependiendo si pudo realizar la operacion
 *
 */
float dividirEnteros (int a, int b, float* resultado);

/** \brief factorea un entero
 *
 * \param | entero a factorear
 *
 * \return | retorna el resultado
 *
 */

int factoriarNumero (int a);







#endif /* BIBLIOTECATP1_H_ */
