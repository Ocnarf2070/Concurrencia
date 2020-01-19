/*
 * personas.h
 *
 *  Created on: 2 mar. 2017
 *      Author: mmar
 */

#ifndef PERSONAS_H_
#define PERSONAS_H_

struct Persona{
	char nombre[15];
	char apellido[15];
	int edad;
};
/**
 * lee el nombre, appellido y edad de una persona y la
 * almacena en *p.
 *  Devuelve 0 si la lectura es correcta.
 */
int leerPersona(struct Persona *p);

/**
 * escribe por la pantalla el nombre, apellido y edad
 * de la persona p
 *
 */
void imprimirComplejo(struct Persona p);


/**
 * imprime el array los personas que hay en las
 * componentes p[0] a p[l-1]
 */
void imprimirArComplejos(struct Persona *p,int l);


/**
 * lee del teclado a lo sumo max personas y las almacena
 * en el array p. Devuelve el número de personas que se ha
 * leído
 */
int leerArComplejos(struct Persona *p,int max);


#endif /* PERSONAS_H_ */
