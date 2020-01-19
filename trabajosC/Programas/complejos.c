/*
 * complejos.c
 *
 *  Created on: 2 mar. 2017
 *      Author: mmar
 */
#include "complejos.h"
#include <stdio.h>

/**
 * lee las componentes real e imaginaria de un
 * número complejo. Devuelve 2 si se han podido leer
 * correctamente.
 */
int leerComplejo(struct Complejo *c){
	printf("Introduce un numero complejo\n");
	int v= scanf("%lf %lf", &(c->pr),&(c->pi));
	return v;
	// c->pe == (*c).pe

}

/**
 * escribe por la pantalla la parte real e imaginaria
 * del número complejo c
 *
 */
void imprimirComplejo(struct Complejo c){
	printf("Parte real: %lf, Parte imag: %lf\n",	c.pr,c.pi);
}

/**
 * lee del teclado a lo sumo max complejos y los almacena
 * en el array c. Devuelve el número de complejos que se ha
 * leído
 */
int leerArComplejos(struct Complejo *c,int max){
	//por implementar. Utilizar cualquier letra (p. e.,'F') para
	//controlar el final de la entrada. Usar
	//la función leerComplejo ya implementada

}
/**
 * imprime el array los complejos que hay en las
 * componentes c[0] a c[l-1]
 */
void imprimirArComplejos(struct Complejo *c,int l){
	int i = 0;
	for (i=0; i<l; i++)
		imprimirComplejo(c[i]);
}



