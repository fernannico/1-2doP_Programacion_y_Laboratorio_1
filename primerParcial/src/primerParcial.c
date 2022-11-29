/*
 ============================================================================
 Name        : primerParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "libro.h"

int main(void) {
	setbuf(stdout, NULL);
	eEditorial editoriales[TAMEP];
	ePais paises[TAMEP];
	eAutor autores[TAMA];
	eLibro libros[TAML];
	eGenero generos[TAMG];
	int opcion;
	int codigoAutoIncremental;
	float acumuladorImportes;
	float promedioImportes;
	int contadorLibrosCargados;
	int contadorSuperanPromedio;
	int contadorLibrosSXX;

	acumuladorImportes= 0;
	contadorSuperanPromedio = 0;
	contadorLibrosSXX = 0;
	promedioImportes = 0;

	///contadores con libros harcodeados
	contadorLibrosCargados = 6;
	codigoAutoIncremental = 7;

	///contadores sin libros harcodeados
//	contadorLibrosCargados = 0;
//	codigoAutoIncremental = 1;

	inicializarEstadoLibros(libros, TAML);
	cargarEditorialesHarcodeadas(editoriales, TAMEP);
	cargarAutoresHarcodeadas(autores, TAMA);
	cargarPaisesHarcodeadas(paises, TAMEP);
	cargarGenerosHarcodeados(generos, TAMG);
	cargarLibrosHarcodeados(libros, TAML); //cambiar codigoAutoincremental

	do {
		mostrarMenuPrincipal();
		utn_getNumero(&opcion, "\nOpcion: ", "\nError, no existe esa opcion del menu", 1, 7, 1);
		switch (opcion) {
			case 1: //alta
				cargarLibros(libros, autores, editoriales, paises, generos, TAML, TAMA, TAMEP, &codigoAutoIncremental, TAMG);
				break;
			case 2: //modificacion
				modificarLibro(libros, editoriales, paises, autores, generos, TAML, TAMEP, TAMA, codigoAutoIncremental, TAMG);
				break;
			case 3: //baja
				darDeBaja(libros, autores, editoriales, generos, TAML, TAMA, TAMEP, codigoAutoIncremental, TAMG);
				break;
			case 4: //informar
				calcularInforme(libros, TAML, &acumuladorImportes, &contadorLibrosCargados, &promedioImportes, &contadorSuperanPromedio, &contadorLibrosSXX);
				break;
			case 5: //listar
				listarDetalles(editoriales, paises, autores, libros, generos, TAML, TAMA, TAMEP, TAMG);
				break;
			case 6:
				printf("\nSaliendo del programa");
				break;
			default:
				printf("\nError");
				break;
		}
	} while (opcion != 6);

	return EXIT_SUCCESS;
}




