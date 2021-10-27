/*
 * estadiaDiaria.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estadiaDiaria.h"
#include "perritos.h"
#include "inputs.h"
#include "duenio.h"
#include <ctype.h>

int EstadiaDiaria_iniciarLista(sEstadiaDiaria lista[], int len)
{
	int retorno=-1;

	if(lista!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			lista[i].estadoEstadiaVacio=1;
		}
		retorno=1;
	}
	return retorno;
}
int EstadiaDiaria_agregarEstadiaDiaria(sEstadiaDiaria lista[], int len, int id, int idDuenio, int idPerro, sFecha fecha)
{
	int retorno=-1;

	int index;
	  index=EstadiaDiaria_buscarEspacioLibre(lista, len);
		if(index!=-1)
		{
			printf("\nCargando la lista en espacios libres espere unos segundos...\n");
			if(lista!=NULL && lista[index].estadoEstadiaVacio==1)
			{
				lista[index].id=id;
				lista[index].idDuenio=idDuenio;
				lista[index].idPerro=idPerro;
				lista[index].fecha=fecha;
				lista[index].estadoEstadiaVacio=0;

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

int EstadiaDiaria_eliminarPerroEstadia(sEstadiaDiaria listaEstadia[], sDuenio listaDuenio[], int len, int id, int lenDuenio)
{
	int retorno=-1;
	int index;
	int idIngresado;
	int auxIdDuenio;
	sDuenio auxDuenio;

	if(listaEstadia!=NULL && listaDuenio!=NULL)
	{
		ingresoEntero(&idIngresado,"Ingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", "Reingrese el ID del cliente de la estadia a borrar de (100000-1000000): ", 100000, 1000000);
		index=EstadiaDiaria_buscarPorId(listaEstadia, len, idIngresado);

		if(index!=-1)
		{
			auxIdDuenio=Duenio_buscarPorId(listaDuenio, lenDuenio, listaEstadia[index].idDuenio);
			auxDuenio=listaDuenio[auxIdDuenio];
			printf("\n");
			EstadiaDiaria_mostrarUnaEstadia(listaEstadia[index], auxDuenio);

			if(!ConfirmarSioNoEstadiaDiaria("\nIngrese 's' para confirmar la eliminacion del perrito de la estadia: "))
			{
				listaEstadia[index].estadoEstadiaVacio=1;
				printf("\nEl perrito de la estadia %d fue eliminado correctamente!\n\n", listaEstadia[index].id);
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
int EstadiaDiaria_orderEstadiaPerrito(sEstadiaDiaria listaEstadia[],sDuenio listaDuenio[], int lenDuenio,  int len)
{

	int retorno=-1;
	int auxDuenioUno;
	int auxDuenioDos;
	sEstadiaDiaria auxLista;

	if(listaEstadia!=NULL && listaDuenio!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				auxDuenioUno=Duenio_buscarPorId(listaDuenio, lenDuenio, listaEstadia[i].idDuenio);
				auxDuenioDos=Duenio_buscarPorId(listaDuenio, lenDuenio, listaEstadia[j].idDuenio);

				if(Fecha_AcpyB(listaEstadia[i].fecha, listaEstadia[j].fecha)==-1)
				{
					auxLista=listaEstadia[i];
					listaEstadia[i]=listaEstadia[j];
					listaEstadia[j]=auxLista;
				}
				else if((Fecha_AcpyB(listaEstadia[i].fecha, listaEstadia[j].fecha)==0) && strcmp(listaDuenio[auxDuenioUno].nombre, listaDuenio[auxDuenioDos].nombre)>0)
				{
					auxLista=listaEstadia[i];
					listaEstadia[i]=listaEstadia[j];
					listaEstadia[j]=auxLista;
				}
			}
		}

		retorno=1;
	}

	return retorno;
}
int EstadiaDiaria_mostrarPerroMasEstadia(sEstadiaDiaria listaEstadia[], sPerritos listaPerritos[], int len, int lenPerritos)
{
	int retorno=-1;
	int auxIdPerro;
	int contadorEstadiaActual=0;
	int estadiaMax=0;
	sPerritos perroMasEstadias;

	if(listaEstadia!=NULL && listaPerritos!=NULL)
	{
		for(int i=0;i<lenPerritos;i++)
		{
			auxIdPerro=listaEstadia[i].idPerro;
			if(listaPerritos[i].estadoVacio==0)
			{
				if(listaEstadia[i].estadoEstadiaVacio==0 && listaEstadia[i].idPerro==auxIdPerro)
				{
					contadorEstadiaActual++;
				}
			}
			if(contadorEstadiaActual>estadiaMax)
			{
				estadiaMax=contadorEstadiaActual;
				perroMasEstadias=listaPerritos[i];
			}
			retorno=1;
		}
		printf("El perro que tiene mas estadias es: \n");
		Perritos_mostrarDatos();
		Perritos_mostrarUnPerrito(perroMasEstadias);
		printf("La cantidad de estadias es: %d\n",estadiaMax);
	}

	return retorno;
}
int EstadiaDiaria_mostrarTodasEstadiasPorPerro(sEstadiaDiaria listEstadias[], sPerritos listaPerro[], sDuenio listaDunio[], int length ,int lengthPerro, int lengthDuenio)
{

    int retorno =-1;
    int auxIdPerro;
    sDuenio auxDuenio;
    int auxIndex;

    if(listEstadias!=NULL && listaPerro!=NULL && listaDunio!=NULL)
    {
        for (int i=0;i<lengthPerro;i++)
        {
            if(listaPerro[i].estadoVacio==0)
            {
                printf("\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");
                auxIdPerro=listaPerro[i].id;
                Perritos_mostrarDatos();
                Perritos_mostrarUnPerrito(listaPerro[i]);
                printf("\n");

                for(int j=0; j<length; j++)
                {
                    if(listEstadias[j].estadoEstadiaVacio==0 && listEstadias[j].idPerro==auxIdPerro)
                    {
                      printf("Fecha de estadia :");
                      Fecha_imprimirFecha(listEstadias[j].fecha);
                      printf("    |Id Duenio: %d", listEstadias[i].idDuenio);

                      auxIndex=Duenio_buscarPorId(listaDunio, lengthDuenio, listEstadias[j].idDuenio);
                      auxDuenio=listaDunio[auxIndex];
                      printf("    | nombre Duenio: %s", auxDuenio.nombre);
                      printf("    | numero de contacto: %d\n", auxDuenio.telefono);

                    }
                retorno=1;
                }

            }
        }
    }
    return retorno;
}
void EstadiaDiaria_mostrarUnaEstadia(sEstadiaDiaria estadia, sDuenio duenio)
{

	printf("%-10d %-15d %-20s %-20d  %-20d  %d-%d-%d \n", estadia.id, estadia.idDuenio, duenio.nombre, duenio.telefono, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);
}

int EstadiaDiaria_imprimirListaEstadiaDiaria(sEstadiaDiaria listaEstadia[], sDuenio listaDuenio[], int length, int lenDuenio)
{
	int retorno=-1;
	int auxIdDuenio;
	sDuenio auxDuenio;

	if(listaEstadia!=NULL && listaDuenio!=NULL)
	{

		for(int i=0;i<length;i++)
		{
			if(listaEstadia[i].estadoEstadiaVacio==0)
			{
				auxIdDuenio=Duenio_buscarPorId(listaDuenio, lenDuenio, listaEstadia[i].idDuenio);
				auxDuenio=listaDuenio[auxIdDuenio];
				EstadiaDiaria_mostrarUnaEstadia(listaEstadia[i], auxDuenio);
			}
		}
		printf("\n");
	 retorno=1;
	}

	return retorno;

}
int ConfirmarSioNoEstadiaDiaria(char* mensaje)
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
int EstadiaDiaria_buscarPorId(sEstadiaDiaria lista[], int len,int id)
{
	int index=-1;

	if(lista!=NULL )
	{
		for(int i=0;i<len;i++)
		{
			if(lista[i].estadoEstadiaVacio==0 && lista[i].id==id)
			{
				index=i;
				break;
			}
		}
	}
	return index;
}
int EstadiaDiaria_buscarEspacioLibre(sEstadiaDiaria lista[], int len)
{
	int i;
	int index=-1;

	if(lista!=NULL)
	{
		for(i=0; i<len; i++)
		{
			if(lista[i].estadoEstadiaVacio==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}




