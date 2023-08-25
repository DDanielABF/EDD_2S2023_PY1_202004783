#include "NodoCola.h"

NodoCola::NodoCola(Proyecto *nuevoProyecto, std::string prioridad)
{
    this->Siguiente = 0;
    this->Proyecto_ABC = nuevoProyecto;
    this->Prioridad = prioridad;
    //ctor
}

NodoCola::~NodoCola()
{
    //dtor
}
