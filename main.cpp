#include <iostream>
#include "Arbol.h"

using namespace std;
int main()
{
	Arbol ArbolInt;

	// InserciÛn de nodos en ·rbol:
	/*ArbolInt.Insertar(ArbolInt.RegresaRaiz(),10);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),5);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),12);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),68);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),456);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),345);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),2);
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),9);
	
	ArbolInt.Insertar(ArbolInt.RegresaRaiz(),43);*/
	ArbolInt.CrearArchivo("archivo.txt");
		cout << "InOrden: ";
	ArbolInt.Inorden();
	cout << endl;
	ArbolInt.Eliminar(43);
	cout << "InOrden: ";
	ArbolInt.Inorden();
	cout << endl;
	ArbolInt.Eliminar(2);
		cout << "InOrden: ";
		ArbolInt.Inorden();
		cout << endl;
		return 0;
}