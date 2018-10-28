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
					if (palabra.length() >=3) 
					{
						myTree.Insertar(palabra, myTree.GetRaiz(),linea);
					}
					oracion.erase(0, oracion.find(' ')+1);
					
				}
				
			}

		}
		archivo.close();
	}
	myTree.InOrder(myTree.GetRaiz());
	cout << endl;
	while (oracion != "F")
	{
		cout << "Que deseas hacer" << endl;
		getline(cin,oracion);
		if (oracion[0] == 'D') 
		{
		
		}
		else if (oracion[0] == 'M')
		{
			myTree.InOrder(myTree.GetRaiz());
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