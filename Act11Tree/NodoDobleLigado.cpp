#include "pch.h"
#include "NodoDobleLigado.h"


NodoDobleLigado::NodoDobleLigado()
{
	antes = NULL;
	sig = NULL;
}

NodoDobleLigado::NodoDobleLigado(int d)
{
	dato = d;
	antes = NULL;
	sig = NULL;
}

NodoDobleLigado::~NodoDobleLigado()
{
}

int NodoDobleLigado::getDato()
{
	return dato;
}

void NodoDobleLigado::setSig(NodoDobleLigado* s)
{
	sig = s;
}

void NodoDobleLigado::setAntes(NodoDobleLigado* s)
{
	antes = s;
}

NodoDobleLigado*NodoDobleLigado::getSig()
{
	return sig;
}
NodoDobleLigado*NodoDobleLigado::getAntes()
{
	return antes;

}

ostream&operator<<(ostream& out, NodoDobleLigado* nodo)
{
	if (nodo != NULL)
		out << nodo->dato;
	else
		out << "  ";
	return out;
}