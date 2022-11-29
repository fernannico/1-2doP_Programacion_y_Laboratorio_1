
#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
	int id_cuatri;
	char nombre[100];
	char categoria[30];
	int tiempo;
	int promedio;

}eParticipante;

/// @brief constructor de -elemento-
/// @return retorna un puntero en memoria dinamica del tipo de variable -elemento-
eParticipante* part_new();

/// @brief constructor de -elemento- para asignarle valor a sus campos
/// @param idStr string de caracteres para el id
/// @param nombreCompletoStr string de caracteres para el nombre
/// @param edadStr string de caracteres  para la edad
/// @param posicionStr string de caracteres para la posicion
/// @param nacionalidadStr string de caracteres para nacionalidad
/// @param idSeleccionStr string de caracteres para el id de seleccion
/// @return puntero al -elemento- con los datos cargados en sus campos
eParticipante* part_newParametros(char* idStr,char* nombreStr,char* categoriaStr, char* tiempoStr, char* promedioStr);

/// @brief borra un -elemento- de memoria dinamica
/// @param this el puntero al -elemento- a borrar
void part_delete(eParticipante* this);

/// @brief setter para asignarle un id al -elemento-
/// @param this el puntero al -elemento-
/// @param id id a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int part_setId(eParticipante* this,int id);

/// @brief getter para obtener el id de un jugador
/// @param this el puntero al jugador
/// @param id puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int part_getId(eParticipante* this,int* id);

/// @brief setter para asignarle un nombre al jugador
/// @param this el puntero al jugador
/// @param nombre a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int part_setNombre(eParticipante* this,char* nombre);

/// @brief getter para obtener el nombre de un jugador
/// @param this el puntero al jugador
/// @param nombreCompleto puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int part_getNombre(eParticipante* this,char* nombre);

int part_setCategoria(eParticipante* this,char* categoria);
int part_getCategoria(eParticipante* this,char* categoria);
int part_setTiempo(eParticipante* this,int tiempo);
int part_getTiempo(eParticipante* this,int* tiempo);
int part_setPromedio(eParticipante* this,int promedio);
int part_getPromedio(eParticipante* this,int* promedio);



///----------------------
/// propias

/// @brief para obtener los valores asignados a los campos de un jugador
/// @param unParticipante el puntero al jugador que quiero sus datos
/// @param id puntero a la variable donde se guardara el valor
/// @param nombreCompleto puntero a la variable donde se guardara el valor
/// @param edad puntero a la variable donde se guardara el valor
/// @param posicion puntero a la variable donde se guardara el valor
/// @param nacionalidad puntero a la variable donde se guardara el valor
/// @param idSeleccion puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener los valores y 1 si pudo
int part_getOneParticipante(eParticipante* unParticipante, int* id, char* nombre, char* categoria, int* tiempo, int* promedio);

/// @brief para asignar valores a los campos del jugador a travez de parametros
/// @param unParticipante el puntero al jugador
/// @param id
/// @param nombreCompleto
/// @param edad
/// @param posicion
/// @param nacionalidad
/// @param idSeleccion
/// @return retorna -1 si no pudo settear los valores y 1 si pudo
int part_setOneParticipante(eParticipante* unParticipante, int id, char* nombre, char* categoria, int tiempo, int promedio);

/// @brief para mostrar los datos de un jugador
/// @param unParticipante el puntero al jugador
/// @return retorna -1 si no pudo mostrar al jugador y 1 si pudo
int part_printOneParticipante(eParticipante* unParticipante);

/// @brief compara dos jugadores por nombre retornando el ordenamiento
/// @param unParticipante
/// @param otroJugador
/// @return retorna el int de la comparacion de la funcion stricmp
int part_CompararPorCategoria(void* unParticipante,void* otroParticipante);

/// @brief compara dos jugadores por la edad retornando el ordenamiento
/// @param unParticipante
/// @param otroJugador
/// @return retorna 0 si tienen la misma edad, -1 si unParticipante es mas joven y 1 si unParticipante es mas viejo
int part_compararPorPromedioIgualCategoria(void* unParticipante,void* otroParticipante);

/// @brief para recibir el indice en que se encuentra el jugador a traves del id
/// @param pArrayListJugador LinkedList* Puntero a la lista de jugadores
/// @param id id del jugador del que quiero saber el indice
/// @return retorna -1 si el puntero a la lista de jugadores es NULL, si falla el retorno de la longitud del array
/// 				 int del el indice donde se encuentra el jugador
int part_BuscarIndiceParticipantePorId(LinkedList* pArrayList, int id);

int part_modificarNombre(eParticipante* this);

int part_modificarNumero(eParticipante* this);


/// @brief para mostrar la cabecera de la lista de jugadores
void mostrarCabecera(void);

int part_filtrarCategoriaMX1(void* elemento);
int part_filtrarCategoriaMX2(void* elemento);
int part_filtrarCategoriaMX3(void* elemento);
int part_filtrarCategoriaSuper(void* elemento);

void* part_mapearPromedio(void* element);

#endif // jug_H_INCLUDED
