#include "NodoListaCircularDoble.h"

NodoListaCircularDoble::NodoListaCircularDoble(std::string password, std::string nombre)
{

    this -> Password=password;
    this->Nombre=nombre;
    this ->Siguiente=0;
    this -> Anterior=0;
    //ctor
}

NodoListaCircularDoble::~NodoListaCircularDoble()
{
    //dtor
}
