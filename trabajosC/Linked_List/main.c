/*
 * main.c
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
#include "list.h";
int main(){
	Linked_List list;
	list=create();
	mostrar(list);
	insert(&list,0,5);
	mostrar(list);
	printf("\n%d",contains(list,5));
	insert(&list,5,4);
	mostrar(list);
	/*insert(&list,5,6);
	mostrar(list);*/
}

