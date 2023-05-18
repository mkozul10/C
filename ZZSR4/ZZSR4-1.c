/*1. Napisati program koji pita korisnika kolika je dimenzija niza cijelih brojeva, dinamički
alocira memoriju za taj niz i unosi brojeve, a zatim unosi i dodatni cijeli broj u također
dinamički alociranu memoriju te na kraju ispisuje, sortiran po veličini, samo one brojeve
iz niza koji su veći od dodanog broja. Koristiti isključivo sintaksu pokazivača. */
#include<stdio.h>
#include<stdlib.h>
void unos(int *pNiz,int *n);
void unos_broja(int *pBroj);
void ispis(int *pNiz,int *n,int *pBroj);
int main(){
	int *pNiz=NULL;
	int *pBroj=NULL;
	int *n=NULL;
	n=(int*)malloc(sizeof(int));
	printf("Unos velicine niza: ");
	scanf("%d",&*n);
	pNiz=(int *)malloc(*n*sizeof(int));
	unos(pNiz,n);
	pBroj=(int *)malloc(sizeof(int));
	printf("Unos dodatnog broja: ");
	unos_broja(pBroj);
	printf("Brojevi veci od broja %d su:\n",*pBroj);
	ispis(pNiz,n,pBroj);
	free(pNiz);
	free(pBroj);
	free(n);
	system("pause");
	return 0;
}
void unos(int *pNiz,int *n)
{
	for(int i=0;i<*n;i++)
	{
		scanf("%d",(pNiz+i));
	}
}
void unos_broja(int *pBroj)
{
	scanf("%d",pBroj);
}
void ispis(int *pNiz,int *n,int *pBroj)
{
for(int j=*n;j>0;j--)
{
	if(*(pNiz+j)>*pBroj)
	{
		printf("%d\n",*(pNiz+j));	
	}
}
}