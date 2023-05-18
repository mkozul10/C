/*5. Napisati program koji unosi rečenicu i ispituje radi li se o palindromu (tekstu koji se čita
isto od naprijed i od nazad, ne uzimajući u obzir razliku velikih i malih slova i
zanemarujući razmake i interpunkciju). Primjeri palindroma su "Ana voli Milovana." i
"Udovica baci vodu."*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	int j=0,k=0,i;
	char recenica[32];
	char lower_space[32];
	char pom[32];
	printf("Unesite recenicu: ");
	fflush(stdin);
	gets(recenica);
	for(i=0;i<strlen(recenica);i++)
	{
		recenica[i]=tolower(recenica[i]);
		if(islower(recenica[i]))
		{
			lower_space[j]=recenica[i];
			j++;
		}
		
	}
	lower_space[j]='\0';
	for(i=strlen(lower_space);i>0;i--)
	{
		pom[k]=lower_space[i-1];
		k++;
	}
	pom[k]='\0';
	if(strcmp(pom,lower_space)==0)
	{
		puts("Vasa recenica je palindrom");
	}
	else
	{
		puts("Vasa recenica nije palindrom");
	}
	system("pause");
	return 0;
}
