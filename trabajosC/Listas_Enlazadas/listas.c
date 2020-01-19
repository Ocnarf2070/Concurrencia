/*
 * listas.c
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
#include "listas.h"

void crear(Lista *l){
	*l=NULL;
}
int listaVacia(Lista l){
	return l==NULL;
}
void insertarCabeza (Lista *l, int v){
	Lista aux=malloc(sizeof(struct Nodo));
	aux->valor=v;
	aux->sig=NULL;
	aux->sig = *l;
	*l=aux;
}
int eliminarCabeza (Lista *l, int *v){
	Lista aux;
	if(listaVacia(*l))return 0;
	else{
		aux=*l;
		*v=aux->valor;
		*l=(*l)->sig;
		free(aux);
		return 1;
	}
}
void mostrar(Lista l){
	Lista aux=l;
	while(aux!=NULL){
		printf("%d", aux->valor);
		aux=aux->sig;
		if(aux!=NULL)printf(" -> ");
	}
}
int buscar (Lista l,int v);


void insertarOrdenado(Lista *l,int v){
	Lista ant=NULL;
	Lista act=*l;
	Lista aux=malloc(sizeof(struct Nodo));
	while (act!=NULL && act->valor < v){
		ant=act;
		act=act->sig;
	}
	if(ant==NULL){
		aux->valor=v;
		aux->sig=*l;
		*l=aux;
	}else{
		aux->valor=v;
		aux->sig=act;
		ant->sig=aux;
	}

}
