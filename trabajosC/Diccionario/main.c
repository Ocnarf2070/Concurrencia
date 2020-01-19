/*
 * main.c
 *
 *  Created on: 15 abr. 2017
 *      Author: franc
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "Diccionario.h"

int main(){
	setvbuf(stdout, NULL, _IONBF,0);
	setvbuf(stderr, NULL, _IONBF,0);

	 /* char str[50] = "Modify This String To Upper";
	  char  strt[50];
	  strcpy(strt,str);
	  strupr(str);
	    printf("%s\n",strt);
	    printf("%s\n",str);
	    return  0;
*/
	/*ListaK dic;
	crear(&dic);
	unsigned ok;
	insertar("arbol",&dic);
	insertar("ArBol",&dic);
	insertar("Ambidiestro",&dic);
	insertar("Azafran",&dic);
	insertar("ayala",&dic);
	insertar("baron",&dic);
	insertar("Varon",&dic);
	insertar("Gol",&dic);
	mostrar(dic);
	eliminar("azafran",&dic,&ok);
	if(ok)printf("Eliminacion correcta\n");
	else printf("No se ha podido eliminar\n");
	mostrar(dic);
	cambiar("arbol","barco",&dic);
	mostrar(dic);
	destruir(&dic);
	mostrar(dic);*/
	ListaK dic2;
	crear(&dic2);
	CrearFichero("ejemplo.txt");
	system("PAUSE");
	leerFichero("ejemplo.txt",&dic2);
	guardarFichero("Dic.txt",dic2);
	return 0;
	/*char pal[20];
	while(scanf("%s",pal)==1&&strcmp(pal,"0")!=0){
		inspeccionar(pal);
		insertar(pal,&dic2);
		printf("%s, ",pal);
	}
	mostrar(dic2);*/
	return 0;
}
