
#include "pokemon.h"

ePokemon* poke_new(){
	ePokemon* unPokemon;

	unPokemon = (ePokemon*)malloc(sizeof(ePokemon));

	return unPokemon;
}

ePokemon* poke_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVariocolorStr){
	ePokemon* unPokemon;

	unPokemon = poke_new();

	poke_setNumero(unPokemon, atoi(numeroStr));
	poke_setNombre(unPokemon, nombreStr);
	poke_setTipo(unPokemon, tipoStr);
	poke_setTamanio(unPokemon, tamanioStr);
	poke_setAtaqueCargado(unPokemon, ataqueCargadoStr);
	poke_setValorAtaque(unPokemon, atoi(valorAtaqueStr));
	poke_setEsVariocolor(unPokemon, atoi(esVariocolorStr));

	return unPokemon;
}

void poke_delete(ePokemon* this){
	free(this);
}

///set de int
int poke_setNumero(ePokemon* this,int numero)
{
	int retorno = -1;

	if(this!= NULL){
		this->numero = numero;
		retorno = 1;
	}

	return retorno;
}

///get de int
int poke_getNumero(ePokemon* this,int* numero){
	int retorno = -1;

	if(this != NULL && numero != NULL){
		*numero= this->numero;
		retorno = 1;
	}

	return retorno;
}

///set de chars
int poke_setNombre(ePokemon* this,char* nombre){
	int retorno = -1;

    if(this != NULL && nombre != NULL){
    	strcpy(this->nombre,nombre);
        retorno = 1;
    }

	return retorno;
}

///get de chars
int poke_getNombre(ePokemon* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre!=NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
	return retorno;
}

int poke_setTipo(ePokemon* this,char* tipo){
	int retorno = -1;

    if(this != NULL && tipo != NULL){
    	strcpy(this->tipo,tipo);
        retorno = 1;
    }

	return retorno;
}

int poke_getTipo(ePokemon* this,char* tipo)
{
	int retorno = -1;
    if(this != NULL && tipo!=NULL){
        strcpy(tipo, this->tipo);
        retorno = 1;
    }
	return retorno;
}

int poke_setTamanio(ePokemon* this,char* tamanio){
	int retorno = -1;

    if(this != NULL && tamanio != NULL){
    	strcpy(this->tamanio,tamanio);
        retorno = 1;
    }

	return retorno;
}

int poke_getTamanio(ePokemon* this,char* tamanio)
{
	int retorno = -1;
    if(this != NULL && tamanio!=NULL){
        strcpy(tamanio, this->tamanio);
        retorno = 1;
    }
	return retorno;
}

int poke_setAtaqueCargado(ePokemon* this,char* ataqueCargado){
	int retorno = -1;

    if(this != NULL && ataqueCargado != NULL){
    	strcpy(this->ataqueCargado,ataqueCargado);
        retorno = 1;
    }

	return retorno;
}

int poke_getAtaqueCargado(ePokemon* this,char* ataqueCargado){
	int retorno = -1;
    if(this != NULL && ataqueCargado!=NULL){
        strcpy(ataqueCargado, this->ataqueCargado);
        retorno = 1;
    }
	return retorno;
}

int poke_setValorAtaque(ePokemon* this,int valorAtaque){
	int retorno = -1;

	if(this!= NULL){
		this->valorAtaque = valorAtaque;
		retorno = 1;
	}

	return retorno;
}

int poke_getValorAtaque(ePokemon* this,int* valorAtaque){
	int retorno = -1;

	if(this != NULL && valorAtaque != NULL){
		*valorAtaque=this->valorAtaque;
		retorno = 1;
	}

	return retorno;
}

int poke_setEsVariocolor(ePokemon* this,int esVariocolor){
	int retorno = -1;

	if(this!= NULL){
		this->esVariocolor = esVariocolor;
		retorno = 1;
	}

	return retorno;
}

int poke_getEsVariocolor(ePokemon* this,int* esVariocolor){
	int retorno = -1;

	if(this != NULL && esVariocolor != NULL){
		*esVariocolor=this->esVariocolor;
		retorno = 1;
	}

	return retorno;
}

int poke_getOnePokemon(ePokemon* unPokemon, int* numero, char* nombre, char* tipo,char* tamanio, char* ataqueCargado, int* valorAtaque, int* esVariocolor){
	int retorno = -1;

	if( poke_getNumero(unPokemon, numero) && poke_getNombre(unPokemon, nombre) && poke_getTipo(unPokemon, tipo) && poke_getTamanio(unPokemon, tamanio) &&
		poke_getAtaqueCargado(unPokemon, ataqueCargado)  && poke_getValorAtaque(unPokemon, valorAtaque) && poke_getEsVariocolor(unPokemon, esVariocolor) ){
		retorno = 1;
	}
	return retorno;
}

int poke_setOnePokemon(ePokemon* unPokemon, int numero,	char* nombre, char* tipo,char* tamanio, char* ataqueCargado, int valorAtaque, int esVariocolor){
	int retorno = -1;

	if( poke_setNumero(unPokemon, numero)&& poke_setNombre(unPokemon, nombre)  && poke_setTipo(unPokemon, tipo)  && poke_setTamanio(unPokemon, tamanio) == 0 &&
			poke_setAtaqueCargado(unPokemon, ataqueCargado)  && poke_setValorAtaque(unPokemon, valorAtaque)  && poke_setEsVariocolor(unPokemon, esVariocolor) ){
		retorno = 1;
	}

	return retorno;
}

int poke_printOnePokemon(ePokemon* unPokemon){
	int retorno = -1;
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;

	if(poke_getOnePokemon(unPokemon, &numero, nombre, tipo, tamanio, ataqueCargado, &valorAtaque, &esVariocolor)==1){
		retorno = 1;
		printf("\n| %-4d | %-25s | %-25s | %-20s | %-20s | %-6d | %-6d", numero, nombre, tipo, tamanio, ataqueCargado, valorAtaque, esVariocolor);
	}

//	ll_deleteLinkedList(pArrayListSeleccionAux);

	return retorno;
}

///comparar por chars
int poke_CompareByName(void* unPokemon,void* otroElemento){
	ePokemon* ElementoUno = NULL;
	ePokemon* ElementoDos = NULL;
	char nombrePokemonUno[100];
	char nombrePokemonDos[100];
	int compara = 0;

	ElementoUno = (ePokemon*)unPokemon;
	ElementoDos = (ePokemon*)otroElemento;

	if(ElementoUno != NULL && ElementoDos != NULL){
		if(poke_getNombre(ElementoUno, nombrePokemonUno)==0 &&
			poke_getNombre(ElementoDos, nombrePokemonDos)==0){
			compara = stricmp(nombrePokemonUno, nombrePokemonDos);
		}
	}
	return compara;
}

int poke_BuscarIndicePokemonPorId(LinkedList* pArrayList, int id){
	int indice = -1;
	int cantidad;
	int idAux;
	ePokemon* unPokemon;

	if(pArrayList != NULL){
		cantidad = ll_len(pArrayList);
		if(cantidad != -1){
			for(int i = 0; i<cantidad; i++){
				unPokemon = ll_get(pArrayList, i);

				if(poke_getNumero(unPokemon, &idAux) && idAux == id){
					indice = ll_indexOf(pArrayList, unPokemon);
					break;
				}
			}
		}
	}

	return indice;
}

void mostrarCabecera(void){
	printf("\n| %-4s | %-25s | %-6s | %-20s | %-17s | %-15s |","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
	printf("\n----------------------------------------------------------------------------------------------------------");
}


int poke_filtrarTipoFuego(void* elemento){
	int retorno = -1;
	ePokemon* unPokemon = NULL;
	char tipo[100];

	unPokemon = (ePokemon*)elemento;///el elemento parametro puede ser cualquier cosa, lo estoy pasando al tipo q vamos a filtrar

	if(unPokemon != NULL){
		if(poke_getTipo(unPokemon, tipo)==1){
//			printf("%s\n", tipo);
			if(strcmp(tipo, "Fire")==0){
//				printf("filtrado\n");
				retorno = 1;
			}/*else{
				printf("no filtrado\n");
			}*/
		}
	}

	return retorno;
}


int poke_filtrarTamanioXl(void* unPokemon){
	int retorno = -1;
	char tamanio[50];
//	char tipo[100];
	ePokemon* unPokemonAux = NULL;
///	LinkedList* pokemonesXl = NULL;

	unPokemonAux = (ePokemon*)unPokemon;
///	pokemonesXl = ll_newLinkedList();		///solo filtramos!!! no creamos una lista. De eso se encarga el filter.

	if(unPokemon != NULL /**&& pokemonesXl != NULL*/){
		if(poke_getTamanio(unPokemonAux, tamanio)==1){
			if(strcmp(tamanio,"XL")==0){
				retorno =1;
			}
		}

	}

	return retorno;
}

int poke_filtrarTipoVeneno(void* unPokemon){
	int retorno = -1;
	char tipo[100];
	ePokemon* unPokemonAux = NULL;

	unPokemonAux = (ePokemon*)unPokemon;

	if(unPokemonAux != NULL){
		if(poke_getTipo(unPokemonAux, tipo)==1){
			if(strcmp(tipo, "Poison")==0){
				retorno = 1;
			}
		}
	}

	return retorno;
}
