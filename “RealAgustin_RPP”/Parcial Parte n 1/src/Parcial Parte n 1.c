/*
 ============================================================================
 Name        : Parcial.c
 Author      : Real Agustin 1D
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inputs.h"
#include "perritos.h"
#include "estadiaDiaria.h"
#include "duenio.h"


#define maxNombreDuenioPerro 51
#define maxNumeroTelefono 1199999999
#define minNumeroTelefono 1100000000
#define minIdPerro 7000
#define maxIdPerro 70000
#define minIdDuenio 1
#define maxIdDuenio 100000
#define minIdcontador 100000
#define maxIdcontador 1000000
#define largoPerritos 1000
#define largoDuenio 1000
#define largoListaClientes 1000
#define cantidadCharsPerritos 21
#define minEdadPerrito 1
#define maxEdadPerrito 15
int main(void)
{
	setbuf(stdout, NULL);
	sDuenio auxDuenio;
	sDuenio listaDuenio[largoDuenio];
	sEstadiaDiaria auxEstadia;
	sEstadiaDiaria listaClientesEstadia[largoListaClientes];
	sPerritos auxPerrito;
	sPerritos listaPerritos[largoPerritos];
	int auxIdDuenio;
	int option;
	int auxEstadoPosicionVacio;
	int contadorClientesActivo=0;
	int contadorPerritosActivo=0;
	int contadorId=100000;
	int contadorIdPerritos=7003;
	char afirmacion;
	int almacenarAuxIdModificar;
	int auxBuscarIndice;
	int contadorPerritos=0;
	float promedioPerritos;
	float acumuladorEdadesPerritos=0;
	int auxEstadoPosicionVacioPerro;
	int contadorAlan=0;


	Perritos_iniciarLista(listaPerritos, largoPerritos);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7000, "Lobo","Sharpie",2);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7001, "Sheila","Golden",12);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7002, "Reina","Galgo,",13);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7003, "Poppy","Galgo,",8);
	Perritos_agregarPerrito(listaPerritos, largoPerritos, 7004, "Garen","Pastor",2);
	EstadiaDiaria_iniciarLista(listaClientesEstadia, largoListaClientes);

	Duenio_iniciarLista(listaDuenio, largoDuenio);
	Duenio_agregarDuenio(listaDuenio, largoPerritos, 1, "Valentin", 1123345656);
	Duenio_agregarDuenio(listaDuenio, largoPerritos, 2, "Carlos", 1167345252);
	Duenio_agregarDuenio(listaDuenio, largoPerritos, 3, "Alan", 1132233445);
	Duenio_agregarDuenio(listaDuenio, largoPerritos, 4, "Tomas", 1121234335);
	Duenio_agregarDuenio(listaDuenio, largoPerritos, 5, "Lucia", 1123456523);



	do
	{
		ingresoEntero(&option, "---------------------------------------------------------------------------------\n"
								 "1.RESERVAR ESTADIA.\n"
								 "2.MODIFICAR ESTADIA.\n"
					             "3.CANCELAR ESTADÍA.\n"
								 "4.LISTAR ESTADÍAS:\n"
								 "5.LISTAR PERROS:\n"
								 "6.Promedio de edad de los perros.\n"
								 "7.El perro que tiene más estadías reservadas.\n"
								 "8.Listado de perros con sus estadías diarias reservadas.\n"
								 "9.ALTA DE PERRO.\n"
								 "10.LA CANTIDAD DE DUENIOS QUE SE LLAMAN ALAN Y QUE, A SU VEZ, TIENEN AL MENOS UN ESTADIA RESERVADA.\n"
								 "11.LISTADO DE ESTADIAS REALIZADAS POR DUENIOS QUE SE LLAMAN LUCIA Y CUYA FECHA DE RESERVA ES DURANTE LA SEGUNDA QUINCENA DE NOVIEMBRE 2021.\n"
								 "12.SALIR\n"
								 "---------------------------------------------------------------------------------\n"
								 "Ingrese una opcion: ",

								 "1.RESERVAR ESTADIA\n"
								 "2.MODIFICAR ESTADIA.\n"
								 "3.CANCELAR ESTADÍA.\n"
								 "4.LISTAR ESTADÍAS:\n"
								 "5.LISTAR PERROS:\n"
								 "6.Promedio de edad de los perros.\n"
								 "7.El perro que tiene más estadías reservadas.\n"
								 "8.Listado de perros con sus estadías diarias reservadas.\n"
								 "9.ALTA DE PERRO.\n"
								 "10.LA CANTIDAD DE DUENIOS QUE SE LLAMAN ALAN Y QUE, A SU VEZ, TIENEN AL MENOS UN ESTADIA RESERVADA.\n"
								 "11.LISTADO DE ESTADIAS REALIZADAS POR DUENIOS QUE SE LLAMAN LUCIA Y CUYA FECHA DE RESERVA ES DURANTE LA SEGUNDA QUINCENA DE NOVIEMBRE 2021.\n"
								 "12.SALIR\n"
								 "---------------------------------------------------------------------------------\n"
								 "Opcion invalida, reingrese: ",1, 11);


			switch(option)
			{
			case 1:
				auxEstadoPosicionVacio=EstadiaDiaria_buscarEspacioLibre(listaClientesEstadia, largoListaClientes);
				if(auxEstadoPosicionVacio!=-1)
				{
					ingresoEntero(&auxEstadia.idDuenio, "Ingrese la id del duenio de la estadia(1-3000): ", "Error. Ingrese la id del duenio de la estadia(1-3000):", minIdDuenio, maxIdDuenio);
					ingresoEntero(&auxEstadia.idPerro, "Ingrese la id del perro del cliente de la estadia(7000-70000): ", "Error. Ingrese la id del perro del cliente de la estadia(7000-70000):", minIdPerro, maxIdPerro);
					Fecha_pedirVerificarFecha(&auxEstadia.fecha);
					auxEstadia.id=contadorId;

					printf("\n");
					EstadiaDiaria_agregarEstadiaDiaria(listaClientesEstadia, largoListaClientes, auxEstadia.id, auxEstadia.idDuenio, auxEstadia.idPerro, auxEstadia.fecha);
					contadorId++;
					contadorClientesActivo++;

					printf("------------------------------------------------------------------------------------------------------------------\n");
					EstadiaDiaria_imprimirListaEstadiaDiaria(listaClientesEstadia, listaDuenio, largoListaClientes, largoDuenio);
					printf("------------------------------------------------------------------------------------------------------------------\n");

					pedirCaracter(&afirmacion,"\n\nPresione S para agregar al cliente ingresado: ");
					if(afirmacion=='s' || afirmacion=='S')
					{
						printf("El nuevo el cliente fue agregado....\n");
						getchar();
					}
					else
					{
						printf("Se ha producido un error...\n");
					}
				}
				else
				{
					printf("El sistema esta lleno vuelva en otras instancias\n");
				}
				printf("Presione un boton para continuar...\n");
				getchar();

				break;
			case 2:
				if(contadorClientesActivo>0)
				{
					ingresoEntero(&almacenarAuxIdModificar, "Cual es id que desea modifcar: ", "Error. Cual es id que desea modifcar: ", minIdcontador, maxIdcontador);
					auxBuscarIndice=EstadiaDiaria_buscarPorId(listaClientesEstadia, largoListaClientes, almacenarAuxIdModificar);
					if(listaClientesEstadia[auxBuscarIndice].estadoEstadiaVacio==0)
					{
						auxIdDuenio=Duenio_buscarPorId(listaDuenio, largoDuenio, listaClientesEstadia[auxBuscarIndice].idDuenio);
						auxDuenio=listaDuenio[auxIdDuenio];
						EstadiaDiaria_mostrarUnaEstadia(listaClientesEstadia[auxBuscarIndice], auxDuenio);
						do
						{

							ingresoEntero(&option,"--------------------------------------------------------------------------------\n"
												"1-MODIFICAR El teléfono de contacto.\n"
												"2-MODIFICAR El perro.\n"
												"3-SALIR.\n"
												"--------------------------------------------------------------------------------\n"
												"Ingrese una opcion: ",

												"1-MODIFICAR El teléfono de contacto.\n"
												"2-MODIFICAR El perro.\n"
												"3-SALIR\n"
												"--------------------------------------------------------------------------------\n"
												"Opcion invalida, reingrese: ", 1, 3);
							switch(option)
							{
								case 1:
									ingresoEntero(&listaDuenio[auxIdDuenio].telefono, "Ingrese el nuevo numero de telefono del cliente de la estadia: ", "Error.Ingrese el nuevo numero de telefono del cliente de la estadia: ", minNumeroTelefono, maxNumeroTelefono);
									break;
								case 2:
									ingresoEntero(&listaClientesEstadia[auxBuscarIndice].idPerro, "Ingrese la nueva id del perro del cliente de la estadia: ", "Error. Ingrese la nueva id del perro del cliente de la estadia:", minIdPerro, maxIdPerro);
									break;

							}
							auxIdDuenio=Duenio_buscarPorId(listaDuenio, largoDuenio, listaClientesEstadia[auxBuscarIndice].idDuenio);
							auxDuenio=listaDuenio[auxIdDuenio];
							EstadiaDiaria_mostrarUnaEstadia(listaClientesEstadia[auxBuscarIndice], auxDuenio);
						}while(option!=3);
					}
					else
					{
						printf("No se indentifico ese cliente\n");
					}
				}
				else
				{
					printf("No se ha ingresado ningun cliente...\n");
				}
				option=0;
				break;
			case 3:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_eliminarPerroEstadia(listaClientesEstadia, listaDuenio, largoListaClientes, almacenarAuxIdModificar, largoDuenio);
				}
				else
				{
					printf("No se ha ingresado ningun cliente...\n");
				}
				break;
			case 4:
				printf("Listado estadias diasrias Perritos.\n");
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_orderEstadiaPerrito(listaClientesEstadia, listaDuenio, largoDuenio, largoListaClientes);
					EstadiaDiaria_imprimirListaEstadiaDiaria(listaClientesEstadia, listaDuenio, largoListaClientes, largoDuenio);
				}
				else
				{
					printf("No se puedo mostrar la lista de estadia...\n");
				}
				break;
			case 5:
				printf("Mostrar los perritos...\n");
				if(contadorClientesActivo>0)
				{
					Perritos_imprimirPerritos(listaPerritos, largoPerritos);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 6:
				if(contadorClientesActivo>0)
				{
					Perritos_contarPerritosActivos(listaPerritos, largoPerritos, &contadorPerritos);
					Perritos_SumaEdadesGeneral(listaPerritos, largoPerritos, &acumuladorEdadesPerritos);
					Perritos_PromedioEdades(listaPerritos, largoPerritos, &promedioPerritos, &acumuladorEdadesPerritos, &contadorPerritos);
					printf("El promedio de los perritos es: %.2f\n", promedioPerritos);
				}
				else
				{
					printf("No se puedo mostrar el promedio de los perritos...\n");
				}
				break;
			case 7:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_mostrarPerroMasEstadia(listaClientesEstadia, listaPerritos, largoListaClientes, largoPerritos);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 8:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_mostrarTodasEstadiasPorPerro(listaClientesEstadia, listaPerritos, listaDuenio, largoListaClientes , largoPerritos, largoDuenio);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 9:
				if(contadorClientesActivo>0)
				{
					auxEstadoPosicionVacioPerro=Perritos_buscarEspacioLibrePerrito(listaPerritos, largoPerritos);
					if(auxEstadoPosicionVacioPerro!=-1)
					{
						pedirCadena(auxPerrito.nombre, "Ingrese el nombre del perrito: ", "Error. Ingrese el nombre del perrito:", cantidadCharsPerritos);
						pedirCadena(auxPerrito.raza, "Ingrese la raza del perrito: ", "Error. Ingrese la raza del perrito: ", cantidadCharsPerritos);
						ingresoEntero(&auxPerrito.edad, "Ingrese la edad del perrito: ", "Error. Ingrese la edad del perrito: ", minEdadPerrito, maxEdadPerrito);
						auxPerrito.id=contadorIdPerritos;
						printf("\n");
						Perritos_agregarPerrito(listaPerritos, largoPerritos, auxPerrito.id, auxPerrito.nombre, auxPerrito.raza, auxPerrito.edad);
						contadorIdPerritos++;
						contadorPerritosActivo++;

						printf("------------------------------------------------------------------------------------------------------------------\n");
						Perritos_imprimirPerritos(listaPerritos, largoPerritos);
						printf("------------------------------------------------------------------------------------------------------------------\n");

						pedirCaracter(&afirmacion,"\n\nPresione S para agregar el perrito ingresado: ");
						if(afirmacion=='s' || afirmacion=='S')
						{
							printf("El nuevo perrito fue agregado....\n");
							getchar();
						}
						else
						{
							printf("Se ha producido un error...\n");
						}
					}
					else
					{
						printf("El sistema esta lleno vuelva en otras instancias\n");
					}
					printf("Presione un boton para continuar...\n");
					getchar();
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 10:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_cantidadDuenioSellamanAlanYTieneEstadia(listaClientesEstadia, listaDuenio, largoListaClientes, largoDuenio, &contadorAlan);
					printf("La cantidad de personas que se llaman ALan es: %d\n", contadorAlan);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			case 11:
				if(contadorClientesActivo>0)
				{
					EstadiaDiaria_ListadoEstadiasRealizadasLLamadaLuciaYFechaSegundaQuiencenaNoviembre(listaClientesEstadia,  listaDuenio, largoListaClientes, listaDuenio, auxEstadia.fecha);
				}
				else
				{
					printf("No se puedo mostrar la lista de perritos...\n");
				}
				break;
			}

		}while(option!=12);


	return EXIT_SUCCESS;
}
