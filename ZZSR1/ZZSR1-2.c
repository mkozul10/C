/*2. Napisati program koji unosi rijeèi sve dok se neka rijeè ne ponovi dva puta zaredom i
nakon toga ispisuje sve unesene rijeèi sortirane po duljini rijeèi, odnosno abecedi ako je
duljina ista.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	printf("Unosite rijeci:\n");
	char rijec[32][16],pom[16];
	int i=0,j,k;
/*	gets(rijec[0]);*/
	do
	{
		strcpy(pom,rijec[i]);
		i++;
		gets(rijec[i]);
		
	}while(strcmp(rijec[i],pom)!=0);
	for(j=0;j<i-1;j++)
	{
	  for(k=j+1;k<i;k++)
	  {
	  	if((strlen(rijec[k]))>(strlen(rijec[j])))
	  	{
	  		strcpy(pom,rijec[k]);
	  		strcpy(rijec[k],rijec[j]);
	  		strcpy(rijec[j],pom);
		}
		else if((strlen(rijec[k]))==(strlen(rijec[j])))
		{
			 if(strcmp(rijec[j], rijec[k]) > 0)
            {
                strcpy(pom, rijec[j]);
                strcpy(rijec[j], rijec[k]);
                strcpy(rijec[k], pom); 
            }
		}
	  }
	}
	printf("Poredani po abecedi i po velicini:\n");
	for(j=0;j<i;j++)
	{
		puts(rijec[j]);
	}
	
	
	
	system("pause");
	return 0;
}
