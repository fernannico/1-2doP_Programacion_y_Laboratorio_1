/*
 * editorial.h
 *
 *  created on: 30 sep. 2022
 *      Author: User
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include "validaciones.h"
#define LIBRE 0
#define CARGADO 1
#define BAJADO 2
#define TAMEP 5
#define TAMA 10
#define TAML 10
#define TAMG 5

typedef struct{
	int idPais;
	char descripcion[51];
	int estado;
}ePais;

typedef struct{
	int idAutor;
	char nombre[51];
	int pais;				///de ePais id
	int estado;
}eAutor;

typedef struct{
	int idEditorial;
	char descripcion[51];
	int estado;
}eEditorial;

typedef struct{
	int dia;
	int mes;
	int	anio;
}eFecha;

typedef struct{
	int idLibro;
	char titulo[51];
	eFecha fechaPublicacion;
	float importe;
	int idAutor;
	int idEditorial;
	int estado;
	int idGenero;
}eLibro;

typedef struct{
	int idGenero;
	char descripcion[51];
}eGenero;

/// \brief carga las editoriales harcodeadas con sus valores respectivos
/// \param editoriales el arrray de estructuras editoriales a cargar
/// \param size el tamaño del array de editoriales
void cargarEditorialesHarcodeadas(eEditorial editoriales[], int size);

/// \brief carga los autores harcodeadas con sus valores respectivos
/// \param autores el arrray de estructuras autores a cargar
/// \param size el tamaño del array de autores
void cargarAutoresHarcodeadas(eAutor autores[], int size);

/// \brief carga los paises harcodeadas con sus valores respectivos
/// \param paises el arrray de estructuras paises a cargar
/// \param size el tamaño del array de paises
void cargarPaisesHarcodeadas(ePais paises[], int size);

/// \brief carga los libros harcodeadas con sus valores respectivos
/// \param libros el arrray de estructuras libros a cargar
/// \param sizeLibros el tamaño del array de libros
void cargarLibrosHarcodeados(eLibro libros[], int sizeLibros); ///comentar luego

/// @brief carga los generos harcodeadas con sus valores respectivos
/// @param generos el arrray de estructuras generos a cargar
/// @param sizeGenero el tamaño del array de generos
void cargarGenerosHarcodeados(eGenero generos[], int sizeGenero);

/// \brief inicializa el array de libros con el estado en LIBRE
/// \param libros el arrray de estructuras libros a inicializar
/// \param sizeLibros el tamaño del array de libros
void inicializarEstadoLibros(eLibro libros[], int sizeLibros);

/// \brief busca el primer espacio LIBRE en el array de estructuras libros y lo retorna
/// \param libros el arrray de estructuras libros donde buscar el espacio libre
/// \param sizeLibro el tamaño del array de libros
/// \return retorna el indice del primer espacio libre
int buscarEspacioLibre(eLibro libros[], int sizeLibro);

/// \brief valida si hay un libro con el estado cARGADO en el array libros
/// \param libros el arrray de estructuras libros donde verificar
/// \param size el tamaño del array de libros
/// \return retorna 1 si hay libros cargados y 0 si no los hay
int ValidarPresenciacargado(eLibro libros[], int size);

/// \brief funcion para la opcion Alta de libros con validaciones logicas
/// \param libros el arrray de estructuras libros donde se realiza la carga
/// \param autores el arrray de estructuras autores usado para la carga del autor del libro
/// \param editoriales el arrray de estructuras editoriales usado para la carga de la editorial del libro
/// \param paises el arrray de estructuras paises usado para la carga del pais del libro
/// \param generos el arrray de estructuras genero usado para la carga del genero del libro
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEditPaises el tamaño del array de editoriales o paises
/// \param sizeGeneros el tamaño del array generos
/// \param codigoAutoIncremental puntero de referencia a la direccion de memoria de la variable del codigo autoincremental
void cargarLibros(eLibro libros[], eAutor autores[], eEditorial editoriales[], ePais paises[], eGenero generos[],int sizeLibros, int sizeAutores, int sizeEditPaises, int* codigoAutoIncremental, int sizeGeneros);

/// \brief da de alta un libro
/// \param libros el arrray de estructuras libros donde se realiza el alta
/// \param autores el arrray de estructuras autores usado para la carga del autor del libro
/// \param editoriales el arrray de estructuras editoriales usado para la carga de la editorial del libro
/// \param paises el arrray de estructuras paises usado para la carga del pais del libro
/// \param generos el arrray de estructuras generos usado para la carga del genero del libro
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEmpPais el tamaño del array de editoriales o paises
/// \param codigoAutoIncremental el codigo que se le asignara automaticamente al libro cargado
/// \param sizeGeneros el tamaño del array de generos
/// \return retorna 1 si el libro pudo ser cargado y -1 si no pudo realizarce la carga
int altaLibro(eLibro libros[], eAutor autores[], eEditorial editoriales[], ePais paises[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEmpPais, int codigoAutoIncremental, int sizeGeneros);

/// \brief para cargar la fecha de un libro validando que los meses tengan su maximo de dias correspondiente
/// \param libro el arrray de estructuras libros donde se va a cargar la fecha
/// \param posicion el indice del libro al que se le va a cargar la fecha
/// \return retorna 1 si se pudo cargar la fecha o -1 si mes,dia o anio no fueron bien cargados
int cargarFecha(eLibro libro[], int posicion);

/// \brief para modificar alguno de los campos cargados de un libro
/// \param libros el arrray de estructuras libros donde se encuentra el libro a modificar
/// \param editoriales el arrray de estructuras editoriales usado para la modificacion de la editorial del libro
/// \param paises el arrray de estructuras paises usado para la modificacion del pais del libro
/// \param autores el arrray de estructuras autores usado para la modificacion del autor del libro
/// \param sizeLibros el tamaño del array de libros
/// \param sizeEditPaises el tamaño del array de editoriales o paises
/// \param sizeAutores el tamaño del array de autores
/// \param codigoAutoIncremental usado para determinar el maximo id a modificar
void modificarLibro(eLibro libros[], eEditorial editoriales[], ePais paises[], eAutor autores[], eGenero generos[], int sizeLibros, int sizeEditPaises, int sizeAutores, int codigoAutoIncremental, int sizeGeneros);

/// \brief para dar de baja logica un libro del array
/// \param libros el arrray de estructuras libros donde se realizara la baja
/// \param autores el arrray de estructuras autores usado para mostrar los autores de los libros
/// \param editoriales el arrray de estructuras editoriales usado para mostrar las editoriales de los libros
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEdit el tamaño del array de editoriales
/// \param codigoAutoIncremental usado para determinar el maximo id a borrar
void darDeBaja(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEdit, int codigoAutoIncremental, int sizeGeneros);


/// \brief Realiza los calculos de la opcion de informe
/// \param libros  el arrray de estructuras libros usado para realizar los calculos y demostracion de ellos
/// \param sizeLibros  el tamaño del array de libros
/// \param acumuladorImportes puntero de referencia a la direccion de memoria de la variable acumulador de importes
/// \param contadorLibroscargados puntero de referencia a la direccion de memoria de la variable contador de libros cargados
/// \param promedioImportes puntero de referencia a la direccion de memoria de la variable promedio de importes
/// \param contadorSuperanPromedio puntero de referencia a la direccion de memoria del contador de libros que superan el promedio
/// \param contadorLibrosSXX puntero de referencia a la direccion de memoria del contador de libros que son anteriores al anio 2000
void calcularInforme(eLibro libros[], int sizeLibros, float* acumuladorImportes, int* contadorLibroscargados, float* promedioImportes, int* contadorSuperanPromedio, int* contadorLibrosSXX);

/// \brief para mostrar el resultado de los calculos de la opcion informe
/// \param acumuladorImportes variable con el valor de importes acumulados de los libros cARGADOS
/// \param promedioImportes variable con el valor del promedio del importe de los libros cargados
/// \param contadorSuperanPromedio variable con el valor del contador de libros que superan el promedio
/// \param contadorLibrosSXX variable con el valor del contador de libros que son anteriores al anio 2000
void mostrarResultadosCalculos(float acumuladorImportes, float promedioImportes, int contadorSuperanPromedio, int contadorLibrosSXX);


/// \brief para ingresar a la opcion de listar las entidades con sus valores cargados
/// \param editoriales la estructura editoriales usada para mostrar sus detalles
/// \param paises la estructura paises usada para mostrar sus detalles
/// \param autores la estructura autores usada para mostrar sus detalles
/// \param libros la estructura libros usada para mostrar sus detalles
/// \param generos la estructura generos usada para mostrar sus detalles
/// \param sizeLibros  el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEditPais el tamaño del array de editoriales y paises
/// \param sizeGeneros  el tamaño del array de generos
void listarDetalles(eEditorial editoriales[], ePais paises[], eAutor autores[], eLibro libros[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros);

/// \brief para mostrar la entidad editoriales con sus valores correspondientes
/// \param editoriales el arrray de estructuras editoriales usado para mostrar sus valores
/// \param sizeEditoriales el tamaño de la estructura editoriales
void mostrarDetallesEditoriales(eEditorial editoriales[], int sizeEditoriales);

/// \brief para mostrar la entidad paises con sus valores correspondientes
/// \param paises el arrray de estructuras paises usado para mostrar sus valores
/// \param sizePaises el tamaño de la estructura paises
void mostrarDetallesPaises(ePais paises[], int sizePaises);

/// \brief para mostrar la entidad autores con sus valores correspondientes
/// \param autores el arrray de estructuras editoriales usado para mostrar sus valores
/// \param paises el arrray de estructuras paises usado para mostrar el nombre del pais de cada autor
/// \param sizeAutores el tamaño de la estructura autores
/// \param sizePais el tamaño de la estructura paises
void mostrarDetallesAutores(eAutor autores[], ePais paises[], int sizeAutores, int sizePais);

/// \brief para mostrar la entidad generos con sus valores correspondientes
/// \param generos el arrray de estructuras generos usado para mostrar sus valores
/// \param sizeGeneros el tamaño de la estructura generos
void mostrarDetallesGeneros(eGenero generos[], int sizeGeneros);


/// \brief para mostrar un libro segun el indice que se le indica
/// \param indiceLibro el indice del libro a mostrar
/// \param libros el arrray de estructura libros usado para mostrar el libro indicado
/// \param autores el arrray de estructura autores usado para mostrar el nombre del autor
/// \param editoriales el arrray de estructuras editoriales usado para mostrar la descripcion de la editorial
/// \param generos el arrray de estructuras generos usado para mostrar la descripcion del genero
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEmpPaises el tamaño del array de editoriales
/// \param sizeGenero  el tamaño del array de generos
void mostrarUnLibroPorIndice(int indiceLibro, eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero genero[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero);

/// @brief para mostrar un libro segun el id que se le indica
/// \param idLibro el ID del libro a mostrar
/// \param libros el arrray de estructura libros usado para mostrar el libro indicado
/// \param autores el arrray de estructura autores usado para mostrar el nombre del autor
/// \param editoriales el arrray de estructuras editoriales usado para mostrar la descripcion de la editorial
/// \param generos el arrray de estructuras generos usado para mostrar la descripcion del genero
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEmpPaises el tamaño del array de editoriales
/// \param sizeGenero  el tamaño del array de generos
void mostrarUnLibroPorId(int idLibro, eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero genero[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero);

/// \brief para mostrar todos los libros con el estado cARGADO
/// \param libros el arrray de estructura libros usado para mostrar los libros
/// \param autores el arrray de estructura autores usado para mostrar sus nombres
/// \param editoriales el arrray de estructura editoriales usado para mostrar sus descripciones
/// \param generos  el arrray de estructura generos usado para mostrar sus descripciones
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEd el tamaño del array de editoriales
/// \param sizeGenero el tamaño del array de generos
void mostrarTodosLosLibros(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEd, int sizeGeneros);

/// \brief ordena y muestra los libros segun importe de manera descendente y por titulo de manera ascendente
/// \param libros el arrray de estructura libros usado para tener una copia de sus cargas a ordenar
/// \param autores el arrray de estructura autores usado para mostrar el nombre del autor
/// \param editoriales el arrray de estructura editoriales usado para mostrar la descripcion de la editorial
/// \param sizeLibros el tamaño del array de libros
void ordenarLibrosPorImporteYTitulo(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeGenero);

/// \brief para mostrar como quedaron ordenados los libros
/// \param libros el arrray de estructura libros usado para mostrar sus detalles
/// \param autores el arrray de estructura autores  usado para mostrar el nombre del autor
/// \param editoriales el arrray de estructura editoriales usado para mostrar la descripcion de la editorial
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEmpPaises el tamaño del array de editoriales
void mostrarLibrosOrdenados(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEmpPaises, int sizeGenero);

/// @brief valida si existe al menos un libro no novela
/// @param libros el arrray de estructura libros
/// @param sizeLibros el tamaño del array de libros
/// @return retorna 1 si existe un libro no novela o 0 si no lo hay
int validarPresenciaNoNovela(eLibro libros[], int sizeLibros);

/// @brief para mostrar los libros que no sean del genero novela
/// \param libros el arrray de estructura libros usado para mostrar sus detalles
/// \param autores el arrray de estructura autores  usado para mostrar el nombre del autor
/// \param editoriales el arrray de estructura editoriales usado para mostrar la descripcion de la editorial
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEditPaises el tamaño del array de editoriales
/// @param sizeGeneros el tamaño del array de generos
void mostrarLibrosNoNovela(eLibro libros[], eAutor autores[], eEditorial editoriales[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros);

/// @brief valida si existe al menos un libro de autor argentino en una editorial dada
/// @param idEditorial id de la editorial a buscar si tiene libros de autores argentinos
/// @param libros el arrray de estructura libros
/// @param autores el arrray de estructura autores
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// @return retorna 0 si no hay libros argentinos en esa editorial y 1 si existe al menos uno
int validarPresenciaLibrosArgentinosPorIdEditorial(int idEditorial, eLibro libros[], eAutor autores[], int sizeLibros, int sizeAutores);

/// @brief para mostrar los libros de autores argentinos de una editorial determinada
/// \param editoriales el arrray de estructura editoriales usado para mostrar la descripcion de la editorial
/// @param paises el arrray de estructura paises
/// @param autores el arrray de estructura autores
/// @param libros el arrray de estructura libros
/// @param generos el arrray de estructura generos
/// \param sizeLibros el tamaño del array de libros
/// \param sizeAutores el tamaño del array de autores
/// \param sizeEditPaises el tamaño del array de editoriales
/// @param sizeGeneros el tamaño del array de generos
void mostrarLibrosArgentinosPorEditorial(eEditorial editoriales[], ePais paises[], eAutor autores[], eLibro libros[], eGenero generos[], int sizeLibros, int sizeAutores, int sizeEditPais, int sizeGeneros);

/// @brief para retornar el indice de un libro segun el id
/// @param libros el arrray de estructura libros
/// @param sizeLibros el tamaño del array de libros
/// @param id el ID del libro que quiero su indice
/// @return retorna -1 si no esta ese ID o el indice si existe el libro
//int buscarIndiceLibroPorId(eLibro libros[], int sizeLibros, int id);

/// \brief para mostrar el menu principal de 5 opciones
void mostrarMenuPrincipal();

/// \brief para mostrar el submenu de la opcion modificaciones
void mostrarSubmenuModificacion();

/// \brief para mostrar el submenu de la opcion listar
void mostrarSubmenuListar();
#endif /* LIBRO_H_ */
