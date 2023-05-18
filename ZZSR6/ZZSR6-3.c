/*3. Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
dio (float) i iz datoteke kompleksni_brojevi.txt čita podatke za 10 kompleksnih brojeva i
smješta ih u dinamički alociran memorijski prostor odgovarajuće duljine. Nakon toga
unosi se dodatni kompleksni broj i ispisuje onaj od učitanih kompleksnih brojeva koji je
od dodatnog broja najudaljeniji u kompleksnoj ravnini.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double racun(double broj1,double broj2);
struct kompleksni{
	double realni;
	double imaginarni;
};
int main(){
	struct kompleksni *b=NULL,pom;
	b=(struct kompleksni*)malloc(sizeof(struct kompleksni)*10);
	double dodatni_r,dodatni_i,pozicija_dodatnog,pozicija_trenutnog,pozicija_sljedeceg,rez1,rez2;
	FILE *dat;
	int i=0;
	dat=fopen("3.kompleksni_brojevi.txt","r");
	while(!feof(dat))
	{
		fscanf(dat,"%lf %lf",(b+i)->realni,(b+i)->imaginarni);
	}
	fclose(dat);
	printf("Unesi dodatni imaginarni broj:\n");
	scanf_s("%lf",&dodatni_r);
	scanf_s("%lf",&dodatni_i);
	pozicija_dodatnog=sqrt((dodatni_r*dodatni_r)+(dodatni_i*dodatni_i));
	for(int j=0;j<9;j++)
	{
		
		rez1=racun((*(b+j)->realni),(*(b+j)->imaginarni));
		rez2=racun(*(b+(j+1))->realni,*(b+(j+1))->imaginarni);
		rez1=rez1-pozicija_dodatnog;
		rez2=rez2-pozicija_dodatnog;
		if(rez1>rez2)
		{
			pom.realni=*(b+j)->realni;
			pom.imaginarni=*(b+j)->imaginarni;
		}
		else if(rez1<rez2)
		{
			pom.realni=*(b+(j+1))->realni;
			pom.imaginarni=*(b+(j+1))->imaginarni;
		}
	}
	printf("Kompleksni broj najudaljeniji od dodatnog je: Z=(%.2lf)+(%.2lf)i\n",pom.realni,pom.imaginarni);
	free(b);
	system("pause");
	return 0;
}
double racun(double broj1,double broj2){
	float rez;
	rez=sqrt((broj1*broj1)+(broj2*broj2));
	return rez;
}