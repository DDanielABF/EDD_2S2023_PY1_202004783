#include "ListaCircularDoble.h"

ListaCircularDoble::ListaCircularDoble()
{
    this->Primero = 0;
    this->Tamanio = 0;
    //ctor
}

ListaCircularDoble::~ListaCircularDoble()
{
    //dtor
}
void ListaCircularDoble::Insertar(std::string password, std::string nombre)
{
    NodoListaCircularDoble *nuevo = new NodoListaCircularDoble(password,nombre);
    if(this->Primero == 0)
    {

        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoListaCircularDoble *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }

        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo;
        this->Tamanio++;
    }
}


    void ListaCircularDoble::VerLista()
{
    NodoListaCircularDoble *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->Nombre << endl;
        cout << aux->Password << endl;
        aux = aux->Siguiente;
        contador++;
    }
}


