/*
 * listas.h
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */

#ifndef LISTAS_H_
#define LISTAS_H_
typedef struct Nodo *Lista;
struct Nodo{
	int valor;
	Lista sig;
};
void crear(Lista *l);
int listaVacia(Lista l);
void insertarCabeza (Lista *l, int v);
int eliminarCabeza (Lista *l, int *v);
void mostrar(Lista l);
int buscar (Lista l,int v);
void insertarOrdenado(Lista *l,int v);

#endif /* LISTAS_H_ */
