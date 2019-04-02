#ifndef __Djikstra__
#define __Djikstra__

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


#define VERTMAX 50
#define ARESTAMAX 20
#define true 1
#define false 0


typedef struct __GRAFO__
{
    int ponderado;
    int digrafo;
    int matriz[VERTMAX][VERTMAX];
    Lista *arestas;
}Grafo;

typedef struct listaAux
{
    int vertice;
    int custo;
    int prev;
}ListaAux;

Grafo *CriarGrafo(int ponderado, int digrafo);
void InserirGrafo(Grafo *grafo,int vertice1, int vertice2, int peso);
void FloydWarshall(Grafo *grafo);
int Numero_Vertice(Grafo *grafo);
void Imprimir(Grafo *grafo);


#endif