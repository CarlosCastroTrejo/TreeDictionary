#include "NodoLigado.h"
#include<iostream>
using namespace std;

NodoLigado::NodoLigado(string valor)
{
	izquierda = NULL;
	derecha = NULL;
	this->dato = valor;
}

NodoLigado::NodoLigado()
{
	izquierda = NULL;
	derecha = NULL;
	this->dato = " ";
}

void NodoLigado::SetDato(string valor)
{
	this->dato = valor;
}

string NodoLigado::GetDato()
{
	return this->dato;
}

NodoLigado* NodoLigado::GetIzquierda()
{
	return this->izquierda;
}

NodoLigado* NodoLigado::GetDerecha()
{
	return this->derecha;
}

void NodoLigado::SetDerecha(NodoLigado* temp)
{
	this->derecha = temp;
}

void NodoLigado::SetIzquierda(NodoLigado* temp)
{
	this->izquierda = temp;
}

ListaDoble NodoLigado::GetLista() 
{
	return lista;
}

NodoLigado::~NodoLigado()
{
}
