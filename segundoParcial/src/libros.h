
#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include "LinkedList.h"
#include "Controller.h"

typedef struct
{
	int id;
	char titulo[100];
	float importe;
	int idTipo;

}eLibro;

/// @brief constructor de -elemento-
/// @return retorna un puntero en memoria dinamica del tipo de variable -elemento-
eLibro* lib_new();

/// @brief constructor de -elemento- para asignarle valor a sus campos
/// @param idStr string de caracteres para el id
/// @param nombreCompletoStr string de caracteres para el nombre
/// @param edadStr string de caracteres  para la edad
/// @param posicionStr string de caracteres para la posicion
/// @param nacionalidadStr string de caracteres para nacionalidad
/// @param idSeleccionStr string de caracteres para el id de seleccion
/// @return puntero al -elemento- con los datos cargados en sus campos
eLibro* lib_newParametros(char* idStr,char* titulo, char* importe, char* idTipo);

/// @brief borra un -elemento- de memoria dinamica
/// @param this el puntero al -elemento- a borrar
void lib_delete(eLibro* this);

/// @brief setter para asignarle un id al -elemento-
/// @param this el puntero al -elemento-
/// @param id id a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int lib_setId(eLibro* this,int id);

/// @brief getter para obtener el id de un libro
/// @param this el puntero al libro
/// @param id puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int lib_getId(eLibro* this,int* id);

/// @brief setter para asignarle un nombre al libro
/// @param this el puntero al libro
/// @param nombre a asignar
/// @return retorna -1 si no pudo asignar y 1 si se logro
int lib_setTitulo(eLibro* this,char* titulo);

/// @brief getter para obtener el nombre de un libro
/// @param this el puntero al libro
/// @param nombreCompleto puntero a la variable donde se guardara el valor
/// @return retorna -1 si no pudo obtener el valor y 1 si pudo
int lib_getTitulo(eLibro* this,char* titulo);

/// @brief
/// @param this
/// @param importe
/// @return
int lib_setImporte(eLibro* this,float importe);

/// @brief
/// @param this
/// @param importe
/// @return
int lib_getImporte(eLibro* this,float* importe);

/// @brief
/// @param this
/// @param idTipo
/// @return
int lib_setIdTipo(eLibro* this,int idTipo);

/// @brief
/// @param this
/// @param idTipo
/// @return
int lib_getIdTipo(eLibro* this,int* idTipo);

///----------------------
/// propias

/// @brief para obtener los valores asignados a los campos de un libro
/// @param unLibro el puntero al libro que quiero sus datos
/// @param id
/// @param titulo
/// @param importe
/// @param idTipo
/// @return -1 si no pudo obtener los valores y 1 si pudo
int lib_getOneLibro(eLibro* unLibro, int* id, char* titulo, float* importe, int* idTipo);

/// @brief para asignar valores a los campos del libro a travez de parametros
/// @param unElemento el puntero al libro
/// @param id
/// @param nombreCompleto
/// @param edad
/// @param posicion
/// @param nacionalidad
/// @param idSeleccion
/// @return retorna -1 si no pudo settear los valores y 1 si pudo
int lib_setOneLibro(eLibro* unElemento,  int id, char* titulo, float importe, int idTipo);

/// @brief para mostrar los datos de un libro
/// @param unElemento el puntero al libro
/// @return retorna -1 si no pudo mostrar al libro y 1 si pudo
int lib_printOneLibro(eLibro* unElemento);

/// @brief compara dos libros por la edad retornando el ordenamiento
/// @param unElemento
/// @param otrolibro
/// @return retorna 0 si tienen la misma edad, -1 si unElemento es mas joven y 1 si unElemento es mas viejo
int lib_compararPorImporte(void* unLibro,void* otroLibro);


/// @brief para mostrar la cabecera de la lista de libros
void mostrarCabecera(void);

/// @brief criterio para mapear los libros
/// @param element
void* lib_mapearImporte(void* element);


#endif // jug_H_INCLUDED
