/*5. Napisati program koji iz datoteke rijeke.txt čita podatke o svim rijekama zapisanima u
datoteci: naziv rijeke (string - pretpostaviti da se radi o jednoj riječi), izvor (string -
pretpostaviti da se radi o jednoj riječi), ušće (string - pretpostaviti da se radi o jednoj
riječi), duljina rijeke u kilometrima (float) i svi se podaci smještaju u dinamički alociran
memorijski prostor odgovarajuće duljine Nakon toga ispisuju se podaci o rijekama čiji je
izvor ili ušće u Bosni i Hercegovini, sortirane po duljini rijeke silazno. Profiling*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct rijeke{
	char *naziv;
	char *izvor;
	char *usce;
	float *duljina;
};
int main(){
	struct rijeke *p=NULL;
	struct rijeke pom;
	int i=0;
	char naziv_[32],izvor_[32],usce_[32];
	float duljina_;
	FILE *dat=fopen("5.rijeke.txt","r");
	do
	{
		if(i==0)
		{
			p=(struct rijeke*)malloc(sizeof(struct rijeke));
			fscanf(dat,"%s %s %s %f",&naziv_,&izvor_,&usce_,&duljina_);
			(p+i)->naziv=(char*)malloc(sizeof(char)*(strlen(naziv_)+1));
			(p+i)->izvor=(char*)malloc(sizeof(char)*(strlen(izvor_)+1));
			(p+i)->usce=(char*)malloc(sizeof(char)*(strlen(usce_)+1));
			(p+i)->duljina=(float*)malloc(sizeof(float));
			strcpy((p+i)->naziv,naziv_);
			strcpy((p+i)->izvor,izvor_);
			strcpy((p+i)->usce,usce_);
			*(p+i)->duljina=duljina_;
			i++;
		}
		else
		{
			p=(struct rijeke*)realloc(p,sizeof(struct rijeke));
			fscanf(dat,"%s %s %s %f",&naziv_,&izvor_,&usce_,&duljina_);
			(p+i)->naziv=(char*)malloc(sizeof(char)*(strlen(naziv_)+1));
			(p+i)->izvor=(char*)malloc(sizeof(char)*(strlen(izvor_)+1));
			(p+i)->usce=(char*)malloc(sizeof(char)*(strlen(usce_)+1));
			(p+i)->duljina=(float*)malloc(sizeof(float));
			strcpy((p+i)->naziv,naziv_);
			strcpy((p+i)->izvor,izvor_);
			strcpy((p+i)->usce,usce_);
			*(p+i)->duljina=duljina_;	
			i++;
		}
	}while(!feof(dat));
	fclose(dat);
	for(int j=0;j<i-1;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if((*(p+k)->duljina)>(*(p+j)->duljina))
			{
				pom=*(p+k);	
				*(p+k)=*(p+j);
				*(p+j)=pom;
			}
		}
	}
	for(int j=0;j<i;j++)
	{
		if((strcmp((p+j)->usce,"BiH")==0) || (strcmp((p+j)->izvor,"BiH")==0))
		printf("%s\n%s\n%s\n%f\n",(p+j)->naziv,(p+j)->izvor,(p+j)->usce,*(p+j)->duljina);
	}
	free(p);
	system("pause");
	return 0;
}