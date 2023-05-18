/*1. Napisati program koji definira strukturu za zapis podataka o kompleksnim brojevima:
realni i imaginarni dio (float), unosi podatke za dva kompleksna broja i u posebnim
funkcijama računa njihov zbroj, razliku, umnožak i količnik (sve funkcije imaju dva
kompleksna broja kao ulazne parametre i vraćaju kompleksni broj koji predstavlja
rezultat računske operacije). Svi rezultati se ispisuju u glavnom programu.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct kompleksni
	{
		float realni;
		float imaginarni;
	};
struct kompleksni zbroj(struct kompleksni z1, struct kompleksni z2);
struct kompleksni razlika(struct kompleksni z1, struct kompleksni z2);
struct kompleksni umnozak(struct kompleksni z1, struct kompleksni z2);
struct kompleksni kolicnik(struct kompleksni z1, struct kompleksni z2);
struct kompleksni rez;
int main(){	
  struct kompleksni z1, z2,rez2;
    puts("Unesi prvi kompleksni broj:");
    printf(" - realni dio: ");
    fflush(stdin);
    scanf("%f", &z1.realni);
    printf(" - imaginarni dio: ");
    scanf("%f", &z1.imaginarni);   

    puts("Unesi drugi kompleksni broj:");
    printf(" - realni dio: ");
    fflush(stdin);
    scanf("%f", &z2.realni);
    printf(" - imaginarni dio: ");
    scanf("%f", &z2.imaginarni);
	/*ispis*/ 
	printf("Rezultati operacija zbrajanja, oduzimanja, mnozenja i djeljenja su:\n");
	rez2=zbroj(z1,z2);
	printf("z=%.2f + %.2fi\n",rez2.realni,rez2.imaginarni);
	rez2=razlika(z1,z2);
	printf("z=%.2f - %.2fi\n",rez2.realni,rez2.imaginarni);
	rez2=umnozak(z1,z2);
	printf("z=%.2f * %.2fi\n",rez2.realni,rez2.imaginarni);
	rez2=kolicnik(z1,z2);
	printf("z=%.2f / %.2fi\n",rez2.realni,rez2.imaginarni);
	system("pause");
	return 0;
}
struct kompleksni zbroj(struct kompleksni z1, struct kompleksni z2)
{
    rez.realni=z1.realni+z2.realni;
    rez.imaginarni=z1.imaginarni+z2.imaginarni;
    return rez;
    
}
struct kompleksni razlika(struct kompleksni z1, struct kompleksni z2)
{
	rez.realni=z1.realni-z2.realni;
    rez.imaginarni=z1.imaginarni-z2.imaginarni;
    return rez;
}
struct kompleksni umnozak(struct kompleksni z1, struct kompleksni z2)
{
	rez.realni=z1.realni*z2.realni;
    rez.imaginarni=z1.imaginarni*z2.imaginarni;
    return rez;
}
struct kompleksni kolicnik(struct kompleksni z1, struct kompleksni z2)
{
	rez.realni=z1.realni/z2.realni;
    rez.imaginarni=z1.imaginarni/z2.imaginarni;
    return rez;
}


