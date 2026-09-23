#include <stdio.h>
#include <stdlib.h>
#define elementos 1000

typedef struct pilha{
	int topo;
	int item[elementos];
}Pilha;

void inicializaPilha (Pilha *p){
	p->topo = -1;
}

void push(Pilha *p, int dado){	
	if((p->topo) >= (elementos-1)){
		printf("Erro ao inserir novo elemento: Overflow\n");
		return;
	}
	p->topo++;
	p->item[p->topo] = dado;
}

void pop(Pilha *p){
	if((p->topo) > - 1)
		p -> topo--;	
	else{
		printf("Erro ao remover elemento: Underflow");
		return;
	}
		
}

void imprimePilha(Pilha *p){
	if(p -> topo == -1){
		printf("Pilha vazia!");
		return;
	}
	for(int i = 0; i <= p -> topo; i++){
		printf("%d ", p->item[i]);
	}
}

void juntarPilhas(Pilha *p1, Pilha *p2, Pilha *p3){
	for (int i = 0; i <= p1->topo; i++){
		push(p3, p1->item[i]);
	}
	
	for (int i = 0; i <= p2->topo; i++){
		push(p3, p2->item[i]);
	}
}

void inverterPilha(Pilha *p1, Pilha *p2){
	int dado = 0;
	while(p1 -> topo != -1){
		dado = p1 -> item[p1->topo];
		pop(p1);
		push(p2, dado);
	}
}

int quantidadeElementos(Pilha *p){
	return p -> topo + 1;
}

int main (){
	
	Pilha p, p2, p3;
	inicializaPilha(&p);
	inicializaPilha(&p2);
	inicializaPilha(&p3);
	
	push(&p, 9);
	push(&p, 10);
	push(&p, 11);
	push(&p, 12);
	push(&p, 13);
	push(&p, 14);
	
	printf("Inicio");
	printf("Pilha 1: ");
	imprimePilha(&p);
	printf("\nPilha 2: ");
	imprimePilha(&p2);
	
	printf("\n\nInvertendo...");
	
	inverterPilha(&p, &p2);
	
	printf("\nApos a inversao:");
	printf("\nPilha 1: ");
	imprimePilha(&p);
	printf("\nPilha 2: ");
	imprimePilha(&p2);
	
	
	inicializaPilha(&p);
	inicializaPilha(&p2);
	inicializaPilha(&p3);
			
	push(&p, 9);
	push(&p, 10);
	push(&p, 11);
	push(&p, 12);
	push(&p, 13);
	push(&p, 14);
	
	
	push(&p2, 1);
	push(&p2, 2);
	push(&p2, 3);
	push(&p2, 4);	
	
	juntarPilhas(&p, &p2, &p3);
	
	printf("\n\n\nPilha 1: ");
	imprimePilha(&p);
	printf("\nQuantidade elementos: %d", quantidadeElementos(&p));
	
	printf("\n\n\nPilha 2: ");
	imprimePilha(&p2);
	printf("\nQuantidade elementos: %d", quantidadeElementos(&p2));
	
	printf("\n\n\nPilha 3: ");
	imprimePilha(&p3);
	printf("\nQuantidade elementos: %d", quantidadeElementos(&p3));
	
	
	/*pop(&p);
	pop(&p);
	pop(&p);
	pop(&p);
	pop(&p);
	pop(&p);
	pop(&p);*/


	return 0;
}

