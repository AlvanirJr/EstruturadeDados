
#include "lista.hpp"


int main()
{

	lista* l = new lista ();

	l->adicionar(10); 
	l->adicionar(20); 
	l->adicionar(30); 
	l->print();
	delete l;

	return 0;
}
