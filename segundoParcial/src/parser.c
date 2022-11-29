
#include "parser.h"

int parser_librosFromText(FILE* pFile , LinkedList* pArrayList){
	int retorno = -1;
	eLibro* unElemento = NULL;
	char id[10];
	char titulo[100];
	char importe[10];
	char idTipo[10];

	if(pFile != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, importe, idTipo);//lectura fantasma

		while(feof(pFile)==0){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",  id, titulo, importe, idTipo);
			unElemento = lib_newParametros( id, titulo, importe, idTipo);
			if(unElemento!=NULL){
				if(ll_add(pArrayList, unElemento)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}


int parser_librosFromBinary(FILE* pFile , LinkedList* pArrayList){
	int retorno = -1;

	eLibro* elementoAux;

	if(pFile !=NULL && pArrayList != NULL){
		while(feof(pFile)==0){
			elementoAux = lib_new();
			if(elementoAux != NULL){
				fread(elementoAux,sizeof(eLibro), 1, pFile);

				if(feof(pFile)){
					free(elementoAux);
					break;
				}
				if(ll_add(pArrayList, elementoAux)==0){
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}


