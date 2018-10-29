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
		if (valor.compare(aux->GetDato())>0) // si la palabra es mas grande
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
		else if (valor.compare(aux->GetDato())<0) // la palabra es mas chica
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
		else if (valor.compare(aux->GetDato())== 0)  // la palabra es igual
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

void Arbol::BorrarDato(string palabra, NodoLigado* temp) 
{
	NodoLigado* aux = temp;
	NodoLigado* antes=temp;
	bool encontrado = false;
	while (aux != NULL && !encontrado) 
	{

		if (palabra.compare(aux->GetDato()) == 0) 
		{
			encontrado = true;
		}
		else if (palabra.compare(aux->GetDato() )< 0) 
		{
			antes = aux;
			aux = aux->GetIzquierda();
		}
		else if (palabra.compare(aux->GetDato())>0)
		{
			antes = aux;
			aux = aux->GetDerecha();
		}
	
	}
	if (aux->GetDerecha() == NULL && aux->GetIzquierda() == NULL) 
	{
		if (antes->GetDerecha() == aux) 
		{
			antes->SetDerecha(NULL);
			delete aux;
		}
		else if (antes->GetIzquierda() == aux) 
		{
			antes->SetIzquierda(NULL);
			delete aux;
		}
	}
	else if (aux->GetDerecha() == NULL && aux->GetIzquierda() != NULL) 
	{
		if (antes->GetDerecha() == aux)
		{
			antes->SetDerecha(aux->GetIzquierda());
			aux = NULL;
			delete aux;
		}
		else if (antes->GetIzquierda() == aux)
		{
			antes->SetIzquierda(aux->GetIzquierda());
			aux = NULL;
			delete aux;
		}
	}
	else if (aux->GetDerecha() != NULL && aux->GetIzquierda() == NULL)
	{
		if (antes->GetDerecha() == aux)
		{
			antes->SetDerecha(aux->GetDerecha());
			aux = NULL;
			delete aux;
		}
		else if (antes->GetIzquierda() == aux)
		{
			antes->SetIzquierda(aux->GetDerecha());
			aux = NULL;
			delete aux;
		}

	}
	else if (aux->GetDerecha() != NULL && aux->GetIzquierda() != NULL)
	{

	}
	numeroPalabras--;
}





void Arbol::Buscar(string palabra,NodoLigado* temp) 
{
	if (temp == NULL)
	{
		cout << "La palabra: " << palabra << " NO esta en el diccionario" << endl;
	}
	else if (temp->GetDato().compare(palabra) == 0)
	{
		cout << "La palabra: " << palabra << " SI esta en el diccionario" << endl;
	}
	else if (temp->GetDato().compare(palabra) < 0) // si la palabra es mas grande
	{
		Buscar(palabra, temp->GetDerecha());
	}
	else if (temp->GetDato().compare(palabra) > 0) // la palabra es mas chica
	{
		Buscar(palabra, temp->GetIzquierda());
	}
}

Arbol::~Arbol()
{
}
