
#include "participantes.h"

eParticipante* part_new(){
	eParticipante* unParticipante;

	unParticipante = (eParticipante*)malloc(sizeof(eParticipante));

	return unParticipante;
}

eParticipante* part_newParametros(char* idStr,char* nombreStr,char* categoriaStr, char* tiempoStr, char* promedioStr){
	eParticipante* unParticipante;

	unParticipante = part_new();

	part_setId(unParticipante, atoi(idStr));
	part_setNombre(unParticipante, nombreStr);
	part_setCategoria(unParticipante, categoriaStr);
	part_setTiempo(unParticipante, atoi(tiempoStr));
	part_setPromedio(unParticipante, atoi(promedioStr));

	return unParticipante;
}

void part_delete(eParticipante* this){
	free(this);
}

int part_setId(eParticipante* this,int id){
	int retorno = -1;

	if(this!= NULL){
		this->id_cuatri = id;
		retorno = 1;
	}

	return retorno;
}

int part_getId(eParticipante* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id=this->id_cuatri;
		retorno = 1;
	}

	return retorno;
}

///set de chars
int part_setNombre(eParticipante* this,char* nombre){
	int retorno = -1;

    if(this != NULL && nombre != NULL){
    	strcpy(this->nombre,nombre);
        retorno = 1;
    }

	return retorno;
}

///get de chars
int part_getNombre(eParticipante* this,char* nombre)
{
	int retorno = -1;
    if(this != NULL && nombre!=NULL){
        strcpy(nombre, this->nombre);
        retorno = 1;
    }
	return retorno;
}

int part_setCategoria(eParticipante* this,char* categoria){
	int retorno = -1;

    if(this != NULL && categoria != NULL){
    	strcpy(this->categoria,categoria);
        retorno = 1;
    }

	return retorno;
}

///get de chars
int part_getCategoria(eParticipante* this,char* categoria)
{
	int retorno = -1;
    if(this != NULL && categoria!=NULL){
        strcpy(categoria, this->categoria);
        retorno = 1;
    }
	return retorno;
}


///set de int
int part_setTiempo(eParticipante* this,int tiempo){
	int retorno = -1;

	if(this!= NULL){
		this->tiempo = tiempo;
		retorno = 1;
	}

	return retorno;
}

///get de int
int part_getTiempo(eParticipante* this,int* tiempo){
	int retorno = -1;

	if(this != NULL && tiempo != NULL){
		*tiempo = this-> tiempo;
		retorno = 1;
	}

	return retorno;
}

int part_setPromedio(eParticipante* this,int promedio){
	int retorno = -1;

	if(this!= NULL){
		this->promedio = promedio;
		retorno = 1;
	}

	return retorno;
}

///get de int
int part_getPromedio(eParticipante* this,int* promedio){
	int retorno = -1;

	if(this != NULL && promedio != NULL){
		*promedio = this-> promedio;
		retorno = 1;
	}

	return retorno;
}


int part_getOneParticipante(eParticipante* unParticipante, int* id, char* nombre, char* categoria, int* tiempo, int* promedio){
	int retorno = -1;

	if(part_getId(unParticipante, id) && part_getNombre(unParticipante, nombre) && part_getCategoria(unParticipante, categoria) && part_getTiempo(unParticipante, tiempo) &&
			part_getPromedio(unParticipante, promedio)){
		retorno = 1;
	}
	return retorno;
}

int part_setOneParticipante(eParticipante* unParticipante, int id, char* nombre, char* categoria, int tiempo, int promedio){
	int retorno = -1;

	if( part_setId(unParticipante, id) && part_setNombre(unParticipante, nombre) && part_setCategoria(unParticipante, categoria) &&
			part_setTiempo(unParticipante, tiempo) && part_setPromedio(unParticipante, promedio)){
		retorno = 1;
	}

	return retorno;
}

int part_printOneParticipante(eParticipante* unParticipante){
	int retorno = -1;
	int id_cuatri;
	char nombre[100];
	char categoria[30];
	int tiempo;
	int promedio;

	if(part_getOneParticipante(unParticipante, &id_cuatri, nombre, categoria, &tiempo, &promedio)==1){
		retorno = 1;
		printf("\n| %-4d | %-25s | %-25s | %-4d | %-4d |", id_cuatri, nombre, categoria, tiempo, promedio);
	}

	return retorno;
}


/////comparar por chars
int part_CompararPorCategoria(void* unParticipante,void* otroParticipante){
	eParticipante* ParticipanteUno = NULL;
	eParticipante* ParticipanteDos = NULL;
	char categoriaParticipanteUno[100];
	char categoriaParticipanteDos[100];
	int compara = 0;

	ParticipanteUno = (eParticipante*)unParticipante;
	ParticipanteDos = (eParticipante*)otroParticipante;

	if(ParticipanteUno != NULL && ParticipanteDos != NULL){
		if(part_getCategoria(ParticipanteUno, categoriaParticipanteUno) &&
			part_getCategoria(ParticipanteDos, categoriaParticipanteDos)){
			compara = stricmp(categoriaParticipanteUno, categoriaParticipanteDos);
		}
	}
	return compara;
}

///Comparar por int
int part_compararPorPromedioIgualCategoria(void* unParticipante,void* otroParticipante){
	int compara = 0;
	eParticipante* participanteUno = NULL;
	eParticipante* participanteDos = NULL;
	int promedioElemUno;
	int promedioElemDos;
	char categoriaParticipanteUno[30];
	char categoriaParticipanteDos[30];

	participanteUno = (eParticipante*)unParticipante;
	participanteDos = (eParticipante*)otroParticipante;

	if(participanteUno != NULL && participanteDos != NULL){
		part_getCategoria(participanteUno, categoriaParticipanteUno);
		part_getCategoria(participanteDos, categoriaParticipanteDos);
		if(strcmp(categoriaParticipanteUno,categoriaParticipanteDos)==0){
			if(part_getPromedio(participanteUno, &promedioElemUno) && part_getPromedio(participanteDos, &promedioElemDos)){
				if(promedioElemUno > promedioElemDos){
					compara = 1;
				}else{
					if(promedioElemUno < promedioElemDos){
						compara = -1;
					}
				}
			}
		}
	}

	return compara;
}
//
//int part_BuscarIndiceParticipantePorId(LinkedList* pArrayList, int id){
//	int indice = -1;
//	int cantidad;
//	int idAux;
//	eParticipante* unParticipante;
//
//	if(pArrayList != NULL){
//		cantidad = ll_len(pArrayList);
//		if(cantidad != -1){
//			for(int i = 0; i<cantidad; i++){
//				unParticipante = ll_get(pArrayList, i);
//
//				if(part_getId(unParticipante, &idAux) && idAux == id){
//					indice = ll_indexOf(pArrayList, unParticipante);
//					break;
//				}
//			}
//		}
//	}
//
//	return indice;
//}
//int part_modificarNombre(eParticipante* this){
//	int retorno = -1;
//	char nombreActual[100];
//	char nombreNuevo[100];
//	char confirmar;
//
//	if(this != NULL){
//		if(part_getNombre(this, nombreActual)==0){
//			if(utn_getNombre(nombreNuevo, 100, "\nIngrese el nuevo nombre del elemento", "\nError", 1)==0){
//				ModularNombre(nombreNuevo);
//
//				printf("\nModificando el nombre del elemento de %s a %s...", nombreActual, nombreNuevo);
//				confirmar = ValidarSeguirNoSeguir("\nModificar el nombre del elemento? [S|N]", "\nError");
//				if(confirmar == 'S'){
//					part_setNombre(this, nombreNuevo);
//					retorno = 1;
//				}
//			}else{
//				printf("\nModificacion interrumpida");
//			}
//		}
//	}
//
//	return retorno;
//}
//
//int part_modificarNumero(eParticipante* this){
//	int retorno = -1;
//	int edadActual;
//	int edadNueva;
//	char confirmar;
//
//	if(this != NULL){
//		part_getNumero(this, &edadActual);
//
//		if(utn_getNumero(&edadNueva, "\nIngrese la nueva edad del elemento[16-60]", "\nError", 1, 1000, 1)==0){
//
//			printf("\nModificando la edad del elemento de %d a %d años", edadActual, edadNueva);
//			confirmar = ValidarSeguirNoSeguir("\nModificar la edad del elemento? [S|N]", "\nError");
//			if(confirmar == 'S'){
//				part_setNumero(this, edadNueva);
//				retorno = 1;
//			}
//		}else{
//			printf("\nModificacion interrumpida");
//		}
//	}
//
//
//	return retorno;
//}
//
//void mostrarCabecera(void){
//	printf("\n| %-4s | %-25s | %-6s | %-20s | %-17s | %-15s |","id","nombre Completo", "edad", "posicion", "nacionalidad", "Selecion");
//	printf("\n----------------------------------------------------------------------------------------------------------");
//}
//
//
int part_filtrarCategoriaMX1(void* elemento){
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	char categoria[20];

	unParticipante = (eParticipante*)elemento;///el elemento parametro puede ser cualquier cosa, lo estoy pasando al tipo q vamos a filtrar

	if(unParticipante != NULL){
		if(part_getCategoria(unParticipante, categoria)==1){
			if(strcmp(categoria, "MX1")==0){
				retorno = 1;
			}
		}
	}

	return retorno;
}

int part_filtrarCategoriaMX2(void* elemento){
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	char categoria[20];

	unParticipante = (eParticipante*)elemento;///el elemento parametro puede ser cualquier cosa, lo estoy pasando al tipo q vamos a filtrar

	if(unParticipante != NULL){
		if(part_getCategoria(unParticipante, categoria)==1){
			if(strcmp(categoria, "MX2")==0){
				retorno = 1;
			}
		}
	}

	return retorno;
}
int part_filtrarCategoriaMX3(void* elemento){
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	char categoria[20];

	unParticipante = (eParticipante*)elemento;///el elemento parametro puede ser cualquier cosa, lo estoy pasando al tipo q vamos a filtrar

	if(unParticipante != NULL){
		if(part_getCategoria(unParticipante, categoria)==1){
			if(strcmp(categoria, "MX3")==0){
				retorno = 1;
			}
		}
	}

	return retorno;
}

int part_filtrarCategoriaSuper(void* elemento){
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	char categoria[20];

	unParticipante = (eParticipante*)elemento;///el elemento parametro puede ser cualquier cosa, lo estoy pasando al tipo q vamos a filtrar

	if(unParticipante != NULL){
		if(part_getCategoria(unParticipante, categoria)==1){
			if(strcmp(categoria, "SUPER_ATV")==0){
				retorno = 1;
			}
		}
	}

	return retorno;
}

///para tiempos menor a 15 se le asignará un promedio de 6 segundos, para tiempos entre 15 y 20 se le asignará un promedio de 8 segundos y
///para tiempos mayores a 20 se le asignará un promedio de 10 segundos.
void* part_mapearPromedio(void* element){
	eParticipante* unParticipante = NULL;
	int tiempo;
	int promedio;

	unParticipante = (eParticipante*)element;

	if(unParticipante != NULL){
		part_getTiempo(unParticipante, &tiempo);
		part_getPromedio(unParticipante, &promedio);
		if(tiempo < 15){
			promedio = 6;
			part_setPromedio(unParticipante, promedio);
		}else{
			if(tiempo >14 && tiempo < 20){
				promedio = 8;
				part_setPromedio(unParticipante, promedio);
			}else{
				if(tiempo > 19){
					promedio = 10;
					part_setPromedio(unParticipante, promedio);
				}
			}
		}
	}

	return unParticipante;
}
