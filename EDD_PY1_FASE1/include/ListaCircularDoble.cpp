#include "ListaCircularDoble.h"

ListaCircularDoble::ListaCircularDoble()
{
    this->Primero = 0;
    this->Tamanio = 0;
    //ctor
}

ListaCircularDoble::~ListaCircularDoble()
{
    //dtor
}
void ListaCircularDoble::Insertar(std::string password, std::string nombre)
{
    NodoListaCircularDoble *nuevo = new NodoListaCircularDoble(password,nombre);
    int numero_empleado = 1 + this->Tamanio;
    std::string codigo = (numero_empleado < 100 ? (numero_empleado < 10 ? "SC-00"+std::to_string(numero_empleado) : "SC-0"+std::to_string(numero_empleado)): "SC-"+std::to_string(numero_empleado));
    nuevo->EmpleadoSistema->Codigo = codigo;
    if(this->Primero == 0)
    {

        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoListaCircularDoble *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }

        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo;
        this->Tamanio++;
    }
}


    void ListaCircularDoble::VerLista()
{
    NodoListaCircularDoble *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->EmpleadoSistema->Codigo << endl;
        cout << aux->EmpleadoSistema->Nombre << endl;
        cout << aux->EmpleadoSistema->Password << endl;
        aux = aux->Siguiente;
        contador++;
    }
}


