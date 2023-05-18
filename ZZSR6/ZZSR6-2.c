/*2. Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese prost. Nakon
svakog unosa, brojevi se smještaju u dinamički alociran memorijski prostor odgovarajuće
veličine. Nakon završetka unosa, brojevi se spremaju u datoteku sortirani_brojevi.txt,
sortirani po veličini silazno.*/
#include<stdio.h>
#include<stdlib.h>
int je_li_prost(int broj);
int main(){
	int *brojevi=NULL;
	int i=0,pom;
	FILE *dat=NULL;
	do
	{
		if(i==0)
		{
			brojevi=(int*)malloc(sizeof(int));
			scanf_s("%d",(brojevi+i));
			i++;
		}
		else
		{
			brojevi=(int*)realloc(brojevi,sizeof(int));
			scanf_s("%d",(brojevi+i));
			i++;
		}
		
	}while(je_li_prost(*(brojevi+(i-1))));
	for(int j=0;j<i-1;j++)
	for(int k=j+1;k<i;k++)
	{
		if((*(brojevi+k))>(*(brojevi+j)))
		{
			pom=*(brojevi+k);
			*(brojevi+k)=*(brojevi+j);
			*(brojevi+j)=pom;	
		}
	}
	dat=fopen("2.sortirani_brojevi.txt","w");
	for(int j=0;j<i;j++)
	fprintf(dat,"%d\n",*(brojevi+j));
	printf("Brojevi su prepisani u datoteku\n");
	fclose(dat);
	free(brojevi);
	system("pause");
	return 0;
}
int je_li_prost(int broj){
	int brojac=0;
	for(int i=2;i<broj;i++)
	{
		if(broj%i==0)
		brojac++;
	}
	if(brojac!=0)
	return 1;
	else
	return 0;
}