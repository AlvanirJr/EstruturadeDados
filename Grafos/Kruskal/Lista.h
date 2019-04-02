#ifndef __LISTA__
#define __LISTA__
#include <stdio.h>
#include <stdlib.h>

//Lista comum para representar as arestas do grafo, contendo dois vertices e peso.

typedef struct lista{
	int vertice1;
	int vertice2;
	int peso;
	struct lista* prox;
} Lista;

Lista* criarLista();
void bubbleSort(Lista* l);
Lista* inserirLista(Lista* l, int vertice1, int vertice2, int peso);


#endif // __LISTA_H__