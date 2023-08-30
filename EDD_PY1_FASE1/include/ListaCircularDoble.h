#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "NodoListaCircularDoble.h"
#include <string>
#include <iostream>
#include "Empleado.h"

using namespace std;


class ListaCircularDoble
{
    public:
        NodoListaCircularDoble *Primero;
        int Tamanio;
        void Insertar(std::string password, std::string nombre);
        void VerLista();
        Empleado *BuscarEmpleado(std::string nombre);
        ListaCircularDoble();
        virtual ~ListaCircularDoble();

    protected:

    private:
};

#endif // LISTACIRCULARDOBLE_H
