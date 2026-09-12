#include <stdio.h>

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
		printf("Erro na alocação de memoria");
		return;
	}
	
	novo_no -> dado = info;
	
	novo_no -> prox = *p_inicio;
	
	*p_inicio = novo_no;
}

void insereFim(No **p_inicio, int info){
	
}



int main(){
	
	No *ini;
	
	inicializaLista(&ini);
	
	
	
	
	return 0;
}
