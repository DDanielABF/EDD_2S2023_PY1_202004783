#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(Proyecto *proyecto, Empleado *encargado, int posx, int posy)
{

    this->Abajo = 0;
    this->Anterior = 0;
    this->Arriba = 0;
    this->Siguiente = 0;
    this->PosY = posy;
    this->PosX = posx;
    this->Encargado_c = encargado;
    this->Proyecto_ABC = proyecto;
    this->Tareas = new ListaDoble();
    //ctor
}

NodoMatriz::~NodoMatriz()
{
    //dtor
}
