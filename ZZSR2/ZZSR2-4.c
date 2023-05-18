/*4. Napisati program koji definira strukturu za zapis podataka o sportovima: naziv sporta,
broj igrača u terenu, trajanje utakmice. Program inicijalizira podatke za 10 sportova i
ispisuje ih sortirane po broju igrača u terenu (silazno), odnosno po trajanju utakmice
(uzlazno) ako je broj igrača isti.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct sport
{
	char naziv[20];
	int broj_igraca;
	int trajanje;
	
};
int main(){
	int pom;
		   struct sport pom_sport, n[10]={{"Nogomet",22,90},
									{"Kosarka",10,48},
									{"Rukomet",12,60},
									{"Odbojka",12,90},
									{"Americki nogomet",22,60},
									{"Tenis",2,40},
									{"Sah",2,60},
									{"Stolni tenis",2,40},
									{"Vaterpolo",14,20},
									{"Boks",2,12}};
	for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(n[j].broj_igraca>n[i].broj_igraca)
			{
				pom_sport=n[i];
				n[i]=n[j];
				n[j]=pom_sport;
			}
			else if(n[j].broj_igraca==n[i].broj_igraca)
			{
			if(n[j].trajanje>n[i].trajanje)
			{
				pom_sport=n[i];
				n[i]=n[j];
				n[j]=pom_sport;
			}	
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		printf("%s- %d, %d\n",n[i].naziv,n[i].broj_igraca,n[i].trajanje);
	}
	
	system("pause");
	return 0;
}