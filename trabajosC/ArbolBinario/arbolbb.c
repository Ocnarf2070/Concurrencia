/*
 * arbolbb.c
 *
 *  Created on: 16 mar. 2017
 *      Author: franc
 */
#include "arbolbb.h";
#include <stdio.h>
#include <stdlib.h>
// Crea la estructura utilizada para gestionar la memoria disponible.
void Crear(T_Arbol* arbol){
	*arbol=NULL;
}

// Destruye la estructura utilizada.
void Destruir(T_Arbol* arbol){
	if(*arbol!=NULL){
		Destruir((*arbol)->izq);
		Destruir((*arbol)->der);
		free((*arbol));
	}
}

// Inserta num en el arbol
void Insertar(T_Arbol* arbol,unsigned num){
	T_Arbol act=*arbol,ant=NULL;
	int repetido = 0;
	while(act!=NULL && !repetido){
		ant=act;
		if(act->dato>num)act=act->izq;
		else act=act->der;
	}

	if(!repetido){
		T_Arbol aux = malloc(sizeof(struct T_Nodo));
		aux->dato=num;
		aux->izq=NULL;
		aux->der=NULL;
		if(ant==NULL)*arbol=aux;
		else{
			if(act->dato>num)ant->izq=aux;
			else ant->der=aux;
		}
	}
}
// Muestra el contenido del árbol en InOrden
void Mostrar(T_Arbol arbol){
	if(arbol!=NULL){
		Mostrar(arbol->izq);
		printf("%d ",arbol->dato);
		Mostrar(arbol->der);
	}
}
// Guarda en disco el contenido del arbol
void Salvar(T_Arbol arbol, FILE* fichero){
	unsigned n;
	if(arbol!=NULL){
		Mostrar(arbol->izq);
		n=arbol->dato;
		fwrite(&n,sizeof(unsigned),1,fichero);
		Mostrar(arbol->der);
	}
}
