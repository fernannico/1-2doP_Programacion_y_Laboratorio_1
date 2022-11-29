
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "libros.h"

/// @brief Carga los datos de los libros desde el archivo libros.csv (modo texto).
/// @param path char* cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de libros
/// @return int retorna -1 si el puntero a la lista de libros es NULL o si no puede abrir el archivo solicitado
/// 					 1 si pudo cargar los libros
int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayList );

int controller_listarLibros(LinkedList* pArrayList);


/// @brief Ordenar libros
/// @param pArrayList  LinkedList* Puntero a la lista de libros
/// @return int retorna -1 si el puntero a la lista de libros o selecciones es NULL o si se ingreso un dato invalido
/// 					 1 si se pudo ordenar y listar a los libros
/// 					 2 si se decidio por no ordenar libros
int controller_ordenarLibros(LinkedList* pArrayList );

/// @brief Guarda los datos de los libros en el archivo libros.csv (modo texto).
/// @param path cadena de caracteres que representa el archivo (ruta y el nombre del archivo)
/// @param pArrayList  LinkedList* Puntero a la lista de libros
/// @return int retorna -1 si el puntero a la lista de libros es NULL, si no se pudo abrir el archivo en modo escritura (error de fopen) o si falla el retorno de la longitud del array
/// 					 1 si pudo guardar los libros en el archivo csv
int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayList );

/// @brief Carga los datos de los libros desde el archivo generado en modo binario.
/// @param pathLibros cadena de caracteres que representa el archivo de libros (ruta y el nombre del archivo)
/// @param pathSelecciones cadena de caracteres que representa el archivo de selecciones (ruta y el nombre del archivo)
/// @return int retorna -1 si no se pudo abrir los archivos (error de fopen)
/// 					 1 si pudo carga los libros desde el archivo binario
int controller_CargarArchivoBinario(char* pathLibros);

/// @brief para mapear los libros
/// @param pArrayList lista
/// @return
int controller_mapearImporte(LinkedList* pArrayList);

