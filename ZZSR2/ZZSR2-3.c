/*3. Napisati program koji definira strukturu za zapis podataka o rijecima rečenice koju unosi
korisnik: redni broj riječi u rečenici (int), tekst riječi (string), dužina riječi (int) i slovo u
riječi sa najvećim ASCII kodom (char). Ispisuju se podaci o svim riječima sortirani po
abecednom poretku teksta riječi.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct podaci
    {
	int redni_broj;
	char tekst_rijeci[32];
	int duzina_rijeci;
	char slovo;
	};
int main()
{
	struct podaci podaci_2[16],pom2;
	char recenica[256],rijeci[16][16],pom[16];
	int i,br=0,bs=0,broj_rijeci=0;
	puts("Unesite recenicu:");
	fflush(stdin);
	gets(recenica);
	for(i = 0; i <= strlen(recenica); i++)
    {
        if((recenica[i] != ' ') && (recenica[i] != '\0'))
        {
            rijeci[br][bs] = recenica[i];
            bs++;
        }
        else
        {
            rijeci[br][bs] = '\0';
            br++;
            broj_rijeci++;
            bs = 0;
        }        
    }    
	 for(i=0;i<broj_rijeci-1;i++)
	 {
	 	for(int j=i+1;j<broj_rijeci;j++)
	 	{
	 		if(strcmp(rijeci[j],rijeci[i])<0)
			 {
			 	strcpy(pom,rijeci[j]);
			 	strcpy(rijeci[j],rijeci[i]);
			 	strcpy(rijeci[i],pom);
			 }	
		}
	 }
	for(i=0;i<=broj_rijeci;i++)
    {
    	strcpy(podaci_2[i].tekst_rijeci,rijeci[i]);
    	podaci_2[i].redni_broj=i+1;
    	podaci_2[i].duzina_rijeci=strlen(rijeci[i]);
	}
	for(i=0;i<broj_rijeci;i++)
	{
		pom2.slovo=rijeci[i][0];
		for(int j=1;j<strlen(rijeci[i]);j++)
		{
			
			if(rijeci[i][j]>pom2.slovo)
			{
				podaci_2[i].slovo=rijeci[i][j];
			}
			else if(rijeci[i][j]<pom2.slovo)
			{
				podaci_2[i].slovo=pom2.slovo;
			}
	    }
	}
     for(int k=0;k<broj_rijeci;k++)
     {
     	printf("Tekst rijeci: %s\n",podaci_2[k].tekst_rijeci);
     	printf("Redni broj rijeci: %d\n",podaci_2[k].redni_broj);
     	printf("Znak sa najvecim ascii kodom: %c\n",podaci_2[k].slovo);
     	printf("Duzina rijeci: %d\n",podaci_2[k].duzina_rijeci);
     	printf("\n");
	 }
	
	
	system("pause");
	return 0;
}