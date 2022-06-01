#include<iostream>
using namespace std;
class Nodo
{
	private:
	int dato;      // Dato del nodo
	Nodo *enlace; // Direccion a otro Nodo,
	public:
	Nodo(int d)
	{
		dato=d; //Asigna el dato=d a este Nodo
		enlace=NULL; //Este nodo apunta a NULL
	}
	Nodo(int d,Nodo *n)
	{
		dato=d;
		enlace=n;
	}
	int getDato() //Devuelve el dato
	{
		return dato;
	}
	void setDato(int nuevoDato) //Fija un nuevo dato
	{
		dato=nuevoDato;
	}
	Nodo *getEnlace() //Devuelve la dirección a donde apunta
	{
		return enlace;
	}
	void setEnlace(Nodo *sgte) //Fija un nuevo enlace
	{
		enlace=sgte;
	}
};
class Lista
{
	private:
	Nodo *primero;
	public:
	Lista() //Constructor
	{
		primero = NULL;
	}
	void crearLista();
	void visualizarLista();
	//Continua las demás funciones
	void insertarCabeza(int);
	void insertarUltimo(int);
	Nodo *ultimoNodo();
	Nodo *buscaNodo(int);
	void insertaDespues(int,int);
	void eliminarNodo(int dato);
	Nodo *buscarAntesNodo(int);
	Nodo *buscarDespuesNodo(int);
	void insertarOrden(int);
};
//Crear una lista
void Lista::crearLista()
{
	int x;
	cout << "Termina con -1" << endl;
	do 
	{
		cin >> x;
		if (x != -1) //El nuevo primero
		{
			//primero = new Nodo(x,primero);
			insertarOrden(x);
		}
	}while (x != -1);
};
//Visualizar una lista
void Lista::visualizarLista()
{
	Nodo *indice;
	cout<<"Direccion del nodo \t Dato \t a donde apunta\n";
	for (indice=primero;indice!=NULL;indice=indice->getEnlace())
		cout<<indice<<"\t"<<indice->getDato()<<"\t"<<indice->getEnlace()<<endl;
}
void Lista::insertarCabeza(int dato)
{
	Nodo *nuevo;
	nuevo=new Nodo(dato);
	nuevo->setEnlace(primero);
	primero=nuevo;
}
Nodo *Lista::ultimoNodo()
{
	Nodo *indice=primero;
	if (primero==NULL)
		return NULL;
	while (indice->getEnlace()!=NULL)
		indice=indice->getEnlace();
	return indice;
}
void Lista::insertarUltimo(int dato)
{
	Nodo *nuevo=new Nodo(dato);
	Nodo *ultimo=ultimoNodo();
	if (ultimo==NULL)
		primero=nuevo;
	else
		ultimo->setEnlace(nuevo);
}
Nodo *Lista::buscaNodo(int dato)
{
	Nodo *indice;
	for (indice=primero;indice!=NULL;indice=indice->getEnlace())
		if (indice->getDato()==dato)
			return indice;
	return NULL;
}
void Lista::insertaDespues(int datoAnt,int dato)
{
	Nodo *nuevo=new Nodo(dato);
	Nodo *anterior=buscaNodo(datoAnt);
	if (anterior==NULL)
		return;
	nuevo->setEnlace(anterior->getEnlace());
	anterior->setEnlace(nuevo);
}
Nodo *Lista::buscarAntesNodo(int dato)
{
	Nodo *anterior;
	for (anterior=primero;anterior!=NULL;anterior=anterior->getEnlace())
	{
	    if(anterior->getEnlace()==NULL)
			return NULL;
		if (anterior->getEnlace()->getDato()==dato)
			return anterior;
	}
	return NULL;
}
void Lista::eliminarNodo(int dato)
{
	if (primero == NULL)
		return;
	if (primero->getDato() == dato) {
		Nodo* n = primero;
		primero = primero->getEnlace();
		delete n;
	}
	else {
		Nodo* anterior = buscarAntesNodo(dato);
		if (anterior == NULL)
			return;
		Nodo* nodoBorrar = buscaNodo(dato);
		anterior->setEnlace(nodoBorrar->getEnlace());
		delete nodoBorrar;
	}
}
void Lista::insertarOrden(int dato)
{
	Nodo *nuevo=new Nodo(dato);
	Nodo *indice=primero, *anterior=NULL;
	if (primero==NULL)
	{
		primero=nuevo;
		return;
	}
	if (dato<primero->getDato())
	{
		insertarCabeza(dato);
		return;
	}
	while(indice!=NULL)
	{
		if (dato>=indice->getDato())
		{
			anterior=indice;
			indice=indice->getEnlace();
		}
		else
			break;	
	}
	//////
	nuevo->setEnlace(anterior->getEnlace());
	anterior->setEnlace(nuevo);
	/////
}