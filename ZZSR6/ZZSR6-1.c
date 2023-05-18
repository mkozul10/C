/*1. Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjerene
dubine vodostaja Neretve na određenom mjernom mjestu tijekom vremena. Pročitati
sve temperature, pohraniti ih u dinamički alociran memorijski prostor odgovarajuće
veličine i odrediti prosječnu dubinu vodostaja na tom mjernom mjestu.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char naziv[32];
	double *temp=NULL;
	int i=0;
	double zbroj=0;
	FILE *dat=NULL;
	printf("Unesi naziv datoteke: ");
	gets(naziv);
	strcat(naziv,".txt");
	dat=fopen(naziv,"r");
	temp=(double*)malloc(sizeof(double));
	while(!feof(dat))
	{
		fscanf(dat,"%lf",(temp+i));
		temp=(double*)realloc(temp,sizeof(double));
		i++;
	}
	fclose(dat);
	printf("Dubine:\n");
	for(int j=0;j<i-1;j++)
	{
		printf("%.3lf\n",*(temp+j));
		zbroj+=*(temp+j);
	}
	printf("Prosjecna dubina: %.3lf\n",zbroj/(double)(i-1));
	free(temp);
	system("pause");
	return 0;
}