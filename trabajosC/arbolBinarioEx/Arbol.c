/*
 * Arbol.c
 *
 *  Created on: 14 abr. 2017
 *      Author: franc
 */

#include "Arbol.h"
#include <stdio.h>

void CrearABB (TArbol *arb){
	*arb=NULL;
}

void InsertarEnABB (TArbol *arb, int elem){
	TArbol aux = malloc(sizeof(struct T_Nodo));
	TArbol act=*arb,ant=NULL;
		aux->dato=elem;
		aux->der=NULL;
		aux->izq=NULL;
	if(act==NULL){
		*arb=aux;
	}else{
		while(act!=NULL){
			ant=act;
			if(act->dato>elem)act=act->izq;
			else act=act->der;
		}
		if(ant->dato>elem)ant->izq=aux;
		else ant->der=aux;

	}

}

void RecorrerABB (TArbol arb){
 if(arb!=NULL){
 		RecorrerABB(arb->izq);
 		printf("%d ",arb->dato);
 		RecorrerABB(arb->der);
 	}
}

void DestruirABB(TArbol *arb){
	TArbol raiz = *arb;
	if(*arb!=NULL){
			DestruirABB(&(raiz)->izq);
			DestruirABB(&(raiz)->der);
			free((raiz));
			*arb=NULL;
		}
}

