/*
 * Cola.h
 *
 *  Created on: 23 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
#ifndef COLA_H_
#define COLA_H_

typedef struct Nodo * Puntero;

struct Nodo{
	unsigned v[2];
	Puntero sig;
};
struct NodoCola{
	Puntero primero;
	Puntero ultimo;
	int tam;
};
typedef struct NodoCola Cola;

Cola crear();
//void crear(Cola* cola);
void insertar(Cola *cola, unsigned *v);
void extraer(Cola *cola, unsigned *v);
int esVacia(Cola cola);
void recorrer(Cola cola);


#endif /* COLA_H_ */
