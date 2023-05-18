/*1. Napisati program koji unosi tekst i formira novi string u kojem se slova engleskog
alfabeta unesenog teksta pojavljuju u obrnutom rasporedu. Npr. za uneseni tekst:
"Danas je srijeda, 05. 04. 2022. godine." Formira se string: "enidogadejirsejsanaD".*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char tekst[32],novi_tekst[32],obrnuta_slova[32];
	int j=0;
	int k=0;
	int i;
	puts("Unesite tekst:");
	fflush(stdin);
	gets(tekst);
	for(i=0;i<strlen(tekst);i++)
	{
		if(isalpha(tekst[i]))
		{
			novi_tekst[j]=tekst[i];
			j++;
		}
		
	}
	novi_tekst[j]='\0';
	for(i=j-1;i>=0;i--)
	{
		obrnuta_slova[k]=novi_tekst[i];
		k++;
	}
	obrnuta_slova[k]='\0';
	printf("Obrnut redoslijed alfabeta u vasem tekstu je:\n");
	puts(obrnuta_slova);
	
	system("pause");
	return 0;
}
