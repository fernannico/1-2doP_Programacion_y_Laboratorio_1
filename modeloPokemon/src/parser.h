
#ifndef PARSER_H_
#define PARSER_H_

//#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>


/// @brief Parsea los datos de los pokemones desde el archivo jugadores.csv (modo texto).
/// @param pFile puntero a la estructura FILE
/// @param pArrayListPokemon LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_PokemonFromText(FILE* pFile , LinkedList* pArrayListPokemon);

/*
/// @brief Parsea los datos de los jugadores desde el archivo binario.
/// @param pFile puntero a la estructura FILE
/// @param pArrayListJugador LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/// @brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
/// @param pFile puntero a la estructura FILE
/// @param pArrayListSeleccion LinkedList*
/// @return int retorna -1 si no pudo parsear y 1 si pudo
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
*/

#endif /* PARSER_H_ */
