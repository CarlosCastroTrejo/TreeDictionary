// Actividad 11
// Proyecto con el objetivo de crear un dicconario a traves de un archivo de texto e implementado en un arbol como estructura de datos
// Carlos Emiliano Castro Trejo A01422062
// Jorge Romero Romanis A01423263

#include "NodoLigado.h"
#include"Arbol.h"
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	Arbol myTree;
	string palabra,oracion;
	int linea = 0;
	ifstream archivo;
	archivo.open("texto.txt");

	if (archivo.is_open())
	{
		while (!archivo.eof())
		{
			linea++;
			getline(archivo, oracion);
			if (oracion.length()>=1)
			{
				if (oracion[0] == ' ')
				{
					while (oracion[0] ==' ')
					{
						oracion.erase(oracion.find(" "), oracion.find(" ") + 1);
					}
				}
				oracion += ' ';
				for (int x = 0; x < oracion.length(); x++)
				{
					oracion[x] = tolower(oracion[x]);
				}
				
				while (oracion.length()>0)
				{
					palabra = oracion.substr(0, oracion.find(' '));
					if (palabra[palabra.length() - 1] == '.' || palabra[palabra.length() - 1] == ',' || palabra[palabra.length() - 1] == ';' || palabra[palabra.length() - 1] == ':')
					{
						palabra.erase(palabra.length()-1);
					}
					if (palabra.length() >3 && palabra[0]>65) 
					{
						myTree.Insertar(palabra, myTree.GetRaiz(),linea);
					}
					oracion.erase(0, oracion.find(' ')+1);
					
				}
				
			}

		}
		archivo.close();
	}
	myTree.PreOrden(myTree.GetRaiz());
	cout << endl;
	while (oracion != "F")
	{
		cout << "Que deseas hacer" << endl;
		getline(cin,oracion);
		if (oracion[0] == 'D') 
		{
			palabra = oracion.substr(2, oracion.length() - 1);
			myTree.BorrarDato(palabra,myTree.GetRaiz());
		}
		else if (oracion[0] == 'M')
		{
			myTree.PreOrden(myTree.GetRaiz());
		}
		else if (oracion[0] == 'C') 
		{
			cout << "Hay " + to_string(myTree.GetNumeroDePalabras()) + " palabras en el diccionario." << endl;
		}
		else if (oracion[0] == 'I') 
		{
			palabra = oracion.substr(2, oracion.length() - 1);
			myTree.Insertar(palabra, myTree.GetRaiz(), 0);
		}
		else 
		{
			myTree.Buscar(oracion, myTree.GetRaiz());
		}
		cout << endl;
	}

	system("pause");
}