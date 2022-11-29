/*
 * libro.c
 *
 *  Created on: 1 oct. 2022
 *      Author: User
 */

#include "libro.h"

void cargarEditorialesHarcodeadas(eEditorial editoriales[], int size){
	int i;
	eEditorial auxiliar[] = { {1, "editorial1", CARGADO}, {2, "editorial2", CARGADO},
							  {3, "editorial3", CARGADO}, {4, "editorial4", CARGADO}, {5, "editorial5", CARGADO} };
	for(i = 0; i<size; i++){
		editoriales[i] = auxiliar[i];
	}
}

void cargarAutoresHarcodeadas(eAutor autores[], int size){
	int i;
	eAutor auxiliar[] = { {1, "Autor1", 1, CARGADO}, {2, "Autor2", 1, CARGADO}, {3, "Autor3", 1, CARGADO},
					 {4, "Autor4", 4, CARGADO}, {5, "Autor5", 1, CARGADO}, {6, "Autor6", 2,  CARGADO},
					 {7, "Autor7", 3, CARGADO}, {8, "Autor8", 1, CARGADO}, {9, "Autor9", 5, CARGADO}, {10, "Autor10", 1, CARGADO} };
	for(i = 0; i<size; i++){
		autores[i] = auxiliar[i];
	}
}

void cargarPaisesHarcodeadas(ePais paises[], int size){
	int i;
	ePais auxiliar[] = { {1, "Argentina", CARGADO}, {2, "Bolivia", CARGADO},
						 {3, "Brasil", CARGADO}, {4, "Chile", CARGADO}, {5, "Paraguay", CARGADO} };
	for(i = 0; i<size; i++){
		paises[i] = auxiliar[i];
	}

}

void cargarLibrosHarcodeados(eLibro libros[], int sizeLibros){
	int i;

	eLibro auxiliar[] = { {1, "arte de guerra", {9, 10, 22}, 900, 4, 5, CARGADO, 1}, {2, "la biblia", {8, 9, 1}, 900, 5, 4, CARGADO, 2},
						  {3, "Harry potter", {7, 8, 1999}, 900, 5, 3, CARGADO,3}, {4, "el principito", {6, 7, 1960}, 1600, 5, 2, CARGADO,4},
						  {5, "el alquimista", {5, 6, 1988}, 1600, 5, 1, CARGADO,5}, {6, "codigo DaVinci", {4, 5, 2003}, 1600, 5, 5, CARGADO,1}};
	for(i = 0; i<sizeLibros; i++){
		libros[i] = auxiliar[i];
	}
}

void cargarGenerosHarcodeados(eGenero generos[], int sizeGenero){
	int i;

	eGenero auxiliar[] = { {1, "Narrativo"}, {2, "Lirico"}, {3, "Dramatico"}, {4, "Didactico"}, {5, "Novela"} };
	for(i = 0; i < sizeGenero; i++){
		generos[i] = auxiliar[i];
	}
}

///HARCODEOS
///----------------------------------------------------------------------------------------------------------------------------------

void inicializarEstadoLibros(eLibro libros[], int sizeLibros){
	int i;

	for(i = 0; i<sizeLibros; i++){
		libros[i].estado = LIBRE;
	}
}

int buscarEspacioLibre(eLibro libros[], int sizeLibro){
	int indiceLibre = -1;
	int i;

	for(i = 0; i < sizeLibro; i++){
		if(libros[i].estado == LIBRE){
			indiceLibre = i;
			break;
		}
	}
	return indiceLibre;
}

int validarPresenciaCargado(eLibro libros[], int size){
	int retorno = 0;
	int i;

	for(i = 0; i<size; i++){
		if(libros[i].estado == CARGADO){
			retorno = 1;
			break;
		}
	}

	return retorno;
}

void cargarLibros(eLibro libros[], eAutor autores[], eEditorial editoriales[], ePais paises[], eGenero generos[],int sizeLibros, int sizeAutores, int sizeEditPaises, int* codigoAutoIncremental, int sizeGeneros){
	char seguir;

	if(*codigoAutoIncremental < sizeLibros){
		do {
			if(altaLibro(libros, autores, editoriales, paises, generos, sizeLibros, sizeAutores, sizeEditPaises, *codigoAutoIncremental, sizeGeneros) == 1){
				printf("\nSe cargo el libro correctamente");
				*codigoAutoIncremental = *codigoAutoIncremental+1;
			}else{
				printf("\nNo se pudo realizar la carga");
			}
			seguir = validarSeguirNoSeguir("\nIngresar otro libro? [S|N]", "\nError", 1);
		} while (seguir == 'S' && *codigoAutoIncremental < sizeLibros);
	}else{
		printf("\nYa estan todos los libros cargados");
	}
}

int altaLibro(eLibro libros[], eAutor autores[], eEditorial editoriales[], ePais paises[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEmpPais, int codigoAutoIncremental, int sizeGeneros){
	int retorno;
	int indice;

	retorno = -1;
	indice = buscarEspacioLibre(libros, sizeLibros);

	if(indice > -1 && indice < sizeLibros){
		libros[indice].idLibro = codigoAutoIncremental;
		//Cargar titulo
		if(pedirCadena(libros[indice].titulo, 51, "\ningrese el titulo") == 1){
			//Cargar fecha
			if(cargarFecha(libros, indice) == 1){
				printf("\nFecha cargada con exito\n");
				//Cargar importe
				if(utn_getNumeroFlotante(&libros[indice].importe, "\ningrese el importe del libro", "\nError", 1, 100000, 1)==0){
					//Cargar autor
					mostrarDetallesAutores(autores, paises, sizeAutores, sizeEmpPais);
					if(utn_getNumero(&libros[indice].idAutor, "\nIngrese el codigo del autor del libro", "\nError", 1, 10, 1)==0){
						//Cargar editorial y estado
						mostrarDetallesEditoriales(editoriales, sizeEmpPais);
						if(utn_getNumero(&libros[indice].idEditorial, "\nIngrese el codigo de la editorial", "\nError", 1, 5, 1)==0){
							//Cargar generos
							mostrarDetallesGeneros(generos, sizeGeneros);
							if(utn_getNumero(&libros[indice].idGenero, "\nIngrese el genero de libro: ", "\nError, no existe ese genero", 1, 5, 1) == 0){
								libros[indice].estado = CARGADO;
								retorno = 1;
							}
						}
					}
				}
			}else{
				printf("\nFecha cargada sin exito");
			}
		}else{
			printf("\nTitulo cargado sin exito");
		}
	}

	return retorno;
}

int cargarFecha(eLibro libro[], int posicion){
	int retorno;
	int maximo;

	if( utn_getNumero(&libro[posicion].fechaPublicacion.mes, "\ningrese el mes de publicacion", "\nNo existe ese mes", 1, 12, 2) == 0 ){
		if( libro[posicion].fechaPublicacion.mes == 1 || libro[posicion].fechaPublicacion.mes == 3 || libro[posicion].fechaPublicacion.mes == 5 ||
			libro[posicion].fechaPublicacion.mes == 7 || libro[posicion].fechaPublicacion.mes == 8 || libro[posicion].fechaPublicacion.mes == 10 || libro[posicion].fechaPublicacion.mes == 12){
			maximo = 31;
		}else{
			if(libro[posicion].fechaPublicacion.mes == 4 || libro[posicion].fechaPublicacion.mes == 6 || libro[posicion].fechaPublicacion.mes == 9 || libro[posicion].fechaPublicacion.mes == 11){
				maximo = 30;
			}else{
				if(libro[posicion].fechaPublicacion.mes == 2){
					maximo = 28;
				}
			}
		}

		if( utn_getNumero(&libro[posicion].fechaPublicacion.dia, "\ningrese el dia de publicacion", "\nNo existe ese dia", 1, maximo, 2) == 0 &&
			utn_getNumero(&libro[posicion].fechaPublicacion.anio, "\ningrese el anio de publicacion", "\nanio no valido", 1, 2022, 2) == 0){
			retorno = 1;
		}else{
		retorno = -1;
		}
	}else{
		//mes mal cargado
		retorno = -1;
	}
	return retorno;
}

void modificarLibro(eLibro libros[], eEditorial editoriales[], ePais paises[], eAutor autores[], eGenero generos[], int sizeLibros, int sizeEditPaises, int sizeAutores, int codigoAutoIncremental, int sizeGeneros){
	int idModificar;
	int subopcion;
	char seguir;

	if(validarPresenciaCargado(libros, sizeLibros)==1){
		mostrarTodosLosLibros(libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEditPaises, sizeGeneros);
		if(utn_getNumero(&idModificar, "\nElija el codigo del libro a modificar", "\nError, no existe ese codigo", 1, codigoAutoIncremental, 1) == 0 && libros[idModificar-1].estado == CARGADO){
			do {
				mostrarSubmenuModificacion();
				if(utn_getNumero(&subopcion, "\nModificar:", "\nError de opcion", 1, 6, 1) == 0){
					switch (subopcion) {
						case 1:
							if(pedirCadena(libros[idModificar-1].titulo, 51, "\nIngrese el nuevo titulo") == 1){
								printf("\nTitulo cambiado con exito");
							}else{
								printf("\nTitulo cambiado sin exito");
							}
							break;
						case 2:
							if(cargarFecha(libros, idModificar-1) == 1){
								printf("\nFecha cambiada con exito");
							}else{
								printf("\nFecha cambiada sin exito");
							}
							break;
						case 3:
							if(utn_getNumeroFlotante(&libros[idModificar-1].importe, "\ningrese el nuvo importe", "\nError", 1, 1000000, 1) == 0){
								printf("\nImporte cambiado con exito");
							}
							break;
						case 4:
							mostrarDetallesAutores(autores, paises, sizeAutores, sizeEditPaises);
							if(utn_getNumero(&libros[idModificar-1].idAutor, "\ningrese el id del nuevo autor", "\nError", 1, 10, 1) == 0){
								printf("\nAutor cambiado con exito");
							}
							break;
						case 5:
							mostrarDetallesEditoriales(editoriales, sizeEditPaises);
							if(utn_getNumero(&libros[idModificar-1].idEditorial, "\nIngrese el id de la nueva editorial", "\nError", 1, 5, 1) == 0){
								printf("\nEditorial cambiada con exito");
							}
							break;
						case 6:
							mostrarDetallesGeneros(generos, sizeGeneros);
							if(utn_getNumero(&libros[idModificar-1].idGenero, "\nIngrese el nuevo id del genero del libro", "\nError de opcion", 1, 5, 1) == 0){
								printf("\nGenero cambiado con exito");
							}
							break;
						default:
							break;
					}
				}
			seguir = validarSeguirNoSeguir("\nquiere realizar otra modificacion en este libro? [S|N]", "\nError de opcion", 1);
			} while (seguir == 'S');
		}else{
			printf("\nEl libro no esta cargado");
		}
	}else{
		printf("\nfalta cargar un libro");
	}
}


void darDeBaja(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEdit, int codigoAutoIncremental, int sizeGeneros){
	int idBorrar;
	char seguir;
	int i;

	if(validarPresenciaCargado(libros, sizeLibros)==1){
		mostrarTodosLosLibros(libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEdit, sizeGeneros);
		utn_getNumero(&idBorrar, "\nIngrese el Id del libro a borrar", "\nError, no existe ese id", 1, codigoAutoIncremental-1, 1);
		seguir = validarSeguirNoSeguir("\nEsta seguro que quiere borrar este libro? [S|N]", "\nError, ingrese S o N", 1);
		if(seguir == 'S'){
			for(i = 0; i<sizeLibros; i++){
				if(libros[i].idLibro == idBorrar){
					libros[i].estado = BAJADO;
				}
			}
			printf("\nEl libro %s con el codigo %d fue dado de baja", libros[idBorrar-1].titulo, idBorrar);
		}else{
			printf("\nNo se borrara el libro");
		}
	}else{
		printf("\nfalta cargar un libro");
	}
}

void calcularInforme(eLibro libros[], int sizeLibros, float* acumuladorImportes, int* contadorLibrosCargados, float* promedioImportes, int* contadorSuperanPromedio, int* contadorLibrosSXX){
	float acumuladorImportesAux = 0;
	float promedioImportesAux = 0;
	int contadorLibrosCargadosAux = 0;
	int contadorSuperanPromedioAux = 0;
	int contadorLibrosSXXAux = 0;
	int i;

	if(validarPresenciaCargado(libros, sizeLibros)==1){
		for(i = 0; i<sizeLibros;i++){
			if(libros[i].estado == CARGADO){
				acumuladorImportesAux = acumuladorImportesAux + libros[i].importe;
				contadorLibrosCargadosAux= contadorLibrosCargadosAux + 1;
				promedioImportesAux = (float)acumuladorImportesAux/ contadorLibrosCargadosAux;
				if(libros[i].importe > promedioImportesAux){
					contadorSuperanPromedioAux =contadorSuperanPromedioAux+1;
				}
				if(libros[i].fechaPublicacion.anio < 2000){
					contadorLibrosSXXAux= contadorLibrosSXXAux+1;
				}
			}
		}
		mostrarResultadosCalculos(acumuladorImportesAux, promedioImportesAux, contadorSuperanPromedioAux, contadorLibrosSXXAux);
	}else{
		printf("\nfalta cargar un libro");
	}

	*acumuladorImportes = acumuladorImportesAux;
	*promedioImportes = promedioImportesAux;
	*contadorLibrosCargados = contadorLibrosCargadosAux;
	*contadorSuperanPromedio = contadorSuperanPromedioAux;
	*contadorLibrosSXX = contadorLibrosSXXAux;
}

void mostrarResultadosCalculos(float acumuladorImportes, float promedioImportes, int contadorSuperanPromedio, int contadorLibrosSXX){
	printf("\nTotal de los importes: $%.2f", acumuladorImportes);
	printf("\nPromedio de los importes: %.2f", promedioImportes);
	printf("\nCantidad de libros que superan el promedio: %d", contadorSuperanPromedio);
	printf("\nCantidad de libros anteriores al 1-1-2000: %d", contadorLibrosSXX);
}

void listarDetalles(eEditorial editoriales[], ePais paises[], eAutor autores[], eLibro libros[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros){
	char subopcionChar;
	char seguir;

	do {
		mostrarSubmenuListar();
		if(utn_getCaracter(&subopcionChar, "\nOpcion: ", "\nError de opcion", 'A', 'H', 1)==0){
			switch (subopcionChar) {
				case 'A':
					mostrarDetallesEditoriales(editoriales, sizeEditPais);
					break;
				case 'B':
					mostrarDetallesPaises(paises, sizeEditPais);
					break;
				case 'C':
					mostrarDetallesAutores(autores, paises, sizeAutores, sizeEditPais);
					break;
				case 'D':
					if(validarPresenciaCargado(libros, sizeLibros)==1){
						mostrarTodosLosLibros(libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEditPais, sizeGeneros);
					}else{
						printf("\nfalta cargar un libro");
					}
					break;
				case 'E':
					if(validarPresenciaCargado(libros, sizeLibros)==1){
						ordenarLibrosPorImporteYTitulo(libros, autores, editoriales, generos, sizeLibros, sizeGeneros);
					}else{
						printf("\nfalta cargar un libro");
					}
					break;
				case 'F'://listar generos
					mostrarDetallesGeneros(generos, sizeGeneros);
					break;
				case 'G'://Listar todos los libros cuyo género no sea novela.
					if(validarPresenciaCargado(libros, sizeLibros)==1){
						if(validarPresenciaNoNovela(libros, sizeLibros)==1){
							mostrarLibrosNoNovela(libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEditPais, sizeGeneros);
						}else{
							printf("\nNo hay libros que no sean del genero novela");
						}
					}else{
						printf("\nfalta cargar un libro");
					}
					break;
				case 'H'://Listar todos los libros de autores argentinos que correspondan a una editorial determinada.
					if(validarPresenciaCargado(libros, sizeLibros)==1){
						mostrarLibrosArgentinosPorEditorial(editoriales, paises, autores, libros, generos, sizeLibros, sizeAutores, sizeEditPais, sizeGeneros);
					}else{
						printf("\nfalta cargar un libro");
					}
					break;
				default:
					printf("\nError");
					break;
			}
		}
		seguir = validarSeguirNoSeguir("\nlistar otra opcion? [S|N]", "Error", 1);
	} while (seguir == 'S');
}


void mostrarDetallesEditoriales(eEditorial editoriales[], int sizeEditoriales){
	int i;
	printf("\nCODIGO\tEDITORIAL");
	for(i = 0; i< sizeEditoriales; i++){
		if(editoriales[i].estado == 1)
		printf("\n%d\t%s", editoriales[i].idEditorial, editoriales[i].descripcion);
	}

}

void mostrarDetallesPaises(ePais paises[], int sizePaises){
	int i;
	printf("\nID\tPAISES");
	for(i = 0; i< sizePaises; i++){
		if(paises[i].estado == 1)
		printf("\n%d\t%s", paises[i].idPais, paises[i].descripcion);
	}
}

void mostrarDetallesAutores(eAutor autores[], ePais paises[], int sizeAutores, int sizePais){
	int i, j;
	printf("\nCODIGO\tNOMBRE\tPAIS");
	for(i = 0; i< sizeAutores; i++){
		for(j = 0; j < sizePais; j++){
			if(autores[i].estado == 1 && autores[i].pais == paises[j].idPais)
			printf("\n%d\t%s\t%s", autores[i].idAutor, autores[i].nombre, paises[j].descripcion);
		}
	}
}

void mostrarDetallesGeneros(eGenero generos[], int sizeGeneros){
	int i;
	printf("\n| ID |  GENERO    |");
	for(i = 0; i< sizeGeneros; i++){
		printf("\n| %-2d | %-10s |", generos[i].idGenero, generos[i].descripcion);
	}
}

void mostrarUnLibroPorIndice(int indiceLibro, eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero genero[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero){
	int j, k, g;

	if(validarPresenciaCargado(libros, sizeLibros)==1){
//		for(i = 0; i< sizeLibros; i++){										dejar para mostrar q estaba mal/innecesario
			if(libros[indiceLibro].estado == CARGADO /*&& i == indiceLibro *//*&& libros[i].idLibro == indiceLibro*/){
				for(j = 0; j<sizeAutores; j++){
					if(libros[indiceLibro].idAutor == autores[j].idAutor){
						for(k = 0; k<sizeEmpPaises; k++){
							if(libros[indiceLibro].idEditorial == editoriales[k].idEditorial){
								for(g = 0; g < sizeGenero; g++){
									if(libros[indiceLibro].idGenero == genero[g].idGenero){
										printf("|   %-4d | %-30s |      %d-%d-%-12d | %-10.2f |   %-8s |   %-11s | %-12s\n", libros[indiceLibro].idLibro, libros[indiceLibro].titulo,
												libros[indiceLibro].fechaPublicacion.dia, libros[indiceLibro].fechaPublicacion.mes,
												libros[indiceLibro].fechaPublicacion.anio, libros[indiceLibro].importe, autores[j].nombre, editoriales[k].descripcion, genero[g].descripcion);
										break;
									}
								}
							}
						}
					}
				}
			}
//		}
	}
}

void mostrarUnLibroPorId(int idLibro, eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero genero[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero){
	int i, j, k, g;

	if(validarPresenciaCargado(libros, sizeLibros)==1){
		for(i = 0; i< sizeLibros; i++){
			if(libros[i].estado == CARGADO && libros[i].idLibro == idLibro){
				for(j = 0; j<sizeAutores; j++){
					if(libros[i].idAutor == autores[j].idAutor){
						for(k = 0; k<sizeEmpPaises; k++){
							if(libros[i].idEditorial == editoriales[k].idEditorial){
								for(g = 0; g < sizeGenero; g++){
									if(libros[i].idGenero == genero[g].idGenero){
										printf("|   %-4d | %-30s |      %d-%d-%-12d | %-10.2f |   %-8s |   %-11s | %-12s\n", libros[i].idLibro, libros[i].titulo,
												libros[i].fechaPublicacion.dia, libros[i].fechaPublicacion.mes,
												libros[i].fechaPublicacion.anio, libros[i].importe, autores[j].nombre, editoriales[k].descripcion, genero[g].descripcion);
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void mostrarTodosLosLibros(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEd, int sizeGeneros){
	int l;
	printf("\n| %-6s | %-30s | %-21s | %-10s |   %-8s |   %-11s | %-12s\n", "CODIGO", "TITULO", "FECHA DE PUBLICACION", "IMPORTE", "AUTOR", "EDITORIAL","GENERO");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	for(l = 0; l<sizeLibros; l++){
		mostrarUnLibroPorIndice(l, libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEd, sizeGeneros);
	}
}

void ordenarLibrosPorImporteYTitulo(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeGenero){
	int i, j;
	eLibro libroAux;
	eLibro librosOrden[sizeLibros];

	for(i = 0; i<sizeLibros;i++){
		librosOrden[i] = libros[i];
	}

	for(i = 0; i<sizeLibros-1; i++){
		for(j = i+1; j<sizeLibros; j++){
			if(librosOrden[i].importe < librosOrden[j].importe ){
				libroAux = librosOrden[i];
				librosOrden[i] = librosOrden[j];
				librosOrden[j] = libroAux;
			}else{
				if(librosOrden[i].importe == librosOrden[j].importe){
					if(stricmp(librosOrden[i].titulo, librosOrden[j].titulo) > 0){
						libroAux = librosOrden[i];
						librosOrden[i] = librosOrden[j];
						librosOrden[j] = libroAux;
					}
				}
			}
		}
	}
	mostrarTodosLosLibros(librosOrden, autores, editoriales, generos, sizeLibros, TAMA, TAMEP, TAMG);
//	mostrarLibrosOrdenados(librosOrden, autores, editoriales, generos, sizeLibros, 10, 5, sizeGenero);
}

void mostrarLibrosOrdenados(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero){
	int i, j, k, g;
	printf("\n| %-6s | %-30s | %-21s | %-10s |   %-8s |   %-11s | %-12s\n", "CODIGO", "TITULO", "FECHA DE PUBLICACION", "IMPORTE", "AUTOR", "EDITORIAL","GENERO");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i< sizeLibros; i++){
		if(libros[i].estado == CARGADO){
			for(j = 0; j<sizeAutores; j++){
				if(libros[i].idAutor == autores[j].idAutor){
					for(k = 0; k<sizeEmpPaises; k++){
						if(libros[i].idEditorial == editoriales[k].idEditorial){
							for(g = 0; g < sizeGenero; g++){
								if(libros[i].idGenero == generos[g].idGenero){
									printf("|   %-4d | %-30s |      %d-%d-%-12d | %-10.2f |   %-8s |   %-11s | %-12s\n", libros[i].idLibro, libros[i].titulo,
											libros[i].fechaPublicacion.dia, libros[i].fechaPublicacion.mes,
											libros[i].fechaPublicacion.anio, libros[i].importe, autores[j].nombre, editoriales[k].descripcion, generos[g].descripcion);
								}
							}
						}
					}
				}
			}
		}
	}
}

int validarPresenciaNoNovela(eLibro libros[], int sizeLibros){
	int retorno = 0;
	int i;

	for(i = 0; i<sizeLibros; i++){
		if(libros[i].estado == CARGADO && libros[i].idGenero != 5){
			retorno = 1;
			break;
		}
	}

	return retorno;
}


void mostrarLibrosNoNovela(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros){
	int i;
	printf("\n| %-6s | %-30s | %-21s | %-10s |   %-8s |   %-11s | %-12s\n", "CODIGO", "TITULO", "FECHA DE PUBLICACION", "IMPORTE", "AUTOR", "EDITORIAL","GENERO");
	printf("-------------------------------------------------------------------------------------------------------------------------\n");

	for(i = 0; i < sizeLibros; i++){
		if(libros[i].idGenero != 5){
			mostrarUnLibroPorIndice(i, libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEditPais, sizeGeneros);
		}
	}
}

int validarPresenciaLibrosArgentinosPorIdEditorial(int idEditorial, eLibro libros[], eAutor autores[], int sizeLibros, int sizeAutores){
	int retorno = 0;
	int i, a;

	for(i = 0; i<sizeLibros; i++){
		if(libros[i].estado == CARGADO && libros[i].idEditorial == idEditorial){
			for(a = 0; a < sizeAutores; a++){
				if(autores[a].pais == 1 && libros[i].idAutor == autores[a].idAutor){
					retorno = 1;
					break;
				}
			}
		}
	}

	return retorno;
}

void mostrarLibrosArgentinosPorEditorial(eEditorial editoriales[], ePais paises[], eAutor autores[], eLibro libros[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros){
	int editorial;
	int l, a;

	mostrarDetallesEditoriales(editoriales, sizeEditPais);
	if(utn_getNumero(&editorial, "\nIngrese la editorial a mostrar sus libros de autores argentinos", "\nError, no existe esa opcion", 1, 5, 1) == 0)
	{
		if(validarPresenciaLibrosArgentinosPorIdEditorial(editorial, libros, autores, sizeLibros, sizeAutores)==1){
			printf("\n| %-6s | %-30s | %-21s | %-10s |   %-8s |   %-11s | %-12s\n", "CODIGO", "TITULO", "FECHA DE PUBLICACION", "IMPORTE", "AUTOR", "EDITORIAL","GENERO");
			printf("-------------------------------------------------------------------------------------------------------------------------\n");
			for(l = 0; l < sizeLibros; l++){
				if(libros[l].idEditorial == editorial){
					for(a = 0; a< sizeAutores; a++){
						if(autores[a].pais == 1 && libros[l].idAutor == autores[a].idAutor){
							mostrarUnLibroPorIndice(l, libros, autores, editoriales, generos, sizeLibros, sizeAutores, sizeEditPais, sizeGeneros);
						}
					}
				}
			}
		}else{
			printf("\nLa editorial no tiene libros de autores argentinos cargados");
		}
	}
}

///int buscarIndiceLibroPorId(eLibro libros[], int sizeLibros, int id){
//	int indice = -1;
//	int i;
//
//	for(i=0;i<sizeLibros; i++){
//		if(i == id){
//			indice = i;
//		}
//	}
//
//	return indice;
//}

void mostrarMenuPrincipal(){
	printf("\n--------------");
	printf("\n1- ALTA"
		"\n2- MODIFICAR"
		"\n3- BAJA"
		"\n4- INFORMAR"
		"\n5- LISTAR"
		"\n6- Salir\n");
}

void mostrarSubmenuModificacion(){
	printf("\nMODIFICAR:"
		"\n1- Titulo"
		"\n2- Fecha de publicacion"
		"\n3- Importe"
		"\n4- Autor"
		"\n5- Editorial"
		"\n6- Genereo");
}

void mostrarSubmenuListar(){
	printf(	"\ningrese una opcion a listar:"
			"\nA- EDITORIALES"
			"\nB- PAISES"
			"\nC- AUTORES"
			"\nD- LIBROS"
			"\nE- LIBROS ORDENADOS"
			"\nF- GENEROS"
			"\nG- libros cuyo genero no sea novela."
			"\nH- libros de autores argentinos que correspondan a una editorial determinada");
}
