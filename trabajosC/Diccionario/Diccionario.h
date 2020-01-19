/*
 * Diccionario.h
 *
 *  Created on: 15 abr. 2017
 *      Author: franc
 */

#ifndef DICCIONARIO_H_
#define DICCIONARIO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct NodoK * ListaK;

typedef struct NodoV * ListaV;

struct NodoV{
	char Palabra [20];
	ListaV sig;
};

struct NodoK{
	char Letra;
	ListaK sig;
	ListaV V;
};

void crear(ListaK *dic);
//Crea el diccionario
void insertar(char * pal,ListaK * dic);
//Inserta nuevas palabras en el diccionario de forma ordenada. No puede haber dos palabras repetidas
//Consejo: se puede guardar las palabras en mayusculas o minusculas. incluir #include <string.h>, la cual tiene las funciones:
//char *__cdecl strupr(char *_Str) y char *__cdecl strlwr(char *_Str)
//Posible modificacion: Conteo de palabras repetidas, insetar las palabras como viene al principio, poner el significado de cada palabra
void eliminar(char * pal,ListaK * dic,unsigned *ok);
//Elimina una palabra del diccionario.ok será un 1 si se ha eliminado, sino un 0;
void cambiar(char *palA,char *palN,ListaK *dic);
//Cambia una palabra por otra. Se debe tener en cuenta si empieza por otra letra
void destruir(ListaK *dic);
//Destruye el diccionario
int buscar(char *pal, ListaK dic);
//Busca una palabra en el diccionario. Si está devuelve un 1 (true), sino un 0 (false)
//modificacion: hacer que sea un void y que ponga en pantalla el significado de la palabra buscada
void mostrar(ListaK dic);
//Muestra el diccionario
/*Formato:
 * A: Alabarda, amor, Arbol
 * B: Bardo, Bendecir, Busqueda
 * Z: Zebra, Zepelin, Zulu
 */
//----------------------------------------//
//Ficheros normales
void CrearFichero(char *NFich);
//Crea un fichero nuevo con palabras introducidas por teclado
void leerFichero(char *NFich, ListaK *dic);
//Lee un fichero con palabras, las cuales seran incluidas en el diccionario
void guardarFichero(char *NFich, ListaK dic);
//Escribe en un fichero el diccionario que tenemos

//Ampliacion: hacerlo para ficheros binarios
#endif /* DICCIONARIO_H_ */
