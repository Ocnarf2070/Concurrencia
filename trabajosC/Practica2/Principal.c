/*
 * Principal.c
 *
 *  Created on: 23 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
unsigned k[4]={128,129,130,131};
void decrypt(unsigned int* v, unsigned int* k){
	const unsigned delta=0x9e3779b9;
	unsigned sum=0xc6ef3720;
	int i=0;
	for(i=0;i<32;i++){
		v[1]-=((v[0]<<4)+k[2])^(v[0]+sum)^((v[0]>>5)+k[3]);
		v[0]-=((v[1]<<4)+k[0])^(v[1]+sum)^((v[1]>>5)+k[1]);
		sum-=delta;
	}
}
int descifrarFichero(char* nombreE, char* nombreS){
	FILE *pfe=fopen(nombreE,"rb");
	FILE *pfs=fopen(nombreS,"wb");
	if(pfe==NULL||pfs==NULL){
		perror("No se ha podido abrir el fichero");
		return -1;
	}
	unsigned tam;
	unsigned v[2];
	fread(&tam,sizeof(unsigned),1,pfe);
	while(fread(v,sizeof(unsigned),2,pfe)==2){
		decrypt(v,k);
		if(tam>=8){
			fwrite(v,sizeof(unsigned),2,pfs);
			tam-=8;
		}else{
			if(tam>0){
				fwrite(v,sizeof(char),tam,pfs);
				tam=0;
			}
		}
	}
	fclose(pfe);
	fclose(pfs);
	return 0;
}
int main(){
	descifrarFichero("crisantemoCifrado.cyf","Desc2.jpg");
	return 0;
}
