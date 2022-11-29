/*
 * pokemon.h
 *
 *  Created on: 21 nov. 2022
 *      Author: User
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include "Controller.h"
typedef struct {
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVariocolor;
}ePokemon;

ePokemon* poke_new();
ePokemon* poke_newParametros(char* numeroStr, char* nombreStr, char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVariocolorStr);
void poke_delete(ePokemon* this);
int poke_setNumero(ePokemon* this,int numero);
int poke_getNumero(ePokemon* this,int* numero);
int poke_setNombre(ePokemon* this,char* nombre);
int poke_getNombre(ePokemon* this,char* nombre);
int poke_setTipo(ePokemon* this,char* tipo);
int poke_getTipo(ePokemon* this,char* tipo);
int poke_setTamanio(ePokemon* this,char* tamanio);
int poke_getTamanio(ePokemon* this,char* tamanio);
int poke_setAtaqueCargado(ePokemon* this,char* ataqueCargado);
int poke_getAtaqueCargado(ePokemon* this,char* ataqueCargado);
int poke_setValorAtaque(ePokemon* this,int valorAtaque);
int poke_getValorAtaque(ePokemon* this,int* valorAtaque);
int poke_setEsVariocolor(ePokemon* this,int esVariocolor);
int poke_getEsVariocolor(ePokemon* this,int* esVariocolor);

int poke_getOnePokemon(ePokemon* unPokemon, int* numero, char* nombre, char* tipo,char* tamanio, char* ataqueCargado, int* valorAtaque, int* esVariocolor);
int poke_setOnePokemon(ePokemon* unPokemon, int numero,	char* nombre, char* tipo,char* tamanio, char* ataqueCargado, int valorAtaque, int esVariocolor);
int poke_printOnePokemon(ePokemon* unPokemon);
int poke_CompareByName(void* unPokemon,void* otroElemento);
int poke_BuscarIndicePokemonPorId(LinkedList* pArrayList, int id);
void mostrarCabecera(void);

int poke_filtrarTipoFuego(void* pokemon);
int poke_filtrarTamanioXl(void* unPokemon);
int poke_filtrarTipoVeneno(void* unPokemon);

void* poke_mapearAtaque(void* element);

#endif /* POKEMON_H_ */
