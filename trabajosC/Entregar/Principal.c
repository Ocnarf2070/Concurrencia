/*
 * HolaMundo.c
 *
 *  Created on: 1 mar. 2017
 *      Author: mmar
 */

#include <string.h>
#include "personas.h"

void intercambiar(int *a,int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

int division(int a, int b, int *coc, int *resto){
	//modificar cabecera
	if (b==0) return -1;
	*coc = a/b;
	*resto = a % b;
	return 0;
}

void concatenar(char *c,char *d){
	//strcat
	int lc = strlen(c);
	int ld = strlen(d);
	int i = 0;
	for (i=0;i<=ld; i++)
		c[lc+i] = d[i];

}

void concatenar2(char *c,char *d){
	//strcat
	int lc = strlen(c);
	int ld = strlen(d);
	int i = 0;
	for (i=0;i<=ld; i++)
		*(c+lc+i) = *(d+i);

}
void concatenar3(char *cc,char *dc){
	//strcat
	while (*cc!='\0') cc++;
	while (*dc!='\0'){
		*cc = *dc;
		cc++;dc++;
	}
	*cc = '\0';

}



int main(){
   struct Persona c[10];
  // leerComplejo(&c);
  // imprimirComplejo(c);
   int l=leerArComplejos(c,10);
   imprimirArComplejos(c,l);

}
