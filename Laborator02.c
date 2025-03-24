#include<stdio.h>
#include<malloc.h>

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

// Afisarea elementelor din vector apeland functia afisare
void afisareVector(struct Telefon* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++) {
		afisare(vector[i]);
	}
}

// Copiere intr-un vector nou pe care il returneaza, a primelor nrElementeCopiate
struct Telefon* copiazaPrimeleNElemente(struct Telefon* vector, int nrElemente, int nrElementeCopiate) {
	struct Telefon *vectorNou=NULL;
	vectorNou = (struct Telefon*)malloc(sizeof(struct Telefon) * nrElementeCopiate);
	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = vector[i]; // shallow copy pt producator = se copiaza adresa
		//deep copy:
		vectorNou[i].producator = (char*)malloc(strlen(vector[i].producator) + 1);
		strcpy_s(vectorNou[i].producator, strlen(vector[i].producator) + 1, vector[i].producator);
	}
	return vectorNou;
}

void dezalocare(struct Telefon** vector, int* nrElemente) { // ** dublu pointer
	for (int i = 0; i < (*nrElemente); i++) {
		if ((*vector)[i].producator != NULL){
			free((*vector)[i].producator);
		}
	}
	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}

void copiazaAnumiteElemente(struct Telefon* vector, char nrElemente, float prag, struct Telefon** vectorNou, int* dimensiune) {
	//parametrul prag poate fi modificat in functie de 
	// tipul atributului ales pentru a indeplini o conditie
	//este creat un nou vector cu elementele care indeplinesc acea conditie
}

struct Telefon getPrimulElementConditionat(struct Telefon* vector, int nrElemente, const char* conditie) {
	//trebuie cautat elementul care indeplineste o conditie
	//dupa atributul de tip char*. Acesta este returnat.
	struct Telefon t;
	t.id = 1;

	return t;
}

int main() {
	// Declarare vector: decl un pointer + alocare memorie
	struct Telefon * vectTelefoane= NULL;
	int nrTelefoane = 3;
	vectTelefoane = (struct Telefon*)malloc(sizeof(struct Telefon)*nrTelefoane);
	vectTelefoane[0] = initializare(1, 256, "Samsung", 2000, 'A');
	vectTelefoane[1] = initializare(2, 512, "Motorola", 1500, 'E');
	vectTelefoane[2] = initializare(3, 256, "Apple", 2200, 'A');
	afisareVector(vectTelefoane, nrTelefoane);
	struct Telefon* primeleTelefoane = NULL;
	int nrPrimeleTelefoane = 2;
	
	primeleTelefoane = copiazaPrimeleNElemente(vectTelefoane, nrTelefoane, nrPrimeleTelefoane);
	printf("\n\nPrimele telefoane: \n");
	afisareVector(primeleTelefoane, nrPrimeleTelefoane);

	dezalocare(&primeleTelefoane, &nrPrimeleTelefoane);
	afisareVector(primeleTelefoane, nrPrimeleTelefoane);
	
	return 0;

}