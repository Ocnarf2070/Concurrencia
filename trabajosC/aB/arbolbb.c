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
	/*if(*arbol!=NULL){
		Destruir((*arbol)->izq);
		Destruir((*arbol)->der);
		free((*arbol));
	}*/
	T_Arbol raiz = *arbol;
	if(*arbol!=NULL){
		Destruir(&(raiz)->izq);
		Destruir(&(raiz)->der);
		free(raiz);
		*arbol=NULL;
	}
}

// Inserta num en el arbol
void Insertar(T_Arbol* arbol,unsigned num){
	T_Arbol act =*arbol,ant=NULL;
	int repetido = 0;	//repetido =false
	T_Arbol aux;
	while(act!=NULL && !repetido){	//repetido == 0
		ant=act;
		if(act->dato == num)repetido =1;	//repetido = true
		else{
			if(act->dato>num)act=act->izq;
			else act =act->der;
		}

	}
	if(!repetido){
		aux = malloc(sizeof(struct T_Nodo));
		aux->dato =num;
		aux->izq = NULL;
		aux->der = NULL;
		if(ant==NULL)*arbol = aux;//es el primer nodo del arbol
		else{
			if(ant->dato>num)ant->izq =aux;
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
		Salvar(arbol->izq,fichero);
		n=arbol->dato;
		fwrite(&n,sizeof(unsigned),1,fichero);
		Salvar(arbol->der,fichero);
	}
}
