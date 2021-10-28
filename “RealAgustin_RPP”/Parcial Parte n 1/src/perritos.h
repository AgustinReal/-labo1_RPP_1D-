/*
 * perritos.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef PERRITOS_H_
#define PERRITOS_H_

#include "inputs.h"

#define LEN 5



typedef struct
{
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int estadoVacio;

}sPerritos;

/**
 * @fn int Perritos_iniciarLista(sPerritos[], int)
 * @brief Esta funcion recorre la "lista de perro" para busacar el 1er  espacio libre mediante un bucle for.
 *
 * @param lista: Array Perritos
 * @param len: Tamaño array
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Perritos_iniciarLista(sPerritos lista[], int len);
/**
 * @fn int Perritos_agregarPerrito(sPerritos[], int, int, char[], char[], int)
 * @brief Esta funcion agrega un perrito: si  el 1er espacio libre de la lista se ocupa. Se ingresan todos
 * los datos del usuario.
 *
 * @param lista: array Perritos.
 * @param len: tamaño de Perritos.
 * @param id: numero de ingreso del cliente.
 * @param nombre: nombre cliente.
 * @param raza: raza del perro.
 * @param edad: edad del perro.
 *
 * @return retorna -1 o 0: "-1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int Perritos_agregarPerrito(sPerritos lista[], int len, int id, char nombre[],char raza[],int edad);
/**
 * @fn int Perritos_buscarEspacioLibrePerrito(sPerritos[], int)
 * @brief  Esta funcion busca el estado libre de un perrito de la lista de perros general.
 *
 * @param lista: array de perritos.
 * @param len: tamaño de la lista perrito.
 *
 * @return index i o -1: "i" si pudo realizar la funcion y devuleve el espacio libre  o "-1" si no pudo realizar la funccion.
 */
int Perritos_buscarEspacioLibrePerrito(sPerritos lista[], int tam);
/**
 * @fn int Perritos_buscarPorIdPerrito(sPerritos[], int, int)
 * @brief Esta funcion: Busca un id de un perrito mendiante un for, que recorre la la lista general.
 *
 * @param lista: array de perritos.
 * @param len: tamaño de la lista perrito.
 * @param id: Es la persona que encuentra la busqueda.
 * @return index 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Perritos_buscarPorIdPerrito(sPerritos lista[], int len,int id);
/**
 * @fn int Perritos_eliminarPerrito(sPerritos[], int, int)
 * @brief Esta funcion elimina un perrito ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa perrito.
 *
 * @param lista: array Perritos.
 * @param len: tamaño de Perritos.
 * @param id: numero de ingreso del cliente.
 *
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Perritos_eliminarPerrito(sPerritos lista[], int len, int id);
/**
 * @fn void Perritos_mostrarUnPerrito(sPerritos)
 * @brief Esta funcion: Muestra los datos de un perrito id, nombre, raza, etc...
 *
 * @param perro recibe los datos de los ingreso de dicho perrito.
 */
void Perritos_mostrarUnPerrito(sPerritos perro);
/**
 * @fn int ConfirmarSioNoPerrito(char*)
 * @brief Esta funcion se usa para confirmar, el si o no de un perrito en este caso.
 *
 * @param mensaje: Lo que se mostrara en pantalla al usuario "algo que mostrar".
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int ConfirmarSioNoPerrito(char* mensaje);
/**
 * @fn int Perritos_contarPerritosActivos(sPerritos[], int, int*)
 * @brief  Esta funcion cuenta la cantidad de perritos activos que se ingresaron, los elminados no,
 * mediante un contador.
 *
 * @param lista: array de perritos.
 * @param len: tamaño de la lista perrito.
 * @param auxContadorPerritos: cantidad de perritos que estan activos se van contando.
 *
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Perritos_contarPerritosActivos(sPerritos lista[],int len, int* auxContadorPerritos);
/**
 * @fn float Perritos_SumaEdadesGeneral(sPerritos[], int, float*)
 * @brief Esta funcion: Realiaza la suma de todas las edades ingresadas de los  perritos y las va sumando
 * cada una.
 *
 * @param array de perritos.
 * @param len: tamaño de la lista perrito.
 * @param acumuladorEdadesPerritosAux: acumulador de edades de cada ingreso
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
float Perritos_SumaEdadesGeneral(sPerritos lista[],int len, float* acumuladorEdadesPerritosAux);
/**
 * @fn float Perritos_PromedioEdades(sPerritos[], int, float*, float*, int*)
 * @brief esta funcion realiza el promedio de las edades ingresadas, las sumas de todas las edades dividido
 * la cantidad de edades ingresadas.
 *
 * @param lista: array de perritos.
 * @param len: tamaño de la lista perrito.
 * @param promedio: donde se guardara el valor obtenido de la division.
 * @param acumuladorEdadesPerritosAux: acumulador de edades de cada ingreso
 * @param auxContadorPerritos: cantidad de perritos que estan activos se van contando.
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
float Perritos_PromedioEdades(sPerritos lista[],int len , float* promedio, float* acumuladorEdadesPerritosAux, int* auxContadorPerritos);
/**
 * @fn int Perritos_imprimirPerritos(sPerritos[], int)
 * @brief Esta funcion: Imprime todos los perritos ingresados por los diversos clientes.
 *
 * @param lista: array de perritos.
 * @param length: el tamaño de la lista de los perritos
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int Perritos_imprimirPerritos(sPerritos lista[], int length);
/**
 * @fn void Perritos_mostrarDatos()
 * @brief Esta funcion muestra un encabezado  de los datos de un perritos "nombre", "raza", etc....
 *
 */
void Perritos_mostrarDatos();
#endif /* PERRITOS_H_ */
