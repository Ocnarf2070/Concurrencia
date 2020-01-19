/*
 * complejos.h
 *
 *  Created on: 2 mar. 2017
 *      Author: mmar
 */

#ifndef COMPLEJOS_H_
#define COMPLEJOS_H_

struct Complejo{
	double pr;
	double pi;
};
/**
 * lee las componentes real e imaginaria de un
 * número complejo. Devuelve 2 si se han podido leer
 * correctamente.
 */
int leerComplejo(struct Complejo *c);

/**
 * escribe por la pantalla la parte real e imaginaria
 * del número complejo c
 *
 */
void imprimirComplejo(struct Complejo c);


/**
 * imprime el array los complejos que hay en las
 * componentes c[0] a c[l-1]
 */
void imprimirArComplejos(struct Complejo *c,int l);


/**
 * lee del teclado a lo sumo max complejos y los almacena
 * en el array c. Devuelve el número de complejos que se ha
 * leído
 */
int leerArComplejos(struct Complejo *c,int max);
// lee del teclado a lo sumo max complejos y los
// almacena en el array c



#endif /* COMPLEJOS_H_ */
