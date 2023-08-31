#include "ListaDoble.h"
#include <iostream>

ListaDoble::ListaDoble()
{
    this->Primero=0;
    this->Tamanio=0;
    //ctor
}

ListaDoble::~ListaDoble()
{
    //dtor
}
void ListaDoble::insertar(std::string codigo, std::string nombre_tarea, std::string codigo_encargado){
NodoListaDoble *nuevo = new NodoListaDoble(codigo, nombre_tarea, codigo_encargado);
if(this->Primero==0){
    this->Primero= nuevo;
    this->Tamanio++;

    }else{
    NodoListaDoble *aux = this->Primero;
    while(aux->Siguiente){

        aux=aux->Siguiente;
    }

    nuevo->Anterior =aux;
    aux->Siguiente = nuevo;
    this->Tamanio++;

    }

}

void ListaDoble::Asignar(std::string codigo, std::string nombre_tarea,std::string codigo_encargado){

    if(this->Primero){

        NodoListaDoble *aux= this->Primero;
        while(aux){
            if (aux->Codigo.compare(codigo)==0 && aux->Nombre_Tarea.compare(nombre_tarea)==0){

                aux->Codigo_Encargado = codigo_encargado;
                this->insertar(aux->Codigo, aux->Nombre_Tarea,aux->Codigo_Encargado);
                break;


            }
            aux=aux->Siguiente;


        }




    }





}






