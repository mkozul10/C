/*4. Napisati program koji unosi 10 stringova i jos jedan dodatni string te ispisuje one
unesene stringove koji po abecedi (ne vodeci racuna o razlici velikih i malih slova) dolaze
ispred dodatnog stringa*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char unos[9][16];
	char unos2[9][16];
	char dodatni[16];
	int i,j;
	printf("Unos 10 stringova:\n");
	for(i=0;i<10;i++)
	{
		gets(unos[i]);
	}
	printf("Unesite dodatni string:\n");
	gets(dodatni);
	for(i=0;i<strlen(dodatni);i++)
	{
		dodatni[i]=tolower(dodatni[i]);
	}
	printf("Uneseni stringovi koji po abecedi dolaze prije dodatnog stringa:\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<strlen(unos[i]);j++)
		{
			unos2[i][j]=tolower(unos[i][j]);
	    }
	    if(strcmp(dodatni,unos2[i])>0)
	    {
	 	    puts(unos[i]);
	    }	 
	}
	system("pause");
	return 0;
}
