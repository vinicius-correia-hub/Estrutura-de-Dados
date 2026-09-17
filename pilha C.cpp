#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
}No;

void inicializaPilha(No **p_inicio){
	*p_inicio = NULL;
}

void inserePilha(No **p_inicio, int info){
	
	No *novo_no = (No*) malloc (sizeof(No));
	
	if(novo_no == NULL){
		printf("Erro ao inicializar o no!");
		return;
	}
	
	novo_no -> dado = info;	
	
	if(*p_inicio == NULL){
		*p_inicio = novo_no;
		novo_no -> prox = NULL;
		return;
	}
	
	if(*p_inicio != NULL){
		novo_no -> prox = *p_inicio;
		*p_inicio = novo_no;
		return;
	}
}


void imprimeLista(No **p_inicio){
	No *aux = *p_inicio;
	while (aux != NULL){
		printf("%d ", aux->dado);
		aux = aux -> prox;
	}
	printf("\n\n");
}

void removePilhaPrimeiroElemento(No **p_inicio){
	No *aux = *p_inicio;
	*p_inicio = aux -> prox;
	free(aux);
}

int main(){
	
	No *ini;
	inicializaPilha(&ini);
	inserePilha(&ini, 10);
	inserePilha(&ini, 50);
	inserePilha(&ini, 60);
	inserePilha(&ini, 40);
	imprimeLista(&ini);
	removePilhaPrimeiroElemento(&ini);
	imprimeLista(&ini);
	
	
	return 0;
	
}
