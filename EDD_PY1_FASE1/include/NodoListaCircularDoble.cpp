#include "NodoListaCircularDoble.h"

NodoListaCircularDoble::NodoListaCircularDoble(std::string password, std::string nombre)
{

    this->EmpleadoSistema = new Empleado(nombre, password);
    this ->Siguiente=0;
    this -> Anterior=0;
    //ctor
}

NodoListaCircularDoble::~NodoListaCircularDoble()
{
    //dtor
}
