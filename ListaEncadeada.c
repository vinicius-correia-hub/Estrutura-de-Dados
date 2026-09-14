#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	
	No *ini;
	int op = -1, valor, posicao, posicaoRemove;
	inicializaLista(&ini);

	// Inicialização preventiva
    //inicializaListas(&ini);

    do {
        printf("\n--- MENU ---\n");
        printf("0 - Inicializar lista\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no meio\n");
        printf("3 - Inserir no fim\n");
        printf("4 - Imprimir a lista\n");
		printf("5 - Remove da Lista\n");
        printf("10 - Sair\n");
        printf("Opção: ");
        scanf("%d", &op);

        switch (op) {
            case 0:
                inicializaLista(&ini);
                printf("Lista limpa/inicializada com sucesso!\n");
                break;
            
            case 1:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                insereInicio(&ini, valor);
                break;

            case 2:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                printf("Informe a posição: ");
                scanf("%d", &posicao);
                insereMeio(&ini, valor, posicao);
                break;

            case 3:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                insereFim(&ini, valor);
                break;

            case 4:
                printf("Lista atual: ");
                imprimeLista(ini); // Passa 'ini' sem '&' (ponteiro simples)
                break;

			case 5:
				printf("Informe a posicao que deseja remover: ");
				scanf("%d", &posicaoRemove);
				removeElemento(&ini, posicaoRemove);
				break;

            case 10:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (op != 10);	
	
	return 0;
}

