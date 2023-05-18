/*4. Napisati program koji dinamički alocira memoriju za string koji se formira spajanjem
unesenih stringova na način da se u obzir uzimaju samo velika slova engleskog alfabeta iz
unesenih stringova. Memorija se realocira prije dodavanja svakog znaka u formirani
string. Unos prestaje u trenutku kada broj samoglasnika u formiranom stringu bude veći
od 10. Nakon toga string se ispisuje. Koristiti isključivo sintaksu pokazivača.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int provjera(char slovo);
int main(){
	char tmpstr[100];
	char *pStr=NULL;
	int brojac;
	int duljina=0;
	int j;
	printf("Unos stringova:\n");
	do
	{
		brojac=0;
		gets(tmpstr);
		if(duljina==0)
		{
		pStr=(char*)malloc(sizeof(char)*(strlen(tmpstr)+1));
		strcpy(pStr,tmpstr);
		}
		else
		{
		pStr=(char*)realloc(pStr,sizeof(char));
		for(int i=0;i<strlen(tmpstr);i++)
		{
			if(isalpha(tmpstr[i]) && isupper(tmpstr[i]))
			{
				*(pStr+j)=tmpstr[i];
				j++;
			}
		}
		*(pStr+j)='\0';
		}
		for(int i=0;i<strlen(pStr);i++)
		{
			if(provjera(*(pStr+i)))
			{
				brojac++;
			}
		}
		
		duljina+=strlen(tmpstr);
	}while(brojac<10);
	printf("Konacni string:\n");
	puts(pStr);
	free(pStr);
	system("pause");
	return 0;
}
int provjera(char slovo){
	char samoglasnici[5]="AEIOU";
	int brojac=0;	
	for(int i=0;i<5;i++)
	{
		if(slovo==samoglasnici[i])
		brojac++;
	}
	if(brojac!=0)
	return 1;
	else
	return 0;	
}









