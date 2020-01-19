/*
 * p.c
 *
 *  Created on: 8 mar. 2017
 *      Author: franc
 */
#include <stdio.h>
int main2(){
	int num=0;

	printf("escribe dato:\n");
	fflush(stdout);
	scanf("%d", &num);

	float f=((2000*8)/(num*1000000));
	printf("%fl",f);
	return 0;
}
char clave = 0xFA;
void cifrar(char *c){
	*c^=clave;
}
int cifrarFichero(char* nombreEntrada, char* nombreSalida){
	FILE *fe=fopen(nombreEntrada,"r");
	FILE *fs=fopen(nombreSalida,"w");
	if(fe==NULL||fs==NULL){
		perror("error");
		return 0;
	}
	char c;
	while(fscanf(fe,"%c",&c)==1){
		cifrar(&c);
		fprintf(fs,"%c",c);
	}
	fclose(fe);fclose(fs);
	return 0;
}
int main(){
	const unsigned char N=3;
	/*unsigned a=170,b=15;
	printf("%d %d %d %d",a&b,a|b,a^b,~a);*/
	unsigned char a,b,c,d,e,f;
	a=17;
	b=22;
	printf("A:%d B:%d Resultado:%d\n",a,b,a&b);
	c=73;
	c=c&~(1<<N);
	printf("%d",c);
	cifrarFichero("texto.txt","hey.txt");
}
