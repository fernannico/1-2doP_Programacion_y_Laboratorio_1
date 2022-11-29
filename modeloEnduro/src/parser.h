
#ifndef PARSER_H_
#define PARSER_H_
#include "Controller.h"

/// @brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
/// @param pFile puntero a la estructura FILE
/// @param pArrayListJugador LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_ParticipantesFromText(FILE* pFile , LinkedList* pArrayList);

/// @brief Parsea los datos de los jugadores desde el archivo binario.
/// @param pFile puntero a la estructura FILE
/// @param pArrayListJugador LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_ParticipantesFromBinary(FILE* pFile , LinkedList* pArrayList);



#endif /* PARSER_H_ */
