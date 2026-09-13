#ifndef funcoes_h
#define funcoes_h

typedef struct no{
		int dado;
		struct no *prox;
	}No;

void inicializaLista(No **p_inicio);
void insereInicio(No **p_inicio, int info);
void insereMeio(No **p_inicio, int info, int pos);
void insereFim(No **p_inicio, int info);
void imprimeLista(No *p_inicio);


#endif