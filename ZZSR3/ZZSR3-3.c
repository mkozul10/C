#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*3. Napisati program koji definira strukturu za zapis podataka o adresama koje unosi
korisnik: ulica (string), kućni broj (int), mjesto (string) i poštanski broj (int), unosi podatke
za 10 adresa, dodatno unosi mjesto i formira dva niza adresa, jedan u dodatno
unesenom mjestu i drugi izvan njega, sortirane po abecedi naziva ulice, odnosno kućnom
broju ako je ulica ista. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u
glavnom programu.*/

struct adresa {
	char ulica[30];
	int kucni_broj;
	char mjesto[30];
	int postanski_broj;
};
int printanje(struct adresa* strukt, char *mjestopom, int p, int i);

int main() {
	struct adresa a[3];
	int i, j;
	char pom[30];
	char mjestopom[30];
	for (i = 0; i < 3; i++) {
		printf("Unesi podatke za %d. adresu.\n", i + 1);
		printf("Ime ulice: ");
		fflush(stdin);
		gets(a[i].ulica);
		printf("Kucni broj: ");
		scanf("%d", &a[i].kucni_broj);
		gets(pom);
		printf("Mjesto: ");
		gets(a[i].mjesto);
		printf("Postanski broj: ");
		scanf("%d", &a[i].postanski_broj);
		gets(pom);
	}
	printf("Unesi dodatno mjesto:");
	fflush(stdin);
	gets(mjestopom);
	printf("Adrese u mjestu %s", mjestopom);
	for (i = 0; i < 3; i++) {
		j = printanje(a, mjestopom, 0, i);
		if (i == j) printf("Ulica: %s\n Mjesto: %s\n Postanski broj: %d\n Kucni broj %d\n\n", a[i].ulica, a[i].mjesto, a[i].postanski_broj, a[i].kucni_broj);
	}
	printf("Adrese u ostalim mjestima:\n");
	for (i = 0; i < 3; i++) {
		j = printanje(a, mjestopom, 1, i);
		if (i == j) printf("Ulica: %s\n Mjesto: %s\n Postanski broj: %d\n Kucni broj %d\n\n", a[i].ulica, a[i].mjesto, a[i].postanski_broj, a[i].kucni_broj);
	}
	system("pause");
	return 0;
}
int printanje(struct adresa* strukt, char *mjestopom, int p, int i) {
	int z, j;
	struct adresa pomocna;
	if (p == 0) {
		for (z = i; z < 3; z++) {
			if (strcmp(strukt[z].mjesto, mjestopom) == 0) {
				for (j = z+1; j < 3; j++) 
				{
						if (strcmp(strukt[z].ulica, strukt[j].ulica) > 0) 
						{
							pomocna = strukt[z];
							strukt[z] = strukt[j];
							strukt[j] = pomocna;

						}
						else if(strcmp(strukt[z].ulica, strukt[j].ulica) == 0)
						{
							if (strukt[z].kucni_broj > strukt[j].kucni_broj) 
								{
									pomocna = strukt[z];
									strukt[z] = strukt[j];
									strukt[j] = pomocna;
								}
						}
				}
				if (strcmp(strukt[z].mjesto, mjestopom) == 0) {
					return z;
				}
			}
		}
	}
	else
	{
			for (z = i; z < 3; z++) {
			if (strcmp(strukt[z].mjesto, mjestopom) != 0) {
				for (j = z+1; j < 3; j++) 
				{
						if (strcmp(strukt[z].ulica, strukt[j].ulica) > 0) 
						{
							pomocna = strukt[z];
							strukt[z] = strukt[j];
							strukt[j] = pomocna;

						}
						else if(strcmp(strukt[z].ulica, strukt[j].ulica) == 0)
						{
							if (strukt[z].kucni_broj > strukt[j].kucni_broj) 
								{
									pomocna = strukt[z];
									strukt[z] = strukt[j];
									strukt[j] = pomocna;
								}
						}
				}
				if (strcmp(strukt[z].mjesto, mjestopom) != 0) {
					return z;
				}
			}
		}
	}
}


