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
 * @param  lista: Array Perritos
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
 * @param lista: array clientes.
 * @param len: tamaño de Perritos.
 * @param id: numero del ingreso del cliente.
 * @param nombresDuenio: nombre cliente.
 * @param telefonoContacto: numero de telefono del cliente.
 * @param idPerro: numero del ingreso del perrito.
 * @param fecha: el dia, mes y anio que eligio para la estadia.
 * @return retorna -1 o 0: "-1" si pudo realizar la funcion o "0" si no pudo realizar la funccion.
 */
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, int idDuenio, int idPerro, sFecha fecha);
/**
 * @fn int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria[], int)
 * @brief Esta funcion: Busca un id de un cliente mendiante un for, que recorre la la lista general.
 *
 * @param len: tamaño de la lista perrito.
 * @param id: Es la persona que encuentra la busqueda.
 * @return index 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len);
/**
 * @fn int EstadiaDiaria_buscarPorId(sEstadiaDiaria[], int, int)
 * @brief Esta funcion elimina un cliente ya ingresado, pregunta la id a eliminar y lo elimina,
 * dando de bajo a esa cliente.
 *
 * @param lista: array clientes.
 * @param len: tamaño de clientes.
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
 * @param lista: array clientes.
 * @param len: tamaño de clientes.
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
 */
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia, sDuenio duenio);
/**
 * @fn int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria[], int)
 * @brief Esta funcion ordena la estadia de los perritos fijandose de la fecha mas aprox y si son iguales las fechas lo ordena
 * por nombre alfabetico  con una funcion de comparar fecha y strcmp en forma ascendente.
 *
 * @param lista: array clientes.
 * @param len: tamaño de clientes.
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria listaEstadia[],sDuenio listaDuenio[], int lenDuenio,  int len);
/**
 * @fn int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria[], int)
 * @brief Esta funcion: Imprime la lista de todos los clinetes ingresados con sus datos, id ,nombre, telefono,
 * etc..
 * lo recorre mediante un for y una funcion que muestra una estadia.
 *
 * @param lista: array de perritos.
 * @param length: el tamaño de la lista de los perritos
 *
 * @return retorna 1 o -1: "1" si pudo realizar la funcion o "-1" si no pudo realizar la funccion.
 */
int EstadiaDiaria_mostrarPerroMasEstadia(sEstadiaDiaria listaEstadia[], sPerritos listaPerritos[], int len, int lenPerritos);
int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria listaEstadia[], sDuenio listaDuenio[], int length, int lenDuenio);
int EstadiaDiaria_mostrarTodasEstadiasPorPerro(sEstadiaDiaria listEstadias[], sPerritos listaPerro[], sDuenio listaDunio[], int length ,int lengthPerro, int lengthDuenio);
#endif /* ESTADIADIARIA_H_ */
