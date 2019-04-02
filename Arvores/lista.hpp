#ifndef __LISTA_HPP__
#define __LISTA_HPP__

#include <iostream>
using namespace std;

struct no
{
	int valor;
	no* prox;
	no(int i);
};


class lista
{
	no* inicio;
public:
	lista();
	void adicionar(int valor);
	void apagar();
	void print();
	~lista();
};




#endif // __LISTA_HPP__
