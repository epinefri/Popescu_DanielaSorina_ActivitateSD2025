#include <stdio.h>

int main() {
	printf("Introduceti un nr real: ");
	float var = 0;
	scanf_s("%f", &var);
	printf("Nr introdus este: %5.2f", var);
}