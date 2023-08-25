#include "Empleado.h"

Empleado::Empleado(std::string nombre, std::string password)
{
    this->Codigo = "";
    this->Nombre = nombre;
    this->Password = password;
    this->Puesto = "";
    //ctor
}

Empleado::~Empleado()
{
    //dtor
}
