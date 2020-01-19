/*
 * ListaCircular.c
 *
 *  Created on: 20 mar. 2017
 *      Author: franc
 */
#include "ListaCircular.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//crea una lista circular vacía (sin ningún nodo)
void crear(TListaCircular *lc){
	*lc=NULL;
}

//inserta un nuevo nodo con el dato nombre al final de la lista circular
void insertar(TListaCircular *lc,char *nombre){
	TListaCircular aux = malloc(sizeof(struct TNodo));
	strcpy((aux->nombre),nombre);
	if(*lc!=NULL){
		aux->sig=(*lc)->sig;
		(*lc)->sig=aux;
	}else{
		aux->sig=aux;
	}
	*lc=aux;
}

//recorre la lista circular escribiendo los nombres de los nodos en la
//pantalla
void recorrer(TListaCircular lc){
	TListaCircular pt = lc->sig;
	printf("[");
	while(pt!=lc){
		printf("%s, ",pt->nombre);
		pt=pt->sig;
	}

	printf("%s]\n",lc->nombre);
}

//devuelve el número de nodos de la lista
int longitud(TListaCircular lc){
	int i=0;
	TListaCircular pt = lc->sig;
	while(pt!=lc){
		i++;
		pt=pt->sig;
	}

	return i+1;
}

//mueve el puntero exterto de la lista n nodos (siguiendo la dirección de la
//lista)
void mover(TListaCircular *lc,int n){
	while(n!=0){
		*lc=(*lc)->sig;
		n--;
	}
}

//elimina el primer nodo de la lista, y devuelve el nombre que contiene
//a través del parámetro nombre
void extraer(TListaCircular *lc,char *nombre){
	strcpy(nombre,((*lc)->sig)->nombre);
	TListaCircular aux=(*lc)->sig;
	(*lc)->sig=((*lc)->sig)->sig;
	free(aux);

}

