#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*
2. Napisati program koji unosi string, rastavlja ga u niz struktura za zapis podataka o
znakovima u stringu: znak (char) i broj njegovih ponavljanja u stringu (int) na način da su
sva ponavljanja istog znaka u stringu predstavljena jednim elementom niza, sortira
znakove stringa po broju pojavljivanja (silazno) te formira i ispisuje novi string sastavljen
od tako sortiranih slova i broja njihovog ponavljanja (navedenog u zagradi). Sve radnje se
obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom programu.
*/
struct podaci {
	char znak;
	int broj;
};
struct podaci prijepis(char slovo,char *string);
void sortiranje(struct podaci *info, char *string);
int main() {
	int i;
	struct podaci info[50];
	char string[50];
	printf("Unesi string: ");
	fflush(stdin);
	gets(string);
	for (i = 0; i < strlen(string); i++) {
		info[i] = prijepis(string[i],string);
	}
	sortiranje(info, string);
	printf("Sortiran string: \n%s\n", string);
	for (i = 0; i < strlen(string); i++) {
		info[i] = prijepis(string[i],string);
		if (info[i].znak != info[i-1].znak)
		printf("Broj ponavljanja %c: %d\n", info[i].znak, info[i].broj);
	}
	system("pause");
	return 0;
}
struct podaci prijepis(char slovo,char *string) {
	struct podaci pom;
	int i, brojac = 0;
	for (i = 0; i < strlen(string); i++) {
		if (slovo == string[i])
			brojac++;
	}

	pom.znak = slovo;
	pom.broj = brojac;
	return pom;
}
void sortiranje(struct podaci *info, char *string) {
	int i, j;
	int brojac1=0;
	struct podaci pom;
	for (i = 0; i < strlen(string); i++)
	{
		for (j = 1; j < strlen(string); j++) {
			if (info[i].broj > info[j].broj) {
				pom = info[i];
				info[i] = info[j];
				info[j] = pom;

			}
		}

	}
	for (i = 0; i < strlen(string); i++) {
		string[i] = info[i].znak;
		brojac1++;
	}
	string[brojac1]='\0';
}