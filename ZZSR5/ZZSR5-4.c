/*4. Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog
znaka ispisuje, sortirane po abecedi sva do dana učitana slova. Na kraju se ispisuje broj
ponavljanja svakog od samoglasnika (ne vodeći računa radi li se o velikim i malim
slovima). */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int brojac_a=0,brojac_e=0,brojac_i=0,brojac_o=0,brojac_u=0;
int ascii_slova(char slovo);
void slova_do_ascii(int pozicija);
int main(){
	char x;
	int pozicija;
	FILE*dat=fopen("4.tekst.txt","r");
	while(!feof(dat))
	{
		x=fgetc(dat);
		if(isalpha(x))
		{
		pozicija=ascii_slova(x);
		if(pozicija!=97 && pozicija!=65)
		slova_do_ascii(pozicija);
		}
		else
		printf("\nZnak (%c) nije slovo\n",x);
	if(pozicija==97)
	{
	printf("\n");
	printf("Slovo %c:\n",pozicija);
	printf("-a je prvo slovo u abecedi");
	printf("\n");
	}
	else if(pozicija==65)
	{
	printf("\n");
	printf("Slovo %c:\n",pozicija);
	printf("-A je prvo slovo u abecedi");
	printf("\n");
	}
	}
	fclose(dat);
	printf("Samoglasnici:\n");
	printf("Broj samoglasnika a/A= %d\n",brojac_a);
	printf("Broj samoglasnika e/E= %d\n",brojac_e);
	printf("Broj samoglasnika i/I= %d\n",brojac_i);
	printf("Broj samoglasnika o/O= %d\n",brojac_o);
	printf("Broj samoglasnika u/U= %d\n",brojac_u);
	system("pause");
	return 0;
}
int ascii_slova(char slovo){
	int ascii;
	ascii=slovo;
	return ascii;
}
void slova_do_ascii(int pozicija){
	int pom=0;
	pom=pozicija;
	int kontrola=0;
	if(pozicija>=97)
	kontrola=1;
	printf("\nSlovo %c:\n",pozicija);
	while((pozicija>65 && kontrola==0) || (pozicija>97 && kontrola==1))
	{
		pozicija--;
		printf("%c",pozicija);
		if(pozicija==65 || pozicija==97)
		brojac_a++;
		else if(pozicija==69 || pozicija==101)
		brojac_e++;
		else if(pozicija==73 || pozicija==105)
		brojac_i++;
		else if(pozicija==79 || pozicija==111)
		brojac_o++;
		else if(pozicija==85 || pozicija==117)
		brojac_u++;
	}
	
}