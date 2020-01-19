/*
 * k.c
 *
 *  Created on: 17 abr. 2017
 *      Author: franc
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main2(){
	char pal[20];
	FILE *pf=fopen("txt.txt","w");
	while(scanf("%s",pal)==1&&strcmp(pal,"0")!=0){
		fprintf(pf,"%s\n",pal);
	}
	fclose(pf);
}

int main(){
	int c;
	char *p;
	c=120;
	p=&c;
	printf("%d\n",*(p));
	p=p+1;
	printf("%d",*(p));
}
