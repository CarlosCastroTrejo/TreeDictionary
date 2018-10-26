#include "pch.h"
#include "ListaDoble.h"
#include "NodoDobleLigado.h"
#include <iostream>
using namespace std;

ListaDoble::ListaDoble()
{
	head = NULL;
}


ListaDoble::~ListaDoble()
{
}

void ListaDoble::insertaOrden(int d)
{// inserci'on en orden permite repetidos
	NodoDobleLigado* nuevo = new NodoDobleLigado(d);
	if (this->head == NULL) 
	{
		this->head = nuevo;
	}
	else
	{
		NodoDobleLigado* aux = head, *antes = head;
		while (aux != NULL && d > aux->getDato())
		{
			antes = aux;
			aux = aux->getSig();
		}
		if (antes == aux)
		{// inserta uno mas pequenio que raiz
			nuevo->setSig(head);
			head->setAntes(nuevo);
			head = nuevo;
		}
		else if (aux == NULL)
		{//inserta al final
			nuevo->setAntes(antes);
			antes->setSig(nuevo);
		}
		else
		{//inserta en medio
			nuevo->setSig(aux);
			nuevo->setAntes(antes);
			antes->setSig(nuevo);
			aux->setAntes(nuevo);
		}
	}
}

void ListaDoble::borraDato(int d)
{
	if (head == NULL)
		cout << "Lista vacia" << endl;
	else
	{
		NodoDobleLigado* aux = head;
		while (aux != NULL && aux->getDato() != d)
			aux = aux->getSig();
		if (aux == NULL)
			cout << "El dato " << d << " no esta en la lista" << endl;
		else
		{
			if (aux == head)
			{// borro head
				head = head->getSig();
				if (head != NULL)
					head->setAntes(NULL);
			}
			else if (aux->getSig() == NULL)
			{// borro ultimo
				aux->getAntes()->setSig(NULL);
			}
			else
			{
				aux->getAntes()->setSig(aux->getSig());
				aux->getSig()->setAntes(aux->getAntes());
			}
		}
	}
}
ostream&operator<<(ostream& out, ListaDoble L)
{
	if (L.head == NULL) 
	{
		out << " vacia " << endl;
	}
	else
	{
		NodoDobleLigado* aux = L.head;
		while (aux != NULL)
		{
			out << aux->getDato() << " ";
			aux = aux->getSig();
		}
		out << endl;
	}
	return out;
}