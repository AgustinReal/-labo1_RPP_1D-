/*
 * fecha.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "inputs.h"
#include <ctype.h>
#include <conio.h>

int Fecha_pedirVerificarFecha(sFecha* fecha)
{
	int retorno=-1;
	int huboError=0;
	int diaAux;
	int mesAux;
	int anioAux;

	if(fecha!=NULL)
	{
		ingresoEntero(&diaAux, "Ingrese el dia para la estadia del perrito: ", "Error. Ingrese el dia para la estadia del perrito: ", 1, 31);
		ingresoEntero(&mesAux, "Ingrese el mes para la estadia del perrito: ", "Error. Ingrese el mes para la estadia del perrito: ", 1, 12);
		ingresoEntero(&anioAux, "Ingrese el anio para la estadia del perrito: ", "Error. Ingrese el anio para la estadia del perrito: ", 2020, 2101);

		if(mesAux>0 && mesAux<12)
		{
			switch(mesAux)
			{
				case  1:
				case  3:
				case  5:
				case  7:
				case  8:
				case 10:
				case 12:
					if (diaAux>0 && diaAux<31)
					{
						printf("\nFECHA CORRECTA");
					}
				break;
				case  4:
				case  6:
				case  9:
				case 11:
					if(diaAux>0 && diaAux<30)
					{
					   printf("\nFECHA CORRECTA");
					}
			    break;
				case 2:
					if((anioAux%4==0 && anioAux%100!=0) || anioAux%400==0)
					{
						if (diaAux>0 && diaAux<28)
						{
							printf("\nFECHA CORRECTA");
						}
					}
					else
					{
						if (diaAux>0 && diaAux<28)
						{
							printf("\nFECHA CORRECTA");
						}
					}
				break;
			}
		}
		else
		{
			printf("\nFECHA INCORRECTA");
			huboError=1;
			getch();
		}
	}

	if(huboError==0)
	{
		retorno=1;
		fecha->dia=diaAux;
		fecha->mes=mesAux;
		fecha->anio=anioAux;
	}

	return retorno;
}

int Fecha_AcpyB(sFecha fechaA, sFecha fechaB)
{
	int retorno;


	if(fechaA.dia>fechaB.dia && fechaA.mes==fechaB.mes && fechaA.anio==fechaB.anio)
	{
		retorno=1;
	}
	else if(fechaA.mes>fechaB.mes && fechaA.anio==fechaB.anio)
	{
		retorno=1;
	}
	else if(fechaA.anio>fechaB.anio)
	{
		retorno=1;
	}
	else if(fechaA.dia == fechaB.dia && fechaA.mes == fechaB.mes && fechaA.anio == fechaB.anio)
	{
		retorno=0;
	}
	else
	{
		retorno=-1;
	}


	return retorno;

}

int Fecha_modificarFecha(sFecha* fecha)
{
	int retorno=-1;

	if(fecha!=NULL)
	{

		Fecha_pedirVerificarFecha(fecha);
		retorno=1;
	}
	return retorno;
}

void Fecha_imprimirFecha(sFecha fecha)
{
	printf("%d/%d/%d", fecha.dia, fecha.mes, fecha.anio);
}



