/*4. Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog
pohranjuje ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon što
su svi znakovi pročitani, ispisuje se onaj znak koji se ponovio najviše puta, kao i broj
njegovih ponavljanja. */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	FILE *fpointer;

	char *slova = NULL;
	int i=0,j = 0,br = 0;
	 int brojac,a,b=0;
	char max;
	slova = (char *)malloc(sizeof(char));
	
	
	fpointer = fopen("4.tekst.txt", "r");
	

		while (!feof(fpointer))
		{
			*(slova+i)=fgetc(fpointer);
			slova = (char *)realloc(slova,sizeof(char));
			i++;
			br++;
			
		}
	
	fclose(fpointer);
	
	for(i = 0;i<br;i++){
		brojac = 1;
		
		for(j=i+1;j<br;j++){
			if(*(slova+j) == *(slova + i)){
				brojac++;
		
			}
		}
		   if (a < brojac) {
            a = brojac;
            max = *(slova + i);


        }

	}
	
	printf("Slovo koje se najvise ponavlja: %c \nBroj ponavljanja:  %d",max,a);
	
	
	return 0;
}
