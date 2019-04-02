#include "Kruskal.h"
#include "Lista.c"
//#include "Heap.c"


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


void Kruskal(Grafo *grafo)
{
    bubbleSort(grafo->arestas);
    Lista *temp;
    int vecaux[VERTMAX];
    int peso, v1, v2;

    for(int i = 0; i < VERTMAX; i++)
    {
        vecaux[i] = i;
    }

    peso = 0;

    for(temp = grafo->arestas; temp != NULL; temp = temp->prox)
    {
        if(vecaux[temp->vertice1] != vecaux[temp->vertice2])
        {
            v1 = vecaux[temp->vertice1];
            v2 = vecaux[temp->vertice2];
        
        for(int j = 0; j < VERTMAX; j++)
        {
            if(vecaux[j] == v2)
            {
                vecaux[j] = v1;
            }
        }
        printf("Aresta entre o vértice [%d] e o vértice [%d] com peso: %d\n", temp->vertice1, temp->vertice2, temp->peso);
        peso = peso + temp->peso;
       
       }


    }
    printf("Peso total da arvore geradora minima por KRUSKAL: %d\n", peso);
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
