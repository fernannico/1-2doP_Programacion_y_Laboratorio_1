/*
 ============================================================================
 Name        : segParcialM.c
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
	int banderaOpcionUno = 0;
	char seguir;
	int banderaOpcionTres = 0;
	int banderaOpcionCinco = 0;
	char nombreArchivo[100];

	LinkedList* listaLibros = NULL;

	listaLibros = ll_newLinkedList();

	LinkedList* librosOrdenados = NULL;
	LinkedList* librosMapeados = NULL;

	do{
		printf( "\n\n|=============================|"
				"\n|            MENU             |\n|=============================|"
				"\n| 1 | CARGA DE ARCHIVOS       |\n|-----------------------------|"
				"\n| 2 | LISTAR LIBROS           |\n|-----------------------------|"
				"\n| 3 | ORDENAR Y LISTAR        |\n|-----------------------------|"
				"\n| 4 | GENERAR ARCHIVO ORDENADO|\n|-----------------------------|"
				"\n| 5 | MAPEAR IMPORTES		 |\n|-----------------------------|"
				"\n| 6 | GENERAR ARCHIVO MAPEADO |\n|-----------------------------|"
				"\n| 7 | SALIR                   |\n|=============================|");
		utn_getNumero(&option, "\nOpcion", "\nError", 1,7, 1);

		switch (option) {
			case 1:
				if(banderaOpcionUno == 0){
					printf("ingrese el nombre del arhivo a cargar: ");
					fflush(stdin);
					scanf("%s", nombreArchivo);
					if(controller_cargarLibrosDesdeTexto(nombreArchivo, listaLibros)==1){
						printf("\nlibros cargados");
						banderaOpcionUno = 1;
					}else{
						printf("\nlibros no cargados");
					}
				}
				break;
			case 2:
				if(banderaOpcionUno == 1){
					if(controller_listarLibros(listaLibros)==1){
						printf("\nlibros cargados");
					}else{
						printf("\nlibros no cargados");
					}
				}else{
					printf("\nFalta cargar el archivo");
				}
				break;
			case 3:
				if(banderaOpcionUno == 1 && banderaOpcionTres == 0){
					librosOrdenados = ll_clone(listaLibros);
					if(controller_ordenarLibros(librosOrdenados)==1){
						printf("\nlibros ordenados");
						banderaOpcionTres = 1;
					}else{
						printf("\nlibros no ordenados");
					}
				}else{
					printf("\nFalta cargar el archivo - ya se ordenaron los libros");
				}
				break;
			case 4:
				if(banderaOpcionUno == 1 && banderaOpcionTres == 1){
					if(controller_guardarLibrosModoTexto("ordenado.csv", librosOrdenados)==1){
						printf("\nlibros ordenados guardados en archivo ");
					}else{
						printf("\n no se guardaron los libros ordenados en un archivo ");
					}
				}else{
					printf("\nFalta cargar el archivo - ordenar los libros");
				}
				break;
			case 5:
				if(banderaOpcionUno == 1 && banderaOpcionCinco == 0){
					librosMapeados = ll_clone(listaLibros);
					if(controller_mapearImporte(librosMapeados)==1){
						printf("\n Importe de los libros mapeado");
						banderaOpcionCinco = 1;
					}else{
						printf("\n Importe de los libros NO mapeado");
					}
				}else{
					printf("\nFalta cargar el archivo- los importes ya fueron mapeados");
				}
				break;
			case 6:
				if(banderaOpcionUno == 1 && banderaOpcionCinco == 1){
					if(controller_guardarLibrosModoTexto("mapeado.csv", librosMapeados)==1){
						printf("\nlibros mapeados guardados en archivo ");
					}else{
						printf("\n no se guardaron los libros mapeados en un archivo ");
					}
				}else{
					printf("\nFalta cargar el archivo-mapear los importes");
				}
				break;
			case 7:
				seguir = ValidarSeguirNoSeguir("\nEsta seguro que quiere salir? [S|N] ","\nError");
				if(seguir == 'S'){
					ll_deleteLinkedList(librosOrdenados);
					ll_deleteLinkedList(librosMapeados);
					ll_deleteLinkedList(listaLibros);
				}
				break;
			default:
				break;
		}
	} while (seguir != 'S');
	return EXIT_SUCCESS;
}
