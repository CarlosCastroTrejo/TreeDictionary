#pragma once
#include<iostream>
#include <string>
#include "ListaDoble.h"
using namespace std;

class NodoLigado
{
	NodoLigado *derecha;
	NodoLigado *izquierda;
	string dato;
public:
	ListaDoble lista;
	NodoLigado(string);
	NodoLigado();
	void SetDato(string);
	string GetDato();
	NodoLigado* GetIzquierda();
	NodoLigado* GetDerecha();
	void SetDerecha(NodoLigado*);
	void SetIzquierda(NodoLigado*);
	ListaDoble GetLista();

	~NodoLigado();
};