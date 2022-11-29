
#include "libros.h"

eLibro* lib_new(){
	eLibro* unLibro;

	unLibro = (eLibro*)malloc(sizeof(eLibro));

	return unLibro;
}
//char titulo, char importe, char idTipo

eLibro* lib_newParametros(char* idStr,char* titulo, char* importe, char* idTipo){
	eLibro* unLibro;

	unLibro = lib_new();

	lib_setId(unLibro, atoi(idStr));
	lib_setTitulo(unLibro, titulo);
	lib_setImporte(unLibro, atof(importe));
	lib_setIdTipo(unLibro, atoi(idTipo));

	return unLibro;
}

void lib_delete(eLibro* this){
	free(this);
}

int lib_setId(eLibro* this,int id){
	int retorno = -1;

	if(this!= NULL){
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int lib_getId(eLibro* this,int* id){
	int retorno = -1;

	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

///set de chars
int lib_setTitulo(eLibro* this,char* titulo){
	int retorno = -1;

    if(this != NULL && titulo != NULL){
    	strcpy(this->titulo,titulo);
        retorno = 1;
    }

	return retorno;
}

///get de chars
int lib_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
    if(this != NULL && titulo!=NULL){
        strcpy(titulo, this->titulo);
        retorno = 1;
    }
	return retorno;
}

///set de int
int lib_setImporte(eLibro* this,float importe){
	int retorno = -1;

	if(this!= NULL){
		this->importe = importe;
		retorno = 1;
	}

	return retorno;
}

///get de int
int lib_getImporte(eLibro* this,float* importe){
	int retorno = -1;

	if(this != NULL && importe != NULL){
		*importe=this->importe;
		retorno = 1;
	}

	return retorno;
}

int lib_setIdTipo(eLibro* this,int idTipo){
	int retorno = -1;

	if(this!= NULL){
		this->idTipo = idTipo;
		retorno = 1;
	}

	return retorno;
}

///get de int
int lib_getIdTipo(eLibro* this,int* idTipo){
	int retorno = -1;

	if(this != NULL && idTipo != NULL){
		*idTipo=this->idTipo;
		retorno = 1;
	}

	return retorno;
}


int lib_getOneLibro(eLibro* unLibro, int* id, char* titulo, float* importe, int* idTipo){
	int retorno = -1;

	if(lib_getId(unLibro, id) && lib_getTitulo(unLibro, titulo) && lib_getImporte(unLibro, importe) && lib_getIdTipo(unLibro, idTipo)){
		retorno = 1;
	}
	return retorno;
}

//int lib_setOneLibro(eLibro* unElemento,  int id, char* titulo, float importe, int idTipo);
//	int retorno = -1;
//
//	if( lib_setNumero(unLibro, id) && lib_setNombre(unLibro, nombre) /*&& lib_setEdad(unLibro, edad) &&
//		lib_setPosicion(unLibro, posicion) && lib_setNacionalidad(unLibro, nacionalidad) && lib_setIdSeleccion(unLibro, idSeleccion)*/){
//		retorno = 1;
//	}
//
//	return retorno;
//}

int lib_printOneLibro(eLibro* unLibro){
	int retorno = -1;
	int id;
	char titulo[100];
	float importe;
	int idTipo;

	if(lib_getOneLibro(unLibro, &id, titulo, &importe, &idTipo)){
		if(idTipo == 1){
			printf("\n| %-4d | %-35s | %-10.2f | %-10s | ", id, titulo, importe, "PAPEL");
		}else{
			if(idTipo == 2){
				printf("\n| %-4d | %-35s | %-10.2f | %-10s | ", id, titulo, importe, "EBOOK");
			}
		}
		retorno = 1;
	}

	return retorno;
}

///Comparar por int
int lib_compararPorImporte(void* unLibro,void* otroLibro){
	int compara = 0;
	eLibro* libroUno = NULL;
	eLibro* libroDos = NULL;
	float importeUno;
	float importeDos;

	libroUno = (eLibro*)unLibro;
	libroDos = (eLibro*)otroLibro;

	if(libroUno != NULL && libroDos != NULL){
		lib_getImporte(libroUno, &importeUno);
		lib_getImporte(libroDos, &importeDos);
		if(importeUno > importeDos){
			compara = 1;
		}else{
			if(importeUno < importeDos){
				compara = -1;
			}
		}
	}

	return compara;
}

void mostrarCabecera(void){
	printf("\n| %-4s | %-35s | %-10s | %-10s |","id","titulo", "importe", "idtipo");

	printf("\n------------------------------------------------------------------------");
}

///, incrementará el precio un 10% para todos los libros del tipo EBOOK y un 20% para PAPEL
void* lib_mapearImporte(void* element){
	eLibro* unLibro = NULL;
	float importe;
	int idTipo;

	unLibro = (eLibro*)element;

	if(unLibro != NULL){
		if(lib_getImporte(unLibro, &importe) && lib_getIdTipo(unLibro, &idTipo)){
			if(idTipo == 1){
				importe = importe * 1.2;
				lib_setImporte(unLibro, importe);
			}else{
				if(idTipo == 2){
					importe = importe * 1.1;
					lib_setImporte(unLibro, importe);
				}
			}
		}
	}

	return unLibro;
}

/////Comparar por int
//int part_compararPorPromedioIgualCategoria(void* unParticipante,void* otroParticipante){
//	int compara = 0;
//	eLibro* participanteUno = NULL;
//	eLibro* participanteDos = NULL;
//	int promedioElemUno;
//	int promedioElemDos;
//	char categoriaParticipanteUno[30];
//	char categoriaParticipanteDos[30];
//
//	participanteUno = (eLibro*)unParticipante;
//	participanteDos = (eLibro*)otroParticipante;
//
//	if(participanteUno != NULL && participanteDos != NULL){
//		part_getCategoria(participanteUno, categoriaParticipanteUno);
//		part_getCategoria(participanteDos, categoriaParticipanteDos);
//		if(strcmp(categoriaParticipanteUno,categoriaParticipanteDos)==0){
//			if(part_getPromedio(participanteUno, &promedioElemUno) && part_getPromedio(participanteDos, &promedioElemDos)){
//				if(promedioElemUno > promedioElemDos){
//					compara = 1;
//				}else{
//					if(promedioElemUno < promedioElemDos){
//						compara = -1;
//					}
//				}
//			}
//		}
//	}
//
//	return compara;
//}
