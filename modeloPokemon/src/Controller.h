
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "pokemon.h"
#include "input.h"

/// @brief Carga los datos de los Elementos desde el archivo Elementos.csv (modo texto).
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de Elementos
/// @return int retorna -1 si el puntero a la lista de Elementos es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los Elementos
int controller_cargarElementosDesdeTexto(char* path , LinkedList* pArrayList);

int controller_guardarPokemonesModoTexto(char* path , LinkedList* pArrayList);


/// @brief Carga los datos de los Elementos desde el archivo generado en modo binario.
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de Elementos
/// @return int retorna -1 si el puntero a la lista de Elementos es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los Elementos
int controller_cargarElementosDesdeBinario(char* path , LinkedList* pArrayList );

int controller_listarElementos(LinkedList* pArrayList);

int controller_filtrarTipoFuego(LinkedList* pArrayList);

int controller_filtrarXlVeneno(LinkedList* pArrayList);

int controller_mapearAtaqueCargado(LinkedList* pArrayList);

/// @brief Ordenar Elementos
/// @param pArrayList  LinkedList* Puntero a la lista de Elementos
/// @return int retorna -1 si el puntero a la lista de Elementos o selecciones es NULL o si se ingreso un dato invalido
/// 					 1 si se pudo ordenar y listar a los Elementos
/// 					 2 si se decidio por no ordenar Elementos
int controller_ordenarElementos(LinkedList* pArrayList );

/// @brief Guarda los datos de los Elementos en el archivo Elementos.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de Elementos
/// @return int retorna -1 si el puntero a la lista de Elementos es NULL, si no se pudo abrir el archivo en modo escritura (error de fopen) o si falla el retorno de la longitud del array
/// 					 1 si pudo guardar los Elementos en el archivo csv
int controller_guardarElementosModoTexto(char* path , LinkedList* pArrayList );

/// @brief Guarda los datos de los Elementos en el archivo binario.
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de Elementos
/// @return int retorna -1 si el puntero a la lista de Elementos es NULL, si la funcion fopen devuelve error, si falla el retorno de la longitud del array o si se ingreso una opcion invalida
/// 					 1 si se pudo guardar a los Elementos en el archivo binario
int controller_guardarElementosModoBinario(char* path , LinkedList* pArrayList );

///--------------------------------------------------------------
/// propias

/// @brief Carga los datos de los Elementos desde el archivo generado en modo binario.
/// @param pathElementos cadena de caracteres que representa el archivo de Elementos (ruta y el nombre del archivo)
/// @param pathSelecciones cadena de caracteres que representa el archivo de selecciones (ruta y el nombre del archivo)
/// @return int retorna -1 si no se pudo abrir los archivos (error de fopen)
/// 					 1 si pudo carga los Elementos desde el archivo binario
int controller_CargarArchivoBinario(char* pathElementos/*, char* pathSelecciones*/);

//int controller_listarElementosConSeleccion(LinkedList* pArrayList /*, LinkedList* pArrayListSeleccion*/);
