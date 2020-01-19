/*
 * main.c
 *
 *  Created on: 14 abr. 2017
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include "planificador.h"

void leerFichero(char* NFichero, T_Planificador* plan){
	char id [81];
	unsigned pri;
	FILE *pf=fopen(NFichero,"r");
	if(pf==NULL)perror("No se ha podido abrir");
	else{
		while(fscanf(pf,"%s %d",id,&pri)==2){
			insertar_tarea(plan,pri,id);
		}
	}
	fclose(pf);
}
void guardarFichero(char* NFich, T_Planificador plan){
	FILE *pf=fopen(NFich,"a");
	if(pf==NULL)perror("No se ha podido abrir");
	else{
		while(plan!=NULL){
			if(plan->sig!=NULL){
				fprintf(pf,"[%s|%d]->",plan->id,plan->pri);
				plan=plan->sig;
			}else{
				fprintf(pf,"[%s|%d]\n",plan->id,plan->pri);
				plan=plan->sig;
			}
		}
	}

	fclose(pf);
}

int main2(T_Planificador* plan){
	leerFichero("planificacion.txt",plan);
	return 0;
}

int main () {
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF,0);


	T_Planificador planif;
	unsigned ok;


	crear(&planif);
	mostrar(planif);

	main2(&planif);
	mostrar(planif);
	guardarFichero("planificacioncorrecta.txt",planif);

	/*insertar_tarea(&planif,4,"t8");
	mostrar(planif);

	insertar_tarea(&planif,8,"t1");
	mostrar(planif);

	insertar_tarea(&planif,1,"t3");
	mostrar(planif);

	insertar_tarea(&planif,8,"t2");
	mostrar(planif);

	insertar_tarea(&planif,3,"t7");
	mostrar(planif);*/

	eliminar_tarea(&planif,"t1",&ok);
	if (ok) {
		printf("Borrado realizado correctamente\n");
	}
	else {
		printf("Borrado no se ha podido realizar\n");

	}
	guardarFichero("planificacioncorrecta.txt",planif);
	mostrar(planif);

	eliminar_tarea(&planif,"t9",&ok);
	if (ok) {
		printf("Borrado realizado correctamente\n");
	}
	else {
		printf("Borrado no se ha podido realizar\n");

	}
	mostrar(planif);

	eliminar_tarea(&planif,"t3",&ok);
	if (ok) {
		printf("Borrado realizado correctamente\n");
	}
	else {
		printf("Borrado no se ha podido realizar\n");

	}
	mostrar(planif);

	insertar_tarea(&planif,9,"t10");
	mostrar(planif);
	guardarFichero("planificacioncorrecta.txt",planif);

	planificar(&planif);
	mostrar(planif);

	planificar(&planif);
	planificar(&planif);
	mostrar(planif);
	guardarFichero("planificacioncorrecta.txt",planif);

	planificar(&planif);
	mostrar(planif);

	destruir(&planif);

	mostrar(planif);
	guardarFichero("planificacioncorrecta.txt",planif);

	printf("Fin Programa\n");

	system("PAUSE");

	return 0;
}
