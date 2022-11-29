

#include "Controller.h"

int controller_cargarElementosDesdeTexto(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			if(parser_PokemonFromText(pArchivo, pArrayList)==1){
				retorno = 1;
			}
		}else{
			printf("parchivo es null");
		}
		fclose(pArchivo);
    }
    return retorno;
}

int controller_guardarPokemonesModoTexto(char* path , LinkedList* pArrayList){
	int retorno = -1;
	int cantidad;
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;
	ePokemon* unPokemon= NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL){
			cantidad = ll_len(pArrayList);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s,%s,%s,%s\n", "numero","nombre","tipoo","tamanio","ataque cargado","valor ataque", "es varicolor");
				for(int i = 0; i < cantidad; i++){
					unPokemon = (ePokemon*)ll_get(pArrayList, i);
					if(unPokemon != NULL){
						if(poke_getOnePokemon(unPokemon, &numero, nombre, tipo, tamanio, ataqueCargado, &valorAtaque, &esVariocolor)==1){
							fprintf(pArchivo, "%d,%s,%s,%s,%s,%d,%d\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);
							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}

int controller_listarElementos(LinkedList* pArrayList){
	int cantidad;
	int retorno = -1;
	ePokemon* elementoAux;

	if(pArrayList != NULL){
		cantidad = ll_len(pArrayList);
		if(cantidad != -1){
//			mostrarCabecera();
			for(int i=0;i<cantidad;i++){
				elementoAux = (ePokemon*)ll_get(pArrayList, i);
				if(elementoAux != NULL){
					if(poke_printOnePokemon(elementoAux)==1){
						retorno = 1;
					}else{
						printf("printfone prob");
					}
				}else{
					printf("ll_get prob");
				}
			}
		}else{
			printf("len null");
		}
	}
    return retorno;
}

int controller_filtrarXlVeneno(LinkedList* pArrayList){
	int retorno = -1;
///	ePokemon* unPokemon = NULL;
	LinkedList* pokemonesXl = NULL;
	LinkedList* pokemonesXlVeneno = NULL;

	pokemonesXl= ll_newLinkedList();
	pokemonesXlVeneno = ll_newLinkedList();

	if(pokemonesXl != NULL && pokemonesXlVeneno != NULL){
		pokemonesXl = ll_filter(pArrayList, poke_filtrarTamanioXl);
		pokemonesXlVeneno = ll_filter(pokemonesXl, poke_filtrarTipoVeneno);
		controller_listarElementos(pokemonesXlVeneno);
	}

	return retorno;
}

int controller_mapearAtaqueCargado(LinkedList* pArrayList){
	int retonorno = -1;
	LinkedList* pokemonesMapeados = NULL;

	pokemonesMapeados = ll_newLinkedList();

	if(pokemonesMapeados != NULL){
		pokemonesMapeados = ll_map(pArrayList, poke_mapearAtaque);
		controller_listarElementos(pokemonesMapeados);
		retonorno = 1;
	}

	return retonorno;
}

///Como el día está despejado, los pokemones de tipo Bug, Fire y Grass aumentarán
///su poder un 20% siempre y cuando el tamaño sea XL, un 10% si es L y sino un 5 para cualquier otro tamaño.
void* poke_mapearAtaque(void* element){
	ePokemon* unPokemon = NULL;
	char tipo[100];
	char tamanio[50];
	int valorAtaque;

	unPokemon = (ePokemon*)element;

	if(unPokemon != NULL){
		poke_getTipo(unPokemon, tipo);
		if(strcmp(tipo,"Bug")==0 || strcmp(tipo,"Fire")==0 || strcmp(tipo,"Grass")==0){
			poke_getTamanio(unPokemon, tamanio);
			poke_getValorAtaque(unPokemon, &valorAtaque);
			if(strcmp(tamanio,"XL")==0){
				valorAtaque = valorAtaque * 1.2;
				poke_setValorAtaque(unPokemon, valorAtaque);
			}else{
				if(strcmp(tamanio,"L")==0){
					valorAtaque = valorAtaque * 1.1;
					poke_setValorAtaque(unPokemon, valorAtaque);
				}else{
					valorAtaque = valorAtaque * 1.05;
					poke_setValorAtaque(unPokemon, valorAtaque);
				}
			}
		}
	}

	return unPokemon;
}


/*
int controller_ordenarJugadores(LinkedList* pArrayList){
    int orden;
    int opcion;
    int retorno = -1;

	if(utn_getNumero(&opcion, "\nOpcion", "\nError", 1, 2, 1)==0){
		switch (opcion) {
			case 1:
				if(utn_getNumero(&orden,"\n0- Orden descendente"
									 "\n1- Orden ascendente"
									 "\nOpcion:", "\nError", 0, 1, 1)==0)
				{
					ll_sort(pArrayList, xxx_CompareByAge, orden);
					if(controller_listarElementos(pArrayList)==1){
						retorno = 1;
					}
				}
				break;
			case 2:
				if(utn_getNumero(&orden,"\n0- Orden descendente"
									 "\n1- Orden ascendente"
									"\nOpcion:", "\nError", 0, 1, 1)==0)
				{
					ll_sort(pArrayList, xxx_CompareByName, orden);
					if(controller_listarElementos(pArrayList)==1){
						retorno = 1;
					}
				}
				break;
			default:
				printf("\nError");
				break;
		}
	}else{
		printf("\nOpcion interrumpida");
	}

    return retorno;
}


int controller_guardarElementosModoTexto(char* path , LinkedList* pArrayList){
	int retorno = -1;
	int cantidad;
	int id;
	char nombreCompleto[100];
//	int edad;
//	char posicion[30];
//	char nacionalidad[30];
//	int idSeleccion;
	eElemento* unPokemon = NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL){
			cantidad = ll_len(pArrayList);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s,%s,%s\n", "id","nombreCompleto","edad","posicion","nacionalidad","idSelecion");
				for(int i = 0; i < cantidad; i++){
					unPokemon = (eElemento*)ll_get(pArrayList, i);
					if(unPokemon != NULL){
						if(xxx_getOneElemento(unPokemon, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion)==1){
//							fprintf(pArchivo, "%d,%s,%d,%s,%s,%d\n", id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
							retorno = 1;
						}
					}
				}
			}
		}
		fclose(pArchivo);
	}

    return retorno;
}


int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayList){
	int retorno = -1;
	int cantidadJugad;
//	int idSelecJugAux;
	FILE* pFileBin;

	eElemento* jugadorAux;

	if(path != NULL && pArrayList != NULL){
		pFileBin = fopen(path, "wb");
		cantidadJugad = ll_len(pArrayList);

		if(cantidadJugad != -1){
			for(int i = 0; i<cantidadJugad; i++){
				jugadorAux = (eElemento*)ll_get(pArrayList, i);
//				if(jug_getSIdSeleccion(jugadorAux, &idSelecJugAux)==0){
//					if(idSelecJugAux != 0){
						fwrite(jugadorAux, sizeof(eElemento), 1, pFileBin);
						retorno = 1;
//					}
//				}
			}
		}

		free(jugadorAux);
		fclose(pFileBin);
	}

    return retorno;
}

int controller_CargarArchivoBinario(char* pathJugadores){
	int retorno = -1;

	if(pathJugadores != NULL){
		LinkedList* jugadoresAuxiliar;
		jugadoresAuxiliar = ll_newLinkedList();

		if(jugadoresAuxiliar != NULL){
			if(controller_cargarElementosDesdeBinario(pathJugadores, jugadoresAuxiliar)==1){
				controller_listarElementos(jugadoresAuxiliar);
				retorno = 1;
			}
		}

		ll_deleteLinkedList(jugadoresAuxiliar);
	}
	return retorno;
}
*/
