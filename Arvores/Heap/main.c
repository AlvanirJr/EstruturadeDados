#include "heap.h"

void main()
{
	//Iniciar o Heap
	heap *inicio = (heap*)malloc(sizeof(heap));
	


	inicio->tamanho = 0;
	
	// Aqui onde é inserido todos os elemtentos da estrutura heap
	Max_Heap_Insertion(inicio ,-4);
	Max_Heap_Insertion(inicio ,-38);
	Max_Heap_Insertion(inicio ,-33);
	Max_Heap_Insertion(inicio ,21);
	Max_Heap_Insertion(inicio ,0);
	Max_Heap_Insertion(inicio ,18);
	Max_Heap_Insertion(inicio ,12);
	Max_Heap_Insertion(inicio ,10);
	Max_Heap_Insertion(inicio ,8);
	Max_Heap_Insertion(inicio ,5);
	Max_Heap_Insertion(inicio, 221);






	


	printf("Heap\n");
	Buil_Max_Heap(inicio);
	Exibir_Heap(inicio);
	


	
	printf("\n");
//Organização do heap de maximo
	printf("HEAP DE MAXIMO ORDENADO:\n");
	HeapSort(inicio);
	
	Exibir_Heap(inicio);
	



	}
