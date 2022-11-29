
#include "parser.h"

int parser_ParticipantesFromText(FILE* pFile , LinkedList* pArrayList){
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	char idCuatri[10];
	char nombre[100];
	char categoria[50];
	char tiempo[10];
	char promedio[10];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCuatri, nombre, categoria, tiempo, promedio);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idCuatri, nombre, categoria, tiempo, promedio);
			unParticipante = part_newParametros(idCuatri, nombre, categoria, tiempo, promedio);
			if(unParticipante!=NULL){
				if(ll_add(pArrayList, unParticipante)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}

/*
int parser_ParticipantesFromBinary(FILE* pFile , LinkedList* pArrayListJugador){
	int retorno = -1;

	eParticipante* elementoAux;

	if(pFile !=NULL && pArrayListJugador != NULL){
		while(feof(pFile)==0){
			elementoAux = part_new();
			if(elementoAux != NULL){
				fread(elementoAux,sizeof(eElemento), 1, pFile);

				if(feof(pFile)){
					free(elementoAux);
					break;
				}
				if(ll_add(pArrayListJugador, elementoAux)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}
*/


