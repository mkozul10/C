/*5. Napisati program koji definira strukturu za zapis podataka o automobilima: proizvođač
(string), model (string), snaga motora (int) i cijena (float). Dinamički se alocira memorija
za niz od 10 automobila i unose se podaci o automobilima, te se sortiraju po
proizvođaču, odnosno modelu (ako je proizvođač isti). Unosi se dodatni realan broj i
ispisuju podaci o automobilima čija je cijena manja od dodatnog broja. Koristiti
isključivo sintaksu pokazivača.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct automobili{
	char *proizvodjac;
	char *model;
	int *snaga;
	double *cijena;
};
int main(){
	char pom_unos[100];
	struct automobili *p=NULL,*pP=NULL;
	double *dodatna_cijena=NULL;
	p=(struct automobili*)malloc(sizeof(struct automobili)*3);
	printf("Unos:\n");
	for(int i=0;i<3;i++)
	{
		printf("Unos proizvodjaca za %d. automobil: ",i+1);
		fflush(stdin);
		gets(pom_unos);
		(p+i)->proizvodjac=(char*)malloc(sizeof(char)*strlen(pom_unos+1));
		strcpy((p+i)->proizvodjac,pom_unos);
		printf("Unos modela za %d. automobil: ",i+1);
		fflush(stdin);
		gets(pom_unos);
		(p+i)->model=(char*)malloc(sizeof(char)*strlen(pom_unos+1));
		strcpy((p+i)->model,pom_unos);
		printf("Unos snage za %d. automobil: ",i+1);
		(p+i)->snaga=(int*)malloc(sizeof(int));
		scanf_s("%d",&(p+i)->snaga);
		printf("Unos cijene za %d. automobil: ",i+1);
		(p+i)->cijena=(double*)malloc(sizeof(double));
		scanf_s("%lf",&(p+i)->cijena);		
	}
	printf("Unesi dodatnu cijenu: ");
	dodatna_cijena=(double*)malloc(sizeof(double));
	scanf_s("%lf",&dodatna_cijena);
	pP=(struct automobili*)malloc(sizeof(struct automobili));
	for(int i=0;i<2;i++)
	{
		for(int j=i+1;j<3;j++)
		{
			if(strcmp((p+j)->proizvodjac,(p+i)->proizvodjac)<0)
			{
				*pP=*(p+j);
				*(p+j)=*(p+i);
				*(p+i)=*pP;
			}
			if(strcmp((p+j)->proizvodjac,(p+i)->proizvodjac)==0)
			{
				if(strcmp((p+j)->model,(p+i)->model)<0)
				*pP=*(p+j);
				*(p+j)=*(p+i);
				*(p+i)=*pP;				
			}
		}
	}
	printf("Automobili sa cijenom manjom od %lf:\n",dodatna_cijena);
	printf("\n");
	for(int i=0;i<3;i++)
	{
			if((p+i)->cijena<=dodatna_cijena)
			{
				printf("%-15s\t%10s\t%5d\t%.3lf\n",(p+i)->proizvodjac,(p+i)->model,(p+i)->snaga,(p+i)->cijena);
			}
			
	}	
	system("pause");
	return 0;
}