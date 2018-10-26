#pragma once
#include "NodoDobleLigado.h"
class ListaDoble
{
	NodoDobleLigado* head;
public:
	ListaDoble();
	~ListaDoble();
	void insertaOrden(int);
	void borraDato(int);
	friend ostream&operator<<(ostream&, ListaDoble);
};

