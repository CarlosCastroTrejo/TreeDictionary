#pragma once
#include <ostream>
using namespace std;

class NodoDobleLigado
{
	int dato;
	NodoDobleLigado*antes, *sig;

public:
	NodoDobleLigado();
	NodoDobleLigado(int);
	~NodoDobleLigado();
	void setSig(NodoDobleLigado*);
	void setAntes(NodoDobleLigado*);
	NodoDobleLigado*getSig();
	NodoDobleLigado*getAntes();
	int getDato();
	friend ostream&operator<<(ostream&, NodoDobleLigado*);
};

