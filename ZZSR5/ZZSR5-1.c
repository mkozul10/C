/*1. Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjerene
temperature (realni brojevi) na određenom mjernom mjestu tijekom vremena. Pročitati
sve temperature i odrediti prosječnu temperaturu na tom mjernom mjestu.*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	char unos[32];
	char *datoteka=NULL;
	float niz[30],zbroj=0,prosjek;
	int i=0;
	printf("Unos imena datoteke: ");
	gets(unos);
	strcat(unos,".txt");
	datoteka=(char*)malloc(sizeof(char)*strlen(unos+1));
	strcpy(datoteka,unos);
	FILE *dat=fopen(datoteka,"r");
	do
	{
	fscanf(dat,"%f",&niz[i]);
	i++;
	}while(!feof(dat));
	fclose(dat);
	printf("Temperature su:\n");
	for(int j=0;j<i-1;j++)
	{
		printf("%.3f C\n",niz[j]);
		zbroj+=niz[j];
	}
	prosjek=zbroj/(i-1);
	printf("Prosjek je: %.3f\n",prosjek);
	free(datoteka);
	system("pause");
	return 0;
}