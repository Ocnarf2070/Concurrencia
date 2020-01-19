/*
 * Arbol.h
 *
 *  Created on: 14 abr. 2017
 *      Author: franc
 */

#ifndef ARBOL_H_
#define ARBOL_H_
#include <stdio.h>

typedef struct T_Nodo* TArbol;

	struct T_Nodo {
			unsigned dato;
			TArbol izq, der;
		};
	void CrearABB (TArbol *arb);
	//Este procedimiento construye un árbol binario de búsqueda vacio.
	void InsertarEnABB (TArbol *arb, int elem);
	//Este procedimiento inserta elem en un árbol binario de búsqueda. Después de la inserción el árbol
	//DEBE seguir siendo un árbol binario de búsqueda.
	void RecorrerABB (TArbol arb);
	//Dado un árbol binario de búsqueda, este procedimiento muestra en pantalla los elementos del árbol
	//ordenados de menor a mayor. Para el dibujo de la figura la salida sería:
	//1,4,5,6,7,15,21,45,77,78,80,90,99
	void DestruirABB(TArbol *arb);
	//Este procedimiento libera la memoria de todos los nodos del árbol.


#endif /* ARBOL_H_ */
