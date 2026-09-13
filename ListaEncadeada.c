#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	
	No *ini;
	
	inicializaLista(&ini);

	printf("0 - ");
	insereInicio(&ini, 68);
	insereFim(&ini, 75);
	insereFim(&ini, 125);
	insereMeio(&ini, 91, 3);
	imprimeLista(ini);	
	
	
	
	return 0;
}

