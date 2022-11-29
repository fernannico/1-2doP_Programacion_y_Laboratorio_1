

#include "Controller.h"

int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			if(parser_librosFromText(pArchivo, pArrayList)==1){
				retorno = 1;
			}
		}
		fclose(pArchivo);
    }
    return retorno;
}

int controller_listarLibros(LinkedList* pArrayList){
	int cantidad;
	int retorno = -1;
	int i;
	eLibro* libroAux = NULL;

	if(pArrayList != NULL){
		cantidad = ll_len(pArrayList);
		if(cantidad != -1){
			mostrarCabecera();
			for(i=0;i<cantidad;i++){
				libroAux = (eLibro*)ll_get(pArrayList, i);
				if(libroAux != NULL){
					if(lib_printOneLibro(libroAux)==1){
						retorno = 1;
					}
				}
			}
		}
	}
    return retorno;
}

int controller_ordenarLibros(LinkedList* pArrayList){
    int retorno = -1;
    if(pArrayList != NULL){
		if(ll_sort(pArrayList, lib_compararPorImporte, 0)==0){
			if(controller_listarLibros(pArrayList)==1){
				retorno = 1;
			}
		}
    }

    return retorno;
}


int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayList){
	int retorno = -1;
	int cantidad;
	int id;
	char titulo[100];
	float importe;
	int idTipo;
	int i;
	eLibro* unLibro = NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL){
			cantidad = ll_len(pArrayList);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s\n", "id","titulo","importe","idTipo");
				for(i = 0; i < cantidad; i++){
					unLibro = (eLibro*)ll_get(pArrayList, i);
					if(unLibro != NULL){
						if(lib_getOneLibro(unLibro, &id, titulo, &importe, &idTipo)==1){
							fprintf(pArchivo, "%d,%s,%.2f,%d\n", id,titulo,importe,idTipo);
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

///, incrementará el precio un 10% para todos los libros del tipo EBOOK y un 20% para PAPEL
int controller_mapearImporte(LinkedList* pArrayList){
	int retonorno = -1;

	if(pArrayList != NULL){
		pArrayList = ll_map(pArrayList, lib_mapearImporte);
		controller_listarLibros(pArrayList);
		retonorno = 1;
	}

	return retonorno;
}

