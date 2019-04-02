#include "Floyd-Warshall.h"
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



void FloydWarshall(Grafo *grafo)
{
    int floyd[VERTMAX][VERTMAX];
    int i, j, k;


    for(i = 0; i < VERTMAX; i++)
    {
        for(j = 0; j < VERTMAX; j++)
        {
            floyd[i][j] = grafo->matriz[i][j];
            if(floyd[i][j] == 0)
            {
                floyd[i][j] = 99999;
            }
        }
    }
    for(k = 0; k < VERTMAX; k++)
    {
        for(i = 0; i < VERTMAX; i++)
        {
            for(j = 0; j < VERTMAX; j++)
            {
                if(i == j)
                {
                    floyd[i][j] = 0;
                }
                else if(floyd[i][k] + floyd[k][j] < floyd[i][j])
                {
                    floyd[i][k] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
    for(i = 1; i <= (Numero_Vertice(grafo)); i++ )
    {
        for(j = 1; j <=(Numero_Vertice(grafo)); j++)
        {
            if(floyd[i][j] != 99999)
            {
                printf("[ %d ]", floyd[i][j]);
            }
        }
        printf("\n");
    }
}

int Numero_Vertice(Grafo *grafo)
{
    int maior;
    maior = grafo->arestas->vertice1;
    Lista *temp;

    for(temp = grafo->arestas; temp != NULL; temp = temp->prox)
    {
        if(temp->vertice1 > maior)
        {
            maior = temp->vertice1;
        }
        else if(temp->vertice2 > maior)
        {
            maior = temp->vertice2;
        }
    }
    return maior;
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
