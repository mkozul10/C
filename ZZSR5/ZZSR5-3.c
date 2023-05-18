/*3. Napisati program koji definira strukturu za zapis kompleksnih brojeva: realni i imaginarni
dio (float), inicijalizira niz od 10 kompleksnih brojeva i u datoteku
kompleksni_brojevi.txt upisuju se sortirani po udaljenosti od ishodišta kompleksne
ravnine. */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float udaljenost(float br1,float br2);
struct kompleksni{
	float realni;
	float imaginarni;
};
int main(){
	float rez1,rez2;
	struct kompleksni pom,p[10]={{6.2,5.3},{7.4,8.9},{1.7,6.6},{2.4,5.8},{6.7,3.9},{4.6,1.5},{7.2,2.3},{2.1,0.9},{3.7,2.9},{9.2,5.4}};
	for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			rez1=udaljenost(p[i].realni,p[i].imaginarni);
			rez2=udaljenost(p[j].realni,p[j].imaginarni);
			if(rez2<rez1)
			{
				pom=p[j];
				p[j]=p[i];
				p[i]=pom;
			}
		}
	}
	FILE *dat=fopen("3.kompleksni_brojevi.txt","w");
	for(int i=0;i<10;i++)
	{
		fprintf(dat,"z=(%.2f)+(%.2f)i\tudaljenost=%.2f\n",p[i].realni,p[i].imaginarni,sqrt((p[i].realni*p[i].realni)+(p[i].imaginarni*p[i].imaginarni)));
	}
	printf("Podaci su uspjesno upisani u datoteku: 3.kompleksni_brojevi.txt\n");
	fclose(dat);
	system("pause");
	return 0;
}
float udaljenost(float br1,float br2){
	float udaljenost;
	udaljenost=sqrt((br1*br1)+(br2*br2));
	return udaljenost;
}