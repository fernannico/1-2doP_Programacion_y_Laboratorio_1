/*
 ============================================================================
 Name        : modeloPokemon.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	int option;
	char seguir;
	int pokemonIndice;
	int pokemonId;
	int lenLL;
	int banderaOpcionUno = 0;
	int banderaOpcionSeis= 0;
	ePokemon* pokemonAModificar = NULL;
	int valorAtaqueNuevo;

    LinkedList* listaPokemones = ll_newLinkedList();
	LinkedList* pokemonesFuego = NULL;

	do {

		printf( "\n\n|=============================|"
				"\n|            MENU             |\n|=============================|"
				"\n| 1 | CARGA DE ARCHIVOS       |\n|-----------------------------|"
				"\n| 2 | MODIFICACION VAL ATAQUE |\n|-----------------------------|"
				"\n| 3 | LISTAR POKEMONES        |\n|-----------------------------|"
				"\n| 4 | FILTRAR TIPO FUEGO      |\n|-----------------------------|"
				"\n| 5 | FILTRAR XL VENENO       |\n|-----------------------------|"
				"\n| 6 | Mapear ataque cargado   |\n|-----------------------------|"
				"\n| 7 | Batalla pokemon:        |\n|-----------------------------|"
				"\n| 8 | SALIR                   |\n|=============================|");
		utn_getNumero(&option, "\nOpcion", "\nError", 1,8, 1);

		switch (option) {
			case 1:
				if(controller_cargarElementosDesdeTexto("Data_Pokemones.csv", listaPokemones)==1){
					printf("archivo cargado");
				}else{
					printf("archivo no cargado");
				}
				banderaOpcionUno = 1;
				break;
			case 2:
				///guardar la funcion modificar nombre y edad y algo generico de elejir el elemento
				if(banderaOpcionUno == 1){
					controller_listarElementos(listaPokemones);
					lenLL = ll_len(listaPokemones);
					if(utn_getNumero(&pokemonId, "\nElija el id del pokemon", "\nError", 1, lenLL, 1)==0){
						pokemonIndice = poke_BuscarIndicePokemonPorId(listaPokemones, pokemonId);
						if(pokemonIndice != -1){
							pokemonAModificar = (ePokemon*)ll_get(listaPokemones, pokemonIndice);
							if(pokemonAModificar != NULL){
								poke_printOnePokemon(pokemonAModificar);
								if(utn_getNumero(&valorAtaqueNuevo, "\nIngrese nuevo valor de ataque: ", "Error", 1, 1000, 1)==0){
									poke_setValorAtaque(pokemonAModificar, valorAtaqueNuevo);
									poke_printOnePokemon(pokemonAModificar);
								}
							}
						}else{
							printf("no existe");
						}
					}else{
						printf("opcion interrumpida");
					}
				}else{
					printf("no cargado");
				}
				break;
			case 3:
				if( banderaOpcionUno == 1 && controller_listarElementos(listaPokemones)==1){
					printf("cargado");
				}else{
					printf("no cargado");
				}
				break;
			case 4:
				if(banderaOpcionUno == 1){
					pokemonesFuego = ll_clone(listaPokemones);
					if(pokemonesFuego != NULL){
						pokemonesFuego = ll_filter(pokemonesFuego, poke_filtrarTipoFuego);
						controller_listarElementos(pokemonesFuego);
						if(controller_guardarPokemonesModoTexto("pokemonesTipoFuego.csv", pokemonesFuego)==1){
							printf("\nArchivo Generado");
						}else{
							printf("\nArchivo no Generado");
						}
					}
				}else{
					printf("no cargado");
				}
				break;
			case 5:
				if(banderaOpcionUno == 1 && controller_filtrarXlVeneno(listaPokemones)==1){
					printf("cargado");
				}else{
					printf("no cargado");
				}
				break;
			case 6:
				if(banderaOpcionUno == 1 && banderaOpcionSeis == 0){
					if(controller_mapearAtaqueCargado(listaPokemones)==1){
						printf("cargado");
					}else{
						printf("no cargado");
					}
					banderaOpcionSeis = 1;
				}else{
					printf("no cargado");
				}
				break;
			case 7:

				break;
			case 8:
				seguir = ValidarSeguirNoSeguir("\nEsta seguro que quiere salir? [S|N] ","\nError");
				break;
			default:
				break;
		}
	} while (seguir != 'S');

	return EXIT_SUCCESS;
}
