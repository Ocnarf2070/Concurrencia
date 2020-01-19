/*
 * gestion_memoria.c
 *
 *  Created on: 10 mar. 2017
 *      Author: franc
 */
#include "gestion_memoria.h"
#include <stdio.h>
#include<stdlib.h>
const unsigned MAX=1000;
/* Crea la estructura utilizada para gestionar la memoria disponible. Inicialmente, sólo un nodo desde 0 a MAX */
	void crear(T_Manejador* manejador){
		T_Manejador aux = malloc(sizeof(struct T_Nodo));
		aux->inicio=0;
		aux->fin=MAX-1;
		aux->sig=NULL;
		*manejador=aux;
	}

/* Destruye la estructura utilizada (libera todos los nodos de la lista. El parámetro manejador debe terminar apuntando a NULL */
	void destruir(T_Manejador* manejador){
		T_Manejador aux=*manejador;
		T_Manejador act;
		while(aux!=NULL){
			act=aux;
			aux=aux->sig;
			free(act);
		}
		*manejador=NULL;
	}/*
	*while(*manejador!=NULL){
	*	act=*manejador;
	*	*manejador=(*manejador)->sig;
	*	free(act);
	*/

/* Devuelve en “dir” la dirección de memoria “simulada” (unsigned) donde comienza el trozo de memoria continua de tamaño “tam” solicitada.
Si la operación se pudo llevar a cabo, es decir, existe un trozo con capacidad suficiente, devolvera TRUE (1) en “ok”; FALSE (0) en otro caso.
 */
	void obtener(T_Manejador *manejador, unsigned tam, unsigned* dir, unsigned* ok){
		T_Manejador act = *manejador;
		T_Manejador ant=NULL;
		while(act!=NULL && (act->fin-act->inicio+1)<tam){
			ant=act;
			act=act->sig;

		}
		*ok = act!=NULL;
		if(*ok){
			*dir=act->inicio;
			act->inicio=act->inicio+tam;
			if(act->inicio>act->fin){
				if(ant==NULL){
					*manejador = act->sig;
				}else{
					ant->sig=act->sig;
				}
				free(act);
			}
		}
	}

/* Muestra el estado actual de la memoria, bloques de memoria libre */
	void mostrar (T_Manejador manejador){
		while(manejador!=NULL){
			printf("[%d %d] ",manejador->inicio,manejador->fin);
			manejador=manejador->sig;
		}
		printf("\n");
	}

/* Devuelve el trozo de memoria continua de tamaño “tam” y que
 * comienza en “dir”.
 * Se puede suponer que se trata de un trozo obtenido previamente.
 */
	void devolver(T_Manejador *manejador,unsigned tam,unsigned dir){
		T_Manejador act = *manejador;
		T_Manejador ant=NULL;
		T_Manejador aux=malloc(sizeof(struct T_Nodo));
		aux->inicio=dir;
		aux->fin = tam-1;
		aux->sig=NULL;

		while(act!=NULL && act->inicio < dir){
			ant = act;
			act=act->sig;
		}
		aux->sig=act;
		if(ant == NULL){
			*manejador=aux;
		}else{
			aux->sig=aux;
		}
		compactar(&manejador);
	}
	void compactar(T_Manejador *m){
		T_Manejador ant=*m;
		T_Manejador act = (*m)->sig;
		if(*m!=NULL){
			while(ant->sig!=NULL){
				if(act->inicio == ant->fin+1){
					ant->fin=act->fin;
					ant->sig=act->sig;
					free (act);
					ant = ant->sig;
				}else{
					ant = ant->sig;
					act = act->sig;
				}
			}
		}

	}
	void obtenerOptimizado(T_Manejador *manejador,unsigned tam, unsigned *dir, unsigned *ok){
		T_Manejador act = *manejador;
		T_Manejador ant=NULL;
		T_Manejador actmin=act,antmin=ant;
		actmin->fin=MAX-1;
		while(act!=NULL){
			int aux=act->fin-act->inicio+1;
			int min=actmin->fin-actmin->inicio+1;
			printf("tam: %d, aux: %d, min: %d, af: %d, ai: %d, mif: %d, mia: %d \n",tam, aux,min,act->fin,act->inicio,actmin->fin,actmin->inicio);
			fflush(stdout);
			if(aux<tam){
				if(min>aux){
				actmin=act;
				antmin=ant;
			}
			}
			ant=act;
			act=act->sig;
		}

		*ok = actmin!=NULL;
		if(*ok){
			*dir=actmin->inicio;
			actmin->inicio=actmin->inicio+tam;
			if(actmin->inicio>actmin->fin){
				if(antmin==NULL){
					*manejador = actmin->sig;
				}else{
					antmin->sig=actmin->sig;
				}
				free(actmin);
			}
		}
	}
