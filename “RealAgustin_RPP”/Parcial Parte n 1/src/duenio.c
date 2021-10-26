/*
 * duenio.c
 *
 *  Created on: 24 oct. 2021
 *      Author: Usuario
 */

#include "duenio.h"

int Duenio_iniciarLista(sDuenio lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{

			lista[i].estadoDuenio=1;
		}
		retorno=1;
	}
	return retorno;
}
int Duenio_agregarDuenio(sDuenio lista[], int len, int id, char nombre[], int telefono)
{
	int retorno=-1;

	int index;

	index=Duenio_buscarEspacioLibre(lista, len);
	if(index!=-1)
	{
		printf("\nCargando la lista en espacios libres espere unos segundos...\n");
		if(lista!=NULL && lista[index].estadoDuenio==1)
		{

			lista[index].id=id;
			strcpy(lista[index].nombre, nombre);
			lista[index].telefono=telefono;
			lista[index].estadoDuenio=0;
		}
		else
		{
			printf("\nError ya se cargo la lista no hay espacios disponibles...\n");
		}
		retorno=0;
	}
	else
	{
		printf("\nNo se pudo cargar...\n");
		retorno=-1;
	}
	return retorno;
}
void Duenio_MostrarDatos()
{
	printf("%-15s %-20s %-20s \n", "ID", "Nombre", "Telefono");
}
int Duenio_eliminarDuenio(sDuenio lista[], int len, int id)
{
	int retorno=-1;
	int index;
	int idIngresado;

	if(lista!=NULL)
	{
		pedirEntero(&idIngresado,"Ingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", "Reingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", 100000, 1000000);
		index=Duenio_buscarPorId(lista, len, idIngresado);

		if(index!=-1)
		{
			Duenio_mostrarUno(lista[index]);

			if(!ConfirmarSioNoDuenio("\nIngrese 's' para confirmar la eliminacion del perrito de la estadia."))
			{
				lista[index].estadoDuenio=1;
				printf("\nEl perrito de la estadia %s fue eliminado correctamente!\n\n", lista[index].nombre);
				retorno=0;
			}
			else
			{
				printf("\nSe cancelo la eliminacion...\n\n");
			}
		}
		else
		{
			printf("\nError. No se encontro la estadia del perrito...");
		}
	}
	return retorno;
}
int Duenio_imprimirListaDuenio(sDuenio lista[], int length)
{
	int retorno=-1;

	if(lista!=NULL)
	{

		for(int i=0;i<length;i++)
		{
			if(lista[i].estadoDuenio==0)
			{
				Duenio_mostrarUno(lista[i]);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

}
int Duenio_contarDuenioActivos(sDuenio lista[], int len, int* auxContadorDuenio)
{
	int retorno=-1;
	*auxContadorDuenio=0;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estadoDuenio==0)
			{
				*auxContadorDuenio+=1;
				retorno=1;
			}
		}
	}
	return retorno;
}
int Duenio_buscarPorId(sDuenio lista[], int len, int id)
{
	int index=-1;

	if(lista!=NULL )
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estadoDuenio==0 && lista[i].id==id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}
void Duenio_mostrarUno(sDuenio duenio)
{
	printf("%-5d %-20s %-20d\n", duenio.id, duenio.nombre, duenio.telefono);
}
int ConfirmarSioNoDuenio(char* mensaje)
{
	int retorno=-1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);

	if(respuesta=='s' || respuesta=='S')
	{
		retorno=0;
	}

	return retorno;
}
int Duenio_buscarEspacioLibre(sDuenio lista[], int len)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i].estadoDuenio==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

