#include "Heap.h"

int pai(int i){
	return ((i+1)/2)-1;
}

int direito(int i){
	return (2*(i+1));
}

int esquerdo(int i){
	return (2*(i+1))-1;
}


void build_min_heap(Heap* A){
	int i;
	for(i = (comp/2); i>=0;i--){
		min_heapify(A,i);
	}
}

void trocar(Heap* A, int a, int b){
	ListaAux* temp;
	temp = A->vetor[a];
	A->vetor[a] = A->vetor[b];
	A->vetor[b] = temp;
}

void min_heapify(Heap* A, int i){
	int l, r, menor;
	l = esquerdo(i);
	r = direito(i);
	if(l< A->tam && A->vetor[l]->custo < A->vetor[i]->custo){
		menor = l;
	}else{
		menor= i;
	}
	if(r< A->tam && A->vetor[r]->custo <A->vetor[menor]->custo){
		menor = r;
	}
	if(menor != i){
		trocar(A, i, menor);
		min_heapify(A, menor);
	}
}

void min_heap_insert(Heap* heap, ListaAux* node){ 
	heap->vetor[heap->tam] = node;
	heap->tam = heap->tam + 1;
}

ListaAux* heap_minimo(Heap* A){
	return A->vetor[0];
}

ListaAux* heap_extract_min(Heap* A){
	ListaAux* min;
	if(A->tam <=0){
		printf("HEAP UNDERFLOW");
	}
	min = A->vetor[0];
	A->tam = A->tam-1;
	A->vetor[0] = A->vetor[A->tam];
	min_heapify(A, 0);
	return min;
}

void heap_increase_key(Heap* A, int i, int chave){
	if(chave <A->vetor[i]->custo){
		printf("Nova chave eh menor que a chave atual");
	}else{
		A->vetor[i]->custo = chave;
		while(i>0 && A->vetor[pai(i)]->custo > A->vetor[i]->custo){
			trocar(A, i, pai(i));
			i = pai(i);
		}
	}
}

int heap_vazia(Heap* heap){
	if(heap->tam == 0){
		return 1;
	}
	return 0;
}

