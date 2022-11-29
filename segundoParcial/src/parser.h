
#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

/// @brief Parsea los datos de los libros desde el archivo libros.csv (modo texto).
/// @param pFile puntero a la estructura FILE
/// @param pArrayListlibro LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_librosFromText(FILE* pFile , LinkedList* pArrayList);

/// @brief Parsea los datos de los libros desde el archivo binario.
/// @param pFile puntero a la estructura FILE
/// @param pArrayListlibro LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_librosFromBinary(FILE* pFile , LinkedList* pArrayList);


#endif /* PARSER_H_ */
