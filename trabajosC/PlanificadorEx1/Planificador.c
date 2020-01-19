/*
 * Planificador.c
 *
 *  Created on: 14 abr. 2017
 *      Author: franc
 */
#include <stdio.h>
#include "Planificador.h"

void crear(T_Planificador *planif){
	*planif=NULL;
}

void insertar_tarea(T_Planificador *planif,int pri,char *id){
	T_Planificador act=*planif, ant=NULL, aux=malloc(sizeof(struct T_Nodo));
	strcpy(aux->id,id);
	aux->pri=pri;
	if(act==NULL){
		aux->sig=NULL;
		*planif=aux;
	}
	else{
		while(act!=NULL&&act->pri>=pri){
			ant=act;
			act=act->sig;
		}
		if(ant==NULL){
			aux->sig=act;
			*planif=aux;
		}else if(act==NULL){
			ant->sig=aux;
			aux->sig=NULL;
		}else{
			ant->sig=aux;
			aux->sig=act;
		}
	}
}


void eliminar_tarea(T_Planificador *planif,char *id,unsigned *ok){
	T_Planificador act=*planif,ant=NULL;
	while(act!=NULL&&strcmp(id,act->id)!=0){
		ant=act;
		act=act->sig;
	}
	if(act==NULL){
		*ok=0;
	}else{
		*ok=1;
		if(ant==NULL)*planif=act->sig;
		else ant->sig=act->sig;
		free(act);
	}
}

void planificar(T_Planificador *planif){
	T_Planificador aux=*planif;
	*planif=aux->sig;
	free(aux);
}


void destruir(T_Planificador *manejador){
	T_Planificador act=*manejador,ant=NULL;
	while(act!=NULL){
		ant=act;
		act=act->sig;
		*manejador=act;
		free(ant);
	}
}


void mostrar (T_Planificador planificador){
	while(planificador!=NULL){
		if(planificador->sig!=NULL){
		printf("[%s|%d] -> ",planificador->id,planificador->pri);
		planificador=planificador->sig;
		}else{
			printf("[%s|%d]\n",planificador->id,planificador->pri);
			planificador=planificador->sig;

		}
	}
}


