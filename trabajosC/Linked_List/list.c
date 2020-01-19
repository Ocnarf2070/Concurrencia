/*
 * list.c

 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */
#include "list.h";
#include <stdio.h>;
Linked_List create(){
	return NULL;
}// Crea una lista enlazada vac�a
void destroy(Linked_List * ptrL){
	free(ptrL);
} // Libera la memoria de una lista
int is_empty(Linked_List l){
 return l==NULL;
} // Devuelve verdadero si la lista est� vac�a
int contains(Linked_List l, int v){
	while(l!=NULL){
		if(l->value==v) return 1;
		l=l->next;
	}
	return 0;
} // Devuelve verdadero si la lista contiene el elemento v
int length(Linked_List l){
	int i=0;
	while(l->next!=NULL){
		i++;
	}
	return i;
} // Devuelve el n�mero de elementos de la lista
int insert(Linked_List * ptrL, int pos, int v){
	Linked_List aux=malloc(sizeof(Node));
	Linked_List pre=NULL;
	Linked_List post=*ptrL;
	int i=0;
	while(post!=NULL&&i<=pos){
		i++;
		pre=post;
		post=post->next;
	}
	if(post==NULL){
			aux->value=v;
			aux->next=*ptrL;
			*ptrL=aux;
	}else{
	aux->value=v;
	aux->next=post;
	pre->next=aux;
	}
	return 1;
} // Inserta v en la posici�n pos de la lista (*prtL). Si ok, devuelve verdadero; si pos no est� entre 1 y length +1, entonces devuelve falso
int remover(Linked_List * ptrL, int pos){
 return 0;
} // Borra el elemento pos de la lista, devolviendo verdadero o falso seg�n la operaci�n se pueda realizar.
int getElement(Linked_List l, int pos){

} // Devuelve el elemento de la posici�n pos. Si esa posici�n no existe, el comportamiento de la funci�n no est� definido.


void mostrar(Linked_List l){
	Linked_List aux=l;
		while(aux!=NULL){
			printf("%d", aux->value);
			aux=aux->next;
			if(aux!=NULL)printf(" -> ");
		}
}
