#ifndef NODOLISTACIRCULARDOBLE_H
#define NODOLISTACIRCULARDOBLE_H
#include <string>
#include "Empleado.h"
using namespace std;

class NodoListaCircularDoble
{
    public:
        Empleado *EmpleadoSistema;
        NodoListaCircularDoble *Siguiente;
        NodoListaCircularDoble *Anterior;
        NodoListaCircularDoble(std::string password, std::string nombre);
        virtual ~NodoListaCircularDoble();

    protected:

    private:
};

#endif // NODOLISTACIRCULARDOBLE_H
