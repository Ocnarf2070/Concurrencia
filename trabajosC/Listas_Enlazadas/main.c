/*
 * main.c
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */
#include "listas.h";
#include <stdio.h>;
int main(){
	Lista list;
	crear(&list);
	mostrar(list);
	printf("\n");
	insertarCabeza(&list,4);
	mostrar(list);
	printf("\n");
	insertarCabeza(&list,2);
	mostrar(list);
	printf("\n");
	eliminarCabeza(&list,&(list->valor));
	mostrar(list);
	printf("\n");
	insertarOrdenado(&list,5);
	mostrar(list);
	printf("\n");
	insertarOrdenado(&list,3);
	mostrar(list);
	printf("\n");
}

