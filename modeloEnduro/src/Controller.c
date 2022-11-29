

#include "Controller.h"

int controller_cargarParticipantesDesdeTexto(char* path , LinkedList* pArrayList)
{
	int retorno = -1;
    FILE* pArchivo;

    if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL){
			if(parser_ParticipantesFromText(pArchivo, pArrayList)==1){
				retorno = 1;
			}
		}
		fclose(pArchivo);
    }
    return retorno;
}


//int controller_cargarParticipantesDesdeBinario(char* path , LinkedList* pArrayList){
//	int retorno = -1;
//	FILE* pArchivo;
//
//	if(path != NULL && pArrayList != NULL){
//		pArchivo = fopen(path, "rb");
//		if(pArchivo != NULL){
//			if(parser_ParticipantesFromBinary(pArchivo, pArrayList) == 1){
//				retorno = 1;
//			}
//		}
//		fclose(pArchivo);
//	}
//
//    return retorno;
//}

int controller_listarParticipantes(LinkedList* pArrayList){
	int cantidad;
	int retorno = -1;
	eParticipante* participanteAux;

	if(pArrayList != NULL){
		cantidad = ll_len(pArrayList);
		if(cantidad != -1){
//			mostrarCabecera();
			for(int i=0;i<cantidad;i++){
				participanteAux = (eParticipante*)ll_get(pArrayList, i);
				if(participanteAux != NULL){
					if(part_printOneParticipante(participanteAux)==1){
						retorno = 1;
					}
				}
			}
		}
	}
    return retorno;
}
//
//int controller_editarParticipante(LinkedList* pArrayList){
//	int retorno = -1;
//	int idMaximo;
//	int idAux;
//	int indiceAux;
//	eParticipante* unParticipante= NULL;
//
//	if(pArrayList != NULL){
//		controller_listarParticipantes(pArrayList);
//		idMaximo = ll_len(pArrayList);
//		if(utn_getNumero(&idAux, "\nIngrese el ID del Participante a modificar: ", "\nError, el Participante ingresado no existe aun", 1, idMaximo, 1)==0){
//			indiceAux = part_BuscarIndiceParticipantePorId(pArrayList, idAux);
//			if(indiceAux != -1){
//				unParticipante = (eParticipante*)ll_get(pArrayList, indiceAux);
//				if(unParticipante!=NULL){
//					part_printOneParticipante(unParticipante);
////					part_modificarNombre(unParticipante);
////					part_modificarNumero(unParticipante);
//				}
//			}else{
//				printf("\nEl jugador habria sido dado de baja");
//			}
//		}else{
//			printf("\nModificacion interrumpida, el jugador ingresado no existe aun");
//		}
//	}
//	return retorno;
//}
//

///listado de los participantes ordenados por categoría y dentro de la misma categoría que aparezcan ordenadas por promedio ascendente
int controller_ordenarParticipantes(LinkedList* pArrayList){
    int retorno = -1;

    if(pArrayList != NULL){
    	if(ll_sort(pArrayList, part_CompararPorCategoria, 1)==0 &&
			ll_sort(pArrayList, part_compararPorPromedioIgualCategoria, 1)==0)
    	{
			controller_listarParticipantes(pArrayList);
			retorno = 1;
    	}
    }

    return retorno;
}

int controller_guardarParticipantesModoTexto(char* path , LinkedList* pArrayList){
	int retorno = -1;
	int cantidad;
	int id_cuatri;
	char nombre[100];
	char categoria[30];
	int tiempo;
	int promedio;
	eParticipante* unParticipante = NULL;

	FILE* pArchivo;

	if(path != NULL && pArrayList != NULL){
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL){
			cantidad = ll_len(pArrayList);
			if(cantidad != -1){
				fprintf(pArchivo, "%s,%s,%s,%s,%s\n", "id_cuatri","nombre","categoria","tiempo","promedio");
				for(int i = 0; i < cantidad; i++){
					unParticipante = (eParticipante*)ll_get(pArrayList, i);
					if(unParticipante != NULL){
						if(part_getOneParticipante(unParticipante, &id_cuatri,nombre,categoria,&tiempo,&promedio)==1){
							fprintf(pArchivo, "%d,%s,%s,%d,%d\n", id_cuatri,nombre,categoria,tiempo,promedio);
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
//
//
//int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayList){
//	int retorno = -1;
//	int cantidadJugad;
////	int idSelecJugAux;
//	FILE* pFileBin;
//
//	eParticipante* jugadorAux;
//
//	if(path != NULL && pArrayList != NULL){
//		pFileBin = fopen(path, "wb");
//		cantidadJugad = ll_len(pArrayList);
//
//		if(cantidadJugad != -1){
//			for(int i = 0; i<cantidadJugad; i++){
//				jugadorAux = (eParticipante*)ll_get(pArrayList, i);
////				if(jug_getSIdSeleccion(jugadorAux, &idSelecJugAux)==0){
////					if(idSelecJugAux != 0){
//						fwrite(jugadorAux, sizeof(eParticipante), 1, pFileBin);
//						retorno = 1;
////					}
////				}
//			}
//		}
//
//		free(jugadorAux);
//		fclose(pFileBin);
//	}
//
//    return retorno;
//}
//
//int controller_CargarArchivoBinario(char* pathJugadores){
//	int retorno = -1;
//
//	if(pathJugadores != NULL){
//		LinkedList* jugadoresAuxiliar;
//		jugadoresAuxiliar = ll_newLinkedList();
//
//		if(jugadoresAuxiliar != NULL){
//			if(controller_cargarParticipantesDesdeBinario(pathJugadores, jugadoresAuxiliar)==1){
//				controller_listarParticipantes(jugadoresAuxiliar);
//				retorno = 1;
//			}
//		}
//
//		ll_deleteLinkedList(jugadoresAuxiliar);
//	}
//	return retorno;
//}
//
//
int controller_filtrarCategoria(LinkedList* pArrayList){
	int retorno = -1;
	LinkedList* participantesCategoria = NULL;
	int opcion;
	char categoriaElegida[20];

	if(utn_getNumero(&opcion, "\n1- MX1"
							 "\n2- MX2"
							 "\n3- MX3"
							 "\n4- SUPER_ATV"
							 "\nelija la categoria. Opcion:", "\nError", 1, 4, 1)==0){
		participantesCategoria = ll_newLinkedList();
		if(participantesCategoria != NULL){
			switch (opcion) {
				case 1:
					strcpy(categoriaElegida, "MX1");
					participantesCategoria = ll_filter(pArrayList, part_filtrarCategoriaMX1);
					break;
				case 2:
					strcpy(categoriaElegida, "MX2");
					participantesCategoria = ll_filter(pArrayList, part_filtrarCategoriaMX2);
					break;
				case 3:
					strcpy(categoriaElegida, "MX3");
					participantesCategoria = ll_filter(pArrayList, part_filtrarCategoriaMX3);
					break;
				case 4:
					strcpy(categoriaElegida, "SUPER_ATV");
					participantesCategoria = ll_filter(pArrayList, part_filtrarCategoriaSuper);
					break;
			}
			controller_listarParticipantes(participantesCategoria);
			retorno = 1;
		}
	}

	return retorno;
}
//
int controller_mapearPromedio(LinkedList* pArrayList){
	int retonorno = -1;
	LinkedList* participantesMapeados = NULL;

	participantesMapeados = ll_newLinkedList();

	if(participantesMapeados != NULL){
		participantesMapeados = ll_map(pArrayList, part_mapearPromedio);
		controller_listarParticipantes(participantesMapeados);
		retonorno = 1;
	}

	return retonorno;
}

