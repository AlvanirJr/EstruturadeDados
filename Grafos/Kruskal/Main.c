#include "Kruskal.c"
#include "Lista.h"


//Listaux

int main(){
	Grafo* grafo = CriarGrafo(false, true);
	InserirGrafo(grafo, 1, 2, 5);
	InserirGrafo(grafo, 1, 3, 4);
	InserirGrafo(grafo, 1, 4, 2);
	InserirGrafo(grafo, 1, 6, 6);
	InserirGrafo(grafo, 2, 4, 1);
	InserirGrafo(grafo, 2, 5, 7);
	InserirGrafo(grafo, 3, 5, 6);
	InserirGrafo(grafo, 4, 6, 1);	
	//InserirGrafo(grafo, 5, 6, 5);
	//InserirGrafo(grafo, 6, 7, 5);
	printf("\nGRAFO: \n");
	Imprimir(grafo);
	printf("\nKRUSKAL - ARVORE GERADORA MININA COM O GRAFO: \n");
	Kruskal(grafo);
}
