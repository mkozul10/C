/*3. Napisati program koji dinamički alocira memoriju za niz realnih brojeva koji se unose sve
dok neki od unesenih brojeva ne bude identičan prvom unesenom broju. Memorija se
realocira prije svakog unosa broja tako da se koristi optimalno. Brojevi se ispisuju,
sortirani silazno po veličini decimalnog dijela. Koristiti isključivo sintaksu pokazivača.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	float *pNiz=NULL;
	int *br=NULL;
	br=(int*)malloc(sizeof(int));
	*br=0;
	float *pom=(float*)malloc(sizeof(float));
	pNiz=(float*)malloc(sizeof(float));
	printf("Unos realnih brojeva:\n");
	scanf_s("%f",pNiz);
	do
	{
		*br=*br+1;
		pNiz=(float*)realloc(pNiz,sizeof(float));
		scanf_s("%f",pNiz+*br);
	}while(*pNiz!=*(pNiz+*br));	
	for(int i=0;i<br-1;i++)
	{
		for(int j=i+1;j<*br;j++)
		{
			if((*(pNiz+j)-(int)(*(pNiz+j)))<(*(pNiz+i)-(int)(*(pNiz+i))))
			{
				*pom=*(pNiz+j);
				*(pNiz+j)=*(pNiz+i);
				*(pNiz+i)=*pom;
			}
		}
	}
	printf("Brojevi poredani silazno po velicini decimalnog dijela:\n");
	for(int i=0;i<*br;i++)
	{
		printf("%.2f\n",*(pNiz+i));
	}
	free(pNiz);
	free(br);
	system("pause");
	return 0;
}