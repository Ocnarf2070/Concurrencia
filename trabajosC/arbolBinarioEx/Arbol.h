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
	//Este procedimiento construye un �rbol binario de b�squeda vacio.
	void InsertarEnABB (TArbol *arb, int elem);
	//Este procedimiento inserta elem en un �rbol binario de b�squeda. Despu�s de la inserci�n el �rbol
	//DEBE seguir siendo un �rbol binario de b�squeda.
	void RecorrerABB (TArbol arb);
	//Dado un �rbol binario de b�squeda, este procedimiento muestra en pantalla los elementos del �rbol
	//ordenados de menor a mayor. Para el dibujo de la figura la salida ser�a:
	//1,4,5,6,7,15,21,45,77,78,80,90,99
	void DestruirABB(TArbol *arb);
	//Este procedimiento libera la memoria de todos los nodos del �rbol.


#endif /* ARBOL_H_ */
