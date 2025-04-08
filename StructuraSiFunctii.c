#include <stdio.h>
#include <stdlib.h>

// Se consideră prima literă din numele vostru, și prima literă din prenumele vostru.
// Sa se construiască un articol care să conțină cele două litere.

struct Pudra {
	int id;
	char* brand;
	int codNuanta;
	float pret;
};

// Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de
//	voi. Funcția returnează obiectul citit.
struct Pudra initializare(int id, char* brand, int codNuanta, float pret) {
	struct Pudra p;
	p.id = id;
	p.codNuanta = codNuanta;
	p.pret = pret;
	p.brand = (char*)malloc(sizeof(char) * (strlen(brand) + 1));
	strcpy_s(p.brand, (sizeof(char) * (strlen(brand) + 1)), brand);
	return p;
}


//	Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi. (o
//		medie sau o suma, un maxim, un minim...sau orice altceva)
float discount(struct Pudra p, float reducere) {
	float pretRedus = p.pret * (1-reducere);
	return pretRedus;
}


//	Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp.
//	noua valoare este primita ca parametru.
void modificaNuanta(struct Pudra* p, float nuantaNoua) {
	p->codNuanta = nuantaNoua;
}


//	Realizați o funcție care afișează un obiect de tipul creat.Afișarea se face la console, și sunt
//	afișate toate informațiile.
void afisare(struct Pudra p) {
	printf("Cod produs: %d \nBrand: %s \nCod nuanta: %d \nPret: %5.2f RON\n --------- \n", p.id, p.brand, p.codNuanta, p.pret);
}

int main() {
	struct Pudra p1, p2, p3;
	p1 = initializare(1, "Dior", 21, 459.99);
	p2 = initializare(2, "Chanel", 12, 320);
	p3 = initializare(3, "Guerlain", 22, 290);
	printf("Initial:\n --------- \n");
	afisare(p1);
	afisare(p2);
	afisare(p3);

	float reducere = 0.2;
	float pretRedus = discount(p1, reducere);
	printf("Dupa o reducere de %.1f%%, pudra cu cod produs 1 are pretul de %5.2f RON\n --------- \n", reducere*100, pretRedus);

	printf("Dupa modificare cod nuanta:\n --------- \n");
	int nuantaNoua = 40;
	modificaNuanta(&p1, nuantaNoua);
	afisare(p1);

	return 0;
}