/*
 ============================================================================
 Name        : Practica2B.c
 Author      : esc
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbolbb.h"

/**
 * Pide un número "tam" al usuario, y
 * crea un fichero binario para escritura con el nombre "nfichero"
 * en que escribe "tam" numeros (unsigned int) aleatorios
 * Se utiliza srand(time(NULL)) para establecer la semilla (de la libreria time.h)
 * y rand()%100 para crear un número aleatorio entre 0 y 99.
 */
void creafichero(char* nfichero)
{
	int tam=0;
	printf("Introduce el tamaño del fichero\n");
	fflush(stdout);
	scanf("%d",tam);
	FILE *pf = fopen(nfichero,"wb");
	if(pf!=NULL)perror("no se ha podido abrir");
	else {
		srand(time(NULL));
		int n,i;
		for(i=0;i<tam;i++){
			int k=rand;
			n=k%100;
			fwrite(&n,sizeof(unsigned),1,pf);

		}
		fclose(pf);
	}

}
/**
 * Muestra por pantalla la lista de números (unsigned int) almacenada
 * en el fichero binario "nfichero"
 */
void muestrafichero(char* nfichero)
{
	FILE *pf = fopen(nfichero,"rb");
	if(pf!=NULL)perror("no se ha podido abrir");
	else {
		unsigned n;
		printf("[");
		while(fread(&n,sizeof(unsigned),1,pf)==1){
			printf("%d ",n);
		}
		printf("]\n");
		fclose(pf);
	}
}

/**
 * Guarda en el arbol "*miarbol" los números almacenados en el fichero binario "nfichero"
 */

void cargaFichero(char* nfichero, T_Arbol* miarbol)
{
	unsigned n;
	FILE *pf=fopen(nfichero,"rb");
	if(pf!=NULL)perror("no se ha podido abrir");
	else {
		while(fread(&n,sizeof(unsigned),1,pf)==1){
			Insertar(miarbol,n);
		}

		fclose(pf);
	}
}

int main(void) {
	/*char nfichero[50];
	printf ("Introduce el nombre del fichero binario:\n");
	fflush(stdout);
	scanf ("%s",nfichero);
	fflush(stdin);
	creafichero(nfichero);
	printf("\n Ahora lo leemos y mostramos\n");
	muestrafichero(nfichero);
	fflush(stdout);

	printf ("\n Ahora lo cargamos en el arbol\n");
	T_Arbol miarbol;
	Crear (&miarbol);
	cargaFichero(nfichero,&miarbol);
	printf ("\n Y lo mostramos ordenado\n");
	Mostrar(miarbol);
	fflush(stdout);
	printf("\n Ahora lo guardamos ordenado\n");
	FILE * fich;
	fich = fopen (nfichero, "wb");
	Salvar (miarbol, fich);
	fclose (fich);
	printf("\n Y lo mostramos ordenado\n");
	muestrafichero(nfichero);
	Destruir (&miarbol);

	return EXIT_SUCCESS;*/

	char nfichero[50];
		printf ("Introduce el nombre del fichero binario:\n");
		fflush(stdout);
		scanf ("%s",nfichero);
		fflush(stdin);
		creafichero(nfichero);
		printf("\n Ahora lo leemos y mostramos\n");
		muestrafichero(nfichero);
		fflush(stdout);
}
