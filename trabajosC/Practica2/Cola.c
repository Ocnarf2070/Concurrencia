/*
 * Cola.c
 *
 *  Created on: 23 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
#include "Cola.h"
Cola crear(){
	Cola* aux=malloc(sizeof(struct NodoCola));
	aux->primero=NULL;
	aux->ultimo=NULL;
	aux->tam=0;
	return *aux;
}
/*void crear(Cola* cola){
 * cola->primero=NULL;
 * cola->ultimo=NULL;
 * cola->tam=0
	}*/
void insertar(Cola *cola, unsigned *v){
	Puntero aux=malloc(sizeof(struct Nodo));
	aux->v[0]=v[0];
	aux->v[1]=v[1];
	aux->sig=NULL;
	if(esVacia(*cola)){
		cola->ultimo=aux;
	}
	else cola->ultimo->sig=aux;
	cola->ultimo=aux;
	cola->tam++;

}
void extraer(Cola *cola, unsigned *v){
	Puntero aux = cola->primero;
	v[0] = aux->v[0];
	v[1] = aux->v[1];
	cola->primero = aux->sig;
	free(aux);
}
int esVacia(Cola cola){
	return cola.tam==0;
	}
void recorrer(Cola cola){
	Puntero aux = cola.primero;
	printf("[ ");
	while(aux!=NULL){
		printf("(%u, %u) ",aux->v[0],aux->v[1]);
		aux = aux->sig;
	}
	printf(" ]\n");
}

