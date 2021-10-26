/*
 * inputs.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Agustin
 */
#include "inputs.h"

int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	int numeroIngresado;

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}

		*entero = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}
int validarSoloEntero(int* numero, char* mensaje, char* errorMensaje, int min, int max)
{
	int retorno=1;
	char auxCadenaNumero[200];
	int auxNumero;
	int banderaEstado;

	if(numero!=NULL && mensaje!=NULL && min<max)
	{
		banderaEstado=conseguirCadebaNumero(mensaje, auxCadenaNumero);
		auxNumero=atoi(auxCadenaNumero);

		while(banderaEstado!=0 || auxNumero<min || auxNumero>max)
		{
			banderaEstado=conseguirCadebaNumero(errorMensaje, auxCadenaNumero);
			auxNumero=atoi(auxCadenaNumero);
		}

		*numero=auxNumero;

		retorno=0;
	}

	return retorno;
}
int esNumero(char* cadena)
{
	int retorno=0;
	int i;
	int len;

	if(cadena != NULL)
	{
		len = strlen(cadena);
		for(i=0; i<len; i++)
		{
			if(cadena[i]<48 || cadena[i]>57)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}
int conseguirCadena(char* mensaje, char* cadena)
{
	int retorno=-1;
	char auxCadena[200];

	if(mensaje != NULL && cadena != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", auxCadena);

		strcpy(cadena, auxCadena);
		retorno=0;
	}

	return retorno;
}
int conseguirCadebaNumero(char* message, char* ingreso)
{
	int retorno=-1;
	char auxIngreso[200];

	if(message != NULL && ingreso != NULL)
	{
		if(conseguirCadena(message, auxIngreso)==0 && esNumero(auxIngreso)==0)
		{
			strcpy(ingreso, auxIngreso);
			retorno=0;
		}
	}

	return retorno;
}
int SoloLetras(char* palabra)
{
    int retorno=1;
    int i=0;

    if(palabra!=NULL)
    {
		while(palabra[i]!='\0')

		{
			if((palabra[i]!=' ')&&(palabra[i] < 'a'||  palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
			{
				retorno=-1;
			}
			i++;
		}
    }
			return retorno;
}

int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
	int retorno = -1;
	float numeroIngresado;

	if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotante = numeroIngresado;
		retorno = 0;
	}

	return retorno;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
	int retorno = -1;
	char buffer[256];
	int tam;

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);
		tam = strlen(buffer);

		while(tam > max || SoloLetras(buffer)==-1)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%[^\n]", buffer);
			tam = strlen(buffer);
		}


		strcpy(cadena, buffer);
		acomodarCadenaIngresada(cadena);
		retorno = 0;
	}

	return retorno;
}
int acomodarCadenaIngresada(char cadena[])
{
    int retorno=-1;
    int i=0;

    if(cadena!=NULL)
    {
        strlwr(cadena);
        cadena[0]=toupper(cadena[0]);

        while(cadena[i]!='\0')
        {
            if(cadena[i]==' ')
            {
                cadena[i+1]=toupper(cadena[i+1]);
            }
            i++;
        }
        retorno=1;
    }

    return retorno;
}
int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}





