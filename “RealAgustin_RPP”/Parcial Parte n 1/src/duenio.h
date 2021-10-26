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

int Duenio_iniciarLista(sDuenio lista[], int len);
int Duenio_agregarDuenio(sDuenio lista[], int len, int id, char nombre[], int telefono);
int Duenio_buscarPorId(sDuenio lista[], int len, int id);
int Duenio_eliminarDuenio(sDuenio lista[], int len, int id);
int Duenio_contarDuenioActivos(sDuenio lista[], int len, int* auxContadorDuenio);
int Duenio_imprimirListaDuenio(sDuenio lista[], int length);
void Duenio_mostrarUno(sDuenio duenio);
int ConfirmarSioNoDuenio(char* mensaje);
int Duenio_buscarEspacioLibre(sDuenio lista[], int len);
void Duenio_MostrarDatos();
#endif /* DUENIO_H_ */
