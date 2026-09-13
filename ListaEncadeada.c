#include <stdio.h>
#include <stdlib.h>

typedef struct no{
		int dado;
		struct no *prox;
	}No;

void inicializaLista(No **p_inicio){
	*p_inicio = NULL;
}

void insereInicio(No **p_inicio, int info){
	No *novo_no = (No*) malloc (sizeof(No));
	
	if(novo_no == NULL){
		printf("Erro na aloca��o de memoria");
		return;
	}

	novo_no -> dado = info;

	novo_no->prox = *p_inicio;
	*p_inicio = novo_no;
}

void insereFim(No **p_inicio, int info){
	No *novo_no = (No*) malloc (sizeof(No));

	if(novo_no == NULL){
		printf("Erro de alocação!");
		return;
	}

	novo_no->dado = info;

	if(*p_inicio == NULL){
		printf("Lista vazia!");
		*p_inicio = novo_no;
	}
	
	novo_no->prox = NULL;
	No *percorre = *p_inicio;
	while(percorre->prox!=NULL){	
		percorre = percorre->prox;
	}

	percorre->prox = novo_no;
}

void insereMeio(No **p_inicio, int info, int pos){
	if(pos == 1){
		insereInicio(p_inicio, info);
		return;
	}	
		
	No *percorre = *p_inicio;
	int cont = 1;

	while(percorre != NULL){
		if(cont == pos - 1){
			No *novo_no = (No*) malloc(sizeof(No));
			if(novo_no == NULL){
				printf("Falha na alocação de memoria!");
				return;
			}
			novo_no -> dado = info;
			novo_no -> prox = percorre->prox;
			percorre -> prox = novo_no;
			return;
		}
		percorre = percorre->prox;
		cont++;
	}

	printf("Posição %d inválida para esta lista!", pos);
}



void imprimeLista(No *p_inicio){
	if(p_inicio == NULL){
		printf("Lista vazia!");
		return;
	}

	No *percorre = p_inicio;

	while(percorre!=NULL){
		printf("%d ", percorre->dado);
		percorre = percorre->prox;
	}

}

int main(){
	
	No *ini;
	
	inicializaLista(&ini);
	insereInicio(&ini, 68);
	insereFim(&ini, 75);
	insereFim(&ini, 125);
	insereMeio(&ini, 91, 3);
	imprimeLista(ini);	
	
	
	
	return 0;
}
