#ifndef NODOLISTACIRCULARDOBLE_H
#define NODOLISTACIRCULARDOBLE_H
#include <string>
using namespace std;

class NodoListaCircularDoble
{
    public:
        std::string Nombre;
        std::string Password;
        NodoListaCircularDoble *Siguiente;
        NodoListaCircularDoble *Anterior;
        NodoListaCircularDoble(std::string password, std::string nombre);
        virtual ~NodoListaCircularDoble();

    protected:

    private:
};

#endif // NODOLISTACIRCULARDOBLE_H
