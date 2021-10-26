/*
 * fecha.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int dia;
	int mes;
	int anio;

}sFecha;
/**
 * @fn int Fecha_pedirVerificarFecha(sFecha*)
 * @brief La funcion: Realiza 2 accion, primero pide una fecha al usuario dia, mes y anio
 * y ademas verifica la fecha obtenida por el usuario.
 *
 * @param fecha donde se va guardar la fecha y se realiza la verificaciones de los dias, meses y anios.
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Fecha_pedirVerificarFecha(sFecha* fecha);
/**
 * @fn int Fecha_AcpyB(sFecha, sFecha)
 * @brief Esta funcion: Compara fechas ingresada por el usuario y determina como pioridad a la fecha mas proxima.
 *
 * @param fechaA: 1er fecha ingresada por el usuario.
 * @param fechaB: 2da fecha ingresada por el usuario.
 * @return retorna 1 o 0 0 -1: "1" si la fecha A es major a la B  o "0" si las fechas A Y B  son iguales
 * o "-1" si la fecha B es mayor a la fecha A.
 */
int Fecha_modificarFecha(sFecha* fecha);
/**
 * @fn int Fecha_modificarFecha(sFecha*)
 * @brief Esta funcion: Permite modificar una fecha ingresada por el usuario
 * permitiendo cambiar dias, horas, anios..
 *
 * @param fecha: Es el parametro fecha que utlizamos para hacer el cambio de fecha.
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
void Fecha_imprimirFecha(sFecha fecha);
/**
 * @fn void Fecha_imprimirFecha(sFecha)
 * @brief Esta funcion: Permite mostrar una fecha ingresada por el usuario.
 *
 * @param fecha: Muestra los dias, meses, anios.
 */
int Fecha_AcpyB(sFecha fechaA,sFecha fechaB);

#endif /* FECHA_H_ */
