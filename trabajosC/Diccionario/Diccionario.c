/*
 * Diccionario.c
 *
 *  Created on: 15 abr. 2017
 *      Author: franc
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Diccionario.h"

void crear(ListaK *dic){
	*dic=NULL;
}
void insertar(char * pal,ListaK * dic){
	ListaK auxK = malloc (sizeof (struct NodoK));
	ListaV auxV = malloc (sizeof (struct NodoV));
	ListaK act = *dic, ant = NULL;
	char mayus[20];
	strcpy (mayus, pal);
	strupr (mayus);
	char letra = mayus[0];
	strcpy (auxV->Palabra, mayus);
	auxK->V=NULL;
	auxK->Letra = letra;
	if(act==NULL){
		auxV->sig=NULL;
		auxK->V=auxV;
		auxK->sig=NULL;
		*dic=auxK;
	}else{
		if(esta(mayus,(*dic)))return;
		while(act!=NULL && act->Letra<letra){
			ant=act;
			act=act->sig;
		}
		if(act!=NULL && act->Letra==letra){
			auxK=act;
		}else{
			if(ant==NULL){
				auxK->sig=act;
				*dic=auxK;
			}else if(act==NULL){
				ant->sig=auxK;
				auxK->sig=NULL;
			}else{
				ant->sig=auxK;
				auxK->sig=act;
			}
		}
		ListaV antv=NULL,actv=auxK->V;
		while(actv!=NULL&&strcmp(mayus,actv->Palabra)>0){
			antv=actv;
			actv=actv->sig;
		}
		if(antv==NULL){
			auxV->sig=actv;
			auxK->V=auxV;
		}else if(actv==NULL){
			antv->sig=auxV;
			auxV->sig=NULL;
		}else{
			antv->sig=auxV;
			auxV->sig=actv;
		}
	}
}
void eliminar(char * pal,ListaK * dic,unsigned *ok){
	char mayus[20];
	strcpy(mayus,pal);
	strupr(mayus);
	unsigned esta=0;
	ListaK actk=*dic,antk=NULL;
	ListaV act,ant;
	while(actk!=NULL&&!esta){
		act=actk->V;
		ant=NULL;
		while(act!=NULL&&!esta){
			if(strcmp(mayus,act->Palabra)==0)esta=1;
			else{ ant=act;
			act=act->sig;
			}
		}if(!esta){
		antk=actk;
		actk=actk->sig;
		}
	}
	*ok=esta;
	if(esta){
		if(ant==NULL){
			printf("n\n");
			actk->V=act->sig;
			free(act);
		}else{
			printf("f\n");
			ant->sig=act->sig;
			free(act);
		}
		if(actk->V==NULL){
			if(antk==NULL){
				*dic=actk->sig;
				free(actk);
			}else{
				antk->sig=actk->sig;
				free(actk);
			}
		}
	}
}
void cambiar(char *palA,char *palN,ListaK *dic){
	unsigned ok;
	eliminar(palA,dic,&ok);
	if(ok)insertar(palN,dic);
	else printf("No se ha podido ambiar la palabra\n");
}
void destruir(ListaK *dic){
	ListaK actk=*dic,antk=NULL;
	ListaV act,ant;
	while(actk!=NULL){
		act=actk->V;
		ant=NULL;
		while(act!=NULL){
			ant=act;
			act=act->sig;
			actk->V=act;
			free(ant);
		}
		antk=actk;
		actk=actk->sig;
		*dic=actk;
		free(antk);
	}
}
int esta(char *pal, ListaK dic){
	return buscar(pal,dic);
}
int buscar(char *pal, ListaK dic){
	while(dic!=NULL){
		ListaV V=dic->V;
		while(V!=NULL){
			if(strcmp(pal,V->Palabra)==0)return 1;
			V=V->sig;
		}
		dic=dic->sig;

	}
	return 0;
}
void mostrar(ListaK dic){
	while(dic!=NULL){
		printf("%c: ",dic->Letra);
		ListaV aux=dic->V;
		while(aux!=NULL){
			if(aux->sig!=NULL){
				printf("%s, ",aux->Palabra);
				aux=aux->sig;
			}else{
				printf("%s",aux->Palabra);
				aux=aux->sig;
			}
		}
		printf("\n");
		dic=dic->sig;
	}
}
//----------------------------------------//
void CrearFichero(char *NFich){
	FILE *pf=fopen(NFich,"w");
	if(pf==NULL)perror("No se ha podido crear el fichero");
	else{
		printf("Introducezca el texto:\n");
		char pal[20];
		while(scanf("%s",pal)==1&&strcmp(pal,"0")!=0){
			inspeccionar(pal);
			fprintf(pf,"%s ",pal);
		}
		fclose(pf);
	}
}
void leerFichero(char *NFich, ListaK *dic){
	char pal[20];
	FILE *pf=fopen(NFich,"r");
	if(pf==NULL)perror("No se ha podido leer el fichero");
	else{
		while(fscanf(pf,"%s",pal)==1){
			insertar(pal,dic);
		}
		fclose(pf);
	}
}
void guardarFichero(char *NFich, ListaK dic){
	FILE *pf=fopen(NFich,"w");
	if(pf==NULL)perror("No se ha podido guardar en el fichero");
	else{
		while(dic!=NULL){
			fprintf(pf,"%c: ",dic->Letra);
			ListaV aux=dic->V;
			while(aux!=NULL){
				if(aux->sig!=NULL){
					fprintf(pf,"%s, ",aux->Palabra);
					aux=aux->sig;
				}else{
					fprintf(pf,"%s",aux->Palabra);
					aux=aux->sig;
				}
			}
			fprintf(pf,"\n");
			dic=dic->sig;
		}
	}
	fclose(pf);
}

void inspeccionar(char * pal){
	int n=0;
	while(n<strlen(pal)){
		if((pal[n]=='¿'&&pal[n]=='¡')||(pal[n]>='!'&&pal[n]<='/')
				||(pal[n]>=':'&&pal[n]<='@')||(pal[n]>='['&&pal[n]<='`')
				||(pal[n]>='{'&&pal[n]<='~')||pal[n]=='“'||pal[n]=='”'
						||pal[n]=='('||pal[n]==')'){
			int i=n;

			while(i<strlen(pal)){
				pal[i]=pal[i+1];
				i++;
			}

		}
		switch(pal[n]){
		}
		n++;
	}
}

