/*5. Napisati program koji iz datoteke drzave.txt čita podatke o svim državama zapisanima u
datoteci: naziv države (string - pretpostaviti da se radi o jednoj riječi), glavni grad (string -
pretpostaviti da se radi o jednoj riječi), kontinent (string - pretpostaviti da se radi o
jednoj riječi), površina države u kvadratnim kilometrima (int) i broj stanovnika (int).
Nakon toga ispisuju se podaci o europskim državama sa više od 5.000.000 stanovnika
sortirani bo površini države silazno.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct drzave{
	char naziv[32];
	char gl_grad[32];
	char kontinent[32];
	int povrsina;
	int br_stan;
};
int main(){
	struct drzave p[100],pom;
	int br=0;
	FILE *dat;
	dat=fopen("5.drzave.txt","r");
	while(!feof(dat))
	{
		fscanf(dat,"%s %s %s %d %d",p[br].naziv,p[br].gl_grad,p[br].kontinent,&p[br].povrsina,&p[br].br_stan);
		br++;
	}
	fclose(dat);
	for(int i=0;i<br-1;i++)
	{
		for(int j=i+1;j<br;j++)
		{
			if(p[j].povrsina>p[i].povrsina)
			{
				pom=p[i];
				p[i]=p[j];
				p[j]=pom;
			}
		}
	}
	printf("Podaci o europskim drzavama sa više od 5.000.000 stanovnika sortirani bo povrsini drzave silazno:\n\n");
	for(int i=0;i<br;i++)
	{
		if((p[i].br_stan>5000000) && (strcmp(p[i].kontinent,"Europa")==0))
		printf("%-10s\t%7s\t%7s\t%8d\t%8d\n",p[i].naziv,p[i].gl_grad,p[i].kontinent,p[i].povrsina,p[i].br_stan);
	}
	system("pause");
	return 0;
}