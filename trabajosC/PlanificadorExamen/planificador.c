/*
 * planificador.c
 *
 *  Created on: 19 abr. 2017
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include "planificador.h"

void crear(T_Planificador *planif){
	*planif=NULL;
}

void insertar_tarea(T_Planificador *planif,int pri,char *id){
	T_Planificador aux=malloc(sizeof(struct TNodo)),
			act=*planif,ant=NULL;
	strcpy(aux->id,id);
	aux->pri=pri;
	aux->sig=NULL;
	if(act==NULL)*planif=aux;
	else{
		while(act!=NULL&&pri<=act->pri){
			ant=act;
			act=act->sig;
		}
		if(ant==NULL){
			aux->sig=act;
			*planif=aux;
		}else if(act==NULL){
			ant->sig=aux;
		}else{
			aux->sig=act;
			ant->sig=aux;
		}
	}
}

void eliminar_tarea(T_Planificador *planif,char *id,unsigned *ok){
	T_Planificador act=*planif, ant=NULL;
	*ok=0;
	while(act!=NULL && strcmp(id,act->id)!=0){
		ant=act;
		act=act->sig;
	}
	if(act!=NULL){
		if(strcmp(id,act->id)==0){
			*ok=1;
			if(ant==NULL)*planif=act->sig;
			else ant->sig=act->sig;
			free(act);
		}
	}
}

void planificar(T_Planificador *planif){
	T_Planificador aux=*planif;
	*planif=aux->sig;
	free(aux);
}

void destruir(T_Planificador *manejador){
	T_Planificador aux=*manejador;
	while(aux!=NULL){
		*manejador=aux->sig;
		free(aux);
	}
}

void mostrar (T_Planificador planificador){
	while(planificador!=NULL){
		if(planificador->sig!=NULL) printf("[%d|%s]->",planificador->pri,planificador->id);
		else printf("[%d|%s]\n",planificador->pri,planificador->id);
		planificador=planificador->sig;
	}
}

void GuardarEnfichero (T_Planificador planificador, char *nombf){
	FILE *pf=fopen(nombf,"w");
	if(pf==NULL)perror("No se ha podido abrir el fichero");
	else{
		while(planificador!=NULL){
				if(planificador->sig!=NULL) fprintf(pf,"[%d|%s]->",planificador->pri,planificador->id);
				else fprintf(pf,"[%d|%s]\n",planificador->pri,planificador->id);
				planificador=planificador->sig;
			}
		fclose(pf);
	}
}

