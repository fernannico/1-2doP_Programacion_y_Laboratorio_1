
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "participantes.h"

/// @brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los jugadores
int controller_cargarParticipantesDesdeTexto(char* path , LinkedList* pArrayListJugador);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los jugadores
int controller_cargarParticipantesDesdeBinario(char* path , LinkedList* pArrayListJugador);

int controller_listarParticipantes(LinkedList* pArrayList);

int controller_editarElemento(LinkedList* pArrayList);

/// @brief Ordenar jugadores
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores o selecciones es NULL o si se ingreso un dato invalido
/// 					 1 si se pudo ordenar y listar a los jugadores
/// 					 2 si se decidio por no ordenar jugadores
int controller_ordenarParticipantes(LinkedList* pArrayList);

/// @brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si no se pudo abrir el archivo en modo escritura (error de fopen) o si falla el retorno de la longitud del array
/// 					 1 si pudo guardar los jugadores en el archivo csv
int controller_guardarParticipantesModoTexto(char* path , LinkedList* pArrayList);

/// @brief Guarda los datos de los jugadores en el archivo binario.
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @return int retorna -1 si el puntero a la lista de jugadores es NULL, si la funcion fopen devuelve error, si falla el retorno de la longitud del array o si se ingreso una opcion invalida
/// 					 1 si se pudo guardar a los jugadores en el archivo binario
int controller_guardarParticipantesModoBinario(char* path , LinkedList* pArrayListJugador);

///--------------------------------------------------------------
/// propias

/// @brief controller para la opcion de ordenar y listar los jugadores o selecciones segun un criterio ascendente/descendente
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param pArrayListSeleccion LinkedList* Puntero a la lista de selecciones
/// @return int retorna -1 si el puntero a la lista de selecciones-jugadores es NULL o si se ingreso una dato invalido
/// 					 1 si pudo ordenar y listar los jugadores o selecciones
int controller_ordenarParticipantesYSelecciones(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/// @brief Carga los datos de los jugadores desde el archivo generado en modo binario.
/// @param pathParticipantes cadena de caracteres que representa el archivo de jugadores (ruta y el nombre del archivo)
/// @param pathSelecciones cadena de caracteres que representa el archivo de selecciones (ruta y el nombre del archivo)
/// @return int retorna -1 si no se pudo abrir los archivos (error de fopen)
/// 					 1 si pudo carga los jugadores desde el archivo binario
int controller_CargarArchivoBinario(char* pathParticipantes/*, char* pathSelecciones*/);

int controller_filtrarCategoria(LinkedList* pArrayList);

int controller_mapearPromedio(LinkedList* pArrayList);


