/*
 * list.h
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */

#ifndef LIST_H_
#define LIST_H_

struct _node;
typedef struct _node * Linked_List;
typedef struct _node{
	int value;
	Linked_List next;
} Node;

Linked_List create(); // Crea una lista enlazada vacía
void destroy(Linked_List * ptrL); // Libera la memoria de una lista
int is_empty(Linked_List l); // Devuelve verdadero si la lista está vacía
int contains(Linked_List l, int v); // Devuelve verdadero si la lista contiene el elemento v
int length(Linked_List l); // Devuelve el número de elementos de la lista
int insert(Linked_List * ptrL, int pos, int v); // Inserta v en la posición pos de la lista (*prtL). Si ok, devuelve verdadero; si pos no está entre 1 y length +1, entonces devuelve falso
int remover(Linked_List * ptrL, int pos); // Borra el elemento pos de la lista, devolviendo verdadero o falso según la operación se pueda realizar.
int getElement(Linked_List l, int pos); // Devuelve el elemento de la posición pos. Si esa posición no existe, el comportamiento de la función no está definido.

void mostrar(Linked_List l);
#endif /* LIST_H_ */
