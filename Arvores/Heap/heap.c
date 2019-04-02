#include "heap.h"

// Mostra quem vai ser Pai e seus Filhos da esquerda e direita
int Pai(int id)
{
	return ((id+1)/2)-1;
}

int Direito(int id)
{
	return (2*(id+1));
}

int Esquerdo(int id)
{
	return (2*(id+1))-1;
}
// Mostrar os elementos do heap
void Exibir_Heap(heap *H)
{
	int i;
	for(i = 0; i < H->tamanho; i++)
	{
		printf("%d\n",H->vetor[i]);
	} 
}
// Funçao de troca
void Troca(heap *H, int a, int b)
{
	int temp;
	temp = H->vetor[a];
	H->vetor[a] = H->vetor[b];
	H->vetor[b] = temp;

}
//Montagem do heap, usando o indice
void Max_Heapify(heap *H, int id)
{
	int l, r, maior;
	l = Esquerdo(id);
	r = Direito(id);

	if(l <= H->tamanho && H->vetor[l] > H->vetor[id])
	{
		maior = l;
	}
	
	else
	{
		maior = id;
	}

	if(r <= H->tamanho && H->vetor[r] > H->vetor[maior])
	{
		maior = r;
	}

	if(maior != id)
	{
		Troca(H, id, maior );
		Max_Heapify(H, maior);
	}
}

void Buil_Max_Heap(heap *H)
{
	int i;
	int comprimeto = H->vetor[comprimeto];

	for(i = (comprimeto/2); i >= 0; i--)
	{
		Max_Heapify(H,i);
	}
	//Exibir_Heap(H);
	
}


// Ordençaõ atraves do algoritmo heap sort
void HeapSort(heap *H)
{	
	int i;
	int tamanho = H->tamanho;
	Buil_Max_Heap(H);
	H->tamanho = H->tamanho -1;
	for(i = H->tamanho ; i >= 0; i--)
	{
		Troca(H, 0, i);
		H->tamanho = H->tamanho -1;
		Max_Heapify(H, 0);
	}
	H->tamanho = tamanho;
	//Exibir_Heap(H);
}

//Retorna o maximo elemento do vetor
int Heap_Maximo(heap *H)
{

	return H->vetor[0];
}


int Heap_Extract_Max(heap *H)
{
	int max;
	if(H->tamanho < 1)
	{
		printf("HEAP UNDERFLOW\n");
	}
	max = H->vetor[0];
	//Troca(H, 1, H->tamanho);
	H->tamanho = H->tamanho -1;
	H->vetor[0] = H->vetor[H->tamanho];
	Max_Heapify(H, 0);
	return max;

}
//Verificação
void Heap_Increase_Key(heap *H, int id, int chave)
{
	if(chave < H->vetor[id])
	{
		printf("Chave menor que a antiga\n");
	}
	H->vetor[id] = chave;
	while(id > 0 && H->vetor[Pai(id)] < H->vetor[id])
	{
		Troca(H, id, Pai(id));
		id = Pai(id);
		//printf("HEAP KEY\n" );
	}
}
//insercao dos elementos

void Max_Heap_Insertion(heap *H, int chave)
{
	H->tamanho = H->tamanho+1;
	H->vetor[H->tamanho] = -99999;
	Heap_Increase_Key(H, H->tamanho-1, chave);
	//Exibir_Heap(H);
	//printf("\n");



}
