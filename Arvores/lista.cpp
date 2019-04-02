#include "lista.hpp"

no::no(int v)
{
	prox = nullptr;
	valor = v;
}

lista::lista()
{
	inicio = nullptr;
}

void lista::adicionar(int valor)
{
	no* n = new no(valor);
	n->prox = inicio;
	inicio = n;
}

void lista::print()
{
	no* aux = inicio;
	while(aux != nullptr)
	{
		cout << aux->valor << " ";
		aux = aux->prox;
	}
}
void lista:: scan()
{
	printf("AQUIII");
}
lista::~lista()
{
	no* aux1 = inicio;
	no* aux2;
	while(aux1 != nullptr)
	{
		aux2 = aux1->prox;
		delete aux1;
		aux1 = aux2;
	}
}
