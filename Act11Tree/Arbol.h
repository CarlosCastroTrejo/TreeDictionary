#pragma once
#include "NodoLigado.h"
#include <string>
using namespace std;

class Arbol
{
	NodoLigado *raiz;
	int numeroPalabras=0;
public:
	Arbol();
	void Insertar(string, NodoLigado*,int);
	void InOrder(NodoLigado*);
	void PreOrden(NodoLigado*);
	void PostOrden(NodoLigado*);
	void Buscar(string,NodoLigado*);
	void BuscarMayor(string, NodoLigado*, NodoLigado*);
	void BorrarDato(string, NodoLigado*);
	int GetNumeroDePalabras();

	NodoLigado* GetRaiz();
	~Arbol();
};
