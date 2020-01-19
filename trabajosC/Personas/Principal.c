/*
 * Principal.c
 *
 *  Created on: 15 mar. 2017
 *      Author: mmar
 */
#include <stdio.h>
#include "ListaPersonas.h"


int creaBinarioPersona(const char* nombreEntrada,const char* nombreSalida){
	struct Persona pers;
	FILE *pfe = fopen(nombreEntrada,"r");
	FILE *pfs = fopen(nombreSalida,"wb");
	if (pfe == NULL || pfs == NULL){
		perror("no se puede abrir");
		return -1;
	}

	while (fscanf(pfe,"%s %s %d",pers.nombre,pers.apellido,&pers.edad)==3){
		fwrite(&pers,sizeof(struct Persona),1,pfs);
	}


	fclose(pfe);fclose(pfs);
	return 0;
}


int creaTextoNumeros(const char* nombre){

	int i;
	FILE *pf = fopen(nombre,"w");
	if (pf == NULL){
		perror("no se puede abrir");
		return -1;
	}

	for (i=1000; i<2000; i++){
		//fwrite(&i,sizeof(int),1,pf);
		fprintf(pf,"%d ",i);
	}

	fclose(pf);
	return 0;
}


int sumarNumerosFichBinario(const char* nombre){
	int i;
	int suma = 0;
	FILE *pf = fopen(nombre,"rb");
	if (pf == NULL){
		perror("no se puede abrir");
		return -1;
	}

	while (fread(&i,sizeof(int),1,pf)==1){
		printf("%d ",i);
		suma = suma + i;
	}

	printf("\nsuma: %d \n",suma);

	fclose(pf);
	return 0;

}
int main1(){
	struct Persona pers;
	FILE *pfe = fopen("personas.txt","r");
	FILE *pfs = fopen("copiaPersonas.txt","w");
	if (pfe == NULL || pfs == NULL){
		perror("No se ha podido abrir el fichero");
		return -1;
	}

	while (fscanf(pfe,"%s %s %d",pers.nombre,pers.apellido,&pers.edad)==3){
		fprintf(pfs,"Nombre: %s, Apellido: %s, Edad: %d \n",pers.nombre,pers.apellido,pers.edad);
	}


	fclose(pfe);fclose(pfs);
	return 0;
	//Esto es un ejemplo
}

int main(){
	//creaBinarioNumeros("numeros.bin");
	//creaTextoNumeros("numeros.txt");
	//sumarNumerosFichBinario("numeros.bin");
	//creaBinarioPersona("personas.txt","personas.bin");
	ListaPersona pr;
	crear(&pr);
	crearDeFichero("personas.txt",&pr);
	mostrar(pr);
}
