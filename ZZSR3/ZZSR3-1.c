#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*1. Napisati program koji unosi string, rastavlja ga u niz struktura za zapis podataka o
znakovima u stringu : znak(char) i njegova pozicija u stringu(int), sortira znakove stringa
po vrijednostima ASCII koda te formira i ispisuje novi string sastavljen od tako sortiranih
slova.Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom
programu.*/
struct podaci {
	char znak;
	int pozicija;
};
struct podaci prepisivanje(char slovo, int br);
void sortiranje(char *string);
int main() {
	int i;
	struct podaci info[50];
	char string[50];
	printf("Unesi string: ");
	gets(string);
	for (i = 0; i < strlen(string)-1; i++) {
		info[i] = prepisivanje(string[i], i);
		printf("Znak: %c, pozicija: %d\n", info[i].znak, info[i].pozicija);
	}
	sortiranje(string);
	system("pause");
	return 0;
}

struct podaci prepisivanje(char slovo, int br) {
	struct podaci pom;
pom.pozicija=br+1;
pom.znak=slovo;
return pom;
}
void sortiranje(char *string){
	char pom;
	int i, j;
	int n = strlen(string);
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (string[i] > string[j]) {
					pom = string[i];
					string[i] = string[j];
					string[j] = pom;
			}
		}
	}

	printf("Sortiran string je : %s", string);
}
