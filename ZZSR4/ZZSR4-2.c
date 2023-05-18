/*2. Napisati program koji dinamički zauzima memoriju za 20 stringova maksimalne duljine
od 20 znakova, unosi stringove, sortira ih po duljini silazno, odnosno po abecedi (ako je
duljina ista) te ih ispisuje. Koristiti isključivo sintaksu pokazivača. */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char **pStr=NULL;
	char *pom=NULL;
	pom=(char*)malloc(sizeof(char)*20);
	pStr=(char**)malloc(sizeof(char*)*20);
	for(int i=0;i<20;i++)
	{
		*(pStr+i)=(char*)malloc(sizeof(char)*20);
	}
	printf("Unos stringova:\n");
	for(int i=0;i<20;i++)
	{
		gets(*(pStr+i));
	}
	for(int i=0;i<19;i++)
	{
		for(int j=i+1;j<20;j++)
		{
		if(strlen(*(pStr+j))>strlen(*(pStr+i)))
			{
				strcpy(pom,*(pStr+j));
				strcpy(*(pStr+j),*(pStr+i));
				strcpy(*(pStr+i),pom);
			}
			else if(strlen(*(pStr+j))==strlen(*(pStr+i)))
			{
				if(strcmp(*(pStr+j),*(pStr)+i)<0)
					{
						strcpy(pom,*(pStr+j));
						strcpy(*(pStr+j),*(pStr+i));
						strcpy(*(pStr+i),pom);
					}	
			}
		}
	}
	printf("Poredani stringovi:\n");
	for(int i=0;i<20;i++)
	{
		puts(*(pStr+i));
	}
	free(pStr);
	free(pom);
	system("pause");
	return 0;
}