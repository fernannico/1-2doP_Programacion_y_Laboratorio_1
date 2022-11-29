#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado */
LinkedList* ll_newLinkedList(void){
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));		///asi creariamos el FirstNode
    ///tenre en cuenta q el constructor sin parametros lo que va a hcaer es crear el elemento pero
    if(this != NULL){
    	this->pFirstNode = NULL;
    	this->size = 0;///cuando creamos la lista, esta vacia.. inicializamos el size
     	 	 	 	 ///en el add va a ser cuando se empiezan a sumar, se agegan elementos y se agregan al size de la lista
     	 	 	 	 /// cuando creamos por primera vez un nuevo elemento, la cabecera va a apuntar al nodo que le agregamos. Es decir
     	 	 	 	 /// el 1000 no es de la cabecera, sino que apunta a la direccion de memoria del primer vagon (cuya direccion de memoria es 1000)
     	 	 	 	 /// entonces el LL es una estructura que se va llamando muchas veces a si mismo.
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista */
int ll_len(LinkedList* this){
    int returnAux = -1;
    ///el campo size del linkedlist nos va a dar el len

    if(this != NULL){
		returnAux = this->size;///y cual seria el valor de size? Cuando le asigno valor?
								 ///cuando se le da un valor inicial al size? : cuando se crea el linkedlist
								 /// el constructor por defecto (sin palabras), crea el espacio en memoria dinamica y le da un valor por defecto a sus campos
								 /// esto quiere decir que no le dimos un valor inicial al size. Entonces cuando retornamos en este -> estamos retornando basura
								 /// asi solo, tira error cuando la lista esta vacia. Tenemos que dar un valor por defecto cuando lo construimos (L21)
    }/*else{
    	returnAux = -1;
    }*////ya esta en la linea 31

    return returnAux;
}


/** \brief  OBTIENE un nodo de la lista
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                          (pNode) Si funciono correctamente!!! */
static Node* getNode(LinkedList* this, int nodeIndex){
/**como recorremos el ll: Tenemos la "cabeza" del ll: esto seria el first node, es lo que engancha-dirige los demas nodos que le vamos agregando.
 * ir a linea 32 de la estrcutura LL.
 * */
	///tengo que devolver el nodo por el indice pasado. Tomando de ejemplo el tren, el primer vagon seguido del cabeza es el 0, el 2do seria el indice 1.
	/// Si el indice pasado es 1, tengo que devolver el nodo 2 (2do vagon)
	/// hay que validar que la lista sea mayor que el valor del index pasado, este indice no puede superar la cantidad de elementos

	int cantidad;
//	int i;

//	void* pElementAux;
//	struct Node* pNextNodeAux;
	Node* unNodo = NULL;///al inicializar el puntero en null, si es error es lo que retorna, asiq no hace falta el else.
//	Node* siguienteNodo = NULL;

	if(this != NULL){
		cantidad = ll_len(this);
		if(cantidad != -1 && nodeIndex < cantidad && nodeIndex >=0){///no es "nodeIndex <= cantidad" porq estamos hablando de indices.  Tomando el tren, si tenemos 3 vagones no tenemos 3, sino que va del 0 al 2. 3 serian 4 bagones
			///ahora tenemos que saber donde empieza la lista, necesitamos el primer nodo para saber donde arrancamos ya que el primer dato sabe del siguiente y asi sucesivamente.
			unNodo = this->pFirstNode/*->pNextNode*/;///asiq xq el q apunta al primer nodo es pFirstNodo

			///while nodeIndex sea mayor a 0. O sea, si el usuario quiere el indice 0, no entra al while, entonces la fx devuelve pFirstNode
			/// es decir: yo puedo retornar el primer valor O los siguientes. Entonces me aseguro que si el indice que me pasan es 0, le estoy diciendo que el que apunta a ese primer elemento es el LL, entonces no recorro el resto
			/// entonces me guardo el primer nodo y no recorro la lista
			while(nodeIndex > 0/*siguienteNodo->pNextNode == NULL*/){
				//*siguienteNodo = unNodo->pNextNode;*/
				unNodo = unNodo->pNextNode;///no es como arrays donde le digo "anda a tal posicion, ahora a esta", aca tenemos que ir nodo a nodo.
											///entonces aca la primera vez que entra, viene siendo el primer nodo (1000), y como entró, le digo "apuntate al siguiente", entonces apunta al 2000. y asi sucesivamente
				nodeIndex--;///porque quiero que vaya restando y que no sea un bucle infinito. Si me pasa el 2 va a reducir las iteraciones hasta que llegue a 0
			}
		}/*else{
			if(siguienteNodo->pNextNode == NULL){
				unNodo = siguienteNodo->pElement;
			}
		}*/
					///no habia que recorrer por el largo de la lista!! sino por el nodeIndex. Si recorro la lista, siempre voy a obtener el ultimo!!!!
//			for(i = 0; i<cantidad; i++){
//				/*pElementAux =*/ unNodo->pElement;
//				/*pNextNodeAux =*/ unNodo->pNextNode;
//			}
//		}
	}

    return unNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente*/
Node* test_getNode(LinkedList* this, int nodeIndex){

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int returnAux = -1;
    int cantidad;

    ///si quiero agregar un elemento lo hago al final de la lista o en cualquier lugar.
    /// puede pasar q la lista este vacia y agregue el primer nodo.´
    // poner uno en medio implica que vamos a tener que correr todos para un costado, hay que cambiar todas las direcciones de memoria.. y no hay que perder las referencias.
    // Si quiero poner un vagon en el medio entre el vagon 2 y 3, el next node de 2mil va  ser el nuevo q pongas en el medio y el nuevo va a apuntar al 3000
    // pensar en el swap donde tenemos un auxiliar.. pensar que en el momento en que le digo al vagon 2 q guarde la direccion 4000 (nuevo)
    // voy a perder el 3000 si no lo guarde en un auxiliar! Entonces pierdo la referencia del 3er vagon. tengo
    // lo que puedo hacer es q el nuevo nodo creado ya de una asignarle el nextNode al vagon 3 q seria el siguiente. Asi ya no pierdo la referencia del 3ero
    // ahora si hago el swap sin miedo a perder la referencia--> le apunto al vagon 2 la direccion 4000 en el campo nextNode
    /// Entonces: lo que necesito es primero el previo a la posicion donde lo quiero guardar (2000) porq me va a dar la direccion de
    /// memoria del siguiente (el que va a apuntar el nuevo [3000]) y tambien le voy a asignar a2 la direccion del nuevo [4000] luego de que
    /// el nuevo (4000) tenga la direccion del siguiente (3000) para no perder su referencia.


    Node* nodoAnterior = NULL;
    Node* nodoAgregado =NULL;

	nodoAgregado = (Node*)malloc(sizeof(Node));
    /*pAuxNode->pNextNode;*////el nuevo nodo que acabo de agregar (guardar en memoria..) quiero guardar el puntero al anterior del indice.
     	 				///la funcion que me da un nodo es la getNode que creamos antes. Tengo que ver que le paso como indice a getNode para traer el nodo anterior al que quiero
    					/// "en el indice tal, dame el anterior", y en este anterior me guardo el indice del que acabo de crear y en el q acabo de crear el puntero que apunta el anterior
    					/// hay que reutilizar las fx que hicimos antes.

    if(this != NULL)
    cantidad = ll_len(this);

    if(cantidad != -1 && nodoAgregado != NULL && this != NULL && nodeIndex <= cantidad && nodeIndex >=0){
///    	nodoAnterior = getNode(this, nodeIndex-1);	mal.. porq si pide el nodo 0 me daria -1...

		if(cantidad == 0){///si el len es 0, agrega en el siguiente al pFirstNode. Y el agregado tiene que apuntar a null
			this->pFirstNode = nodoAgregado;
			nodoAgregado->pNextNode=NULL;
			nodoAgregado->pElement = pElement;
			returnAux = 0;
		}else{///si el len es != 0, agrega en el indice indicado, por lo que puedo agregar en:la posicion 0, la posicion final o donde pida el nodeIndex
			if(nodeIndex == 0){///agrego un nodo en el indice 0 si hay elementos
	///			nodoAgregado = this->pFirstNode;		MAL! ES AL REVEZ! PORQUE QUIERO QUE LL APUNTE AL NUEVO NODO UNICO
	//			nodoAnterior->pNextNode = pAuxNode;
				nodoAgregado->pNextNode = this->pFirstNode;
				this->pFirstNode = nodoAgregado;
				nodoAgregado->pElement = pElement;
				returnAux = 0;
			}else{
//				nodoUltimo = getNode(this, ll_len(this));
				nodoAnterior = getNode(this, nodeIndex-1);
				if(nodeIndex == cantidad && nodoAnterior != NULL){///agrego un nodo en la ultima posicion
					nodoAnterior->pNextNode = nodoAgregado;
					nodoAgregado->pNextNode = NULL;
					nodoAgregado->pElement = pElement;
					returnAux = 0;

				}else{///agrego un nodo en cualquier posicion
					nodoAgregado->pNextNode = nodoAnterior->pNextNode;
					nodoAnterior->pNextNode = nodoAgregado;
					nodoAgregado->pElement = pElement;
					returnAux = 0;
				}
			}
		}
		this->size = this->size+1;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    ///llama a addNode. llamamos al addnode y le decimos que agregue al final de la lista.
    int ultimoIndice;

    if(this != NULL){
		ultimoIndice = ll_len(this);
		if(ultimoIndice != -1)
		if(addNode(this, ultimoIndice, pElement) == 0)
		returnAux = 0;
    }

    return returnAux;
}

/// @brief Retorna un puntero al elemento que se encuentra en el índice especificado
/// @param this
/// @param index
/// @return void* Retorna NULL Si la verificación falla
/// 			 			   Si tiene éxito retorna el elemento.
void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    int lenLL;
    Node* nodoAux = NULL;

    if(this != NULL)
    lenLL = ll_len(this);
    												///el indice no puede ser igual a la cantidad porq si hay 370, el elemento 370 tiene el indice 369???
    if(index >=0 && index < lenLL){
    	nodoAux = getNode(this, index);
    	if(nodoAux != NULL){
			returnAux = nodoAux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    int lenLL;
	Node* nodoAux = NULL;

	if(this != NULL){
		lenLL = ll_len(this);
		if(index >=0 && index < lenLL){
			nodoAux = getNode(this, index);
			if(nodoAux != NULL){
				nodoAux->pElement = pElement;
				returnAux = 0;
			}
		}
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    int lenLL;
    Node* nodoAux = NULL;
    Node* nodoAnterior = NULL;

    if(this != NULL)
    lenLL = ll_len(this);

    if(lenLL != -1 && index >=0 && index < lenLL){
    	nodoAux = getNode(this, index);
    	if(nodoAux != NULL){
    		if(index == 0){///borro nodo en el indice 0 si hay elementos
    			this->pFirstNode = nodoAux->pNextNode;
    			free(nodoAux);
				returnAux = 0;
			}else{
				nodoAnterior = getNode(this, index-1);
				if(index == lenLL && nodoAnterior != NULL){///borro un nodo en la ultima posicion
					free(nodoAux);
					nodoAnterior->pNextNode = NULL;
					returnAux = 0;
				}else{///borro un nodo en cualquier posicion
					nodoAnterior->pNextNode  = nodoAux->pNextNode;
					free(nodoAux);
					returnAux = 0;
				}
			}
			this->size = this->size-1;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_clear(LinkedList* this){
    int returnAux = -1;
    int lenLL;
    int i;
    /*
    Node* nodoAux = NULL;

    if(this != NULL){
		lenLL = ll_len(this);
		if(lenLL != -1){
			for(i = lenLL; i > 0; i--){
				nodoAux = getNode(this, i);
				if(nodoAux != NULL){
					free(nodoAux);
					returnAux = 0;
				}
			}
		}
    }*////acabo de crear una funcion que borra un elemento de la lista!!! reusar!

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(lenLL != -1){
    		for(i = lenLL; i>=0; i--){
///tambien:    (i = 0; i< lenLL; i++)
    			if(ll_remove(this, i)==0){
    				returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente*/
int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
    	if(ll_clear(this)==0){
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente*/
int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int lenLL;
    int i;
///    Node* nodoAux = NULL;		la funcion habla de elementos (que son del tipoo void*, no nodos)
    void* elementoAux =NULL;

    if(this != NULL /**&& pElement != NULL*/){
    	lenLL = ll_len(this);
		for(i = 0; i<lenLL; i++){
///    			nodoAux = (Node*)ll_get(this, i);
//    			nodoAux = getNode(this, i);
			elementoAux = ll_get(this, i);
			if(/*elementoAux != NULL && */elementoAux == pElement){
				returnAux = i;
				break;
			}
		}

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia */
int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    int lenLL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(lenLL == 0){
    		returnAux = 1;
    	}else{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente*/
int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    int lenLL;
//    Node* nodoAux = NULL; YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)

    if(this != NULL){
		lenLL = ll_len(this);
		if(index >=0 && index<=lenLL){
			if(addNode(this, index, pElement)==0){
				returnAux = 0;
			}
		}
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente*/
void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    int lenLL;
    ///YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)
//    Node* nodoAux = NULL;
    ///ya tengo el returnAux!!!
//    void* elementoAux = NULL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(index >= 0 && index <= lenLL){
//    		nodoAux = getNode(this, index);
    		returnAux = ll_get(this, index);
    		if(returnAux != NULL){
//				returnAux = returnAux;
				if(ll_remove(this, index)==-1){
					returnAux = NULL;
				}
    		}
    	}
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento*/
int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;
    int lenLL;
    int i;
//    Node* nodoAuxiliar = NULL; YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)
    void* elementoAux;

    if(this != NULL){
    	lenLL = ll_len(this);
    	returnAux = 0;			///no abajo dentro del for porque: en uno de los test te pasan lista sin nada entonces nunca entra al for ese.
    	 	 	 	 	 	 	 ///Osea el for haria 0<0 no entra por eso necesitas el retorno 0 antes de ese for
    	for(i=0; i < lenLL; i++){
//    		nodoAuxiliar = getNode(this, i); YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)
    		elementoAux = ll_get(this, i);
    		if(elementoAux != NULL){
    			if(elementoAux == pElement){
					returnAux = 1;
					break;
				}/*else{
					returnAux = 0;
				}*/
    		}
    	}
    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    int lenLL;
    int lenLLDos;
    int i;
///    Node* nodoAuxiliar = NULL; YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)
    void* elementoAux;

    if(this != NULL && this2 != NULL){
    	lenLL = ll_len(this);
    	lenLLDos = ll_len(this2);
    	if(lenLL != lenLLDos){///si tienen diferente size ya puedo decir que alguna lista tiene un elemento mas q otra.
    		returnAux = 0;
    	}else{		///si tienen igual cantidad, puede pasar que igualmente no tenga el elemento y en su lugar tenga otro (misma cant, != elementos)
			returnAux = 1;
			for(i=0; i < lenLLDos; i++){
///				nodoAuxiliar = getNode(this2, i); YA TENGO LA FUNCION LL_GET. Y la funcion habla de elementos (que son del tipoo void*, no nodos)
				elementoAux = ll_get(this2, i);
				if(ll_contains(this, elementoAux)==0){
					returnAux = 0;
					break;///si encuentro un elemento que no contiene ya doy break, sino sigo buscando hasta retornar 1 al final del bucle
				}/*else{
					returnAux = 1;
				}*/
			}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* cloneArray = NULL;
    int lenLL;
    int i;
//    Node* nodoFrom;
///    Node* nodosIntermedios;
    void* elementosIntermedios;

    if(this != NULL){
    	lenLL = ll_len(this);
    	if(from >= 0 && to <= lenLL && from < to){
    		cloneArray = ll_newLinkedList();
//			nodoFrom = getNode(this, from);
//			if(addNode(cloneArray, from, nodoFrom->pElement)==0){
			///no es necesario agregar el nodoFrom aparte, el for tambien lo agrega
    		if(cloneArray != NULL){
				for(i = from; i<to;i++){
					/**		YA TENGO FUNCINOES QUE SON LL_GET Y LL_ADD, NO TENGO QUE SEGUIR USANDO ESTAS DE NODOS. y como duncionan con void*, no tengo que usar Nodo*
					nodosIntermedios = getNode(this, i);
					addNode(cloneArray, i, nodosIntermedios->pElement);*/
					elementosIntermedios = ll_get(this, i);
					ll_add(cloneArray, elementosIntermedios);
				}
///				nodoTo = getNode(this, to); 		no incluido el elemento to en la funcion
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    int i;
    int lenLL;
    void* elementoAux = NULL;

    if(this != NULL){
    	lenLL = ll_len(this);
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL && lenLL != -1){
    		for(i=0;i<lenLL;i++){
				elementoAux = ll_get(this, i);
				if(elementoAux != NULL){
					ll_add(cloneArray, elementoAux);
				}
			}
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux =-1;
    int lenLL;
    int i, j;
//    void* elementoUno;
//    void* elementoDos;
    Node* nodoUno;
    Node* nodoDos;
    void* elementoAux;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0)){
    	lenLL = ll_len(this);

		for(i = 0; i < lenLL-1; i++){
//			elementoUno = ll_get(this, i);
			nodoUno = getNode(this, i);
			for(j = i+1; j < lenLL; j++){
//				elementoDos = ll_get(this, j);
				nodoDos = getNode(this, j);
				if(order == 1){					///ORDEN AScENDENTE
					if(pFunc(nodoUno->pElement, nodoDos->pElement) > 0){
						elementoAux = nodoUno->pElement;
						nodoUno->pElement = nodoDos->pElement;
						nodoDos->pElement = elementoAux;
						returnAux = 0;
					}
				}else{
					if(order == 0){				///ORDEN DESCENDENTE
						if(pFunc(nodoUno->pElement, nodoDos->pElement) < 0){
							elementoAux = nodoUno->pElement;
							nodoUno->pElement = nodoDos->pElement;
							nodoDos->pElement = elementoAux;
							returnAux = 0;
						}
					}
				}
			}
		}
    }

    return returnAux;

}

/// @brief devolverá una nueva linkedlist que contenga alguno de los elementos de la lista original, según algún criterio
/// @param this
/// @param pFunc
/// @return
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element)){
	///se deberá iterar todos los elementos de la lista y pasárselos a la función “pFunc”.
	/// La función “pFunc” devolverá 1 si ese ítem se debe agregar a la lista resultado o 0 si no debe agregarse.
	/// la función “ll_filter” generará la nueva lista resultado, agregará a la misma los ítems correspondientes y la devolverá
	int lenThis;
	int i;
	void* elementoAux;
	LinkedList* listaFiltrada = NULL;

	if(this != NULL && pFunc != NULL){
		listaFiltrada = ll_newLinkedList();
		if(listaFiltrada != NULL){
			lenThis = ll_len(this);
			for(i = 0; i < lenThis; i++){
				elementoAux = ll_get(this, i);
				if(pFunc(elementoAux) == 1){
					ll_add(listaFiltrada, elementoAux);
				}
			}
		}
	}

	return listaFiltrada;
}

/// @brief
/// @param this
/// @param pFunc
/// @return
LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* element)){
	///se deberán iterar todos los elementos de la lista y pasárselos a la función “pFunc” que recibirá el elemento y le hara lo que tenga que hacer,
	/// el retorno de “pFunc” se agregará a la lista resultado
	/// Diferencia q hay es que filtro t filtra algo y mapp t agrega un valor a algo q puede ser filtrado o no
	int lenThis;
	int i;
	void* elementoAux;
	LinkedList* listaMapeada = NULL;

	if(this != NULL && *pFunc != NULL){
		lenThis = ll_len(this);
		listaMapeada = ll_newLinkedList();
		if(listaMapeada != NULL){
			for(i = 0; i< lenThis; i++){
				elementoAux = ll_get(this, i);
				if(elementoAux != NULL){
					elementoAux = pFunc(elementoAux);
					if(elementoAux != NULL)
					ll_add(listaMapeada, elementoAux);
				}
			}
		}
	}

	return listaMapeada;
}




