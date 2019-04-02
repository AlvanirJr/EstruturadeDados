#include "Prim.h"
#include "Lista.c"
#include "Heap.c"


Grafo *CriarGrafo(int ponderado, int digrafo)
{
    Grafo *grafo = (Grafo*)malloc(sizeof(Grafo));
    //Lista de arestas
    Lista *arestas = (Lista*)malloc(sizeof(Lista));
    grafo->arestas = arestas;
    int i, j;
    for(i = 0; i < VERTMAX; i++){
        for(j = 0; j < VERTMAX; j++){
            grafo->matriz[i][j] = 0;
        }
    }
    grafo->digrafo = digrafo;
    grafo->ponderado = ponderado;

    
    return grafo;
}


void InserirGrafo(Grafo *grafo, int vertice1, int vertice2, int peso)
{
    grafo->arestas = inserirLista(grafo->arestas, vertice1, vertice2, peso);

    if(grafo->ponderado == true && grafo->digrafo == true)
    {
        grafo->matriz[vertice1][vertice2] = peso;
    }

    else if(grafo->ponderado == true && grafo->digrafo == false)
    {
        grafo->matriz[vertice1][vertice2] = peso;
        grafo->matriz[vertice2][vertice1] = peso;
    }

    else if(grafo->ponderado == false && grafo->digrafo == true)
    {
        grafo->matriz[vertice1][vertice2] = 1;
    }

    else if(grafo->ponderado == false && grafo->digrafo == false)
    {
        grafo->matriz[vertice1][vertice2] = 1;
        grafo->matriz[vertice2][vertice1] = 1;
    }
}



void Prim(Grafo *grafo, int v_inicial)
{
    bubbleSort(grafo->arestas);
    int i, escolha, peso;
    Heap *prioridade = (Heap*)malloc(sizeof(Heap));
    Lista *aux;
    ListaAux *geradora[VERTMAX];
    ListaAux *min;

    for(i = 0; i < VERTMAX; i++)
    {
        geradora[i] = (ListaAux*)malloc(sizeof(geradora));
        geradora[i]->vertice = i;
        geradora[i]->custo = 99999;
        geradora[i]->prev = -1;

        if(i == v_inicial)
        {
            geradora[i]->custo = 0;
        }
        min_heap_insert(prioridade, geradora[i]);
     }
     build_min_heap(prioridade);
     printf("Vertice inicial: [%d] \n", v_inicial);
     while(heap_vazia(prioridade) != 1)
     {
        min = heap_extract_min(prioridade);
        for(aux = grafo->arestas->prox; aux != NULL; aux = aux->prox)
        {
            if(aux->vertice1 == min->vertice)
            {
                escolha = aux->vertice2;
            }
            else if(aux->vertice2 == min->vertice)
            {
                escolha = aux->vertice1;

            }
            if(geradora[escolha]->custo > aux->peso)
            {
                geradora[escolha]->custo = aux->peso;
                geradora[escolha]->prev = min->vertice;
                build_min_heap(prioridade); 
                //printf("98");
            }
        }
     
     if(min->prev != -1)
     {  //printf("Peso\n");
        printf("Aresta entre o vértice [%d] e o vértice [%d] com peso: %d\n", min->vertice, min->prev, min-> custo);
		peso = peso + min->custo;	
     
     }
    }
     	printf("Peso total da arvore geradora minima por PRIM: %d\n", peso);

}


void Imprimir(Grafo *grafo)
{
    int i, j;

    for(i = 0; i < VERTMAX; i++)
    {
        for(j = 0; j < VERTMAX; j++)
        {
            if(grafo->matriz[i][j] != 0 && grafo->ponderado == false)
            {
                printf("VERTICES COM LIGAÇAO %d e %d \n",i,j);
            }
            else if(grafo->matriz[i][j] != 0 && grafo->ponderado == true)
            {
                printf("VERTICES COM LIGAÇAO: %d e %d, PESO DA ARESTA = %d \n",i,j,grafo->matriz[i][j]);
            }
        }
    }
}