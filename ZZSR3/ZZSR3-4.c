#include <stdio.h>
#include <string.h>
/*
4. Napisati program koji definira strukturu za zapis podataka o gradovima: ime grada
(string), država u kojoj se nalazi (string), broj stanovnika (int), najbliža rijeka (string) i
najbliža planina (string). Program inicijalizira podatke za 10 gradova, unosi ime rijeke i
planine i pronalazi onaj grad kojima je to najbliža rijeka, odnosno planina (po jedan grad
za svaki zemljopisni pojam), a ako ima više takvih gradova ispisuje se onaj koji ima
najveći broj stanovnika. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata
u glavnom programu.
*/

struct grad {
	char ime[30];
	char drzava[30];
	int br_stanovnika;
	char nb_rijeka[30];
	char nb_planina[30];
};
int grad_rijeka(char *string, struct grad *strukt_unos);
int grad_planina(char *string, struct grad *strukt_unos);
int main() {
	struct grad g[10] = {
		{"Mostar", "Bosna i Hercegovina", 105797, "Neretva", "Velez"},
		{"Sarajevo", "Bosna i Hercegovina", 275524, "Miljacka", "Bjelasnica"},
		{"Banja Luka", "Bosna i Hercegovina", 185042, "Vrbas", "Cemernica"},
		{"Zagreb", "Rebuplika Hrvatska", 770000, "Sava", "Medvednica"},
		{"Beograd", "Reupublika Srbija", 1250000, "Dunav", "Kosmaj"},
		{"Bec", "Republika Austrija", 1800000, "Dunav", "Alpe"},
		{"Bratislava", "Slovacka Republika", 460000, "Dunav", "Karpati"},
		{"Zurich", "Svicarska", 404783, "Limmat", "Zugerberg"},
		{"Split", "Republika Hrvatska", 342000, "Jadro","Mosor"},
		{"Nis", "Republika Srbija", 260237, "Nisava", "Suva planina"},
	};
	char unos_rijeka[30];
	char unos_planina[30];
	int j;
	printf("Unesi rijeku: ");
	gets(unos_rijeka);
	printf("Unesi planinu: ");
	gets(unos_planina);
	j = grad_rijeka(unos_rijeka, g);
	printf("Grad blizu rijeke %s:\n", unos_rijeka);
	printf("Ime grada: %s\nDrzava: %s\nBroj stanovnika: %d\nNajbliza rijeka tom gradu: %s\nNajbliza planina tom gradu: %s\n", g[j].ime, g[j].drzava, g[j].br_stanovnika, g[j].nb_rijeka, g[j].nb_planina);
	j = grad_planina(unos_planina, g);
	printf("Grad blizu planine %s:\n", unos_planina);
	printf("Ime grada: %s\nDrzava: %s\nBroj stanovnika: %d\nNajbliza rijeka tom gradu: %s\nNajbliza planina tom gradu: %s\n", g[j].ime, g[j].drzava, g[j].br_stanovnika, g[j].nb_rijeka, g[j].nb_planina);
	return 0;
}
int grad_rijeka(char *string, struct grad *strukt_unos) {
	int i, j;
	int broj_stanovnika = 0;
	for (i = 0; i < 10; i++) {
		if ((strcmp(strukt_unos[i].nb_rijeka, string) == 0) && (strukt_unos[i].br_stanovnika > broj_stanovnika)) {
			j = i;
			broj_stanovnika = strukt_unos[i].br_stanovnika;
		}
	}
	return j;
}
int grad_planina(char* string, struct grad* strukt_unos) {
	int i, j;
	int broj_stanovnika = 0;
	for (i = 0; i < 10; i++) {
		if ((strcmp(strukt_unos[i].nb_planina, string) == 0) && (strukt_unos[i].br_stanovnika > broj_stanovnika)) {
			j = i;
			broj_stanovnika = strukt_unos[i].br_stanovnika;
		}
	}
	return j;
}