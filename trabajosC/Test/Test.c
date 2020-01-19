/*
 * Test.c
 *
 *  Created on: 23 feb. 2017
 *      Author: franc
 */
#include <stdio.h>
void intercambiar (int *a,int *b,int c){
	int aux=*a;
	*a=*b;
	*b=aux;
	c=0;
}
int division (int a, int b, int *resto, int *cociente){
	if(b==0)return -1;
	*cociente=a/b;
	*resto=a%b;
	return 0;
}

void concatenar(char *c,char *d){
	//strcat
	int lc = strlen(c);
	int ld = strlen(d);
	int i=0;
	for (i=0; i<=ld; i++){
		*(c+lc+i)=*(d+i);//c[lc+i]=d[i];
	}
}
void concatenar2(char *cc, char *dc){
	while(*cc!='\0')cc++;
	while(*dc!='\0'){
		*cc=*dc;
		cc++;dc++;
	}
}
int main (int argc, char const *argv[]){
	int a=10,b=3,*pto1=&a,*pto2;
	pto2=&b;
	printf("%d %d",*pto1, *pto2);
	/*char c[20]="Hola ";
	char d[10]="Mundo";
//	strcat(c,d);
	printf("c: %s d: %s %c",c,d,10);
	concatenar2(&c,&d);
	printf("c: %s d: %s",c,d);

*/
	/*char str[5][10];
	int i=-1;
	do{
		i++;
		printf("Introduce el string %d : ",i);
		fflush(stdout);
		scanf("%s",str[i]);
	}while(strcmp(str[i],"f")!=0 &&i<5);
	int j=0;
	for(j=0;j<i;j++)printf("Array %d: %s\n",j,str[j]);
	*/
/*	int x,y;
	int resto,cociente;
	printf("Introduce el divisor: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdout);
	printf("Introduce el dividendo: ");
	fflush(stdout);
	scanf("%d",&y);
	fflush(stdout);
	division(x,y,&resto,&cociente);
	printf("La division da: %c",10);
	printf("cociente: %d resto: %d",cociente,resto);*/
/*
	int x=2;
	int y=0;
	int z=2;
	int resto,cociente;
	intercambiar(&x,&y,z);
	printf("%d %d %d",x,y,z);
	printf("%c",10);
	division(x,y,&resto,&cociente);
	printf("%d %d %d %d",x,y,resto,cociente);

	/*int s=10;
	printf("El valor de la variables es = %d\n", s);
	char cadena[5]="hola";
	printf("Valor de cadena = %s\n",
	cadena);

	double sum,v;
	sum=0;
	printf("Introduce numeros\n");
	fflush(stdout);
	while(scanf("%lf",&v)==1){
		fflush(stdout);
		printf("%.2lf",sum+=v);printf(" ");
		fflush(stdout);
	}
	int	c;
	while((c=getchar())!='f') {
	putchar(c);
	fflush(stdout);
	}
	char a,b;
	int i=0;
	while(i!=256){
	a=-i;
	b=256+a;
	printf("a: ");
	printf("%c",a);
	printf(" b: ");
	printf("%c",b);
	printf(" i: ");
	printf("%d",b);
	printf("%c",10);
	i++;
	}
*/
/*
int *n,l;
*n=&l;
scanf("%d",*n);
printf(" %d",*n);*/
	return 0;
}
/**
*
Syscall.c
*/
//#include <stdio.h>
//#include <unistd.h>
//int main(int argvc, char ** argv) {
//printf("Hola, mundo"); /*funcion C de E/S */
//write(1, "Adios, mundo", 12); /*llamada al sistema*/
//}
