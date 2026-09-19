#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox, *ant;
}No;

typedef struct descritor{
	int tam;
	struct no *prim;
	struct no *ult;
} Desc;


void inicializaLista(No **p_inicio){
	*p_inicio = NULL;
}

void insereInicio(No **p_inicio, int info){
	
	
	No *novo_no = (No*) malloc (sizeof(No));
	
	if(novo_no == NULL){
		printf("Erro ao criar o nó!");
		return;
	}
	
	novo_no -> dado = info;
	
	if (*p_inicio == NULL){
		*p_inicio = novo_no;
		novo_no -> prox = NULL;
		novo_no -> ant = NULL;
		return;
	}
	
	novo_no -> ant = NULL;
	novo_no -> prox = *p_inicio;
	(*p_inicio) -> ant = novo_no;
	*p_inicio = novo_no;
}

void insereMeio(No **p_inicio, int info, int posicao){
	
	if (*p_inicio == NULL){
		printf("Lista vazia!");
		return;
	}
	
	No *novo_no = (No*) malloc (sizeof(No));
	
	if(novo_no == NULL){
		printf("Falha ao criar o nó.");
		return;
	}
	
	novo_no -> dado = info;
	
	int cont = 1;
	
	No *aux = *p_inicio;
	
	while(aux != NULL){
		if(cont == posicao){
			novo_no -> ant = aux -> ant;
			novo_no -> prox = aux;
			(aux->ant) -> prox = novo_no;
			aux -> ant = novo_no;
			return;
		}
		aux = aux -> prox;
		cont++;
	}
	
}

void insereFim(No **p_inicio, int info){
	
	if(*p_inicio == NULL){
		insereInicio(p_inicio, info);
		return;
	}
	
	No *novo_no = (No*) malloc (sizeof(No));
	
	if(novo_no == NULL){
		printf("Erro ao criar nó.");
		return;
	}
	
	novo_no -> dado = info;
	
	No *aux = *p_inicio;
	
	while(aux != NULL){
		if(aux -> prox == NULL){
			aux -> prox = novo_no;
			novo_no -> ant = aux;
			novo_no -> prox = NULL;
			return;
		}
		aux = aux -> prox;
	}
	
}

void imprimeLista(No **p_inicio){
	
	if(*p_inicio == NULL){
		printf("Lista vazia!");
		return;
	}
	
	No *aux = *p_inicio;
	while(aux!=NULL){
		printf("%d ", aux -> dado);
		aux = aux -> prox;
	}
	
}

void imprimeListaInversa(No *p_inicio){
	
	if(p_inicio == NULL){
		printf("Lista vazia");
		return;
	}
	
	No *aux = p_inicio;
	
	while(aux -> prox != NULL){
		aux = aux -> prox;
	}
	
	while(aux != NULL){
		printf("%d ", aux -> dado);
		aux = aux -> ant;
		
	}
	
}


int main(){
	
	
	No *ini;
	inicializaLista(&ini);
	
	insereInicio(&ini, 50);
	
	insereInicio(&ini, 60);
	insereInicio(&ini, 70);
	insereInicio(&ini, 80);
	insereInicio(&ini, 90);
	insereFim(&ini, 100);
	insereMeio(&ini, 500, 2);
	imprimeLista(&ini);
	printf("\n");
	imprimeListaInversa(ini);
	
	
	
	return 0;
}
