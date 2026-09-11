#include <stdio.h>
#include <stdlib.h>

typedef struct no_ls{
    int info;
    struct no_ls *prox;
} Tno_ls;

typedef struct descritor_ls{
    int tam;
    struct no_ls *prim;
    struct no_ls *ult;
} TFila;

void inicializaFila(TFila *descritor){
    descritor->prim = NULL;
    descritor->ult = NULL;
    descritor->tam = 0;
}

void insereElemento(TFila *descritor, int dado){
    Tno_ls *novo_no;
    novo_no = (Tno_ls *) malloc (sizeof(Tno_ls));
    
    if (novo_no == NULL){
    	printf("Falha!");
    	return;
	}
    
    novo_no -> info = dado;
    novo_no -> prox = NULL;
    descritor->tam++;

    if (descritor->prim == NULL){
        descritor->prim = novo_no;
        descritor->ult = novo_no;
    }else{
         descritor->ult->prox = novo_no;
         descritor->ult = novo_no;
    }
}

int removeElemento (TFila *descritor){
	Tno_ls *aux;
	int elemento = descritor->prim->info;
	aux = descritor->prim;
	descritor->prim = aux->prox;
	free(aux);
	descritor->tam--;
	return elemento;
}


void imprimeFila(TFila *descritor){
	
	Tno_ls *aux;
	aux = descritor->prim;
	
	do{
		printf("%d ", aux->info);
		aux = aux->prox;
	}while((aux!=NULL));
	

}


int main(){
    TFila *descritor;

    descritor = (TFila *) malloc (sizeof(TFila));
    
	
	
    inicializaFila(descritor);
    insereElemento(descritor, 10);
    insereElemento(descritor, 23);
    insereElemento(descritor, 15);
    insereElemento(descritor, 45);
    insereElemento(descritor, 78);
    imprimeFila(descritor);
    //int retorno = removeElemento(descritor);
    
    
    
    printf("\nPrimeiro elemento: %d", descritor->prim->info);
    printf("\nUltimo elemento: %d", descritor->ult->info);
    printf("\nQuantidade de elementos na fila: %d", descritor->tam);
    //printf("\nElemento removido: %d", retorno);
    

	return 0;
}
