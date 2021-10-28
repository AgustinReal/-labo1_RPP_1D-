/*
 * estadiaDiaria.h
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include "inputs.h"
#include "perritos.h"
#include "fecha.h"
#include "duenio.h"

typedef struct
{
	int id;
	int idDuenio;
	int idPerro;
	sFecha fecha;
	int estadoEstadiaVacio;

}sEstadiaDiaria;
/**
 * @fn int EstadiaDiaria_iniciarLista(sEstadiaDiaria[], int)
 * @brief Esta funcion recorre la "lista de clientes de perro" para busacar el 1er  espacio libre mediante un bucle for.
 *
 * @param  lista: Array Estadia
 * @param len: Tamaño array
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_iniciarLista(sEstadiaDiaria lista[], int len);
/**
 * @fn int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria[], int, int, char[], int, int, sFecha)
 * @brief Esta funcion agrega un cliente de perrito: si  el 1er espacio libre de la lista se ocupa. Se ingresan todos
 * los datos del cliente.
 *
 * @param lista: array Estadia.
 * @param len: tamanio de Estadia.
 * @param id: numero del ingreso del cliente.
 * @param idDuenio: id del duenio.
 * @param idPerro: numero del ingreso del perrito.
 * @param fecha: el dia, mes y anio que eligio para la estadia.
 * @return retorna -1 o 0: "-1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, int idDuenio, int idPerro, sFecha fecha);
/**
 * @fn int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria[], int)
 * @brief Esta funcion: Busca un id de un cliente mendiante un for, que recorre la la lista general.
 *
 * @param len: tamanio de la lista Estadia.
 * @param id: Es la persona que encuentra la busqueda.
 * @return index 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len);
/**
 * @fn int EstadiaDiaria_buscarPorId(sEstadiaDiaria[], int, int)
 * @brief Esta funcion elimina un cliente ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa cliente.
 *
 * @param lista: array Estadia.
 * @param len: tamanio de clientes.
 * @param id: numero de ingreso del cliente.
 *
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_buscarPorId(sEstadiaDiaria lista[], int len, int id);
/**
 * @fn int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria[], int, int)
 * @brief Esta funcion elimina una estadia  perrito ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa perrito.
 *
 * @param listaEstadia: array Estadia.
 * @param listaDuenio: array clientes.
 * @param len: tamanio de Estadia.
 * @param len: tamanio de Duenio.
 * @param id: numero de ingreso del cliente perrito.
 *
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria listaEstadia[], sDuenio listaDuenio[], int len, int id, int lenDuenio);
/**
 * @fn int ConfirmarSioNoEstadiaDiaria(char* mensaje)
 *@brief Esta funcion se usa para confirmar, el si o no de un cliente en este caso.
 *
 * @param mensaje: Lo que se mostrara en pantalla al usuario "algo que mostrar".
 * @return retorna 0 o -1: "0" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int ConfirmarSioNoEstadiaDiaria(char* mensaje);
/**
 * @fn void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria)
 * @brief Esta funcion: Muestra los datos de un cliente id, nombre, raza, etc...
 *
 * @param estadia recibe los datos de los ingreso de dicho cliente.
 * @param duenio recibe los datos del dunio
 */
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia, sDuenio duenio);
/**
 * @fn int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria[], int)
 * @brief Esta funcion ordena la estadia de los perritos fijandose de la fecha mas aprox y si son iguales las fechas lo ordena
 * por nombre alfabetico  con una funcion de comparar fecha y strcmp en forma ascendente.
 *
 * @param lista: array clientes.
 * @param len: tamanio de clientes.
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria listaEstadia[],sDuenio listaDuenio[], int lenDuenio,  int len);
/**
 * @fn int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria[], int)
 * @brief Esta funcion: Imprime la lista de todos los clinetes ingresados con sus datos, id ,idDuenio, ,
 * etc..
 * lo recorre mediante un for y una funcion que muestra una lista de estadia.
 *
 * @param listaEstadia: array de Estadia.
 * @param listaDuenio: array de duenio.
 * @param length: el tamanio de la lista de las estadias
 * @param lenDuenio: el tamanio de la lista de los duenios
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria listaEstadia[], sDuenio listaDuenio[], int length, int lenDuenio);
/**
 * @fn int EstadiaDiaria_mostrarPerroMasEstadia(sEstadiaDiaria[], sPerritos[], int, int)
 * @brief Esta funcion recorre la lista de perritos y verifica que el perrito tiene una estadia.
 * mediante un for y despues mediante un contador cuenta la cantidad de estadia de los perritos y mediante
 * una bandera se queda con el perrito con mas estadias
 *
 * @param listaEstadia: Lista de estadia
 * @param listaPerritos: Lista de perritos
 * @param len: Tamanio de la lista del array estadia
 * @param lenPerritos Tamanio de la lista del array perritos
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_mostrarPerroMasEstadia(sEstadiaDiaria listaEstadia[], sPerritos listaPerritos[], int len, int lenPerritos);
/**
 * @fn int EstadiaDiaria_mostrarTodasEstadiasPorPerro(sEstadiaDiaria[], sPerritos[], sDuenio[], int, int, int)
 * @brief Esta funcion muestra la estadia del perro con sus datos ingresados, con su duenio.
 * Se busca si el perrito fue ingresado con su duenio y se muestra en pantalla con sus datos,
 * se recorre la lista de perro y se imprime.
 *
 * @param listEstadias: Array de estadia
 * @param listaPerro: Array de perritos
 * @param listaDunio: Array de duenio
 * @param length:Tamanio de la lista del array estadia
 * @param lengthPerro: Tamanio de la lista del array perritos
 * @param lengthDuenio: el tamanio de la lista de los duenios
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_mostrarTodasEstadiasPorPerro(sEstadiaDiaria listEstadias[], sPerritos listaPerro[], sDuenio listaDunio[], int length ,int lengthPerro, int lengthDuenio);
#endif /* ESTADIADIARIA_H_ */
