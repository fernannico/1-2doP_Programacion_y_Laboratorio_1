
#include "Controller.h"


int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPokemon){
	int retorno = -1;
	ePokemon* unPokemon = NULL;
	char numero[10];
	char nombre[100];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	char valorAtaque[10];
	char esVariocolor[10];

	if(pFile != NULL){

//		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);
			unPokemon = poke_newParametros(numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);
			if(unPokemon != NULL){
				if(ll_add(pArrayListPokemon, unPokemon)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}

/*
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador){
	int retorno = -1;

	Jugador* jugadorAux;

	if(pFile !=NULL && pArrayListJugador != NULL){
		while(feof(pFile)==0){
			jugadorAux = jug_new();
			if(jugadorAux != NULL){
				fread(jugadorAux,sizeof(Jugador), 1, pFile);

				if(feof(pFile)){
					free(jugadorAux);
					break;
				}
				if(ll_add(pArrayListJugador, jugadorAux)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}


int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion){
	int retorno = -1;

	Seleccion* unaSeleccion = NULL;
	char id[10];
	char pais[100];
	char confederacion[100];
	char convocados[10];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, pais, confederacion, convocados);
			unaSeleccion = selec_newParametros(id, pais, confederacion, convocados);

			if(unaSeleccion != NULL){
				if(ll_add(pArrayListSeleccion, unaSeleccion)==0){
					retorno = 1;
				}
			}
		}
	}


    return retorno;
}

*/
