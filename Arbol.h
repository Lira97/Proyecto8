#include <iostream> 
#include <fstream> 
#include <cstdlib>
#include <string> 
#ifndef Arbol_H
#define Arbol_H

using namespace std;
class Arbol;
class nodo 
{
	private:
		int Info;
		nodo *HijoDer;
		nodo *HijoIzq;
	public:
		nodo ();
		friend class Arbol;
};
nodo::nodo()
{
	HijoDer=NULL;
	HijoIzq=NULL;
}
class Arbol 
{
	private:
		nodo *Raiz;
		nodo *RegresaRaiz();
		
		void Inorden(nodo *);
		void Insertar(nodo*,int);
		void Eliminar(nodo *, int );
	public:
		Arbol();
		void CrearArchivo(string);
		void Inorden();
		bool Busqueda(nodo *,int);
		void Insertar(int);
		void Eliminar( int );
		
};

Arbol::Arbol()
{
	Raiz=NULL;
}
nodo *Arbol::RegresaRaiz()
{
	return Raiz;
}
void Arbol::Insertar(int dato)
{
	Insertar(RegresaRaiz(),dato);
}
void Arbol::Eliminar(int dato)
{
	Eliminar(RegresaRaiz(),dato);
}
void Arbol::Inorden()
{
	Inorden(RegresaRaiz());
}

void Arbol::CrearArchivo(string archivo)
{
	fstream datos;//se instancia el archivo 
	datos.open(archivo); //se abre el archivo 
	string line; //se crea la variable línea  	
	while (!datos.eof())//si detecta el fin del archivo
	{
		datos.ignore(0,'\n'); //ignora la primera línea del archivo 
		getline (datos, line, '\n'); //toma la línea que se encuentra debajo de la otra 
		Insertar(RegresaRaiz(),atoi (line.c_str()));//la primera posición del arreglo se iguala a la trasformación del string a un numero 				
	}
	Eliminar(RegresaRaiz(),0);
	datos.close();//se cierra el archivo 
}
void Arbol::Inorden(nodo *Apunt)
{
	if (Apunt)
	{
		Inorden(Apunt->HijoIzq);
		cout<<Apunt->Info<<" ";
		Inorden(Apunt->HijoDer);
	}
}

bool Arbol::Busqueda(nodo * Apunt, int dato )
{
	if (Apunt)
	{
		if(dato<Apunt->Info)
		{
			return Busqueda(Apunt->HijoIzq, dato);
		}
		else
		{
			if (dato>Apunt->Info)
			{
				return Busqueda(Apunt->HijoDer, dato);
			}
			else 
			{
				return true;
			}
		}
	}
	else 
	{
		return false;
	}
}
void Arbol::Insertar(nodo *Apunt, int dato)
{
	nodo *ApAux;
	if (Apunt)
	{
		if (dato<Apunt->Info)
		{
			Insertar(Apunt->HijoIzq, dato);
			Apunt->HijoIzq=Raiz;
		}
		else 
			if(dato>Apunt->Info)
			{
				Insertar(Apunt->HijoDer, dato);
				Apunt->HijoDer=Raiz;	
			}
			Raiz=Apunt;
	}
	else 
	{
		
		ApAux=new nodo();
		ApAux->Info=dato;
		Raiz=ApAux;
	}	
}
void Arbol::Eliminar(nodo *Apunt, int dato)
{
	if (Apunt)
		if(dato<Apunt->Info)
		{
			Eliminar(Apunt->HijoIzq, dato);
			Apunt->HijoIzq=Raiz;
		}
		else 
			if(dato>Apunt->Info)
			{
				Eliminar(Apunt->HijoDer, dato);
				Apunt->HijoDer=Raiz;
			}
			else 
			{
				nodo *ApAux1,*ApAux2,*ApAux3 ;
				ApAux3=Apunt;
				if(!ApAux3->HijoDer)
					if(!ApAux3->HijoIzq)
						Apunt=NULL;
					else 
						Apunt=ApAux3->HijoIzq;
				else 
					if(!ApAux3->HijoIzq)
					Apunt=ApAux3->HijoDer;
					else 
					{
						ApAux1=ApAux3->HijoIzq;
						ApAux2=ApAux3;
						while(ApAux1->HijoDer)
						{
							ApAux2=ApAux1;
							ApAux1=ApAux1->HijoDer;
						}
						ApAux3->Info=ApAux1->Info;
						if(ApAux3==ApAux2)
							ApAux3->HijoIzq=NULL;
						else
							if(!ApAux1->HijoIzq)
								ApAux2->HijoDer=NULL;
							else
								ApAux2->HijoDer=ApAux1->HijoIzq;
						ApAux3=ApAux1;
					}
				delete ApAux3;	
			}
			Raiz=Apunt;
}
#endif