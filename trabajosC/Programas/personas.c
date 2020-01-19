/*
 * personas.c
 *
 *  Created on: 2 mar. 2017
 *      Author: mmar
 */
#include "personas.h" 
#include <stdio.h>

//implementación de las funciones de
//personas.h
int leerPersona(struct Persona *p){
	printf("introduce los datos de la persona");
	fflush(stdout);
	int per=scanf("%s %s %d",(p->nombre),(p->apellido),&(p->edad));
	return per;
}
void imprimirComplejo(struct Persona p){
	printf("Nombre: %s,Apellido: %s,Edad: %d",p.nombre,p.apellido,p.edad);
}
void imprimirArComplejos(struct Persona *p,int l){
	int i=0;
	for(int i=0;i<l;i++)imprimirComplejo(p[i]);
}
int leerArComplejos(struct Persona *p,int max){
	int i=0;
	while(i < max){
		leerPersona(&p[i]);
		i++;
	}
	return i;
}
