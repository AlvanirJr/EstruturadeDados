#include "Lista.h"


Lista* criarLista(){
	return NULL;
}

void bubbleSort(Lista* l){
	Lista* aux;
	int trocou = 0;	
	int tempV1, tempV2, tempP;
	while(trocou == 0){
		trocou = 1;
		for(aux = l; aux->prox!=NULL; aux = aux->prox){
			if(aux->peso > aux->prox->peso){
				tempP = aux->peso;
				aux->peso = aux->prox->peso;
				aux->prox->peso = tempP;
				
				tempV1 = aux->vertice1;
				aux->vertice1 = aux->prox->vertice1;
				aux->prox->vertice1 = tempV1;
				
				tempV2 = aux->vertice2;
				aux->vertice2 = aux->prox->vertice2;
				aux->prox->vertice2 = tempV2;
				trocou = 0;
			}	
		}
	}
}

Lista* inserirLista(Lista* l, int vertice1, int vertice2, int peso){
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->vertice1 = vertice1;
	novo->vertice2 = vertice2;
	novo->peso = peso;
	if(l==NULL){
		novo->prox = NULL;
		return novo;
	}
	novo->prox = l;
	return novo;
}



