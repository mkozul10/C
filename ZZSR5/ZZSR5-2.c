/*2. Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese broj 0. Nakon
svakog unosa broj se smješta u datoteku uneseni_brojevi.txt. Nakon toga u datoteku
sortirani_brojevi.txt pohranjuju se svi brojevi sortirani po veličini.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *niz=NULL,pom,brojac=0;
	FILE *dat1=fopen("2.uneseni_brojevi.txt","w");
	int i=-1;
	niz=(int*)malloc(sizeof(int));
	printf("Unos brojeva:\n");
	do
	{
		i++;
		scanf_s("%d",niz+i);
		niz=(int*)realloc(niz,sizeof(int));
		if(*(niz+i)!=0)
		fprintf(dat1,"%d\n",*(niz+i));
	}while(*(niz+i)!=0);
	for(int j=0;j<i-1;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(*(niz+k)>*(niz+j))
			{
				pom=*(niz+k);
				*(niz+k)=*(niz+j);
				*(niz+j)=pom;	
			}
		}
	}
	FILE *dat2=fopen("2.sortirani_brojevi.txt","w");
	do
	{
		fprintf(dat2,"%d\n",*(niz+brojac));
		brojac++;
	}while(brojac<=i-1);
	fclose(dat1);
	fclose(dat2);
	free(niz);
	system("pause");
	return 0;
}