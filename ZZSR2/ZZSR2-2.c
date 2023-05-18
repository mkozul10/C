/*2. Napisati program koji definira strukturu za zapis podataka o vozilima: proizvođač
(string), model (string), snaga u kW (int) i cijena (float). Program inicijalizira podatke za
10 vozila, od korisnika traži podatke o minimalnoj snazi i maksimalnoj cijeni vozila koje
korisnik traži te mu ispisuje podatke o svim vozilima koja zadovoljavaju unesene
podatke.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct automobili
{
	char proizvodjac[32];
	char model[100];
	int snaga;
	float cijena;
	
};
int main(){
	struct automobili n[10]={{"Mercedes-Benz","GT63s 4 door coupe biTURBO 4 MATIC+ E-performance 2022",620,330000},
									{"Audi","A6 C6 3.0 TDI Quattro Facelift 2010",176,16000},
									{"Volkswagen","Passat B7 2.0 TDI 4MOTION 2012",103,15000},
									{"Volkswagen","Golf 6 2.0 TDI 4MOTION 2012",103,14000},
									{"Audi","SQ7 4.0 biTDI Quattro 2018",320,80000},
									{"Yamaha","MT-09 2020",85,18000},
									{"Volkswagen","Golf 3 1.9 TDI 1998",67,5000},
									{"Mercedes-Benz","GLE 400d 3.0 4MATIC 2021",243,100000},
									{"BMW","X5 M50d X-drive 2020",294,230000},
									{"Volkswagen","Golf 7 2.0 TDI 2016",110,25000}};
	int unos_snaga,brojac=0;
	float unos_cijena;
	printf("Unesite minimalnu snagu vozila(kw): ");
	scanf_s("%d",&unos_snaga);
	printf("Unesite maksimalnu cijenu vozila(KM): ");
	scanf_s("%f",&unos_cijena);
	printf("\nRezultati pretrage:\n\n");
	for(int i=0;i<10;i++)
	{
		if(n[i].cijena<=unos_cijena && n[i].snaga>=unos_snaga)
		{
			printf("Proizvodjac: %s\nModel: %s\nSnaga motora: %d kw\nCijena: %f KM\n\n",n[i].proizvodjac,n[i].model,n[i].snaga,n[i].cijena);
			brojac++;
		}
	}
	if(brojac==0)
	{
		printf("Pretrazivanje nije dalo rezultata\n");
	}
	system("pause");
	return 0;
}