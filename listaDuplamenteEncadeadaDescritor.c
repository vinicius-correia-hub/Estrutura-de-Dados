#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
    struct no *ant;
}No;

typedef struct descritor{
    int tam;
    struct no *inicio;
    struct no *fim;
}Descritor;

void inicializaLista(Descritor *desc){
    desc -> tam = 0;
    desc -> inicio = NULL;
    desc -> fim = NULL;
}

void insereInicio(Descritor *desc, int info){

    No *novo_no = (No*) malloc (sizeof(No));

    if(novo_no == NULL){
        printf("Erro ao alocar o no");
        return;
    }

    novo_no -> dado = info;

    if(desc -> tam == 0){
        desc -> inicio = novo_no;
        desc -> fim = novo_no;
        novo_no -> ant = NULL;
        novo_no -> prox = NULL;
    }else {
        novo_no -> ant = NULL;
        novo_no -> prox = desc -> inicio;
        (desc -> inicio) -> ant = novo_no;
        desc -> inicio = novo_no;
    }

    desc -> tam++;

}

void insereFim(Descritor *desc, int info){
    if (desc -> tam == 0){
        insereInicio(desc, info);
        return;
    }

    No *novo_no = (No*) malloc (sizeof(No));

    if(novo_no == NULL){
        printf("Erro ao alocar");
        return ;
    }

    novo_no -> dado = info;

    novo_no -> prox = NULL;
    novo_no -> ant = desc -> fim;
    (desc -> fim) -> prox = novo_no;
    desc -> fim = novo_no;

    desc -> tam++;
    
}

void imprimeLista(Descritor *desc){
    No *aux = desc -> inicio;
    while(aux != NULL){
        printf("%d ", aux -> dado);
        aux = aux -> prox;
    }

    printf("Quantidade de elementos na lista: %d", desc -> tam);
}

void imprimeListaInvertida(Descritor *desc){
    No *aux = desc -> fim;

    printf("\n");

    while(aux != NULL){
        printf("%d ", aux -> dado);
        aux = aux -> ant;
    }
}


void removeElemento(Descritor *desc, int posicao){
    if(desc -> tam == 0){
        printf("Lista está vazia!");
        return;
    }

    if(posicao < 1 || posicao > desc -> tam){
        printf("Posicao inserida é invalida!");
        return;
    }

    No *aux = NULL;   

    if(posicao == 1 && desc -> tam == 1){
        aux = desc -> inicio;
        desc -> inicio = NULL;
        desc -> fim = NULL;
        free(aux);
        desc -> tam--;
    }else{
        if(posicao == 1){
            aux = desc -> inicio;
            (aux -> prox) -> ant = NULL;
            desc -> inicio = aux -> prox;
            free(aux);
            desc -> tam--;
        }
        else if(posicao == desc -> tam){
            aux = desc -> fim;
            desc -> fim = (desc -> fim) -> ant;
            (desc -> fim) -> prox = NULL;
            free(aux);
            desc -> tam--;
        }
        else{
            int cont = 0;
            //verificação se o inicio da varredura 
            //deveria começar pelo fim da lista ou pelo inicio.            
            if ((posicao - 1) >= (desc -> tam - posicao)){
                aux = desc -> fim;
                cont = desc -> tam;
                while(aux != NULL){
                    if(posicao == cont){
                        (aux -> prox) -> ant = aux -> ant;
                        (aux -> ant) -> prox = aux -> prox;
                        free(aux);
                        desc -> tam--;
                        return;
                    }
                    aux = aux -> ant;
                    cont--;
                }
            } else{
                aux = desc -> inicio;
                cont = 1;
                while(aux != NULL){
                    if(posicao == cont){
                        (aux -> prox) -> ant = aux -> ant;
                        (aux -> ant) -> prox = aux -> prox;
                        free(aux);
                        desc -> tam--;
                        return;
                    }
                    aux = aux -> prox;
                    cont++;
                }
            }
        }
    }

}


int main(){
    Descritor descritor;
    inicializaLista(&descritor);


    insereInicio(&descritor, 90);
    insereInicio(&descritor, 100);
    insereFim(&descritor, 80);
    imprimeLista(&descritor);
    imprimeListaInvertida(&descritor);

    return 0;
}