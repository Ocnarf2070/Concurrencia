/*
 * ListaPersonas.h
 *
 *  Created on: 15 mar. 2017
 *      Author: mmar
 */

#ifndef LISTAPERSONAS_H_
#define LISTAPERSONAS_H_
struct Persona{
	char nombre[10];
	char apellido[10];
	int edad;
};

typedef struct Nodo * ListaPersona;
struct Nodo{
	struct Persona pers;
	ListaPersona sig;
};

void crear(ListaPersona *l);
void crearDeFichero(const char * nombre, ListaPersona *l);

void mostrar(ListaPersona l);
void eliminar(ListaPersona *l);

void insertarPrimero(ListaPersona *l,struct Persona pers);
void insertarUltimo(ListaPersona *l,struct Persona pers);
void insertarOrdenado(ListaPersona *l,struct Persona pers);


#endif /* LISTAPERSONAS_H_ */
