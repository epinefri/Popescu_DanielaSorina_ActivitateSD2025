#include<stdio.h>
#include<stdlib.h>

// Definire structura Telefon
struct Telefon {
	int id;
	int RAM;
	char* producator;
	float pret;
	char serie;
};

// Functie de initializare
struct Telefon initializare(int id, int ram, const char* producator, float pret, char serie) {
	struct Telefon t;
	t.id = id;
	t.RAM = ram;
	t.producator = (char*)malloc(sizeof(char) * (strlen(producator) + 1));
		//malloc returneaza void*, e necesar cast explicit ca char*
		//strlen +1, pt a include caracterul \0 (sfarsit de sir de caractere)
	strcpy_s(t.producator, strlen(producator)+1, producator); 
		//strcpy_s(destinatia, nr de caract de copiat, sursa) 
	t.pret = pret;
	t.serie = serie;
	return t;
}

void afisare(struct Telefon t) {
	if (t.producator != NULL)
		printf("%d. Telefonul %s seria %c are %d GB RAM si costa %5.2f RON\n", t.id, t.producator, t.serie, t.RAM, t.pret);
	else
		printf("%d. Telefonul seria %c are %d GB RAM si costa %5.2f RON\n", t.id, t.serie, t.RAM, t.pret);

}

// Functie de modificare a unui atribut
void modificaPret(struct Telefon* t, float pretNou) { // pointer catre structura Telefon
	if (pretNou>0)
		t->pret = pretNou; // sau (*t).pret = pretNou; 
}

	// Functie pt dezalocare campuri alocate dinamic
void dezalocare(struct Telefon* t) {
	if (t->producator != NULL) {
		free(t->producator);
		t->producator = NULL;
	}
}

int main() {
	struct Telefon t;
	t = initializare(1, 256, "Samsung", 2000.5, 'A');
		// "sir de caractere", 'c' (singur caracter)
	afisare(t);
	modificaPret(&t, 1000); // transmiterea parametrului prin adresa
	afisare(t);
	dezalocare(&t);
	afisare(t);
	return 0;
}