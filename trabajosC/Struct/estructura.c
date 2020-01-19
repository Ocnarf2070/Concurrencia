/*
 * estructura.c
 *
 *  Created on: 1 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
#include "complejos.h"
/*struct Persona{
	char nombre [25];
	char apellidos[50];
	int edad;
};*/
/*void leerComplejo(struct Complejo *c){
	printf("Introduce un numero complejo \n");
	fflush(stdout);
	scanf("%lf %lf",&(c->pr),&(c->pi)); //c->pe == (*c).pe
}
void imprimirComplejo(struct Complejo c){
	printf("Parte entera: %lf, Parte imaginaria: %lf \n",c.pr,c.pi);
}
void imprimirArrayComplejo(struct Complejo *c,int l){
	int i=0;
	for(i=0; i<l; i++)imprimirComplejo(c[i]);
}
int leerArrayComplejo(struct Complejo *c){
	int i=0;
	do{
		leerComplejo(&(c[i]));
		i++;
		if((c[i].pr)!='f' && (c[i].pi)!='f')return i;
	}while(i<10);
	return i;
}*/
int main (int argc, char const *argv[]){
/*	struct Complejo c;
	leerComplejo(&c);
	imprimirComplejo(c);
*/
	struct Complejo c[10];
	int l = leerArrayComplejo(&c);
	imprimirArrayComplejo(&c,l);
	return 0;
}
