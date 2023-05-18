/*3. Napisati program koji unosi reèenicu i na osnovu nje formira niz cijelih brojeva tako da
èlanovi niza predstavljaju ASCII kodove znakova unesene reèenice.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char recenica[32];
	int i=0;
	int j=0;
	int k;
	int recenica_ascii[32];
	puts("Unesi recenicu");
	gets(recenica);
	/*65-90=A-Z*/
	/*97-122=a-z*/
    while(recenica[i])
    {
    recenica_ascii[j]=recenica[i++];
    j++;
    }
    printf("Ascii kod karaktera u recenici su:\n");
    for(k=0;k<j;k++)
    {
    	printf("%d\n",recenica_ascii[k]);
	}
		
	system("pause");
	return 0;
}
