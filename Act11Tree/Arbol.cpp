#include "Arbol.h"
#include<iostream>
#include<string>

using namespace std;

Arbol::Arbol()
{
	raiz = NULL;
}

void Arbol::Insertar(string valor, NodoLigado * aux,int linea)
{
	NodoLigado *temp = new NodoLigado(valor);
	if (raiz == NULL)
	{
		numeroPalabras++;
		raiz = temp;
		raiz->lista.insertaOrden(linea);
	}
	else
	{
		if (aux->GetDato().compare(valor)<0) // si la palabra es mas grande
		{
			if (aux->GetDerecha() == NULL)
			{
				aux->SetDerecha(temp);
				aux->GetDerecha()->lista.insertaOrden(linea);
				numeroPalabras++;
			}
			else
			{
				Insertar(valor, aux->GetDerecha(),linea);
			}
		}
		else if (aux->GetDato().compare(valor)>0) // la palabra es mas chica
		{
			if (aux->GetIzquierda() == NULL)
			{
				aux->SetIzquierda(temp);
				aux->GetIzquierda()->lista.insertaOrden(linea);
				numeroPalabras++;
			}
			else
			{
				Insertar(valor, aux->GetIzquierda(),linea);
			}
		}
		else if (aux->GetDato().compare(valor) == 0)  // la palabra es igual
		{
			aux->lista.insertaOrden(linea);
		}
	}
}

int Arbol::GetNumeroDePalabras()
{
	return this->numeroPalabras;
}

NodoLigado* Arbol::GetRaiz()
{
	return this->raiz;
}

void Arbol::InOrder(NodoLigado* temp)
{
	if (temp != NULL)
	{
		InOrder(temp->GetIzquierda());
		cout << temp->GetDato()<<" "<<temp->GetLista() << endl;
		InOrder(temp->GetDerecha());
	}

}

void Arbol::PreOrden(NodoLigado* temp)
{
	if (temp != NULL)
	{
		cout << temp->GetDato() << " " << temp->GetLista() << endl;
		PreOrden(temp->GetIzquierda());
		PreOrden(temp->GetDerecha());
	}
}

void Arbol::PostOrden(NodoLigado* temp)
{
	if (temp != NULL)
	{
		PostOrden(temp->GetIzquierda());
		PostOrden(temp->GetDerecha());
		cout << temp->GetDato() << " " << temp->GetLista() << endl;
	}
}

Arbol::~Arbol()
{
}
