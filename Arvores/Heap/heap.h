#ifndef __HEAP__
#define __HEAP_H__

#include <stdlib.h>
#include <stdio.h>

//Comprimento maximo do meu vetor
#define comprimento 99999

typedef struct heap heap;

struct heap
{
	int tamanho;
	int vetor[comprimento];
	int id;
	int chave;
};

// Todas as funções que seram usadas no no meu heap.c

int Pai(int id);
int Direito(int id);
int Esquerdo(int id);
void Exibir_Heap(heap *H);
void Troca(heap *H, int a, int b);
void Max_Heapify(heap *H, int id);
void Buil_Max_Heap(heap *H);
void Max_Heap_Insertion(heap *H, int chave);
void HeapSort(heap *H);
int Heap_Maximo(heap *H);
int Heap_Extract_Max(heap *H);
void Heap_Increase_Key(heap *H, int id, int chave);

#endif //__HEAP_H__ 