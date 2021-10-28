/*
 * dunio.h
 *
 *  Created on: 24 oct. 2021
 *      Author: Usuario
 */

#ifndef DUENIO_H_
#define DUENIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

typedef struct
{
	int id;
	char nombre[41];
	int telefono;
	int estadoDuenio;

}sDuenio;
/**
 * @fn int Duenio_iniciarLista(sDuenio[], int)
 * @brief
 *  Esta funcion recorre la "lista de duenios" para busacar el 1er espacio libre mediante un bucle for.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_iniciarLista(sDuenio lista[], int len);
/**
 * @fn int Duenio_agregarDuenio(sDuenio[], int, int, char[], int)
 * @brief Esta funcion agrega un duenio: si  el 1er espacio libre de la lista se ocupa. Se ingresan todos
 * los datos del cliente.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @param id: numero del ingreso del duenio.
 * @param nombre: Donde ingresa el nombre del duenio.
 * @param telefono: Donde ingresa el telefono el duenio
 * @return retorna -1 o 0: "-1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int Duenio_agregarDuenio(sDuenio lista[], int len, int id, char nombre[], int telefono);
/**
 * @fn int Duenio_buscarPorId(sDuenio[], int, int)
 * @brief Esta funcion elimina o busca un duenio ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa cliente.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @param id: numero del ingreso del duenio.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_buscarPorId(sDuenio lista[], int len, int id);
/**
 * @fn int Duenio_eliminarDuenio(sDuenio[], int, int)
 * @brief Esta funcion elimina un duenio  ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa duenio.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @param id: numero del ingreso del duenio.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_eliminarDuenio(sDuenio lista[], int len, int id);
/**
 * @fn int Duenio_contarDuenioActivos(sDuenio[], int, int*)
 * @brief Esta funcion cuenta la cantidad de duenios activos que se ingresaron, los elminados no,
 * mediante un contador.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @param auxContadorDuenio: cantidad de duenios que estan activos se van contando.
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_contarDuenioActivos(sDuenio lista[], int len, int* auxContadorDuenio);
/**
 * @fn int Duenio_imprimirListaDuenio(sDuenio[], int)
 * @brief Esta funcion: Imprime la lista de todos los duenios ingresados con sus datos,
 * etc..
 *
 * @param lista: Array Duenio.
 * @param length: Tamaño array.
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_imprimirListaDuenio(sDuenio lista[], int length);
/**
 * @fn void Duenio_mostrarUno(sDuenio)
 * @brief Esta funcion: Muestra los datos de un duenio, nombre, telefono, etc..
 *
 * @param duenio: recibe los datos del dunio.
 */
void Duenio_mostrarUno(sDuenio duenio);
/**
 * @fn int ConfirmarSioNoDuenio(char*)
 * @brief Esta funcion se usa para confirmar, el si o no de un duenio en este caso.
 *
 * @param mensaje: Lo que se mostrara en pantalla al usuario "algo que mostrar".
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int ConfirmarSioNoDuenio(char* mensaje);
/**
 * @fn int Duenio_buscarEspacioLibre(sDuenio[], int)
 * @brief Esta funcion: Busca un id de un duenio mendiante un for, que recorre la la lista general.
 *
 * @param lista: Array Duenio.
 * @param len: Tamaño array.
 * @return index 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Duenio_buscarEspacioLibre(sDuenio lista[], int len);
/**
 * @fn void Duenio_MostrarDatos()
 * @brief Esta funcion muestra un encabezado de un dunio: id, nombre y telefono.
 *
 */
void Duenio_MostrarDatos();
#endif /* DUENIO_H_ */
