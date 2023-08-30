#include "NodoListaDoble.h"

NodoListaDoble::NodoListaDoble(std::string codigo, std::string nombre_tarea, std::string codigo_encargado)
{
    this->Codigo= Codigo;
    this->Nombre_Tarea = nombre_tarea;
    this->Codigo_Encargado = codigo_encargado;
    this->Anterior =0;
    this->Siguiente=0;
    //ctor
}

NodoListaDoble::~NodoListaDoble()
{
    //dtor
}
