/*
 * PuntFuncion.c
 *
 *  Created on: 22 mar. 2017
 *      Author: franc
 */
int esMayor(void *a,void *b, int (*f)(void*,void*)){
	return f(a,b);
}

int esMayorInt(int *a,int *b){
	return *a>*b;
}

int main(){
	int a=7,b=8;
	printf("%d",esMayor(&a,&b,&esMayorInt));
}
