#include<stdlib.h>
#include<stdio.h>
#include"Floyd-Warshall.h"
#ifndef __HEAP__
#define __HEAP_H__

#define comp 99999

typedef struct heap{
	int tam;
	ListaAux* vetor[comp]; //A HEAP ira conter um vetor de listas auxiliares, que representam informacoes para o algoritomo de Prim e	 Djkistra
}Heap;


int pai(int i);
int direito(int i);
int esquerdo(int i);
void heap_print(Heap* A);
void trocar(Heap* A, int a, int b);
void min_heapify(Heap* A, int i);
void build_min_heap(Heap* A);
void min_heap_insert(Heap* A, ListaAux* node);
ListaAux* heap_minimo(Heap* A);
ListaAux* heap_extract_min(Heap* A);
void heap_increase_key(Heap* A, int i, int chave);
int heap_vazia(Heap* heap);

#endif //__HEAP__ 