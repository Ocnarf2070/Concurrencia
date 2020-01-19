/*
 * ficheroBinario.c
 *
 *  Created on: 15 mar. 2017
 *      Author: franc
 */
/*
#include <stdio.h>;
int crearBinarioNumeros(const char* nombre){
	int i;
	FILE *pf=fopen(nombre,"wb");
	if(pf==NULL){
		perror("No se puede abrir");
		return -1;
	}
	for(i=1000;i<2000;i++){
		fwrite(&i,sizeof(int),1,pf);
		//fprintf(pf,"%d\n",i);
	}

	fclose(pf);
	return 0;
}
int sumarNumerosFichBinario(const char*nombre) {
	FILE *pf=fopen(nombre,"rb");
	int i;
	int suma=0;
		if(pf==NULL){
			perror("No se puede abrir");
			return -1;
		}
	while(fread(&i,sizeof(int),1,pf)==1){
		printf("%d ",i);
		suma=suma+i;
	}
	printf("\nsuma: %d\n",suma);
	fclose(pf);
	return 0;
}
int main(){
	crearBinarioNumeros("num.txt");
	sumarNumerosFichBinario("num.txt");
	return 0;
}
*/
