/*
 * FicherosIO.c
 *
 *  Created on: 15 mar. 2017
 *      Author: franc
 */

#include <stdio.h>
struct Persona{
	char nombre[10] ;
	char apellido[10] ;
	int edad;
}pers;

int main(){
	char c[10];
	//FILE *pf = fopen("Ejemplo.class","w");
	//FILE *pf = fopen("Ejemplo.txt","r");
	FILE *pfe=fopen("personas.txt","r");
	FILE *pfs=fopen("copiaPersonas.txt","w");
	if(pfe==NULL||pfs==NULL){
		perror("No se ha podido abrir el fichero");
		return -1;
	}
	//fprintf(pf,"k");
	//while(fscanf(pf,"%s",c)==1){
	//	printf("%s\n",c);
	//}
	while(fscanf(pfe,"%s, %s %d",pers.nombre,pers.apellido,&pers.edad)==3){
		fprintf(pfs,"Nombre: %s, Apellido: %s,Edad: %d\n",pers.nombre,pers.apellido,pers.edad);
	}

	fclose(pfe);
	fclose(pfs);
	//close(pf);
	return 0;
}

