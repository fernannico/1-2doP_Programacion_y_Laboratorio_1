/*
 ============================================================================
 Name        : modeloEnduro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Controller.h"

int main(void) {
	setbuf(stdout,NULL);
	int option;
	char seguir;
	int banderaOpcion1 = 0;
	int banderaOpcion3 = 0;
	int banderaOpcion5 = 0;
	LinkedList* listaParticipantes = NULL;

	listaParticipantes = ll_newLinkedList();

	LinkedList* listaParticipantesOrdenada = NULL;

	do{
		printf( "\n\n|==============================|"
				"\n|            MENU              |\n|==============================|"
				"\n| 1 | CARGA DE ARCHIVOS        |\n|------------------------------|"
				"\n| 2 | LISTADOS                 |\n|------------------------------|"
				"\n| 3 | Asignar promedios:       |\n|------------------------------|"
				"\n| 4 | Filtrar por tipo:        |\n|------------------------------|"
				"\n| 5 | Mostrar orden posiciones:|\n|------------------------------|"
				"\n| 6 | Guardar posiciones csv   |\n|------------------------------|"
				"\n| 7 | SALIR                    |\n|==============================|");
		utn_getNumero(&option, "\nOpcion", "\nError", 1,7, 1);

		switch (option) {
			case 1:
				if(banderaOpcion1 == 0){
					if(controller_cargarParticipantesDesdeTexto("enduro.csv", listaParticipantes)==1){
						printf("\nLista cargada");
					}else{
						printf("\nLista no cargada");
					}
					banderaOpcion1 = 1;
				}
				break;
			case 2:
				if(banderaOpcion1 == 1){
					if(controller_listarParticipantes(listaParticipantes)==1){
						printf("\nLista cargada");
					}else{
						printf("\nLista no cargada");
					}
				}else{
					printf("\nfalta cargar los archivos");
				}
				break;
			case 3:
				if(banderaOpcion1 == 1){
					if(banderaOpcion3 == 0 && controller_mapearPromedio(listaParticipantes)==1){
						printf("\nLista cargada");
						banderaOpcion3 = 1;
					}else{
						printf("\nLista no cargada");
					}
				}else{
					printf("\nfalta cargar los archivos");
				}
				break;
			case 4:///Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan participantes de la categoría seleccionada.
				if(banderaOpcion1 == 1){
					if(controller_filtrarCategoria(listaParticipantes)==1){
						printf("\nLista cargada");
					}else{
						printf("\nLista no cargada");
					}
				}else{
					printf("\nfalta cargar los archivos");
				}
				break;
			case 5:///mostrar por pantalla un listado de los participantes ordenados por categoría y dentro de la misma categoría que aparezcan ordenadas por promedio ascendente.
				if(banderaOpcion1 == 1){
					if(banderaOpcion3 == 1 && banderaOpcion5 == 0){
						listaParticipantesOrdenada = ll_clone(listaParticipantes);
						if(listaParticipantesOrdenada != NULL){
							controller_ordenarParticipantes(listaParticipantesOrdenada);
							banderaOpcion5 = 1;
						}else{
							printf("\nfalta mapear los promedios");
						}
					}
				}else{
					printf("\nfalta cargar los archivos");
				}
				break;
			case 6:///Se deberá guardar el listado del punto anterior en un archivo de texto.
				if(banderaOpcion1 == 1){
					if(banderaOpcion5 == 1){
						if(controller_guardarParticipantesModoTexto("participantesOrdenados.csv", listaParticipantesOrdenada)==1){
							printf("\nArchivo creado");
						}else{
							printf("\nArchivo No creado");
						}
					}else{
						printf("\nfalta ordenar los participantes");
					}
				}else{
					printf("\nfalta cargar los archivos");
				}
				break;
			case 7:
				seguir = ValidarSeguirNoSeguir("\nEsta seguro que quiere salir? [S|N] ","\nError");
				break;
			default:
				break;
		}
	} while (seguir != 'S');

	return EXIT_SUCCESS;
}
