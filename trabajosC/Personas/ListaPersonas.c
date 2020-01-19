/*
 * ListaPersonas.c
 *
 *  Created on: 22 mar. 2017
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListaPersonas.h"

void crear(ListaPersona *l){
	*l=NULL;
}
void crearDeFichero(const char * nombre, ListaPersona *l){
	struct Persona pers;
	FILE *pf=fopen(nombre,"r");
	if(pf==NULL)perror("No se puede abrir");
	else{
		while((fscanf(pf,"%s %s %d",pers.nombre,pers.apellido,&pers.edad))==3){
			insertarPrimero(l,pers);
		}
		fclose(pf);
	}
}

void mostrar(ListaPersona l){
	while(l!=NULL){
		printf("Nombre: %s, Apellido: %s, Edad: %d\n",l->pers.nombre,l->pers.apellido,l->pers.edad);
		l=l->sig;
	}
}
void eliminar(ListaPersona *l){
	ListaPersona aux=*l;
	while(*l!=NULL){
		aux=*l;
		*l=aux->sig;
		free(aux);
	}
}

void insertarPrimero(ListaPersona *l,struct Persona pers){
	ListaPersona aux=malloc(sizeof(struct Nodo));
	aux->pers=pers;
	aux->sig=*l;
	*l=aux;

}
void insertarUltimo(ListaPersona *l,struct Persona pers){
	ListaPersona aux=malloc(sizeof(struct Nodo));
	ListaPersona ant = NULL,act=*l;
	aux->pers=pers;
	aux->sig=NULL;
	while(act!=NULL){
			ant=act;
			act=act->sig;
	}
	if(ant==NULL)*l=aux;
	else ant->sig=aux;
}
void insertarOrdenado(ListaPersona *l,struct Persona pers);


