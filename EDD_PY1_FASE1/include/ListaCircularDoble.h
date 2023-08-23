#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H
#include "NodoListaCircularDoble.h"
#include <string>
#include <iostream>

using namespace std;


class ListaCircularDoble
{
    public:
        NodoListaCircularDoble *Primero;
        int Tamanio;
        void Insertar(std::string password, std::string nombre);
        void VerLista();
        ListaCircularDoble();
        virtual ~ListaCircularDoble();

    protected:

    private:
};

#endif // LISTACIRCULARDOBLE_H
